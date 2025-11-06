#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum)
{
    static int current_char;
    static int bit_index;
    
    current_char <<= 1;
    if (signum == SIGUSR2)
        current_char |= 1;
    bit_index++;
    if (bit_index == 8)
    {
        if (current_char == '\0')
            write(1, "\n", 1);
        else
            write(1, &current_char, 1);
        current_char = 0;
        bit_index = 0;
    }
}

int main()
{
    struct sigaction sa;
    int pid = getpid();
    
    printf("%d\n", pid);
    
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    while (1)
    {
        pause();
    }
    return (0);
}