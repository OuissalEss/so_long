/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:24:12 by oessamdi          #+#    #+#             */
/*   Updated: 2022/02/17 13:50:13 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	change_position(int t[], int new_i, int new_j, t_vars *vars)
{	
	if (vars->map[new_i][new_j] == 'C')
		vars->nb_c--;
	if (vars->map[new_i][new_j] == 'E' && vars->nb_c == 0)
	{
		g_nb_moves++;
		ft_printf("The total number of movements is %d\n", g_nb_moves);
		ft_printf("Congratulations!!\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		free_map(vars);
		exit(0);
	}
	else if (vars->map[new_i][new_j] != '1' && vars->map[new_i][new_j] != 'E')
		vars->map[new_i][new_j] = 'P';
	else
		return (0);
	vars->map[t[0]][t[1]] = '0';
	return (1);
}

int	update_map(int direction, t_vars *vars)
{
	int	t[2];

	t[0] = 0;
	while (t[0] < vars->height)
	{
		t[1] = 0;
		while (t[1] < vars->width)
		{
			change_girl(vars, direction);
			if (vars->map[t[0]][t[1]] == 'P' && direction == 1)
				return (change_position(t, t[0] - 1, t[1], vars));
			else if (vars->map[t[0]][t[1]] == 'P' && direction == 2)
				return (change_position(t, t[0] + 1, t[1], vars));
			else if (vars->map[t[0]][t[1]] == 'P' && direction == 3)
				return (change_position(t, t[0], t[1] - 1, vars));
			else if (vars->map[t[0]][t[1]] == 'P' && direction == 4)
				return (change_position(t, t[0], t[1] + 1, vars));
			t[1]++;
		}
		t[0]++;
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	x;

	x = 0;
	if (keycode == 13)
		x = update_map(1, vars);
	else if (keycode == 1)
		x = update_map(2, vars);
	else if (keycode == 0)
		x = update_map(3, vars);
	else if (keycode == 2)
		x = update_map(4, vars);
	else if (keycode == 53)
	{
		free_map(vars);
		ft_printf("Exit\n");
		exit(0);
	}
	if (x != 0)
	{
		mlx_clear_window(vars->mlx, vars->mlx_win);
		draw_map(*vars);
		put_movements(vars);
		free (vars->s);
	}
	return (x);
}

int	mouse_hook(t_vars *vars)
{
	free_map(vars);
	ft_printf("Exit\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		return (error_msg(&vars, -1));
	else if (ac > 2)
		return (error_msg(&vars, -2));
	vars.height = 0;
	vars.width = -1;
	vars.error = 1;
	if (get_map(av[1], &vars) != 1 || check_map(&vars) != 1)
		return (error_msg(&vars, vars.error));
	else
	{
		vars.mlx = mlx_init();
		if (images_init(&vars) != 1)
			return (error_msg(&vars, vars.error));
		vars.mlx = draw_map(vars);
		mlx_hook(vars.mlx_win, 2, 1L << 0, key_hook, &vars);
		mlx_hook(vars.mlx_win, 17, 0, mouse_hook, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
