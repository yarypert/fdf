/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:01:22 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/18 14:43:09 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long int n)
{
	int len;

	len = 2;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char				*str;
	long long int		nsave;
	int					len;

	nsave = n;
	len = ft_len(nsave);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	if (n < 0)
		nsave = -nsave;
	len = len - 2;
	while (len >= 0)
	{
		str[len] = (nsave % 10) + '0';
		len--;
		nsave = nsave / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
