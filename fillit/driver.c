/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:49:42 by jkimmina          #+#    #+#             */
/*   Updated: 2018/03/21 21:43:23 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "input.h"

unsigned int	*cleanall(unsigned int *pieces)
{
	int		i;

	i = 0;
	while (pieces[i] != 0)
	{
		pieces[i] = cleantet(pieces[i]);
		i++;
	}
	return (pieces);
}

int				main(int argc, char **argv)
{
	unsigned int	*pieces;
	char			***map;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (1);
	}
	pieces = readtet(argv[1]);
	if (!pieces)
	{
		ft_putendl("error");
		return (0);
	}
	pieces = cleanall(pieces);
	map = fi_solve(pieces);
	fi_map_print(map);
	free(pieces);
	return (0);
}
