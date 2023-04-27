#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H

# include "./printf/ft_printf.h"
# include <signal.h>

int		ft_atoi(char *str);
void	send_msg(int pid, char *str);
void	use_sig(int sig, siginfo_t *pid, void *c);
void	final(int sig);

#endif