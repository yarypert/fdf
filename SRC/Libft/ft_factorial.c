/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:05:19 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/18 14:41:09 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if ((nb < 0) || (nb > 12))
		return (0);
	if (nb == 1)
		return (1);
	return (nb * ft_factorial(nb - 1));
}
