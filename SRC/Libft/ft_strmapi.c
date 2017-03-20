/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:59:13 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/10 00:07:51 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			i;
	char		*new_s;

	if (!s || !f || !(new_s = ft_strdup(s)))
		return (0);
	i = -1;
	while (new_s[++i])
		new_s[i] = f(i, new_s[i]);
	return (new_s);
}
