#include "minitalk.h"

static void	sighandler(int signum)
{
	static int	ascii;
	static int	power;
	ascii = 0;
	power = 0;

	if (signum = SIGUSR1)
		ascii += 1 << (7 - power);
	if ((power += 1) == 8)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
	}
}

int		main(int argc, char **argv)
{
	//if (argc == 3)
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (42);
	return;
}