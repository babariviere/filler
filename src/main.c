/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:20:58 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 15:38:58 by briviere         ###   ########.fr       */
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

void	write_place(t_zone *zone)
{
	ft_putnbr(zone->y);
	ft_putchar(' ');
	ft_putnbr(zone->x);
	ft_putchar('\n');
}

int		main(void)
{
	t_map	*map;
	t_piece	*piece;
	char	player;
	t_lst	*poss;

	player = read_player_num();
	map = create_map();
	while (1)
	{
		if ((piece = create_piece()) == 0)
			break ;
		poss = get_poss(map, piece, player);
		if (poss)
			write_place(poss->content);
		else
		{
			for (int i = 0; i < piece->height; i++)
				ft_putendl_fd(piece->data[i], 2);
			ft_putendl_fd("no poss", 2);
			delete_piece(&piece);
			ft_putendl("-1 -1");
			break ;
		}
		ft_lstdel(&poss, ft_lstdel_def);
		delete_piece(&piece);
		update_map(map);
	}
	delete_map(&map);
	return (0);
}
