#include "minitalk.h"

static void	sighandler(int signum)
{
	static int	ascii;
	static int	power;
	ascii = 0;
	power = 0;

	if (signum == SIGUSR1)
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
	struct sigaction catch;
	char	*pid;

	write(1,"Server started\nPID: ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&catch.sa_mask); //инициализирует набор сигналов, указанный в set, и "очищает" его от всех сигналов
	sigaddset(&catch.sa_mask, SIGUSR1);
	sigaddset(&catch.sa_mask, SIGUSR2);
	//catch.sa_flags = SA_SIGINFO;
	//catch.sa_siaction = &sighandler;
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (8);
	return (0);
}