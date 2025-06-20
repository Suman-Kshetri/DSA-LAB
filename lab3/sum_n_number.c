#include<stdio.h>

int sum_nth_number(int num, int a){
    if(num == 1) return a;
    else {
        return sum_nth_number(num-1, num+a);
    }
}

int main(){
    int n;
    printf("Enter the nth numnber for sum : ");
    scanf("%d", &n);
    int result  = sum_nth_number(n, 1);
    printf("The sum of %dth number is: %d \n", n, result);
    return 0;
}