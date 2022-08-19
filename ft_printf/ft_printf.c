#include "ft_printf.h"

int 	count_par(char *s, char **type)
{
	int	cnt;
	int	i;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			cnt++;
		}
	}
	(*type) = (char *)malloc(sizeof(char) * (cnt + 1));
	if (type == NULL)
		return -1;
	i = 0;
	while (*s)
	{
		if (*s == '%')
			(*type)[i++] = *++s;
		s++;
	}
	type[i] = '\0';
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	x;
	sizeof	i;

	i = -1;
	va_start(x, s);
	while (s[++i])
	{
		if (s[i] != '%')
			write(1, s + i++, 1);
		else
			print()
	}
	va_end(x)
}