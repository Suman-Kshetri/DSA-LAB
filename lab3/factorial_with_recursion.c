#include<stdio.h>
#include<time.h>

long long int tailfactorial(int n,long long int a){
    if(n == 1){
        return a;
    }
    else {
        return tailfactorial(n-1, a*n);
    }
}


int main() {
    int num;
    time_t start,end, diff;
    printf("Enter the number for factorial : ");
    scanf("%d", &num);
    start = time(NULL);
    long long int result = tailfactorial(num , 1);
    end = time(NULL);
    printf("The factorial of %d is: %lld \n", num  ,result);
    diff = difftime(end, start);
    printf("The time taken is %ld seconds : ", diff);
    return 0;
}