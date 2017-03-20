/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 06:01:36 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/18 14:44:04 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ds;
	const char	*sr;

	i = 0;
	ds = dst;
	sr = src;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
