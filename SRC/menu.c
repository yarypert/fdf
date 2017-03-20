#include "fdf.h"

void	menu_border(t_ptr *ptr)
{
	int color;
	color = 0x00FFFF;
	ptr->iso_xy = (int *)malloc(sizeof(int) * 2);
	ptr->iso_xy2 = (int *)malloc(sizeof(int) * 2);
	ptr->iso_xy[0] = 0;
	ptr->iso_xy[1] = (SIZE_Y / 4) - 5;
	ptr->iso_xy2[0] = SIZE_X;
	ptr->iso_xy2[1] = (SIZE_Y / 4) - 5;
	line_menu(ptr,color);
	ptr->iso_xy[0] = 0;
	ptr->iso_xy[1] = (SIZE_Y / 4) + 5;
	ptr->iso_xy2[0] = SIZE_X;
	ptr->iso_xy2[1] = (SIZE_Y / 4) + 5;
	line_menu(ptr,color);
	color = 0x0000FF;
	ptr->iso_xy[0] = 0;
	ptr->iso_xy[1] = SIZE_Y / 4;
	ptr->iso_xy2[0] = SIZE_X;
	ptr->iso_xy2[1] = SIZE_Y / 4;
	line_menu(ptr,color);
}

void	menu_bkg(t_ptr *ptr)
{
	int x;
	int y;
	int i;
	int j;
	int color;
	x = SIZE_X;
	y = (SIZE_Y / 4) + 10;
	i = 0;
	color = 0x000000;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			mlx_pix_img(ptr, i, j, color);
			j++;
		}
		i++;
	}
	menu_border(ptr);
}

void	line_menu(t_ptr *ptr, int color)
{
	t_init	i;

	line_init(&i, *ptr);
	while (1)
	{
		mlx_pix_img(ptr, ptr->iso_xy[0], ptr->iso_xy[1], color);
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

void	menu_string(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, SIZE_Y / 20, 0xFFFFFF, "<<      +       >>  Increase Z coordinates");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, (SIZE_Y / 20) * 2, 0xFFFFFF, "<<      -       >>  Decrease Z coordinates");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, (SIZE_Y / 20) * 3, 0xFFFFFF, "<<  Up Arrow    >>  Move Up");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, (SIZE_Y / 20) * 4, 0xFFFFFF, "<< Down Arrow   >>  Move Down");

	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, SIZE_Y / 20, 0xFF0000, "<<      +       >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, (SIZE_Y / 20) * 2, 0xFF0000, "<<      -       >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, (SIZE_Y / 20) * 3, 0xFF0000, "<<  Up Arrow    >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 20, (SIZE_Y / 20) * 4, 0xFF0000, "<< Down Arrow   >>");




	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, SIZE_Y / 20, 0xFFFFFF, "|");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, (SIZE_Y / 20) * 2, 0xFFFFFF, "|");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, (SIZE_Y / 20) * 3, 0xFFFFFF, "|");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, (SIZE_Y / 20) * 4, 0xFFFFFF, "|");



	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 20), SIZE_Y / 20, 0xFFFFFF, "<< Left Arrow   >> Move Left");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 20), SIZE_Y / 20 * 2, 0xFFFFFF, "<< Right Arrow  >> Move Right");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 20), SIZE_Y / 20 * 3, 0xFFFFFF, "<< ESC or Cross >> Exit");

	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 20), SIZE_Y / 20, 0xFF0000, "<< Left Arrow   >>");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 20), SIZE_Y / 20 * 2, 0xFF0000, "<< Right Arrow  >>");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 20), SIZE_Y / 20 * 3, 0xFF0000, "<< ESC or Cross >>");

}
