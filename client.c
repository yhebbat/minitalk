#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	size_t	result;
	int		signe;

	result = 0;
	signe = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result > 4294967295 && signe == 1)
			return (-1);
		if (signe == -1 && result > 4294967295)
			return (0);
	}
	return ((int)result * signe);
}

static void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	ret;

	j = 0;
	i = 0;
	if (ac != 3)
		ft_error("🚨error🚨\nThe number of arguments is not correct\n");
	while (av[2][i])
	{
		j = 0;
		while (j < 8 && (usleep(150) || 1))
		{
			if ((av[2][i] >> j) & 1)
				ret = kill(ft_atoi(av[1]), SIGUSR1);
			else
				ret = kill(ft_atoi(av[1]), SIGUSR2);
			if (ret == -1)
				ft_error("🚨error🚨\nThis process does not exist\n");
			j++;
		}
		i++;
	}
	return (0);
}
