/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:37:10 by hseven            #+#    #+#             */
/*   Updated: 2022/10/02 15:07:34 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	use_sig(int sig)
{
	static char	c = 0;
	static int	a = 0;

	if (sig == SIGUSR1)
		c = c | 1;
	if (++a == 8)
	{
		a = 0;
		if (!c)
			ft_printf("\n");
		ft_printf("%c", c);
		c = 0;
	}	
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("PID = %d\n", getpid());
	signal(SIGUSR1, use_sig);
	signal(SIGUSR2, use_sig);
	while (1)
	{
		pause();
	}
	return (0);
}
