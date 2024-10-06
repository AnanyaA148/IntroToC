#include <stdio.h>
#include <stdbool.h>
//unit3.hw

int main(){
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
    myArray[9] = 7;

    int * sum;
    sum = malloc(sizeof(int))
    sum[0]=0;

    int * large;
    large = malloc(sizeof(int))
    large[0] = *score

    bool dup = false;

    for(int i=0; i<10; i++){
        int num = myArray[i];
        sum = sum + num;
        if(num > large){
            large =num;
        }
        for(int j=i+1; j<10; j++){
            if (dup == false){
                if (num == myArray[j]){
                    dup = true;
                }
            }
        }

    }


    float * average;
    average[0] = (*sum)/10.0;

    printf("1) Largest value = %d\n", large);
    printf("2) Average value as a float = %.2f\n", average);

    if (dup){
        printf("The array has duplicates.");
    }else{
        printf("There array has no duplicates.");
    }



    return 0;

}
