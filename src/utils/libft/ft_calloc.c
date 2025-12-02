/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:09:24 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/10 09:37:47 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	bytes;
	size_t	max_value;

	if (count == 0 || size == 0)
	{
		return ((void *)malloc(0));
	}
	max_value = (size_t)-1;
	if (count != 0 && size > max_value / count)
		return (NULL);
	bytes = count * size;
	str = (void *)malloc(bytes);
	if (!str)
		return (NULL);
	ft_bzero(str, bytes);
	return (str);
}
