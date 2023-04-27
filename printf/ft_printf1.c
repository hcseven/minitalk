/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:04:52 by hseven            #+#    #+#             */
/*   Updated: 2022/07/03 10:04:52 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ulennum(unsigned int a)
{
	int	b;

	b = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /= 10;
		b++;
	}
	return (b);
}

int	lennum(int a)
{
	int	b;

	b = 0;
	if (a < 0)
	{
		a *= -1;
		b++;
	}
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a /= 10;
		b++;
	}
	return (b);
}

int	put_hex(unsigned int b, char c)
{
	int		len;
	char	*s;

	len = 0;
	if (c == 'x')
		s = ft_strdup("0123456789abcdef");
	else
		s = ft_strdup("0123456789ABCDEF");
	if (b >= 16)
	{
		len += put_hex(b / 16, c);
		len += put_hex(b % 16, c);
	}
	else
	{
		len++;
		put_char(s[b]);
	}
	free (s);
	return (len);
}

int	put_hex_l(unsigned long b)
{
	int		a;
	char	*s;

	a = 0;
	s = ft_strdup("0123456789abcdef");
	if (b >= 16)
	{
		a += put_hex_l(b / 16);
		a += put_hex_l(b % 16);
	}
	else
	{
		put_char(s[b]);
		a++;
	}
	free (s);
	return (a);
}

int	put_ptr(unsigned long a)
{
	int	b;

	b = 0;
	put_char('0');
	put_char('x');
	b = put_hex_l(a);
	return (b + 2);
}
