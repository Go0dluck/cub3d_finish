/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:44:50 by ksharee           #+#    #+#             */
/*   Updated: 2020/11/02 09:47:40 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *old_elem;

	if (*lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			old_elem = *lst;
			*lst = old_elem->next;
			free(old_elem);
		}
		*lst = NULL;
	}
}
