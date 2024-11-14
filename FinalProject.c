#include <stdio.h>
typedef struct{ // faculty info
    char * name;
    char * id;
    char * department;
    char * rank;


} faculty;


typedef struct{ // student info
    char * name;
    char * id;
    float gpa;
    int credit;

} student;


void addFaculty(faculty * f); // Add a new faculty memeber

void addFaculty(faculty * f){



    f->name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    f->id = malloc(20 * sizeof(char)); // Allocate enough space for the id
    f->department = malloc(50 * sizeof(char)); // Allocate enough space for the department
    f->rank = malloc(30 * sizeof(char));

    printf("\n\nEnter the faculty's info:\n\n ");

    printf("\tName of the faculty: ");
    scanf("%s", (*f).name);

    printf("\tID: ");
    scanf("%s", (*f).id);

    printf("\tRank:");
    scanf("%s", (*f).rank);

    printf("\tDepartment: ");
    scanf("%s", (*f).department);



}

void addStudent(student * s); // Add a new student

void addStudent(student * s){



    s->name = malloc(50 * sizeof(char)); // Allocate enough space for the name
    s->id = malloc(20 * sizeof(char)); // Allocate enough space for the id


    printf("\n\nEnter the student's info:\n\n ");

    printf("\tName of the student: ");
    scanf("%s", (*s).name);
    printf("%s", s->name);

    printf("\tID: ");
    scanf("%s", (*s).id);

    printf("\tGPA:");
    scanf("%f", &(*s).gpa);
    printf("%f", (*s).gpa);

    printf("\tCredit hours: ");
    scanf("%d", &(*s).credit);


}

void printTuition(student *s); // Print tuition invoice for a student

void printTuition(student *s){
    char * givenId;
    printf("Enter the student's id: ");
    scanf("%s", givenId);
    printf("hi");


    for(student * p = s; p<s+5; p++){
        printf("hi");

        if (strcmp((*p).id, givenId)){
            printf("bye");
            printf("Here is the tuition invoice for %s", (*p).name);
            printf("%s \t\t\t\t %s", (*p).name, (*p).id);
            printf("Credit Hours: %d ($236.45/credit hour)", (*p).credit);
            printf("Fees: $52");
            printf("Total Payment:");

            break;
        }
    }
}

 int main(){

    faculty * facultylst;
    facultylst = malloc(sizeof(faculty));
    int numfaculty =0;

    student * studentlst;
    studentlst = malloc(sizeof(student));
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
                addFaculty(facultylst + numfaculty);
                numfaculty++;

                break;
            case 2:
                addStudent(studentlst + numstudent);

                printf("%f", (studentlst + numstudent)->gpa); // not working for some reason. The memory is not getting stored in this variable. Everything is empty.
                numstudent++;
                break;
            case 3:
                printTuition(studentlst);
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
