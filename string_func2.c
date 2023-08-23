/**
 * _strcpy - Copies a string to another
 * @dest: Destination
 * @src:Source
 * Return: A pointer to the copied string
 */
char *_strcpy(char *d, char *s)
{
	int i = 0;

	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/**
 * _strcat - Concatenates Two Strings
 * @dest: First String
 * @src: Second String
 * Return: The new string
 */
char *_strcat(char *d, char *source)
{
	char *s = d;

	while (*d != '\0')
	{
		d++;
	}

	while (*source != '\0')
	{
		*d = *source;
		d++;
		source++;
	}
	*d = '\0';
	return (s);
}

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
