#include <stdio.h>
#include <stdbool.h>
//unit3.hw

void main(){
    int * myArray;

    myArray = malloc(10 * sizeof(int));
    myArray[0] = 1;
    myArray[1] = 56;
    myArray[2] = 4;
    myArray[3] = 0;
    myArray[4] = -1;
    myArray[5] = 5;
    myArray[6] = 4;
    myArray[7] = 1;
    myArray[8] = 9;
    myArray[9] = 78;

    int * sum;
    sum = malloc(sizeof(int));
    sum[0]=0;

    int * large;
    large = malloc(sizeof(int));
    large[0] = *myArray;

    int * dup;
    dup  = malloc(sizeof(int));
    dup[0] = 0;

    int * count;
    count = malloc(sizeof(int));

    for(*count=0; *count<10; *count = *count +1){

        *sum = *sum +  *(myArray+ *count);
        if( *(myArray+ *count) > *large){
            *large =*(myArray+ *count);
        }

        int * j;
        j =  malloc(sizeof(int));

        for(*j=*count+1; *j<10; *j= *j+1){
            if (*dup == 0){
                if (*(myArray+ *count) == *(myArray+ *j)){
                    *dup = 1;
                }
            }
        }

    }


    float * average;
    average = malloc(sizeof(int));
    average[0] = (*sum)/10.0;

    printf("1) Largest value = %d\n", *large);
    printf("2) Average value as a float = %.2f\n", *average);

    if (*dup){
        printf("The array has duplicates.");
    }else{
        printf("There array has no duplicates.");
    }





}
