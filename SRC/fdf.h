/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:16:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/20 22:26:14 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define SIZE_X 800
# define SIZE_Y 800
# define TEST ft_putchar('a');

typedef struct	s_ptr
{
	int		bpp;
	char	*bts;
	int		size_line;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	int		count_column;
	int		count_line;
	float	max_coord;
	int		max_z;
	float	cst;
	float	cst2;
	float	cst3;
	int		*iso_xy;
	int		*iso_xy2;
	int		i;
	int		j;
	int		**coord;
	int		x;
	int		y;
}				t_ptr;

typedef	struct	s_init
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}				t_init;

void			line_init(t_init *i, t_ptr ptr);
void			mlx_pix_img(t_ptr *ptr, int x, int y, int color);
void			ft_error(char *str);
void			line(t_ptr *ptr, int color);
void			line_menu(t_ptr *ptr, int color);
void			draw_image(char *str, t_ptr ptr);
void			put_iso_pix(t_ptr *ptr);
void			line_len(int *count_column, int *count_line, char *str);
void			draw(t_ptr *ptr, int color);
void			menu_bkg(t_ptr *ptr);
void			menu_string(t_ptr *ptr);
void			hook_sub(t_ptr *ptr);
void			hook_add(t_ptr *ptr);
void			pagedown(t_ptr *ptr);
void			reset(t_ptr *ptr);

int				get_color(int c1, int c2, float med);
int				max_coord(t_ptr ptr);
int				max_z(t_ptr ptr);
int				key_hook(int keycode, t_ptr *ptr);
int				exit_cross(void);
int				**pick_nb(char *str, int **coord, int col, int line);
int				**parse(char *str, int *count_line, int *count_column);
int				*pix_iso_coord(int x, int y, int z, t_ptr ptr);
int				refresh(t_ptr *ptr);

char			*ft_strappend(char *str1, char *str2);
char			*read_file(char *file);

#endif
