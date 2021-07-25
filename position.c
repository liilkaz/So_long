#include "so_long.h"

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (0);
}

void	ft_action(t_data *img, int y, int x)
{
	img->map[img->pos_of_P_y][img->pos_of_P_x] = '0';
	if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] != '1')
	{
		if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] != 'E')
		{
			if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] == 'C')
			{
				img->collection_count++;
				write(1, "\033[0;33mYou collected 🐚!\n", 28);
			}	
			img->pos_of_P_x += x;
			img->pos_of_P_y += y;
			write(1, "\033[0;32msteps: \033[0m", 19);
			ft_putnbr_fd(++img->steps, 1);
			write(1, "\n", 1);
		}
		else if (img->collection_count == img->C_count)
		{
			write (1, "\033[0;33mYOU ARE WIN!\n", 21);
			ft_exit();
		}
	}
	img->map[img->pos_of_P_y][img->pos_of_P_x] = 'P';
	ft_position(img, img->pos_of_P_y, img->pos_of_P_x);
	ft_position(img, img->pos_of_P_y - y, img->pos_of_P_x - x);
}

int	ft_keycode(int keycode, t_data *img)
{
	if (keycode == 53)
		ft_exit();
	else if (keycode == 13)
		ft_action(img, -1, 0);
	else if (keycode == 1)
		ft_action(img, 1, 0);
	else if (keycode == 0)
		ft_action(img, 0, -1);
	else if (keycode == 2)
		ft_action(img, 0, 1);
	return (0);
}

void	ft_position(t_data *img, int hei, int wid)
{
	int	x;
	int	y;

	x = wid * img->icon_size;
	y = hei * img->icon_size;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->background, x, y);
	if (img->map[hei][wid] == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->wall, x, y);
	else if (img->map[hei][wid] == 'C')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->collect, x, y);
	else if (img->map[hei][wid] == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, x, y);
	else if (img->map[hei][wid] == 'P')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player, x, y);
		img->pos_of_P_y = hei;
		img->pos_of_P_x = wid;
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->water, x, y);
}

int	ft_put(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_width)
			ft_position(img, y, x++);
		y++;
	}
	return (0);
}
