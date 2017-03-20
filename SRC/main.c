#include "fdf.h"

int		main(int argc, char **argv)
{
	t_ptr ptr;
	ptr.x = 0;
	ptr.y = 0;
	ptr.cst3 = 5;
	if (argc == 2)
	{
		ptr.coord = parse(read_file(argv[1]), &ptr.count_line, &ptr.count_column);
		ptr.max_z = max_z(ptr);
		ptr.max_coord = max_coord(ptr);
		ptr.cst2 = 0.001682765 * powf(ptr.max_coord, 2) - (0.438691 * ptr.max_coord) + 21.7276;
		draw_image(argv[1], ptr);
		return(0);
	}
	ft_error("Not enough arguments");
	return (0);
}
