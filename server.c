#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void decriptage(int SignalCode)
{
    static unsigned char c;
    static char i;

    c += (SIGUSR1 == SignalCode) << i;
	i++;
	if (i > 7)
	{
		i = 0;
		write(1, &c,1);
		c = 0;
	}
}

int main(void)
{
    int pid = getpid();

	printf("server PID: %d\n", pid);
    signal(SIGUSR1, decriptage);
    signal(SIGUSR2, decriptage);
    while(1)
        pause();
	return 0;
}