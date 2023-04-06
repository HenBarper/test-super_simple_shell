#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main()
{
	char *command = NULL;
	size_t size = 0;

	while (1)
	{
		printf("$ ");
		getline(&command, &size, stdin);
		printf("%s", command);
	}

	free(command);

	return (0);
}*/

char** split_string(char* str, int* count) 
{
	char* token;
	char** words = NULL;
	int i = 0;

	token = strtok(str, " ");
	while (token != NULL) 
	{
		words = realloc(words, (i + 1) * sizeof(char*));
		words[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	*count = i;
	return words;
}

int main()
{
	char str[] = "This is a test string";
	int count;
	char** words = split_string(str, &count);

	for (int i = 0; i < count; i++) 
	{
		printf("%s\n", words[i]);
	}

	free(words);
	return 0;
}
