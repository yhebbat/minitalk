#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

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