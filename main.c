#include "monty.h"

/**
 * main - entry point
 * @argv: list of args
 * @argc: ammount of args
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t _len = 0;
	char *buffer = NULL, *s = NULL;
	stack_t *stack = NULL;
	unsigned int a = 1;

	global.data_struct = 1;
	if (argc != 2)
		err();

	file = fopen(argv[1], "r");

	if (!file)
		f_error(argv[1]);

	while (getline(&buffer, &_len, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			a++;
			continue;
		}
		s = strtok(buffer, " \t\n");
		if (!s || *s == '#')
		{
			a++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, s, a);
		a++;
	}

	free(buffer);
	stackless(stack);
	fclose(file);
	exit(status);
}

int status = 0;
