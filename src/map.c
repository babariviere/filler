/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:26:04 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 18:33:36 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fill_size(char *buf, t_map *map)
{
	while (*buf && !ft_iswhitespace(*buf))
		buf++;
	if (*buf == 0)
		return ;
	buf++;
	map->height = ft_atoi(buf);
	buf += ft_numlen(map->height);
	if (*buf == 0 || !ft_iswhitespace(*buf))
		return ;
	buf++;
	map->width = ft_atoi(buf);
}

t_map			*create_map(void)
{
	t_map	*map;
	char	*buf;
	int		idx;

	if ((map = ft_memalloc(sizeof(t_map))) == 0)
		return (0);
	if (ft_gnl(0, &buf) <= 0)
		return (0);
	fill_size(buf, map);
	free(buf);
	if ((map->data = ft_memalloc(sizeof(char *) * (map->height + 1))) == 0)
		return (0);
	idx = 0;
	ft_gnl(0, &buf);
	free(buf);
	while (idx < map->height)
	{
		if (ft_gnl(0, &buf) <= 0)
			continue ;
		map->data[idx++] = ft_strdup(buf + 4);
		free(buf);
	}
	return (map);
}

static void		update_row(char *dst, const char *src)
{
	int		idx;

	idx = -1;
	while (dst[++idx])
		dst[idx] = src[idx + 4];
}

void			update_map(t_map *map)
{
	char	*buf;
	int		idx;

	if (ft_gnl(0, &buf) <= 0)
		return ;
	free(buf);
	ft_gnl(0, &buf);
	free(buf);
	idx = 0;
	while (idx < map->height)
	{
		if (ft_gnl(0, &buf) <= 0)
			continue ;
		update_row(map->data[idx++], buf);
		free(buf);
	}
}

void			delete_map(t_map **map)
{
	t_map	*tmp;
	int		idx;

	tmp = *map;
	if (tmp == 0)
		return ;
	if (tmp->data)
	{
		idx = 0;
		while (idx < tmp->height)
			ft_strdel(&tmp->data[idx++]);
		ft_memdel((void **)&tmp->data);
	}
	ft_memdel((void **)map);
}
