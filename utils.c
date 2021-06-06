#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}



int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s)
			write(1, s++, 1);
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{		
		write(1, "-", 1);
		ft_putnbr (-n);
	}
	else if (n > 9)
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else
		ft_putchar(n + '0');
}
