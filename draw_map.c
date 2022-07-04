/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:24:12 by oessamdi          #+#    #+#             */
/*   Updated: 2022/07/04 03:44:32 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars vars, char x, int i, int j)
{
	if (x == '1')
		mlx_put_image_to_window(vars.mlx, vars.mlx_win,
			vars.img_w, j * 50, i * 50);
	else
	{
		mlx_put_image_to_window(vars.mlx, vars.mlx_win,
			vars.img_bg, j * 50, i * 50);
		if (x == 'P')
			mlx_put_image_to_window(vars.mlx, vars.mlx_win,
				vars.img_g, j * 50, i * 50);
		else if (x == 'C')
			mlx_put_image_to_window(vars.mlx, vars.mlx_win,
				vars.img_c, j * 50, i * 50);
		else if (x == 'E')
		{
			if (vars.nb_c != 0)
				mlx_put_image_to_window(vars.mlx, vars.mlx_win,
					vars.img_el, j * 50, i * 50);
			else
				mlx_put_image_to_window(vars.mlx, vars.mlx_win,
					vars.img_eo, j * 50, i * 50);
		}
	}
}

void	*draw_map(t_vars vars)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < vars.height)
	{
		j = 0;
		while (j < vars.width)
		{
			put_image(vars, vars.map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (vars.mlx);
}

void	change_girl(t_vars *vars, int direction)
{
	if (direction == 3)
		vars->img_g = vars->img_gl;
	else if (direction == 4)
		vars->img_g = vars->img_gr;
}

int	check_images(t_vars *vars)
{
	if (vars->img_gr == NULL || vars->img_gl == NULL || vars->img_w == NULL
		|| vars->img_c == NULL || vars->img_el == NULL || vars->img_eo == NULL
		|| vars->img_bg == NULL)
		return (set_error(vars, 6));
	return (1);
}

int	images_init(t_vars *vars)
{
	int		x;
	int		y;

	vars->img_gr = mlx_xpm_file_to_image(vars->mlx, "xpm/GirlRight.xpm", &x, &y);
	vars->img_gl = mlx_xpm_file_to_image(vars->mlx, "xpm/GirlLeft.xpm", &x, &y);
	vars->img_g = vars->img_gr;
	vars->img_w = mlx_xpm_file_to_image(vars->mlx, "xpm/Wall.xpm", &x, &y);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx, "xpm/Collectible.xpm", &x, &y);
	vars->img_el = mlx_xpm_file_to_image(vars->mlx, "xpm/ExitLocked.xpm", &x, &y);
	vars->img_eo = mlx_xpm_file_to_image(vars->mlx, "xpm/ExitOpen.xpm", &x, &y);
	vars->img_bg = mlx_xpm_file_to_image(vars->mlx, "xpm/ground.xpm", &x, &y);
	vars->mlx_win = mlx_new_window(vars->mlx, vars->width * 50,
			vars->height * 50, "So Long");
	return (check_images(vars));
}
