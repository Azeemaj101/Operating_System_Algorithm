#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
pid_t p1,p2;
int w1,w1status;
printf("before fork\n");
p1=fork();
p2=fork();
if(p1==0)
{
printf("I am child having id %d\n",getpid());
printf("My parent id is %d\n",getppid());
}
else if(p2==0){
printf("I am child having id %d\n",getpid());
printf("My parent id is %d\n",getppid());
}
else{
w1=wait(&w1status);
printf("Status is %d\n",WIFEXITED(w1status));
printf("PID of child  is %d\n",w1);
printf("I am parent having id %d\n",getpid());
printf("My parent id is %d\n",getppid());
}
}
