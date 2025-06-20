#include<stdio.h>

int GCD (int num1, int num2){
    int result;
    if(num2 == num1){
        return num1;
    }
    else {
        while(num2 != 0){
            result = num1 %num2;
            num1 = num2;
            num2 = result;
        }
        return num1;
    }
}

int main(){
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    int result  = GCD (num1, num2);
    printf("The GCD of %d and %d is: %d \n", num1, num2, result );
    return 0;
}