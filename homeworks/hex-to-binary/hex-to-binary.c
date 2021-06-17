#include <stdio.h>  
#include <string.h>  
   
int main() {  
    char *hexDigitToBinary[16] = {"0000", "0001", "0010", "0011", "0100", "0101", 
 "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};    
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hexadecimal[30], binaryNumber[100];   
    int i = 0, j, index=0;  
   
    /* 
     * Take a hexadecimal number as input from user 
     */ 
    printf("Enter a Hexadecimal Number\n");  
    scanf("%s", hexadecimal);
   
    /* 
     * Find he hexadecimal digit in hexDigits and the substitute it
     * with corresponding value in hexDigitToBinary
     */ 
    for(i=0; hexadecimal[i] != '\0'; i++)  {  
        for(j = 0; j < 16; j++){
            if(hexadecimal[i] == hexDigits[j]){
                strcat(binaryNumber, hexDigitToBinary[j]);
            }
        }
    }  
   
    printf("Binary Number : %s", binaryNumber);  
   
    return 0;  
}