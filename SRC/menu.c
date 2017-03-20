#include "fdf.h"

void	menu_border(t_ptr *ptr)
{
	int color;
	color = 0xFF8800;
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
	color = 0xFF0000;
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
	x = SIZE_X;
	y = (SIZE_Y / 4) + 5;
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			mlx_pix_img(ptr, i, j, 0x200000);
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
	int i;
	i = 0;
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, SIZE_Y / 20 - 10, 0xFFFFFF, "      +       >>  Increase Z");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 2, 0xFFFFFF, "      -       >>  Decrease Z");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 3, 0xFFFFFF, "  Up Arrow    >>  Move Up");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 4, 0xFFFFFF, " Down Arrow   >>  Move Down");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 5, 0xFFFFFF, " ESC or Cross >>  Exit");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, SIZE_Y / 20 - 10, 0xFF0000, "      +       >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 2, 0xFF0000, "      -       >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 3, 0xFF0000, "  Up Arrow    >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 4, 0xFF0000, " Down Arrow   >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 25, (SIZE_Y / 20 - 10) * 5, 0xFF0000, " ESC or Cross >>");
	while (i++ < 5)
		mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, (SIZE_Y / 20 - 10) * i, 0xFFFFFF, "|");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), SIZE_Y / 20 - 10, 0xFFFFFF, " Left Arrow   >> Move Left");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 2, 0xFFFFFF, " Right Arrow  >> Move Right");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 3, 0xFFFFFF, " Page Up      >> Zoom In");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 4, 0xFFFFFF, " Page Down    >> Zoom Out");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 5, 0xFFFFFF, "      R       >> Reset Window");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), SIZE_Y / 20 - 10, 0xFF0000, " Left Arrow   >>");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 2, 0xFF0000, " Right Arrow  >>");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 3, 0xFF0000, " Page Up      >>");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 4, 0xFF0000, " Page Down    >>");
	mlx_string_put(ptr->mlx, ptr->win, (SIZE_X / 2) + (SIZE_X / 25), (SIZE_Y / 20 - 10) * 5, 0xFF0000, "      R       >>");
}
