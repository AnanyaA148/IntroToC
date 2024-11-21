/* NAME OF STUDENTS

    Ananya Agarwal
    Sharon Huang
    Caleb
    Adrian
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
void freefunc(faculty f[], student s[], int numFaculty, int numStudent); // Frees all of the information in studentlst and facultylst at the end of the whole process

//_____________FUNCTIONS
void addFaculty(faculty f[], int index){



    f[index].name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    f[index].id = malloc(20 * sizeof(char)); // Allocate enough space for the id
    f[index].department = malloc(50 * sizeof(char)); // Allocate enough space for the department
    f[index].rank = malloc(30 * sizeof(char));


    printf("\n\nEnter the faculty's info:\n\n ");

    printf("\tName of the faculty: ");
    char dead[5];
    gets(dead);
    fgets(f[index].name, 50, stdin);
    //scanf("%s", f[index].name);
    makeCapital(f[index].name);

    //printf("%s", f[index].name);


    printf("\tID: ");
    scanf("%s", f[index].id);
    makeCapital(f[index].id);



    int i =0;
    while(i<3){

            printf("\tRank: ");
            scanf("%s", f[index].rank);
            makeCapital(f[index].rank);
            if (strcmp(f[index].rank, "PROFESSOR") ==0|| strcmp(f[index].rank, "ADJUNCT") ==0) {
                break;
            }else{
                if (i ==2){
                    printf("\n\n\tYou have tried too many times...\n");
                    done =1;
                    return;

                }
                printf("\n\t\tSorry entered rank (%s) is invalid. Try again.\n\n", f[index].rank );
                i++;


            }
    }

    i =0;
    while(i<3){

            printf("\tDepartment: ");
            scanf("%s", f[index].department);
            makeCapital(f[index].department);
            if (strcmp(f[index].department, "MATH") ==0|| strcmp(f[index].department, "CS") ==0 || strcmp(f[index].department, "SCIENCE") ==0) {
                break;
            }else{
                if (i ==2){
                    printf("\n\n\tYou have tried too many times...\n");
                    done =1;
                    return;

                }
                printf("\n\t\tSorry entered rank (%s) is invalid. Try again.\n\n", f[index].department );
                i++;


            }
    }



    printf("\nThanks!\n\n");

}



void addStudent(student s[], int index){



    s[index].name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    s[index].id = malloc(20 * sizeof(char)); // Allocate enough space for the id


    printf("\n\nEnter the student's info:\n\n ");

    printf("\tName of the student: ");
    char dead[5];
    gets(dead);
    fgets(s[index].name, 50, stdin);
    makeCapital(s[index].name);
    //printf("%s", s[index].name);


    printf("\tID: ");
    scanf("%s", s[index].id);
    makeCapital(s[index].id);

    printf("\tGPA:");
    scanf("%f", &s[index].gpa);
    //printf("%f", s[index].gpa);

    printf("\tCredit hours: ");
    scanf("%d", &s[index].credit);

    printf("\nThanks!\n\n");


}


void printTuition(char * name, char * id, float  gpa, int  credit){
    //printf("%d", credit);
    float totalFee= credit * 236.45;
    float discount= 0;
    if (gpa>=3.85){
        discount = totalFee * .25;
        totalFee= totalFee -discount;
    }


    printf("Here is the tuition invoice for %s: \n\n", name);
    printf("---------------------------------------------------------------------------");
    printf("\n\t %s \t\t %s", name ,id);
    printf("\n\t Credit Hours: %d ($236.45/credit hour)", credit);
    printf("\n\t Fees: $52");
    printf("\n\t Total payment: $%.2f \t\t\t($%.f discount applied)", totalFee, discount);
    printf("\n---------------------------------------------------------------------------\n");

}



void printFaculty(char * name, char * department, char * rank){


    printf("Faculty found:\n");
    printf("--------------------------------------------\n");
    printf("\t %s\n", name);
    printf("\t %s department, ", department);
    printf("%s\n", rank);
    printf("---------------------------------------------\n");
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

    int invalid =0;

    faculty facultylst[30];
    int numfaculty = 0;

    student studentlst[100];
    int numstudent =0;

    printf("\t\t\tWelcome to PerPro\n\n");

    while(1){

        char givenID[50];
        int notFound =1;

        printf("Choose one of the options: \n\n");
        printf("1- Add a new faculty member\n");
        printf("2- Add a new Student \n");
        printf("3- Print tuition invoice for a student\n");
        printf("4- Print information of a faculty\n");
        printf("5 - Exit Program\n");
        printf("\n\n\tEnter your selection: ");
        char select;
        scanf("%s", &select);

        switch(select)
        {
            case '1':
                addFaculty(facultylst, numfaculty);
                numfaculty++;
                break;
            case '2':
                addStudent(studentlst, numstudent);
                //printf("%s", studentlst[numstudent].name);
                numstudent++;
                break;
            case '3':
                printf("\n\tEnter the student\'s id: ");
                scanf("%s", givenID);


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
                    printf("\n\tSorry %s doesn\'t exist\n\n", givenID);
                }

                break;
            case '4':
                printf("\n \tEnter the faculty\'s id: ");
                scanf("%s", &givenID);


                for (int i = 0; i < numfaculty; i++) {
                    if (strcmp(givenID, facultylst[i].id) == 0) {
                        notFound =0;
                        printFaculty(facultylst[i].name, facultylst[i].department, facultylst[i].rank);

                    }
                }
                // If the given ID is not in the faculty list
                if (notFound){
                    printf("\n\tSorry %s doesn\'t exist\n\n", givenID);
                }

                break;
            case '5':


                done =1;
                break;
            default:
                invalid++;
                if (invalid ==3){
                        printf("You have tried too many times...");
                        done =1;
                }
                else{
                        printf("Invalid entry- please try again.");
                }

                break;


        }
        if (done){
            freefunc(facultylst, studentlst, numfaculty, numstudent);
            break;
        }


    }
    printf("\n\tThank you for using PerPro. Goodbye!");

 }
