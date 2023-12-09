/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:44:57 by hfazaz            #+#    #+#             */
/*   Updated: 2023/11/26 00:10:15 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_cn;

	res = NULL;
	new_cn = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_cn = ft_lstnew(f(lst->content));
		if (!new_cn)
		{
			ft_lstclear(&new_cn, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new_cn);
		lst = lst->next;
	}
	return (res);
}
