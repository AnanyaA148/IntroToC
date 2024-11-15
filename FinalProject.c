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
void printTuition(student s[], int numStudents); // Print tuition invoice for a
// *?? makeCapital (char[] a); // as STRING entries are stored in capital, this makes all letter inputs capital letters

//_____________FUNCTIONS
void addFaculty(faculty f[], int index){



    f[index].name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    f[index].id = malloc(20 * sizeof(char)); // Allocate enough space for the id
    f[index].department = malloc(50 * sizeof(char)); // Allocate enough space for the department
    f[index].rank = malloc(30 * sizeof(char));


    printf("\n\nEnter the faculty's info:\n\n ");

    printf("\tName of the faculty: ");
    scanf("%s", f[index].name);


    printf("\tID: ");
    scanf("%s", f[index].id);

    printf("\tRank:");
    scanf("%s", f[index].rank);

    printf("\tDepartment: ");
    scanf("%s", f[index].department);



}



void addStudent(student s[], int index){



    s[index].name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    s[index].id = malloc(20 * sizeof(char)); // Allocate enough space for the id


    printf("\n\nEnter the student's info:\n\n ");

    printf("\tName of the student: ");
    scanf("%s", s[index].name);
    printf("%s", s[index].name);

    printf("\tID: ");
    scanf("%s", s[index].id);

    printf("\tGPA:");
    scanf("%f", &s[index].gpa);
    printf("%f", s[index].gpa);

    printf("\tCredit hours: ");
    scanf("%d", &s[index].credit);


}


void printTuition(student s[], int numStudents){
    //not working for some reason

    /*
    char givenId[20];
    printf("Enter the student's ID: ");
    scanf("%s", givenId);
    for (int i = 0; i < numStudents; i++) {
            if (strcmp(s[i].id, givenId) == 0) {
                printf("Here is the tuition invoice for %s:\n", s[i].name);
                printf("%s \t\t\t\t %s\n", s[i].name, s[i].id);
                printf("Credit Hours: %d ($236.45/credit hour)\n", s[i].credit);
                printf("Fees: $52\n"); float tuition = s[i].credit * 236.45 + 52;
                // Apply 25% discount if GPA >= 3.85
                if (s[i].gpa >= 3.85) {
                        tuition *= 0.75;
                }
                printf("Total Payment: $%.2f\n", tuition);
                return;
            }
    }
    printf("Student with ID %s not found.\n", givenId);
    */
}

//_____________MAIN FUNCTION
 int main(){

    faculty facultylst[30];
    int numfaculty;

    student studentlst[100];
    int numstudent;

    while(1){
        int done =0;
        printf("Choose one of the options: \n\n");
        printf("1- Add a new faculty member\n");
        printf("2- Add a new Student \n");
        printf("3- Print tuition invoice for a student\n");
        printf("4- Print information of a faculty\n");
        printf("5 - Exit Program\n");
        printf("\n\n\tEnter your selection: ");
        int select;
        scanf("%d", &select);

        switch(select)
        {
            case 1:
                addFaculty(facultylst, numfaculty);
                numfaculty++;
                break;
            case 2:
                addStudent(studentlst, numstudent);
                //printf("%s", studentlst[numstudent].id);
                numstudent++;
                break;
            case 3:
                printf("%s", studentlst[numstudent-1].id);
                printTuition(studentlst, numstudent);
                break;
            case 4:
                break;
            case 5:
                done =1;
                break;
            default:
                done =1;


        }
        if (done){
            break;
        }


    }

 }
