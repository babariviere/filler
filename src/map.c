/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:26:04 by briviere          #+#    #+#             */
/*   Updated: 2018/02/15 13:13:41 by briviere         ###   ########.fr       */
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
			return (0);
		map->data[idx++] = ft_strdup(buf + 4);
		free(buf);
	}
	return (map);
}

void			update_map(t_map *map)
{
	(void)map;
	// TODO: 
}

void		delete_map(t_map **map)
{
	t_map	*tmp;
	int		idx;

	tmp = *map;
	if (tmp->data)
	{
		idx = 0;
		while (idx < tmp->height)
			ft_strdel(&tmp->data[idx++]);
		ft_memdel((void **)&tmp->data);
	}
	ft_memdel((void **)map);
}
