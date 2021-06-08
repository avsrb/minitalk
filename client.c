#include "minitalk.h"

static void send_ascii(char *str, pid_t pid)
{
	int i;
	
	while (*str != '\0')
	{
		i = 128;
		while (i > 0)
		{
			if (i & *str)
			{
				if ((kill(pid, SIGUSR1)) < 0)
					error("pizdest_sent1");
			}
			else
			{
				if ((kill(pid, SIGUSR2)) < 0)
					error("pizdest_sent1");
			}
			i >>= 1;
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc < 3)
		error("not enough arguments\n");
	if (argc > 3)
		error("many arguments\n");
	pid = (pid_t)atoi(argv[1]);
	send_ascii(argv[2], pid);
}