/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 04:32:39 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/18 14:52:45 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_s;

	if (!(new_s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_strclr(new_s);
	return (new_s);
}
