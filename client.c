#include "minitalk.h"

int	ft_check_pid(char *c)
{
	int i;

	i = 0;
	while (c[i] != 0)
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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
					error("check_correct");
			}
			else
			{
				if ((kill(pid, SIGUSR2)) < 0)
					error("check_correct");
			}
			i >>= 1;
			usleep(60);
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
	if (!(ft_check_pid(argv[1])) || pid > 99998 || pid <= 0)
		error("pid_not_correct");
	send_ascii(argv[2], pid);
}
