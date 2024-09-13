#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    printf("%d", num);
    int count =0;
    int prime[] = {};  // prime number array
    printf("hi");

    for( int i =1; i< num; i++){
        printf("hello");
        if (num%i != 0){
            printf("%d", i);
            prime[count] = i;
            count++;
        }
    }
    printf("bye");
    for( int j=0; j< count; j++){
        printf("%d", prime[j]);
    }
    printf("bye");
}
