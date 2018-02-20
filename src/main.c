/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:20:58 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 18:23:49 by briviere         ###   ########.fr       */
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

void	write_place(t_pos *pos)
{
	ft_putnbr(pos->y);
	ft_putchar(' ');
	ft_putnbr(pos->x);
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
			write_place(get_best_poss(map, poss, player));
		else
		{
			delete_piece(&piece);
			break ;
		}
		ft_lstdel(&poss, ft_lstdel_def);
		delete_piece(&piece);
		update_map(map);
	}
	delete_map(&map);
	return (0);
}
