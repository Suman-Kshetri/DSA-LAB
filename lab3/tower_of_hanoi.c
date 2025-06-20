#include<stdio.h>
#include<time.h>

int tower_of_hanoi(int n, char src, char dst, char temp){
    if(n == 1){
        printf("Move disk %d from %c to %c.\n ",n, src, dst);
    }
    else {
        tower_of_hanoi(n-1, src, temp, dst);
        printf("Move disk %d from %c to %c. \n", n, src, dst);
        tower_of_hanoi(n-1, temp, dst, src);
    }
}

int main() 
{
    time_t start, end, diff;
    int num;
    printf("Enter the value: ");
    scanf("%d", &num);
    start = time(NULL);
    tower_of_hanoi(num, 'A', 'C', 'D');
    end = time(NULL);
    diff = difftime(end, start);
    printf("The time taken is %ld seconds.",diff);
    return 0 ;
}