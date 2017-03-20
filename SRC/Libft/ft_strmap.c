/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:57:55 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/21 22:32:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*new_s;

	if (!s || !f || !(new_s = ft_strdup(s)))
		return (0);
	i = -1;
	while (new_s[++i])
		new_s[i] = f(new_s[i]);
	new_s[i] = '\0';
	return (new_s);
}
