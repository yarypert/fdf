/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 09:40:40 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/18 14:41:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (2);
	while (nb % i != 0)
	{
		i++;
	}
	if (nb != i && nb % i == 0)
	{
		return (ft_find_next_prime(nb + 1));
	}
	else
		return (nb);
}
