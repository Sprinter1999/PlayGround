#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Please input n=");
    scanf("%d",&n);
    pid_t pid;
    pid=fork();
    if(pid==0)//child process
    {
        while(n!=1)
        {
            printf("%d\n",n);
            if(n&1==1)
                n=3*n+1;
            else
                n=n/2;    
        }
        printf("1\n");
    }
    else if (pid<0) 
    { // error occurred
        printf("Fork failed\n");
    }
    printf("Main process ends in here\n");
}