/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:10:05 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/15 13:17:56 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add the element "new" in the list
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
