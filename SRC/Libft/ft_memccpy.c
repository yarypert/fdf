/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:44:24 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/21 17:44:27 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;
	char	x;

	dst2 = (char*)dst;
	src2 = (char*)src;
	x = (char)c;
	i = 0;
	while (i < n)
	{
		if ((*dst2++ = *src2++) == x)
			return (dst2);
		i++;
	}
	return (0);
}
