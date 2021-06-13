#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int i,j;

    j = 0;
    i = 0;
    if (ac != 3)
    {
        printf("error\n");
        return 0;
    }
    while(av[2][i])
    {
        j = 0;
        while (j < 8 && (usleep(150) || 1))
        {
            if ((av[2][i] >> j) & 1)
                kill(atoi(av[1]), SIGUSR1);
            else
                kill(atoi(av[1]), SIGUSR2);
            j++;
        }
        i++;
    }
}