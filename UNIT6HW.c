//unit6.hw
//Group Members: Sharon Huang, Ananya Agarwal
//Directives: User enters String and gets report of the most occuring character, how many lower and uppercase and how many digits

//Prototypes
char most_occuring_character ( char *str);
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit);
char * Up_letters ( char *str);

#include <stdio.h>

//this function retuns the char that appears the most. It returns -1 if that doesn’t apply
//finished
char most_occuring_character ( char *str){
	int size = 0; //declares size var
	int occurance=-1;
	int occurance_temp=0;
	char popChar=str[0];

	//get's *str size
    while (str[size] != '\0') {
        size++;
    }

    //^

	for (int i = 0; i< size-1; i++){
        occurance_temp =0;
        for (int i2 = i+1; i2<size; i2++){
            if (str[i]== *(str+i2)){
                occurance_temp++;
            }
        }
        if (occurance_temp!=0&&occurance_temp>occurance+1){
                if (str[i] != ' '){
                    occurance=occurance_temp;
                    popChar = str[i];
                }


        }
	}

    if (occurance==-1)
        return -1;
    else
        return popChar;
}

//this function counts how many lower, upper and digit characters.
//finished
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit){

	int size = 0; //declares size var
	while (str[size] != '\0') {
        size++;
	}

	for (int i = 0; i<size; i++){

        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            upper[0]++;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            lower[0]++;
        }
        else if(str[i]>= '0' &&str[i]<='9')
        {
            //printf("%c\n", str[i]);
            digit[0]++;
        }
	}
}

//This function returns the sorted upper case letters as shown in sample runs…
char *Up_letters( char *str){


	int size = 0; //declares size var

    char* upper;
    upper = calloc(1,sizeof(char));
    //printf("%s\n", upper);





	//get's *str size
	int let =0;

    while (str[size] != '\0') {
        size++;
    }


    for (int i = 0; i<size; i++){

        if(str[i] >= 'A' && str[i] <= 'Z')
        {

            upper[let] = str[i];
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            upper[let] = str[i] - 32;
        }else{
            let--;

        }
        let++;
    }

    int swap;
    char temp;
    for (int j =0; j <let; j++){
        swap =0;
        for(int k=0; k<let-1; k++){
            if(*(upper+k) > *(upper+k+1)){
                temp = *(upper+k);
                upper[k] = *(upper+k+1);
                upper[k+1] = temp;
                swap =1;
            }
        }

        if (swap){
            break;
        }

    }

    return upper;


}


int main() {

      char str[50] ="";
      char *upper_sorted;
      char most_occur = -1;
      int lower_case=0 , upper_case=0, digits=0;


      printf("Enter your string: ");
      gets(str);


      most_occur = most_occuring_character ( str );
      if ( most_occur == -1 ) printf ("All characters appears once\n");
      else printf ("The most occuring character is: %c \n", most_occur);

      count_low_up_digit ( str, &lower_case, &upper_case , &digits );
      printf ("There is/are %d lower case letter(s)\n", lower_case);
      printf ("There is/are %d upper case letter(s)\n", upper_case);
      printf ("There is/are %d digit(s)\n", digits);

      upper_sorted = Up_letters (str);
      printf ("%s\n", upper_sorted);
      printf ("%s\n", str);




      return 0;
}
