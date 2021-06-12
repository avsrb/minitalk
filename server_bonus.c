#include "minitalk_bonus.h"

static	void	sighandler(int signum)
{
	static char	ascii = 0;
	static int	count = 128;

	if (signum == SIGUSR1)
		ascii += count;
	count >>= 1;
	if (count == 0)
	{
		ft_putchar(ascii);
		count = 128;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	catch;

	write(1, "Server started\nPID: ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&catch.sa_mask);
	sigaddset(&catch.sa_mask, SIGUSR1);
	sigaddset(&catch.sa_mask, SIGUSR2);
	while (1)
	{
		catch.sa_handler = sighandler;
		if (sigaction(SIGUSR1, &catch, NULL) < 0 || \
		sigaction(SIGUSR2, &catch, NULL) < 0)
			error("sigaction_return_less_than_zero");
		pause();
	}
}
