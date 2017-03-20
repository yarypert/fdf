/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:37:04 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/10 04:32:16 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t c;
	size_t item;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && n > 0)
	{
		c = 0;
		if (n < (unsigned long)ft_strlen(s2))
			return (NULL);
		item = i;
		while (s1[item] == s2[c] && s2[c] && s1[item])
		{
			item++;
			c++;
		}
		if (s2[c] == '\0')
			return ((char *)s1 + i);
		i++;
		n--;
	}
	return (NULL);
}
