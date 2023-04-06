#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	int CoP;

	CoP = fork();
	if(CoP != 0)
	{
		wait(NULL);
		printf("Adult Time: %d\n", CoP);
		CoP = fork();
	}
	else
	{
		printf("I'm a child: %d\n", getpid());
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

	return (0);
}
