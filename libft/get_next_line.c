/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:52:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/21 17:52:36 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_checkfile(const int fd, t_list **file)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static int		ft_copy_line(char *c, char **l)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (c[++i])
	{
		if (c[i] == '\n')
			break ;
	}
	*l = ft_strnew(i + 1);
	*l = ft_strncpy(*l, c, i);
	return (i);
}

static t_list	*ft_del_str(t_list *mem, int i)
{
	char *tmp;

	if (i < (int)ft_strlen(mem->content))
	{
		tmp = mem->content;
		mem->content = ft_strdup(mem->content + i + 1);
		ft_strdel(&tmp);
	}
	else
		ft_strclr(mem->content);
	return (mem);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*mem;
	char			tmp[BUFF_SIZE + 1];
	char			*tmp2;
	int				i;

	if ((fd < 0 || line == NULL || read(fd, tmp, 0) < 0))
		return (-1);
	mem = ft_checkfile(fd, &file);
	while ((i = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[i] = 0;
		tmp2 = mem->content;
		mem->content = ft_strjoin(mem->content, tmp);
		ft_strdel(&tmp2);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (i < BUFF_SIZE && !ft_strlen(mem->content))
		return (0);
	i = ft_copy_line(mem->content, line);
	mem = ft_del_str(mem, i);
	return (1);
}
