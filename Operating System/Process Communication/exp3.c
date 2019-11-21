#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    int pid=fork();
    if(pid>0)
    {
        close(fd1[0]);
        close(fd2[1]);
        char str[50];
        printf("Father process:Please input a small string to send\n");
        char s[50];
        scanf("%s",&s);
        write(fd1[1],s,50);
        
        read(fd2[0],str,50);
        printf("Father GET:%s\n",str);
        int status;
        int i=wait(&status);
        printf("pid:%d\t%d\n",i,WIFEXITED(status));
        exit(0);
    }
    else if(pid==0)
    {
       close(fd1[1]);
       close(fd2[0]);
       char str[50];
       read(fd1[0],str,50);
       //process BIG-SMALL casefold
       int m = strlen(str);
       for(int i = 0; i < m; i++)
       {
           if(str[i]>='A'&&str[i]<='Z')
              str[i] = str[i]+32;
           else if(str[i]>='a'&&str[i]<='z')
              str[i] = str[i]-32;
       }
       //printf
       printf("Child GET:%s\n",str);
       printf("Child Process:Please input a small string to send\n");
       char si[50];
       scanf("%s",&si);
       write(fd2[1],si,50);
    }
    return 0;
}
