/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:32:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // For write
# include <stdlib.h> // For malloc, free
# include <limits.h> // For INT_MAX, INT_MIN

// Part of push_swap's t_node, but libft list functions are generic
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long	ft_atoi_checked(const char *str, int *error_flag);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);

#endif