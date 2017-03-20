#include "fdf.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 69)
		hook_sub(ptr);
	else if (keycode == 78)
		hook_add(ptr);
	else if (keycode == 123)//gauche
		ptr->x -= 10;
	else if (keycode == 124)//droite
		ptr->x += 10;
	else if (keycode == 125)//down
		ptr->y += 10;
	else if (keycode == 126)//up*/
		ptr->y -= 10;
	else if (keycode == 116)//pageup
		ptr->cst2++;
	else if (keycode == 121)//pagedown
		pagedown(ptr);
	else if (keycode == 15)
		reset(ptr);
	refresh(ptr);
	return (0);
}

void	reset(t_ptr *ptr)
{
	ptr->y = 0;
	ptr->x = 0;
	ptr->cst2 = 0.001682765 * powf(ptr->max_coord, 2) - (0.438691 * ptr->max_coord) + 21.7276;
	ptr->cst3 = 5;
}

int		exit_cross(void)
{
	exit(0);
	return(0);
}

void	pagedown(t_ptr *ptr)
{
		if (ptr->cst2 <= 1)
			ptr->cst2 = ptr->cst2;
		else
			ptr->cst2--;
}

void	hook_add(t_ptr *ptr)
{
	if (ptr->cst3 > 5)
		ptr->cst3 = ptr->cst3 + 0.4;
	else
		ptr->cst3 = ptr->cst3 + 0.1;
}

void	hook_sub(t_ptr *ptr)
{
	if (ptr->cst3 > 5)
		ptr->cst3 = ptr->cst3 - 0.4;
	else if (ptr->cst3 > 0.2)
		ptr->cst3 = ptr->cst3 - 0.1;
	else
		ptr->cst3 = ptr->cst3;
}

int		refresh(t_ptr *ptr)
{
	//mlx_clear_window(ptr->mlx, ptr->win);
	mlx_destroy_image(ptr->mlx, ptr->img);
	ptr->img = mlx_new_image(ptr->mlx, SIZE_X,SIZE_Y);
	ptr->bts = mlx_get_data_addr(ptr->img, &(ptr->bpp), &(ptr->size_line), &(ptr->endian));
	put_iso_pix(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	menu_string(ptr);
	return (0);
}
