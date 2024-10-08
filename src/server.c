/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:05:49 by jhuck             #+#    #+#             */
/*   Updated: 2024/09/17 19:17:48 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minitalk.h"

void	sig_handler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c, i");
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
		
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler); 
		pause();
	}
	return (0);
}
