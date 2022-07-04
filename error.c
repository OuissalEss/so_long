/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:47:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/02/17 11:15:41 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_error(t_vars *vars, int er)
{
	vars->error = er;
	return (er);
}

int	error_msg(t_vars *vars, int error)
{
	if (error == -1 || error == -2)
	{
		if (error == -1)
			ft_printf("Few arguments\n");
		else if (error == -2)
			ft_printf("Many arguments\n");
	}
	else
	{
		free_map(vars);
		if (vars->error == 2)
			ft_printf("File does not exist or empty\n");
		else if (vars->error == 3)
			ft_printf("Invalid map\n");
		else if (vars->error == 4)
			ft_printf("Invalid file name\n");
		else if (vars->error == 6)
			ft_printf("Image does not exist\n");
		else
			ft_printf("Error\n");
	}
	return (0);
}
