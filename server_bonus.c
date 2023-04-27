/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:21:37 by hseven            #+#    #+#             */
/*   Updated: 2022/10/02 17:32:36 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	use_sig(int sig, siginfo_t *pid, void *ch)
{
	static char	c = 0;
	static int	a = 0;

	(void)ch;
	if (sig == SIGUSR1)
		c = c | 1;
	if (++a == 8)
	{
		if (!c)
		{
			ft_printf("\n");
			kill(pid->si_pid, SIGUSR1);
		}
		ft_printf("%c", c);
		c = 0;
		a = 0;
	}	
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	t_sig;

	t_sig.sa_sigaction = use_sig;
	t_sig.sa_flags = SA_SIGINFO;
	ft_printf("PID = %d\n", getpid());
	sigaction(SIGUSR1, &t_sig, 0);
	sigaction(SIGUSR2, &t_sig, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
