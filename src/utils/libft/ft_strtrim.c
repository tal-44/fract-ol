/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:58:09 by jmiguele          #+#    #+#             */
/*   Updated: 2025/10/07 11:33:34 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_total;
	size_t	sublen;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len_total = ft_strlen(s1);
	if (start == len_total)
		return (ft_calloc(1, sizeof(char)));
	end = len_total - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	sublen = end - start + 1;
	str = malloc(sublen + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, sublen + 1);
	return (str);
}
