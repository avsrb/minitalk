#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	error(char *str);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif
