/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:47:35 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/17 14:51:47 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*pix_iso_coord(int x, int y, int z, t_ptr ptr)
{
	int	*iso_xy;
	ptr.cst = -1.5;
	ptr.cst2 = 0.001682765 * powf(ptr.max_coord, 2) - (0.438691 * ptr.max_coord) +  21.7276;
	if (ptr.max_z == 0)
		ptr.cst3 = 1;
	else
		ptr.cst3 = 5;
	iso_xy = (int *)malloc(sizeof(int) * 2);
	iso_xy[0] = ((ptr.cst * (-x) - ptr.cst * y) * (abs(ptr.cst) * ptr.cst2));
	iso_xy[1] = (((-z / ptr.cst3) + ((ptr.cst/2) * (-x)) + ((ptr.cst/2) * y)) * (abs(ptr.cst) * ptr.cst2));
	return(iso_xy);
}

void	put_iso_pix(t_ptr *ptr)
{
	ptr->i = 0;
	int color;
	while (ptr->i < ptr->count_line)
	{
		ptr->j = 0;
		while (ptr->j < ptr->count_column)
		{
			color = 0x222222;
			draw(ptr, color);
			ptr->j++;
		}
		ptr->i++;
	}
	menu_bkg(ptr);
}

void	draw(t_ptr *ptr, int color)
{
	if(ptr->j+1 < ptr->count_column && ptr->i < ptr->count_line)
	{
		if (ptr->coord[ptr->i][ptr->j] > 0 && ptr->coord[ptr->i][ptr->j + 1])
			color = 0xFF0000;
		ptr->iso_xy = pix_iso_coord(ptr->i, ptr->j, (ptr->coord[ptr->i][ptr->j] / 6), *ptr);
		ptr->iso_xy2 = pix_iso_coord(ptr->i, ptr->j + 1, (ptr->coord[ptr->i][ptr->j + 1] / 6), *ptr);
		line(ptr,color);
	}
	color = 0x222222;
	if(ptr->j < ptr->count_column && ptr->i + 1 < ptr->count_line)
	{
		if (ptr->coord[ptr->i][ptr->j] > 0 && ptr->coord[ptr->i + 1][ptr->j])
			color = 0xFF0000;
		ptr->iso_xy = pix_iso_coord(ptr->i, ptr->j, (ptr->coord[ptr->i][ptr->j] / 6), *ptr);
		ptr->iso_xy2 = pix_iso_coord(ptr->i + 1, ptr->j, (ptr->coord[ptr->i + 1][ptr->j] / 6), *ptr);
		line(ptr,color);
	}
}
