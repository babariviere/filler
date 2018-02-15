/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:20:58 by briviere          #+#    #+#             */
/*   Updated: 2018/02/15 13:36:52 by briviere         ###   ########.fr       */
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
	t_piece	*piece;
	char	player;
	int		idx;

	player = read_player_num();
	ft_putendl2_fd("i am ", &player, 2);
	map = create_map();
	piece = create_piece();
	idx = 0;
	ft_putendl_fd("map:", 2);
	ft_putstr_fd("width: ", 2);
	ft_putnbr_fd(map->width, 2);
	ft_putstr_fd(", height: ", 2);
	ft_putnbr_fd(map->height, 2);
	ft_putchar_fd('\n', 2);
	while (idx < map->height)
		ft_putendl_fd(map->data[idx++], 2);
	ft_putendl_fd("piece:", 2);
	ft_putstr_fd("width: ", 2);
	ft_putnbr_fd(piece->width, 2);
	ft_putstr_fd(", height: ", 2);
	ft_putnbr_fd(piece->height, 2);
	ft_putchar_fd('\n', 2);
	idx = 0;
	while (idx < piece->height)
		ft_putendl_fd(piece->data[idx++], 2);
	t_zone *zone = locate_player(map, player);
	ft_putstr_fd("x: ", 2);
	ft_putnbr_fd(zone->x, 2);
	ft_putstr_fd(", y: ", 2);
	ft_putnbr_fd(zone->y, 2);
	ft_putstr_fd(", width: ", 2);
	ft_putnbr_fd(zone->width, 2);
	ft_putstr_fd(", height: ", 2);
	ft_putnbr_fd(zone->height, 2);
	ft_putchar_fd('\n', 2);
	if (try_placing(map, piece, (t_pos){zone->x, zone->y}, player) == 1)
	{
		ft_putnbr(zone->x);
		ft_putchar(' ');
		ft_putnbr(zone->y);
		ft_putchar('\n');
	}
	delete_map(&map);
	delete_piece(&piece);
	return (0);
}
