/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:11:03 by yarypert          #+#    #+#             */
/*   Updated: 2016/11/15 13:20:12 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** applies f to each element of the list and create a new list with the results
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (lst && f)
	{
		ret = f(lst);
		ret->next = ft_lstmap(lst->next, f);
		return (ret);
	}
	return (0);
}
