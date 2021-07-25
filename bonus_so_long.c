#include "so_long.h"

void	ft_img(t_data *img)
{
	char	*pic[11];
	int		width;
	int		height;

	pic[0] = "./png 64x64/seaweed.xpm";
	pic[1] = "./png 64x64/shell.xpm";
	pic[2] = "./png 64x64/mermaid_2.xpm";
	pic[3] = "./png 64x64/home.xpm";
	pic[4] = "./png 64x64/blue.xpm";
	pic[5] = "./png 64x64/water.xpm";
	pic[6] = "./png 64x64/sea-monster.xpm";
	pic[7] = "./png 64x64/count.xpm";
	pic[8] = "./png 64x64/shell_2.xpm";
	pic[9] = "./png 64x64/mermaid.xpm";
	img->wall = mlx_xpm_file_to_image(img->mlx, pic[0], &width, &height);
	img->collect = mlx_xpm_file_to_image(img->mlx, pic[1], &width, &height);
	img->player = mlx_xpm_file_to_image(img->mlx, pic[2], &width, &height);
	img->exit = mlx_xpm_file_to_image(img->mlx, pic[3], &width, &height);
	img->background = mlx_xpm_file_to_image(img->mlx, pic[4], &width, &height);
	img->water = mlx_xpm_file_to_image(img->mlx, pic[5], &width, &height);
	img->monster = mlx_xpm_file_to_image(img->mlx, pic[6], &width, &height);
	img->counter = mlx_xpm_file_to_image(img->mlx, pic[7], &width, &height);
	img->animate = mlx_xpm_file_to_image(img->mlx, pic[8], &width, &height);
	img->an_P = mlx_xpm_file_to_image(img->mlx, pic[9], &width, &height);
}

int	ft_exit (void)
{
	write (1, "\033[0;35mGAME IS OVER!\n", 22);
	exit (0);
}

void	ft_start(t_data *img)
{
	img->win_width = img->map_width * img->icon_size;
	img->win_height = img->map_height * img->icon_size;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->win_width, \
		img->win_height, "So Long");
	img->img = mlx_new_image(img->mlx, img->win_width, img->win_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	ft_img(img);
	ft_put(img);
	mlx_loop_hook(img->mlx, ft_put, img);
	mlx_hook(img->mlx_win, 17, 1L << 0, ft_exit, img);
	mlx_hook(img->mlx_win, 2, 1L << 0, ft_keycode, img);
	mlx_loop(img->mlx);
}

void	ft_init(t_data *img)
{
	img->pos_of_P_x = 0;
	img->pos_of_P_y = 0;
	img->collection_count = 0;
	img->C_count = 0;
	img->E_count = 0;
	img->P_count = 0;
	img->empt_count = 0;
	img->wall_count = 0;
	img->steps = 0;
	img->map_width = 0;
	img->map_height = 0;
	img->win_width = 0;
	img->win_height = 0;
	img->icon_size = 64;
	img->map = NULL;
	img->mlx = NULL;
	img->mlx_win = NULL;
	img->img = NULL;
	img->time = 0;
	img->two_time = 0;
}

int	main(int argc, char **argv)
{
	t_data	*img;
	int		i;

	i = -1;
	img = NULL;
	if (argc != 2)
		ft_error("\033[0;31mMap is not found!");
	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		ft_error("\033[0;31mERROR!\n");
	ft_init(img);
	ft_read_map(img, argv);
	ft_map_check(img);
	ft_start(img);
	while (img->map[++i])
		free(img->map[i]);
	free(img);
}
