/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:20:58 by briviere          #+#    #+#             */
/*   Updated: 2018/02/15 12:36:44 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	read_player_num(void)
{
	char	*line;
	char	num;

	if (ft_gnl(0, &line) <= 0)
		return (0);
	num = line[10];
	free(line);
	if (num == '1')
		return ('O');
	else if (num == '2')
		return ('X');
	return (0);
}

int		main(void)
{
	t_map	*map;
	char	player;
	size_t	idx;

	player = read_player_num();
	ft_putendl2_fd("i am ", &player, 2);
	map = create_map();
	idx = 0;
	ft_putstr_fd("width: ", 2);
	ft_putnbr_fd(map->width, 2);
	ft_putstr_fd(", height: ", 2);
	ft_putnbr_fd(map->height, 2);
	ft_putchar_fd('\n', 2);
	while (idx < map->height)
		ft_putendl_fd(map->data[idx++], 2);
	return (0);
}
