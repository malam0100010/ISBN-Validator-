#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char isbn[30];
    int isIsbnValid10; 
    int isIsbnValid13;
    int digitCntr = 0;
    bool possible10;
    bool possible13;
    int isbnSum = 0;
    


    //prompt user for valid ISBN which should be read as a c-string
    printf("Please enter an ISBN:\n");
    scanf("%s", isbn);

    //loop through array, stopping when a null '\0' is reached
    int i = 0;
    while(isbn[i] != '\0'){
        
        if(isdigit(isbn[i])){
            ++digitCntr;
        }
        ++i;
    }
    //determine if there are 10 or 13 digits; if not, no valid entry
    if(digitCntr == 10 || digitCntr == 9){
        possible10 = true;
    }else if(digitCntr == 13){
        possible13 = true;
    }else{
        possible10 = false;
        possible13 = false;
    }
    
    //calcuate sum of digits and take respective modulus (11 for ISBN-10 and 10 for ISBN-13)
    int tenCoefficent = 10;
    if(possible10 == true){
        for(int i = 0; i < strlen(isbn); ++i){
            if(isdigit(isbn[i])){
                int convertToInt = isbn[i] - '0';
                isbnSum = isbnSum + tenCoefficent * convertToInt;
                --tenCoefficent;
            }else if(i == strlen(isbn) - 1){
                printf("Value read\n");
                if(isbn[i] == 'X' || isbn[i] == 'x'){
                    isbnSum = isbnSum + 10;
                }else{
                    possible10 = false;
                }
            }
            
        }
        isIsbnValid10 = isbnSum % 11;
    }else if(possible13 == true){
        int oddCntr = 0;
        for(int i = 0; i < strlen(isbn); ++i){
            int convertToInt = isbn[i] - '0';
            if(isdigit(isbn[i]) && oddCntr%2 == 0){
                isbnSum = isbnSum + convertToInt;
                ++oddCntr;
            }else if(isdigit(isbn[i]) && oddCntr%2 == 1){
                isbnSum = isbnSum + convertToInt * 3;
                ++oddCntr;
            }
        }
        
        isIsbnValid13 = isbnSum % 10;
    }

    //print result
    if(possible10 == true && isIsbnValid10 == 0){
        printf("Valid ISBN-10\n");
        printf("Invalid ISBN-13\n");
    }else if(possible13 == true && isIsbnValid13 == 0){
        printf("Invalid ISBN-10\n");
        printf("Valid ISBN-13\n");
    }
    else{
        printf("Invalid ISBN-10\n");
        printf("Invalid ISBN-13\n");
    }
    
    return 0;
}