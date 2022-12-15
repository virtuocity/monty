#include "monty.h"


/**
 * _srch - search if a char is inside a string
 * @s: string to check
 * @c: char to find
 * Return: 1 if success 0 if not
 */

int _srch(char *s, char c)
{
	int count = 0;

	while (s[count] != '\0')
	{
		if (s[count] == c)
			break;
		count++;
	}
	if (s[count] == c)
		return (1);
	else
		return (0);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strtok - function that parse a string into tokens depending of the delimit
 * @s: string to parse in parts
 * @delim: delimiters
 * Return: first partition
 */

char *_strtok(char *s, char *delim)
{
	static char *string;
	int i = 0, j = 0;

	if (!s)
		s = string;
	while (s[i] != '\0')
	{
		if (_srch(delim, s[i]) == 0 && s[i + 1] == '\0')
		{
			string = s + i + 1;
			*string = '\0';
			s = s + j;
			return (s);
		}
		else if (_srch(delim, s[i]) == 0 && _srch(delim, s[i + 1]) == 0)
			i++;
		else if (_srch(delim, s[i]) == 0 && _srch(delim, s[i + 1]) == 1)
		{
			string = s + i + 1;
			*string = '\0';
			string++;
			s = s + j;
			return (s);
		}
		else if (_srch(delim, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

