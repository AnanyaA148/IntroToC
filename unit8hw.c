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
void printEmployee ( struct employee e);
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
    int sum;
    int num;
    for(int i =0; name[i] != '\0'; i++){
        num = name[i] = '0';
        sum = sum + num;
    }

    return sum;
}
//1.
void printEmployee ( struct employee e){

    float netSalary = e.salary*0.91 + (e.numberOfDependents *0.01*e.salary);
    printf("[%d,%s,%f]\n", e.id, e.name, netSalary);

}
//2.
void printAllEmployees ( struct employee * list){

    while(list != NULL){
        printEmployee(*list);
        list = list->next;
    }
}
//3.
struct employee * addEmployee ( struct employee * list , struct employee e){
    
    struct employee *temp2 = (struct employee *)malloc(sizeof(struct employee)); 

    temp2->id = e.id; 
    temp2->salary = e.salary; 
    temp2->numberOfDependents = e.numberOfDependents; 
    temp2->below = e.below; 
    strcpy(temp2->name, e.name); 
    temp2->next = NULL; 
    
    if (list == NULL) { 
        return temp2; 
    } 
    
    struct employee *temp = list; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = temp2; 
    return list;
    
}

//4.
int searchEmployee ( struct employee * list , char * name){
    while(list != NULL){
        if (strcmp(list->name, name) ==0){
            return 1;
        }
        list = list->next;
    }
    return 0;

}
//5.
float highestNetSalary ( struct employee * list){
    float high = 0;
    while(list != NULL){
        float netSalary = list->salary*0.91 + (list->numberOfDependents *0.01*list->salary);
        if (netSalary> high){
            high = netSalary;
        }
        list = list->next;
    }

    return high;
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
        scanf ("%f-%d", &tempEmployee.salary, &tempEmployee.numberOfDependents);

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
