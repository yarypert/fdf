/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:25:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/11 00:52:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_endline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		last_line(char **str, char **line)
{
	if (!(*line = ft_strdup(*str)))
		return (-1);
	free(*str);
	*str = ft_strnew(0);
	return (1);
}

static int		cut_line(char **str, char **line, int len)
{
	char	*tmp;

	if (!(*line = ft_strsub(*str, 0, len)))
		return (-1);
	tmp = *str;
	if (!(*str = ft_strdup(ft_strchr(*str, '\n') + 1)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static int		read_file(int fd, char **str, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		len;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buf);
		ft_strdel(&tmp);
		if ((len = find_endline(*str)) > -1)
			return (cut_line(str, line, len));
	}
	return (-2);
}

int				get_next_line(int fd, char **line)
{
	static char		*str[2560];
	int				len;
	int				ret;

	if (fd < 0 || fd == 1 || fd == 2 || fd > 2559 \
			|| BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	if (ft_strlen(str[fd]) && (len = find_endline(str[fd])) != -1)
		return (cut_line(&str[fd], line, len));
	if ((ret = read_file(fd, &str[fd], line)) && ret != -2)
		return (ret);
	if (str[fd] && find_endline(str[fd]) == -1 && ft_strlen(str[fd]))
		return (last_line(&str[fd], line));
	*line = ft_strdup("");
	ft_strclr(str[fd]);
	return (0);
}
