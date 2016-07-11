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
	ssize_t sz = read(0,buf,sizeof(buf));
	if(sz > 0)
		buf[sz-1] = '\0';

	char *my_argv[64];
	char *p = buf;
	int index = 0;
	my_argv[0] = p;
	while(*p != '\0')
	{
		if(*p == ' ')
		{
			*p = '\0';
			p++;
			my_argv[index++] = p;
			continue;
		}
		p++;
	}
	my_argv[index] = NULL;
	
	pid_t id = fork();
	if(id == 0)   //child
	{
			execvp(my_argv[0],my_argv);
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
