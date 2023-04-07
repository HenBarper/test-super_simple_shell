#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char** split_string(char *str, int *count);

/**
 * main - entry point
 *
 * Return: int
 */
int main(void)
{
	char *command = NULL;
	size_t size = 0;
	char **words = NULL;
	int count;
	int CoP = 666;
	int i = 0;

	while (1)
	{
		printf("Entered while loop: %d\n", CoP);
		printf("$ ");
		getline(&command, &size, stdin);
		printf("Command received: %s", command);
		words = split_string(command, &count);

		for (; i < count ; i++)
		{
			printf("token %d: %s\n", i, words[i]);
		}

		CoP = fork();
		printf("Forked by %d\n", CoP);

		if (CoP == 0)
		{
			printf("Child executing.\n");
			if (execve(words[0], words, NULL) == -1)
			{
				perror("Error");
				return (-1);
			}
			return (0);
		}
		else
		{
			printf("Parent waiting.\n");
			wait(NULL);
			printf("Parent awakend.\n");
		}
		printf("Just before end of while loop: %d\n", CoP);
	}

	printf("End of prog: %d\n", CoP);

	return (0);
}

/**
 * split_string - splits the string into arr of strings
 * @str: string
 * @count: count of strings
 * Return: char ptr
 */
char** split_string(char *str, int *count)
{
	char *token;
	char **words = NULL;
	int i = 0;

	token = strtok(str, " \n");
	while (token != NULL)
	{
		words = realloc(words, (i + 1) *sizeof(char*));
		words[i] = token;
		printf("%s", words[i]);
		i++;
		token = strtok(NULL, " \n");
	}
	*count = i;
	return (words);
}
