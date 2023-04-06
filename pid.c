#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("parent pid = %u\n", my_pid);

	//printf("%d\n", getppid());
	
	int peepeepoopoo = fork();
	if (peepeepoopoo == 0)
	{
		printf("child peepeepoopoo is %d\n", peepeepoopoo);
		printf("Child PID is %d\n", getpid());
		printf("ppid = %d\n", getppid());
	}
	else
	{
		printf("parent peepeepoopoo is %d\n", peepeepoopoo);
	}
	
	return (0);
}
