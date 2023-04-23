#include "main.h"
#include <stdio.h>
/**
 * putswt: function writes the string at s, followed by a newline
 * @s: pointer
 * Return: 0
 */
int putswt(const char *s)
{
	while (*s)
	{
		if (putcharwt(*s++) == EOF)
			return (EOF);
	}
	if (putcharwt('\n') == EOF)
		return (EOF);
	return (0);
}
