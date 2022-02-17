#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int fds[2],n;
char buffer[100];
pid_t p;
pipe(fds);
p=fork();
if(p>0)
{
wait(NULL);
printf("parent reading child\n");
n=read(fds[0],buffer,10);
write(1,buffer,n);
}
else{
printf("child writing student id\n");
write(fds[1],"12\n",10);
}
}
