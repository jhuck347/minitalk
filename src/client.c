/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:31:41 by juhuck            #+#    #+#             */
/*   Updated: 2025/06/25 17:32:08 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_msg	g_msg;

static void	send_next_char_bit(pid_t server_pid)
{
	static int	bit_i = 0;
	static int	str_i = 0;
	int			sig_to_send;

	if (str_i > g_msg.len)
		exit(0);
	if (g_msg.str[str_i] & (1 << bit_i++))
		sig_to_send = SIGUSR1;
	else
		sig_to_send = SIGUSR2;
	if (kill(server_pid, sig_to_send) == -1)
	{
		ft_printf("Error on send signal %d\n", sig_to_send);
		exit(EXIT_FAILURE);
	}
	if (bit_i == 8)
	{
		str_i++;
		bit_i = 0;
	}
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		send_next_char_bit(info->si_pid);
	(void)context;
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error on sigaction with SIGUSR1 signal.\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	g_msg.len = ft_strlen(argv[2]);
	g_msg.str = argv[2];
	send_next_char_bit(server_pid);
	while (1)
		pause();
	return (0);
}
