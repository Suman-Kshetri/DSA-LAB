#include<stdio.h>

int table[100] = {0};
long int fibonaciiMem(int num){
    if(num == 1 || num == 2)
        return 1;
    else{
        if(table[num] == 0){
            table[num] = fibonaciiMem(num-1) + fibonaciiMem(num - 2);
        }
        return table[num];
    }
}

int main() {
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    long int result = fibonaciiMem(num);
    printf("The %d th term in fibonacii is: %ld \n", num, result );
}