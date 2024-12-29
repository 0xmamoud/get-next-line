/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkane <mkane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:07:40 by kane              #+#    #+#             */
/*   Updated: 2024/03/21 15:42:19 by mkane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	line = NULL;
	ft_read_fd(fd, &list);
	if (!list)
		return (NULL);
	line = ft_getline(list);
	ft_clean_list(&list);
	if (!*line)
	{
		ft_free_list(list);
		free(line);
		list = NULL;
		return (NULL);
	}
	return (line);
}

void	ft_read_fd(int fd, t_list **list)
{
	char	*buf;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes != 0 && !ft_find_newline(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1 || (!buf && read_bytes == 0))
		{
			free(buf);
			ft_free_list(*list);
			*list = NULL;
			return ;
		}
		buf[read_bytes] = '\0';
		ft_lstadd(list, buf, read_bytes);
		free(buf);
	}
}

void	ft_lstadd(t_list **list, char *buf, int read_bytes)
{
	t_list	*new;
	t_list	*last;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = (char *)malloc(sizeof(char) * (read_bytes + 1));
	if (!new->content)
		return ;
	i = 0;
	while (i < read_bytes && buf[i])
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (!(*list))
	{
		*list = new;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new;
}

char	*ft_getline(t_list *list)
{
	int		i;
	int		j;
	char	*line;

	line = malloc(sizeof(char) * (ft_linesize(list) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			if (list->content[j] == '\n')
			{
				line[i++] = list->content[j];
				line[i] = '\0';
				return (line);
			}
			line[i++] = list->content[j++];
		}
		list = list->next;
	}
	line[i] = '\0';
	return (line);
}

void	ft_clean_list(t_list **list)
{
	t_list	*tmp;
	t_list	*last;
	int		i;
	int		j;

	tmp = malloc(sizeof(t_list));
	if (!tmp || !(*list))
		return ;
	last = ft_lstlast(*list);
	tmp ->next = NULL;
	i = 0;
	while (last -> content[i] && last -> content[i] != '\n')
		i++;
	if (last -> content[i] == '\n')
		i++;
	tmp -> content = malloc(sizeof(char)
			* (ft_strlen(last -> content) - i + 1));
	if (!tmp -> content)
		return ;
	j = 0;
	while (last -> content[i])
		tmp -> content[j++] = last -> content[i++];
	tmp -> content[j] = '\0';
	ft_free_list(*list);
	*list = tmp;
}

int main()
{
	int fd = open("./test.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
}
