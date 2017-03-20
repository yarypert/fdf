#include "./fdf.h"

void		line_len(int *count_column, int *count_line, char *str)
{
	int i;
	int flag;
	i = 0;
	flag = 0;
	*count_line = 0;
	while (str[i] != '\0')
	{
		*count_column = 0;
		while (str[i] != '\n' && str[i])
		{
			if ((ft_isalnum(str[i])) && ((str[i + 1] == ' ') ||
						(str[i + 1] == '\n') || (str[i + 1] == '\0')))
				*count_column += 1;
			i++;
		}
		if (flag == 0)
			flag = *count_column;
		if (*count_column != flag)
			ft_error("file not valid");
		*count_line += 1;
		i++;
	}
}

int		**pick_nb(char *str, int **coord, int col, int line)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			coord[i][j] = ft_atoi(str + k);
			while (str[k] == '-' || str[k] == ',' || ft_isalnum(str[k]))
				k++;
			while (str[k] == ' ' || str[k] == '\n')
				k++;
			j++;
		}
		i++;
	}
	return (coord);
}

int		**parse(char *str, int *count_line, int *count_column)
{
	int i;
	int **coord;
	i = 0;
	line_len(count_column, count_line, str);
	coord = ((int **)malloc(sizeof(int *) * (*count_line)));
	while (i < *count_line)
	{
		coord[i] = ((int *)malloc((sizeof(int) * *count_column)));
		i++;
	}
	coord = pick_nb(str, coord, *count_column, *count_line);
	return (coord);
}

int		max_z(t_ptr ptr)
{
	int		i;
	int		j;
	ptr.max_z = 0;
	//coord[i][j]
	i = 0;
	while (i < ptr.count_line)
	{
		j = 0;
		while (j < ptr.count_column)
		{
			ptr.coord[i][j] = ptr.coord[i][j] * 10;
			if (ptr.max_z < ptr.coord[i][j])
				ptr.max_z = ptr.coord[i][j];
			j++;
		}
		i++;
	}
	return (ptr.max_z);
}

int		max_coord(t_ptr ptr)
{
	if (ptr.count_column < ptr.count_line)
		return (ptr.count_line);
	else if (ptr.count_column > ptr.count_line)
		return (ptr.count_column);
	else
		return (ptr.count_column);
}
