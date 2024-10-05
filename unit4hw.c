#include <stdio.h>
#include <stdbool.h>
//unit3.hw

int main(){
    int myArray[10] ={1,56,4,0,-1,5,4,1,9,78};
    int sum =0;
    int large =myArray[0];
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
    float average = sum/10.0;

    printf("1) Largest value = %d\n", large);
    printf("2) Average value as a float = %.2f\n", average);

    if (dup){
        printf("The array has duplicates.");
    }else{
        printf("There array has no duplicates.");
    }



    return 0;

}
