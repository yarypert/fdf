#include "fdf.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 125)
	{
		ptr->cst3 = ptr->cst3 - 0.1;
	}
	else if (keycode == 126)
	{
		ptr->cst3 = ptr->cst3 + 0.1;
	}
		dprintf(1,"%f",ptr->cst3);
	refresh(ptr);
	return (0);
}

int		exit_cross(void)
{
	exit(0);
	return(0);
}

int		refresh(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	put_iso_pix(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	menu_string(ptr);
	return (0);
}
