/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:31:36 by juhuck            #+#    #+#             */
/*   Updated: 2025/06/25 17:47:58 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static t_msg	g_msg;

static void	send_next_char_bit(pid_t server_pid)
{
	static int	bit_i = 0;
	static int	str_i = 0;
	int			signal;

	if (str_i > g_msg.len)
		exit(0);
	if (g_msg.str[str_i] & (1 << bit_i++))
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(server_pid, signal) == -1)
	{
		ft_printf("Error on send signal %d\n", signal);
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

static void	handle_confirmation(int sig)
{
	(void)sig;
	ft_printf("Señal recibida\n");
}

static void	setup_signals(void)
{
	struct sigaction	sa;
	struct sigaction	sa_ack;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	sigemptyset(&sa_ack.sa_mask);
	sa_ack.sa_flags = 0;
	sa_ack.sa_handler = handle_confirmation;
	if (sigaction(SIGUSR2, &sa_ack, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", argv[0]);
		return (1);
	}
	g_msg.str = argv[2];
	g_msg.len = ft_strlen(argv[2]);
	setup_signals();
	server_pid = ft_atoi(argv[1]);
	send_next_char_bit(server_pid);
	while (1)
		pause();
	return (0);
}
