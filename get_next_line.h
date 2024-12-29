/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kane <kane@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:03:36 by kane              #+#    #+#             */
/*   Updated: 2023/11/27 00:11:48 by kane             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h> 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
char	*get_next_line(int fd);
void	ft_read_fd(int fd, t_list **list);
void	ft_lstadd(t_list **list, char *buf, int read_bytes);
void	ft_clean_list(t_list **list);
char	*ft_getline(t_list *list);
void	ft_free_list(t_list *list);
int		ft_linesize(t_list *list);
int		ft_find_newline(t_list *list);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *s);

#endif