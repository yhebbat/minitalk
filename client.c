#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void		ft_putstr(char *c)
{
	int i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
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

int main(int ac, char **av)
{
    int i;
    int j;
    int ret;
    int pid;
    
    pid = getpid();
    j = 0;
    i = 0;
    if (ac != 3)
    {
        ft_putstr("error\n");
        return (0);
    }
    ft_putstr("client pid: ");
    ft_putnbr(pid);
    ft_putstr("\n");
    while(av[2][i])
    {
        j = 0;
        while (j < 8 && (usleep(150) || 1))
        {  
            if ((av[2][i] >> j) & 1)
                ret = kill(atoi(av[1]), SIGUSR1);
            else
                ret = kill(atoi(av[1]), SIGUSR2);
            if (ret == 1)
            {
                ft_putstr("error\n");
                return(0);
            }
            j++;
        }
        i++;
    }
    return (0);
}