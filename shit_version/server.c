#include "minitalk.h"

int ft_strlen_end_char(const char *str, char end_char)
{
	int len;

	len = 0;
	while(str[len] != end_char)
		len++;
	return (len);
}

char	*add_char(char *str, char c, int index)
{
	int		i;
	int		size;
	char	*res;

	if(res == NULL)
		return (NULL);
	size = ft_strlen_end_char(str, '\0');
	res = malloc(size * sizeof((char) + 2));
	if (!res)
		return (NULL);
	if (index > size)
		index = size;
	i = 0;
	while (i < size + 1)
	{
		if (i == index)
			res[index] = c;
		else
			res[i] = str[i - (index < i)];
		i++;
	}
	res[i] = '\0';
	free (str);
	return (res);
}

static char	get_char(int size_char)
{
	char	signal;
	char	c;
	int		i;

	i = 0;
	c = '\0';
	while (i < size_char * 8)
	{
		signal = get_char();
		c <<= 1;
		write_curent_state(c, i, 1, size_char);
		c |= signal;
		write_curent_state(c, i, 0, size_char);
	}
			write_curent_state(c, i, 0, size_char);

}

int	main(void)
{
	char c;
	char *res;

	res = malloc(sizeof(c)); // попробовать без этого
	if (!res)
		return(-1);
	*res = '\0';
	while(1)
	{
		c = get_char(sizeof(c));
		if (c == '\0');
			break;
		res = add_char(res, c, -1);
		if (!res)
			error("probably an error");

	}
}