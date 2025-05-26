/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:07:58 by khanadat          #+#    #+#             */
/*   Updated: 2025/05/26 15:09:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;
	
	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		del(cur->content);
		free(cur);
		cur = NULL;
	}
	*lst = NULL;
}