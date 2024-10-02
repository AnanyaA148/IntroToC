#include <stdio.h>

int main(){
    int x =23;
    float y =2.5;


    printf("%d", x);
    printf("%d", &x);

    int * ptr; //an int pointer  because I want to store the address of an int in a pointer
    ptr = &x; // pointer. ptr points to x. If this whole line was commented out, we would get an error. It would crash.

    *ptr =70; // changes the value of x


    // %p is conversion specifier for pointers

    printf("%p", &x);
    printf("%p", ptr);

    printf("%d", x);

    scanf("%f", &y);

    int * score;
    printf("How many scores?");
    int n;
    scanf("%d", &n);

    score = malloc(n); // int contains 4 bytes



    return 0;

}
