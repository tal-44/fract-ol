/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:22 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/07 12:37:48 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *t_f, size_t len)
{
	size_t	i;
	size_t	j;

	if (t_f[0] == '\0')
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] && t_f[j] && str[i + j] == t_f[j])
		{
			j++;
			if (t_f[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
