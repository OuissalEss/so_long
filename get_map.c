/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:55:16 by oessamdi          #+#    #+#             */
/*   Updated: 2022/02/17 12:32:39 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compteur(const char *file_name, t_vars *maps)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd, &x);
	if (line == NULL)
		return (set_error(maps, 2));
	maps->width = ft_strlen(line);
	while (line != NULL)
	{
		if (ft_strlen(line) != maps->width && maps->width != -1)
		{
			free(line);
			return (set_error(maps, 3));
		}
		(maps->height)++;
		free(line);
		line = get_next_line(fd, &x);
	}
	if (x == 1)
		return (set_error(maps, 3));
	close(fd);
	return (1);
}

int	get_map(const char *file_name, t_vars *maps)
{
	int	fd;
	int	i;
	int	len;
	int	x;

	maps->map = NULL;
	len = ft_strlen(file_name);
	if (ft_strcmp(".ber", file_name + len - 4) != 0)
		return (set_error(maps, 4));
	if (compteur(file_name, maps) != 1)
		return (maps->error);
	maps->map = malloc(sizeof(char *) * (maps->height + 1));
	if (!maps->map)
		return (set_error(maps, 5));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < maps->height)
	{
		maps->map[i] = get_next_line(fd, &x);
		if (maps->map)
			i++;
	}
	maps->map[i] = NULL;
	return (1);
}

int	free_map(t_vars *maps)
{
	int	fd;
	int	i;

	i = 0;
	if (maps->map != NULL)
	{
		while (i < maps->height)
		{
			free(maps->map[i]);
			maps->map[i] = NULL;
			i++;
		}
		free(maps->map);
	}
	return (1);
}

int	check_map2(t_vars *maps, int i, int j)
{
	i = 0;
	j = 0;
	maps->nb_p = 0;
	maps->nb_c = 0;
	maps->nb_e = 0;
	while (i < maps->height)
	{
		j = 0;
		while (j < maps->width)
		{
			if (maps->map[i][j] == 'P')
				(maps->nb_p)++;
			else if (maps->map[i][j] == 'C')
				(maps->nb_c)++;
			else if (maps->map[i][j] == 'E')
				(maps->nb_e)++;
			else if (maps->map[i][j] != '0' && maps->map[i][j] != '1')
				return (set_error(maps, 3));
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_vars *maps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (maps->map[i])
	{
		if (maps->map[i][0] != '1' || maps->map[i][maps->width - 1] != '1')
			return (set_error(maps, 3));
		i++;
	}
	while (j < maps->width - 1)
	{
		if (maps->map[0][j] != '1' || maps->map[maps->height - 1][j] != '1')
			return (set_error(maps, 3));
		j++;
	}
	if (check_map2(maps, i, j) != 1)
		return (set_error(maps, 3));
	if (maps->nb_c < 1 || maps->nb_e < 1 || maps->nb_p != 1)
		return (set_error(maps, 3));
	return (1);
}
