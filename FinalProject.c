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

    printf("\n\nEnter the faculty's info:\n\n ");
    printf("\tName of the faculty: ");
    scanf("%s", &(*f).name);
    printf("\tID: ");
    scanf("%s", &(*f).id);
    printf("\tRank:");
    scanf("%s", &(*f).rank);
    printf("\tDepartment: ");
    scanf("%s", &(*f).department);


}

void addStudent(student * s); // Add a new student

void addStudent(student * s){

    printf("\n\nEnter the student's info:\n\n ");
    printf("\tName of the student: ");
    scanf("%s", &(*s).name);
    printf("\tID: ");
    scanf("%s", &(*s).id);
    printf("\tGPA:");
    scanf("%s", &(*s).gpa);
    printf("\tCredit hours: ");
    scanf("%s", &(*s).credit);


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
                numstudent++;
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                done =1;
                break;



        }
        if (done){
            break;
        }


    }
 }
