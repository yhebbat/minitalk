#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int ft(int i)
{
    unsigned char c;
    c = 'a';
}

int main(void)
{
    int pid = getpid();

    printf("server PID: %d\n", pid);
    signal(SIGUSR1, ft);
    signal(SIGUSR2, ft);
    while (1)
        pause();
}
kill