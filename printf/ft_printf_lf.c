/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseven <hseven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:23:58 by hseven            #+#    #+#             */
/*   Updated: 2022/08/04 16:57:30 by hseven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	int		a;
	int		c;

	c = 0;
	while (str[c])
		c++;
	a = 0;
	s = malloc(sizeof(char) * c + 1);
	if (!s)
		return (0);
	while (str[a] != '\0')
	{
		s[a] = str[a];
		a++;
	}
	s[a] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		a;

	a = lennum(n);
	s = (char *)ft_calloc(a + 1);
	if (!s)
		return (0);
	if (n == 0)
		*s = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(s, "-2147483648", a + 1);
			return (s);
		}
		s[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		*(s + --a) = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char	*ft_calloc(int a)
{
	char	*str;
	int		b;

	str = (char *)malloc(sizeof(char) * a + 1);
	if (str == 0)
		return (0);
	b = 0;
	while (b < a)
	{
		str[b] = '\0';
		b++;
	}
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > a)
	{
		while (src[a] != '\0' && (size - 1) > a)
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	while (src[a] != '\0')
	{
		a++;
	}
	return (a);
}
