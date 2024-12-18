/* NAME OF STUDENTS

    Ananya Agarwal
    Sharon Huang
    Caleb  Kimondo
    Adrian Bernazar
*/

//________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int done =0;
//_____________DATATYPE
typedef struct{ // faculty info (MAX: 30)
    char * name;
    char * id;
    char * department;
    //only math, cs, or science
    char * rank;
    //professor or adjunct
} faculty;


typedef struct{ // student info (MAX: 100)
    char * name;
    char * id;
    float gpa;
    //if GPA>= 3.85 then 25% TOTAL payment
    int credit;
    // $236.45 per one credit hour + 52 for admin fee

} student;

//_____________PROTOTYPES
void addFaculty(faculty f[], int index );// Add a new faculty memeber
void addStudent(student s[], int index); // Add a new student
void printTuition(char * name, char * id, float  gpa, int  credit); // Print tuition invoice for a student
void printFaculty(char * name, char * department, char * rank); // Print information of a faculty
void makeCapital (char *givenStr); // as STRING entries are stored in capital, this makes all letter inputs capital letters
void freefunc(faculty f[], student s[], int numF, int numS); // Frees all of the information in studentlst and facultylst at the end of the whole process
void exitProgram(faculty f[], student s[], int numF, int numS); // Prints out final report if user wanted to exit the program

//_____________FUNCTIONS
void addFaculty(faculty f[], int index){



    f[index].name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    f[index].id = malloc(10 * sizeof(char)); // Allocate enough space for the id
    f[index].department = malloc(50 * sizeof(char)); // Allocate enough space for the department
    f[index].rank = malloc(30 * sizeof(char));


    printf("\n\nEnter the faculty's info:\n ");

    printf("\n\tName of the faculty: ");
    char dead[5];
    gets(dead);
    fgets(f[index].name, 50, stdin);
    makeCapital(f[index].name);



    printf("\n\tID: ");
    fgets(f[index].id, 50, stdin);
    makeCapital(f[index].id);



    int i =0;
    while(i<3){

            printf("\n\tRank: ");
            //gets(dead);
            fgets(f[index].rank, 50, stdin);
            char * rank1 = malloc(30 * sizeof(char));
            strcpy(rank1, f[index].rank);
            //scanf("%s", f[index].rank);
            makeCapital(f[index].rank);
            if (strcmp(f[index].rank, "PROFESSOR") ==0|| strcmp(f[index].rank, "ADJUNCT") ==0) {
                break;
            }else{
                if (i ==2){
                    printf("\n\n\tYou have tried too many times...\n");
                    done =1;
                    return;

                }
                int j;
                for (j = 0; rank1[j] != '\0'; j++)
                {
                    if (rank1[j] == '\n'){
                        rank1[j] = '\0';
                    }
                }
                printf("\n\t\tSorry entered rank (%s) is invalid. Try again.\n", rank1 );
                i++;


            }
    }

    i =0;
    while(i<3){

            printf("\n\tDepartment: ");
            fgets(f[index].department, 50, stdin);
            char * department1 = malloc(30 * sizeof(char));
            strcpy(department1, f[index].department);
            //scanf("%s", f[index].department);
            makeCapital(f[index].department);
            if (strcmp(f[index].department, "MATH") ==0|| strcmp(f[index].department, "CS") ==0 || strcmp(f[index].department, "SCIENCE") ==0) {
                break;
            }else{
                if (i ==2){
                    printf("\n\n\tYou have tried too many times...\n");
                    done =1;
                    return;

                }
                int j;
                for (j = 0; department1[j] != '\0'; j++)
                {
                    if (department1[j] == '\n'){
                        department1[j] = '\0';
                    }
                }
                printf("\n\t\tSorry entered department (%s) is invalid. Try again.\n", department1 );
                i++;


            }
    }



    printf("\nThanks!\n\n");

}



void addStudent(student s[], int index){



    s[index].name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    s[index].id = malloc(10 * sizeof(char)); // Allocate enough space for the id


    printf("\n\nEnter the student's info:\n\n ");

    printf("\n\tName of Student: ");
    char dead[5];
    gets(dead);
    fgets(s[index].name, 50, stdin);
    makeCapital(s[index].name);
    //printf("%s", s[index].name);


    printf("\n\tID: ");
    scanf("%s", s[index].id);
    makeCapital(s[index].id);

    printf("\n\tGPA: ");
    scanf("%f", &s[index].gpa);
    //printf("%f", s[index].gpa);

    printf("\n\tCredit hours: ");
    scanf("%d", &s[index].credit);

    printf("\nThanks!\n\n");


}


void printTuition(char * name, char * id, float  gpa, int  credit){
    //printf("%d", credit);
    float totalFee= credit * 236.45;
    float discount= 0;
    if (gpa>=3.85){
        discount = totalFee * .25;
        totalFee= totalFee - discount;
    }
    totalFee= totalFee +52;


    printf("\n\tHere is the tuition invoice for %s: \n\n", name);
    printf("---------------------------------------------------------------------------");
    printf("\n\t %s \t\t\t\t %s\n", name ,id);
    printf("\n\t Credit Hours: %d ($236.45/credit hour)\n", credit);
    printf("\n\t Fees: $52\n\n");
    printf("\n\t Total payment: $%.2f \t\t\t($%.f discount applied)\n", totalFee, discount);
    printf("\n---------------------------------------------------------------------------\n\n");

}



void printFaculty(char * name, char * department, char * rank){


    printf("\nFaculty found:");
    printf("\n--------------------------------------------\n");
    printf("\n\t %s\n", name);
    printf("\n\t %s department, ", department);
    printf("%s\n", rank);
    printf("\n---------------------------------------------\n\n");
    return;

}

void exitProgram(faculty f[], student s[], int numF, int numS){
    //User can output the faculty information sorted
    char facultyC;

    printf("\nEnter\n");
    printf("\t N or n to sort the faculty by name\n");
    printf("\t D or d to sort the faculty by department\n");
    printf("\t R or r to sort the faculty by rank\n");

    printf("\nMake your sort selection: ");
    scanf("%s",&facultyC);

    // Sort faculty based on selection
    int swapped;
    faculty temp;

    if(facultyC== 'n'|| facultyC== 'N')
    {
        //sort by name
        for (int i =0; i<numF; i++){
            swapped =0;
            for (int j =0; j <numF-1; j++){
                if (strcmp(f[j].name, f[j+1].name) >0){
                    temp = f[j];
                    f[j] = f[j+1];
                    f[j+1] = temp;
                }
            }
            if (swapped){
                break;
            }
        }

    }
    else if(facultyC== 'd'|| facultyC== 'D')
    {
        //sort by department
        for (int i =0; i<numF; i++){
            swapped =0;
            for (int j =0; j <numF-1; j++){
                if (strcmp(f[j].department, f[j+1].department) >0){
                    temp = f[j];
                    f[j] = f[j+1];
                    f[j+1] = temp;
                }
            }
            if (swapped){
                break;
            }
        }
    }
    else if(facultyC== 'r'|| facultyC== 'R')
    {
        // sort by rank
        for (int i =0; i<numF; i++){
            swapped =0;
            for (int j =0; j <numF-1; j++){
                if (strcmp(f[j].rank, f[j+1].rank) >0){
                    temp = f[j];
                    f[j] = f[j+1];
                    f[j+1] = temp;
                }
            }
            if (swapped){
                break;
            }
        }
    }
    else
    {
        printf("\nInvalid sorting option");
    }

    //User can output the student information sorted

    char studentC;

    printf("\n\nEnter\n");
    printf("\t N or n to sort the students by name\n");
    printf("\t G or g to sort the students by gpa\n");

    printf("\nMake your sort selection: ");
    scanf("%s",&studentC);

    student tempS;

    if(studentC== 'n'|| studentC== 'N')
    {
        //sort by student name
        for (int i =0; i<numS; i++){
            swapped =0;
            for (int j =0; j <numS-1; j++){
                if (strcmp(s[j].name, s[j+1].name) >0){
                    tempS = s[j];
                    s[j] = s[j+1];
                    s[j+1] = tempS;
                }
            }
            if (swapped){
                break;
            }
        }
    }
    else if(studentC== 'g'|| studentC== 'G')
    {
        //sort by gpa
        for (int i =0; i<numS; i++){
            swapped =0;
            for (int j =0; j <numS-1; j++){
                if (s[j].gpa > s[j+1].gpa){
                    tempS = s[j];
                    s[j] = s[j+1];
                    s[j+1] = tempS;
                }
            }
            if (swapped){
                break;
            }
        }
    }
    else
    {
        printf("\nInvalid sorting option");
    }



    // Print out List of Faculty and Students
    printf("\nHere is your report....\n");

    //Print Faculty
    printf("\n\t---- L I S T  O F  F A C U L T Y ----\n");

    for (int i = 0; i < numF; i++) {
        printf("\n\t\t%s - %s\n",f[i].name,f[i].department);
    }
    //Print Student
    printf("\n\t---- L I S T  O F  S T U D E N T S ----\n");

    for (int j = 0; j < numS; j++) {
        printf("\n\t\t%s (GPA = %.2f)\n",s[j].name, s[j].gpa);
    }

    return;



}


void makeCapital(char *givenStr)
{
    int i;
    for (i = 0; givenStr[i] != '\0'; i++)
    {
        if (givenStr[i] >= 'a' && givenStr[i] <= 'z')
        {
            givenStr[i] = givenStr[i] - 32;
        }
        if (givenStr[i] == '\n'){
            givenStr[i] = '\0';
        }
    }
}


void freefunc(faculty f[], student s[], int numF, int numS) {
    for (int i = 0; i < numF; i++) {
        free(f[i].name);
        free(f[i].id);
        free(f[i].department);
        free(f[i].rank);
    }

    for (int j = 0; j < numS; j++) {
        free(s[j].name);
        free(s[j].id);
    }
    return;
}



//_____________MAIN FUNCTION
 int main(){

    char answer;
    int invalid =0;

    faculty facultylst[30];
    int numfaculty = 0;

    student studentlst[100];
    int numstudent =0;

    printf("\t\t\tWelcome to PerPro\n\n");


    while(1){

        char givenID[10];
        int notFound =1;

        if (invalid ==0){


            printf("Choose one of the options: \n\n");
            printf("1- Add a new faculty member\n");
            printf("2- Add a new Student \n");
            printf("3- Print tuition invoice for a student\n");
            printf("4- Print information of a faculty\n");
            printf("5 - Exit Program\n");
        }
        printf("\n\n\tEnter your selection: ");
        char select;
        scanf("%s", &select);

        switch(select)
        {
            case '1':
                addFaculty(facultylst, numfaculty);
                numfaculty++;
                invalid =0;
                break;
            case '2':
                addStudent(studentlst, numstudent);
                numstudent++;
                invalid =0;
                break;
            case '3':
                printf("\n\tEnter the student\'s id: ");
                scanf("%s", givenID);
                makeCapital(givenID);
                invalid =0;

                //printf("%s", givenID);
                for (int i =0; i<numstudent; i++){

                    if (strcmp(givenID, studentlst[i].id)==0){
                        //printf("%s", studentlst[numstudent-1].name);
                        //printf("%s",studentlst[i].name);
                        notFound =0;
                        printTuition(studentlst[i].name, studentlst[i].id, studentlst[i].gpa, studentlst[i].credit);
                    }
                }
                // If the given ID is not in the student list
                if (notFound){
                    printf("\n\tSorry-student not found!\n\n");
                }

                break;
            case '4':
                printf("\n \tEnter the faculty\'s id: ");
                scanf("%s", givenID);

                char * temp1 = malloc(30 * sizeof(char));
                strcpy(temp1, givenID);

                makeCapital(givenID);
                invalid =0;


                for (int i = 0; i < numfaculty; i++) {
                    if (strcmp(givenID, facultylst[i].id) == 0) {
                        notFound =0;
                        printFaculty(facultylst[i].name, facultylst[i].department, facultylst[i].rank);

                    }
                }
                // If the given ID is not in the faculty list
                if (notFound){
                    printf("\n\tSorry %s doesn\'t exist\n\n", temp1);
                }

                break;
            case '5':
                printf("\nWould you like to print a final report (Y/N): ");
                scanf("%s",&answer);


                if(answer == 'N'|| answer == 'n')
                {
                    printf("\n");
                }else{
                    exitProgram(facultylst, studentlst, numfaculty, numstudent);
                }
                done =1;
                invalid =0;
                break;
            default:
                invalid++;
                if (invalid ==3){
                        printf("\n\tYou have tried too many times...\n");
                        done =1;
                }
                else{
                        printf("\n\tInvalid entry- please try again.");
                }

                break;


        }
        if (done){
            freefunc(facultylst, studentlst, numfaculty, numstudent);
            break;
        }


    }
    printf("\n\tThank you for using PerPro. Goodbye!\n");

 }
