
/* void	flood_fill(t_data *data, char **map, int x, int y)
{
	int	i;

	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	i = 0;
	if (x >= data->env->map_size[0] - 1 || \
	y >= data->env->map_size[1] - 1 || !is_valid_pos(map, x, y))
		exit_error(MAP_ERR, data);
	map[y][x] = 'X';
	while (i < 8)
	{
		flood_fill(data, map, x + data->parser->x_moves[i], y + data->parser->y_moves[i]);
		i++;
	}
} */

typedef struct  s_point
{
    int x;
    int y;
}     

void  flood_fill(char **tab, t_point size, t_point begin);


int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");


	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}