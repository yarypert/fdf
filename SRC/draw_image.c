/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:29:57 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/17 14:51:32 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_init(t_init *i, t_ptr ptr)
{
	i->dx = abs(ptr.iso_xy2[0] - ptr.iso_xy[0]);
	i->sx = ptr.iso_xy[0] < ptr.iso_xy2[0] ? 1 : -1;
	i->dy = abs(ptr.iso_xy2[1] - ptr.iso_xy[1]);
	i->sy = ptr.iso_xy[1] < ptr.iso_xy2[1] ? 1 : -1;
	i->err = (i->dx > i->dy ? i->dx : -i->dy) / 2;
}

void	line(t_ptr *ptr,int color)
{
	t_init	i;

	line_init(&i, *ptr);
	while (1)
	{
		mlx_pix_img(ptr, (ptr->iso_xy[0] + (SIZE_X / 8) + ptr->x), (ptr->iso_xy[1] + (SIZE_Y / 2 + 140) + ptr->y), color);
		if (ptr->iso_xy[0] == ptr->iso_xy2[0] && ptr->iso_xy[1] == ptr->iso_xy2[1])
			return ;
		i.e2 = i.err;
		if (i.e2 > -i.dx)
		{
			i.err -= i.dy;
			ptr->iso_xy[0] += i.sx;
		}
		if (i.e2 < i.dy)
		{
			i.err += i.dx;
			ptr->iso_xy[1] += i.sy;
		}
	}
}

void	draw_image(char *str, t_ptr ptr)
{
	ptr.x = 0;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SIZE_X, SIZE_Y, str);
	mlx_hook(ptr.win, 17,(1L << 17),exit_cross,&ptr);
	mlx_hook(ptr.win, 2,(1L << 0), key_hook, &ptr);
	ptr.img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	ptr.bts = mlx_get_data_addr(ptr.img, &(ptr.bpp), &(ptr.size_line), &(ptr.endian));
	put_iso_pix(&ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	menu_string(&ptr);
	mlx_loop(ptr.mlx);
}

int createARGB(int A,int R, int G, int B)
{
	return ((A & 0xff) << 24) + ((R & 0xff) << 16) +
		((G & 0xff) << 8) + (B & 0xff);
}

void	mlx_pix_img(t_ptr *ptr, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x) + 2] = r;
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x) + 1] = g;
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x)] = b;
	}
}
