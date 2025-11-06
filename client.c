#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>


void send_char_as_bit(pid_t server_pid, char character)
{
	int bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((character >> bit_index) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		bit_index--;
	}
}

int main(int ac, char **av)
{
	pid_t server_pid;
	char *message_to_send;
	int i;

	i = 0;
	if (ac != 3)
	{
		printf("Usage: ./client <Server_pid> \"<Message>\"\n");
		exit(EXIT_FAILURE);
	}
	server_pid = atoi(av[1]);
	message_to_send = av[2];
	if (server_pid <= 0)
	{
		printf("Invalid Server PID\n");
		exit(EXIT_FAILURE);
	}
	while (message_to_send[i] != '\0')
	{
		send_char_as_bit(server_pid, message_to_send[i]);
		i++;
	}
	send_char_as_bit(server_pid, '\0');
	printf("Message sent successfully\n");
	return (0);
}