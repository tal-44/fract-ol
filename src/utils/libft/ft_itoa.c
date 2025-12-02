/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:25:22 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/10 10:12:16 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_num(int n)
{
	size_t	len;
	long	num;

	num = n;
	len = 0;
	if (num <= 0)
	{
		len = 1;
		num = -num;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*c;

	num = (long)n;
	len = ft_strlen_num(n);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (num < 0)
	{
		c[0] = '-';
		num = -num;
	}
	if (num == 0)
		c[0] = '0';
	while (num > 0)
	{
		c[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (c);
}
