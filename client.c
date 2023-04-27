/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:37:07 by hseven            #+#    #+#             */
/*   Updated: 2022/10/02 15:08:03 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	ea;

	ea = 1;
	a = 0;
	b = 0;
	if (str[0] == '-')
	{
		ea = -1;
		a++;
	}
	while (str[a] != '\0')
	{
		b = b * 10 + str[a] - 48;
		a++;
	}
	return (b * ea);
}

void	send_msg(int pid, char *str)
{
	char	c;
	int		a;
	int		b;

	a = 0;
	while (str[a] != '\0')
	{
		b = 8;
		c = str[a];
		while (b--)
		{
			if (c >> b & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}	
		a++;
	}
	b = 8;
	while (b--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		ft_printf("Error!\n");
		return (0);
	}
	if (av[1][0] == '-' && av[1][1] == '1' && av[1][2] == '\0')
	{
		ft_printf("You pass the monkey test :D\n");
		return (0);
	}
	send_msg(ft_atoi(av[1]), av[2]);
}
