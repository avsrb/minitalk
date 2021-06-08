#include "minitalk.h"

static void decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(50);
}

static void ascii_to_binary(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		decimal_conversion(str[i], 7, pid);
		i++;
	}

}

int	main(int argc, char **argv)
{
	if (argc < 3)
		error("not enough arguments\n");
	if (argc > 3)
		error("many arguments\n");
	//set_signal();
	ascii_to_binary (argv[2], (atoi(argv[1])));
	// while (1)
	// 	pause();
}