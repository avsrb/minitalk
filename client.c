#include "minitalk.h"

static void decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep;
}

static void ascii_to_binary(char *str, int pid)
{
	int	i;

	i = 0;

	while (str[i])
	{
		decimal_conversion(str[i], 7, pid);
		i += 1; // i++; ???
	}
}

static void sentdata(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
		decimal_conversion(str[i++], 7, pid);
}

int	main(int argc, char **argv)
{
	pid_t pid;
	pid = ft_atoi(argv[1]);
}