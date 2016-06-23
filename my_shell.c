#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	printf("haha@hehe my_shell]$ ");
	fflush(stdout);
	char * buf[1024];
	memset(buf,'\0',sizeof(buf));
	ssize sz = read(0,buf,sizeof(buf));
	if(sz > 0)
		buf[sz-1] = '\0';

	pid_t id = fork();
	if(id == 0)   //child
	{
		
	}
	else if(id > 0)   //father
	{
		pid_t ret = waitpid(id,NULL,NULL);
		if(ret > 0)
			printf("father wait success\n");
		else if(ret < 0)
			printf("father wait failed\n");
	}
	return 0;
}
