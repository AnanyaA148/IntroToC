#include <stdio.h>
#include <stdbool.h>

void main(){
    //it works!!
    float check(float c1){
        int count =0;
        while ((c1 <=100 && c1>=0) == false){
          if (count ==2){
              return -1;
          }
          printf("Invalid Score. Try again:");
          scanf("%f", &c1);
          count++;


        }
        return c1;
    }
    void startOver(){

    }
    bool num1 =false;
    while(true){

        if (num1){
            char over;
            int count =0;
            printf("\nWould you like to start over (Y/N):");
            scanf("%s", &over);
            while((over =='Y' || over == 'N') == false){
                printf("Invalid character. Try Again:");
                scanf("%s", &over);
                count++;
                if (count ==2){
                    break;
                }
            }

            if (over == 'Y'){
                printf("*******************\n");

            } else if(over =='N'){
                printf("\n\tGood-Bye!");
                break;
            } else{
                printf("\n\tProgram Terminated!");
                break;
            }
        }

        num1=true;



        float hw = 200;
        printf("\nEnter the hw average score:");
        scanf("%f", &hw);
        hw = check(hw);
        if (hw ==-1){
            printf("I\'m sorry...You tried too many time.\n");
            continue;
        }

        float project =200;
        printf("\nEnter the project average score:");
        scanf("%f", &project);
        project = check(project);
        if (project ==-1){
            printf("I\'m sorry...You tried too many time.\n");
            continue;
        }


        float lab =200;
        printf("\nEnter the lab average score:");
        scanf("%f", &lab);
        lab = check(lab);
        if (lab ==-1){
            printf("I\'m sorry...You tried too many time.\n");
            continue;
        }

        float mid1, mid2, final1;

        printf("\nEnter midterm1, midterm2, and final:");
        scanf("%f %f %f", &mid1, &mid2, &final1);

        int count =0;

        while (( mid1<= 100 && mid1>=0) == false){
            if (count ==2){
                mid1= -1;
                break;
            }
            printf("Invalid midterm1. Try Again:");
            scanf("%f", &mid1);
            count++;

        }
        if (mid1 ==-1){
            printf("I\'m sorry...You tried too many time.\n");
            continue;
        }

        count =0;
        printf("\n");
        while (( mid2<= 100 && mid2>=0) == false){
            if (count ==2){
                mid2= -1;
                break;
            }
            printf("Invalid midterm2. Try Again:");
            scanf("%f", &mid2);
            count++;
        }
        if (mid2 ==-1){
            printf("I\'m sorry...You tried too many time.\n");
            continue;
        }

        count =0;
        printf("\n");
        while (( final1<= 100 && final1>=0) == false){
            if (count ==2){
                final1= -1;
                break;
            }
            printf("Invalid final. Try Again:");
            scanf("%f", &final1);
            count++;
        }
        if (final1 ==-1){
            printf("I\'m sorry...You tried too many time.\n");
            continue;
        }



        printf("\nHere are all your average scores:\n");
        printf("\tHW\t\t: %.2f\n", hw);
        printf("\tPROJECTS\t: %.2f\n", project);
        printf("\tLABS\t\t: %.2f\n", lab);
        printf("\tMIDTERM1\t: %.2f\n", mid1);
        printf("\tMIDTERM2\t: %.2f\n", mid2);
        printf("\tFINAL\t\t: %.2f\n", final1);
        printf("------------------------\n");
        float average = hw*(0.2) + project*(0.2)+lab*(0.05)+ (mid1+mid2+final1)*(0.55/3);
        printf("OVERALL AVERAGE: %.2f\n", average);
        printf("(%.2f *.2 + %.2f *.2 + %.2f *.05 + (%.2f + %.2f +%.2f)*.55/3 is %.2f)\n", hw, project, lab, mid1, mid2, final1, average);
        printf("------------------------\n");
        char letter[] = "";

        if(average>93){
            letter[0]= 'A';
        }else if (average >89){
            letter[0] = 'A';
            letter[1] ='-';
        }else if (average >86){
            letter[0] = 'B';
            letter[1] ='+';
        }else if (average >83){
            letter[0] = 'B';
        }else if (average >79){
            letter[0] = 'B';
            letter[1] ='-';
        }else if (average >76){
            letter[0] = 'C';
            letter[1] ='+';
        }else if (average >73){
            letter[0] = 'C';
        }else if (average >69){
            letter[0] = 'C';
            letter[1] ='-';
        }else if (average >66){
            letter[0] = 'D';
            letter[1] ='+';
        }else if (average >63){
            letter[0] = 'D';
        }else if (average >60){
            letter[0] = 'D';
            letter[1] ='-';
        }else{
            letter[0] = 'F';
        }

        printf("\tFINAL LETTER GRADE: %s\n\n", letter);



    }







}
