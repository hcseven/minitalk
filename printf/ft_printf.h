/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:45:24 by hseven            #+#    #+#             */
/*   Updated: 2022/07/03 11:45:24 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_calloc(int a);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
int		lennum(int a);
int		ulennum(unsigned int a);
int		put_char(char a);
int		put_hex(unsigned int b, char c);
int		put_hex_l(unsigned long b);
int		put_ptr(unsigned long a);
int		put_array(char *s);
int		put_itoa(int a);
int		put_uitoa(unsigned int b);
int		chechker(va_list arg, char a);
int		ft_printf(const char *s, ...);

#endif
