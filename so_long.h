/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:25:06 by oessamdi          #+#    #+#             */
/*   Updated: 2022/02/17 12:32:28 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_vars
{
	char	**map;
	char	*s;
	int		error;
	int		width;
	int		height;
	int		nb_p;
	int		nb_c;
	int		nb_e;
	void	*mlx;
	void	*mlx_win;
	void	*img_g;
	void	*img_gr;
	void	*img_gl;
	void	*img_w;
	void	*img_c;
	void	*img_el;
	void	*img_eo;
	void	*img_bg;
}				t_vars;
int		g_nb_moves;
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd, int *x);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putchar(char c, int *n);
void	ft_putstr(char *s, int *n);
void	ft_putnbr(int n, int *np);
void	ft_putnbrbase(unsigned int nb, const char *base, int *n);
int		ft_printf(const char *str, ...);
int		compteur(const char *file_name, t_vars *maps);
int		get_map(const char *file_name, t_vars *maps);
int		check_map(t_vars *maps);
int		free_map(t_vars *maps);
void	*draw_map(t_vars vars);
void	change_girl(t_vars *vars, int direction);
int		images_init(t_vars *vars);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
int		set_error(t_vars *vars, int er);
int		error_msg(t_vars *vars, int error);
void	put_movements(t_vars *vars);

#endif