#include "fdf.h"

int		main(int argc, char **argv)
{
	t_ptr ptr;

	ptr.cst3 = 5;
	if (argc == 2)
	{
		ptr.coord = parse(read_file(argv[1]), &ptr.count_line, &ptr.count_column);
		ptr.max_z = max_z(ptr);
		ptr.max_coord = max_coord(ptr);
		draw_image(argv[1], ptr);
		return(0);
	}
	ft_error("Not enough arguments");
	return (0);
}
