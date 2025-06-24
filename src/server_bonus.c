/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:25:40 by jhuck             #+#    #+#             */
/*   Updated: 2025/06/24 22:40:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static char	*g_msg = NULL;

void	message_received(void)
{
	ft_printf("Received: %s\n", g_msg);
	free(g_msg);
	g_msg = NULL;
}

void	concat_char(char c, int msg_size)
{
	char	*new_message;

	new_message = (char *)malloc(sizeof(char) * (msg_size + 2));
	if (!new_message)
	{
		free(g_msg);
		exit(1);
	}
	if (g_msg)
	{
		ft_memcpy(new_message, g_msg, msg_size);
		free(g_msg);
	}
	new_message[msg_size] = c;
	new_message[msg_size + 1] = '\0';
	g_msg = new_message;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	size = 0;
	static int	byte = 0;
	static int	bit_index = 0;

	if (sig == SIGUSR1)
		byte |= (1 << bit_index);
	else if (sig != SIGUSR2)
		return ;
	bit_index++;
	if (bit_index == 8)
	{
		concat_char(byte, size++);
		if (byte == '\0')
		{
			size = 0;
			message_received();
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_putstr_fd("Error sending confirmation\n", 2);
		}
		bit_index = 0;
		byte = 0;
	}
	(void)context;
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_putstr_fd("Error on ack\n", 2);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction error\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	g_msg = ft_strdup("");
	if (!g_msg)
		exit(1);
	while (1)
		pause();
	if (g_msg)
		free(g_msg);
	return (0);
}
