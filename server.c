#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void ft_putnbr(int n)
{
    int i;
    char c;

    i = 0;
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

void decriptage(int signal_code)
{
    static unsigned char c;
    static char i;

    c += (SIGUSR1 == signal_code) << i;
	i++;
	if (i > 7)
	{
		i = 0;
		write(1, &c,1);
		c = 0;
	}
}

int main(int ac, char **av)
{
    int pid;
    
    pid = getpid();
	if (ac != 1)
    {
        write(1,"error",6);
        return (0);
    }
    if (av[0])
    {
        ft_putstr("server pid :");
        ft_putnbr(pid);
        ft_putstr("\n");
        signal(SIGUSR1, decriptage);
        signal(SIGUSR2, decriptage);
        while(1)
            pause();
    }
	return (0);
}