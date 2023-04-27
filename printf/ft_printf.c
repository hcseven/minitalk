/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:04:29 by hseven            #+#    #+#             */
/*   Updated: 2022/07/03 10:04:29 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char a)
{
	write (1, &a, 1);
	return (1);
}

int	put_array(char *s)
{
	int	a;

	a = 0;
	if (!s)
		s = "(null)";
	while (s[a] != '\0')
	{
		put_char(s[a]);
		a++;
	}
	return (a);
}

int	put_uitoa(unsigned int b)
{
	char	*s;
	int		c;

	c = ulennum(b);
	s = (char *)malloc(sizeof(char) * c + 1);
	if (b == 4294967295)
	{
		if (b == 4294967295)
			put_array("4294967295");
		free (s);
		return (10);
	}
	s[c] = '\0';
	while (c > 0)
	{
		s[c - 1] = b % 10 + 48;
		b = b / 10;
		c--;
	}
	c = put_array(s);
	free (s);
	return (c);
}

int	chechker(va_list arg, char a)
{
	int		len;
	char	*s;

	len = 0;
	if (a == 'c')
		return (put_char(va_arg(arg, int)));
	else if (a == 's')
		return (put_array(va_arg(arg, char *)));
	else if (a == 'd' || a == 'i')
	{
		s = ft_itoa(va_arg(arg, int));
		len += put_array(s);
		free (s);
	}
	else if (a == 'u')
		return (put_uitoa(va_arg(arg, unsigned int)));
	else if (a == 'p')
		return (put_ptr(va_arg(arg, unsigned long)));
	else if (a == 'x' || a == 'X')
		return (put_hex(va_arg(arg, unsigned int), a));
	else if (a == '%')
		return (put_char(a));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list			arg;
	unsigned int	a;
	unsigned int	len;

	va_start(arg, s);
	len = 0;
	a = 0;
	while (s[a] != '\0' )
	{
		if (s[a] == '%' && s[a + 1] != '\0')
		{
			a++;
			len += chechker(arg, s[a]);
		}
		else
		{
			write (1, &s[a], 1);
			len++;
		}
		a++;
	}
	va_end(arg);
	return (len);
}
