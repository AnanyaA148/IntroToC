#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct employee {
int id;
char name[50];
float salary;
int numberOfDependents;
//---------------------
struct employee * next;
struct employee * below;
};
//----------------------- FUNCTION PROTOTYPES ---------------------------
//0.
int getId ( char * name);
/*
returns the sum of the ascii codes of the letters of name.
*/
//1.
void printEmployee ( struct employee );
/*
prints an employee in the format [id,name,net salary], where:
Net salary = salary*0.91 + (numberOfDependent *0.01*salary)
Examples: [562,AaBc xYz,1253.56] [562,bAac ZyX,6253.06]
*/
//2.
void printAllEmployees ( struct employee * list);
/*
prints all employees in the list. Loops through list and calls
printEmployee for each employee in list
*/
//3.
struct employee * addEmployee ( struct employee * list , struct employee e);
/*
adds e to list.
*/
//4.
int searchEmployee ( struct employee * list , char * name);
/*
returns 1 if name is found in list. Otherwise, it returns 0
*/
//5.
float highestNetSalary ( struct employee * list);
/*
returns the highest net salary.
*/
//----------------------- FUNCTION DEFINITIONS ---------------------------
//0.
int getId ( char * name ){
    printf ("COMING UP\n");
    return 0;
}
//1.
void printEmployee ( struct employee ){
    printf ("COMING UP\n");
}
//2.
void printAllEmployees ( struct employee * list){
    printf ("COMING UP\n");
}
//3.
struct employee * addEmployee ( struct employee * list , struct employee e){
    printf ("COMING UP\n");
    return list;
}

//4.
int searchEmployee ( struct employee * list , char * name){
    printf ("COMING UP\n");
    return 0;
}
//5.
float highestNetSalary ( struct employee * list){
    printf ("COMING UP\n");
    return 0.0;
}
//DO NOT CHANGE ANYTHING IN main
int main() {
    struct employee * company = NULL , tempEmployee;
    int tempInt = 0;
    char tempName [50] = "Allal Kamch" ;

    char dummy;
    printf ("Enter 1 to add a new employee, 0 to stop: ");
    scanf ("%d", &tempInt);

    while ( tempInt == 1 ){
        printf("Enter Full Name: ");
        scanf("%c",&dummy);

        fgets(tempEmployee.name, 50, stdin);
        tempEmployee.id = getId ( tempEmployee.name );

        printf ("Enter salary-numberOfDependents: ");
        scanf ("%f-%d", &tempEmployee.salary,
        &tempEmployee.numberOfDependents);
        company = addEmployee ( company , tempEmployee );
        printf ("Enter 1 to add a new employee, 0 to stop: ");
        scanf ("%d", &tempInt);
    }
    printAllEmployees ( company ) ;
    printf ("Highest Net Salary = %.2f\n", highestNetSalary(company) );
    tempInt = searchEmployee ( company , tempName) ;
    if ( tempInt == 1 ) printf ("%s is found!\n", tempName);
    else printf ("%s is NOT found!\n", tempName);
    return 0;
}
