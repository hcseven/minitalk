/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:34:23 by hseven            #+#    #+#             */
/*   Updated: 2022/10/02 15:08:28 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./printf/ft_printf.h"
# include <signal.h>

int		ft_atoi(char *str);
void	send_msg(int pid, char *str);
void	use_sig(int sig);

#endif