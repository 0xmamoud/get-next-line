/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:39 by kane              #+#    #+#             */
/*   Updated: 2023/11/26 23:52:51 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_find_newline(t_list *list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!list)
		return (0);
	tmp = ft_lstlast(list);
	while (tmp -> content[i])
	{
		if (tmp -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_linesize(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			if (list->content[j] == '\n')
				return (i + 1);
			j++;
			i++;
		}
		list = list->next;
	}
	return (i);
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	if (!(list))
		return ;
	tmp = list;
	while (tmp)
	{
		free(tmp -> content);
		next = tmp -> next;
		free(tmp);
		tmp = next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}
