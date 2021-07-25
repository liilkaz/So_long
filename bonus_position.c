#include "so_long.h"

void	ft_map_elem(t_data *img, int y, int x)
{
	if (img->map[y][x] == 'E')
		img->E_count++;
	else if (img->map[y][x] == 'C')
		img->C_count++;
	else if (img->map[y][x] == 'P')
		img->P_count++;
	else if (img->map[y][x] == '0')
		img->empt_count++;
	else if (img->map[y][x] == 'M')
		img->M_count++;
	else if (img->map[y][x] == '1')
		ft_wall_check(img);
	else
		ft_error("\033[0;31mInvalid characters in the map!\n");
}

void	ft_action(t_data *img, int y, int x)
{
	img->map[img->pos_of_P_y][img->pos_of_P_x] = '0';
	if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] != '1')
	{
		if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] != 'E' \
			&& img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] != 'M')
		{
			if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] == 'C')
			{
				img->collection_count++;
				write(1, "\033[0;33mYou collected 🐚!\n", 28);
			}	
			img->pos_of_P_x += x;
			img->pos_of_P_y += y;
			ft_output_steps(img);
		}
		else if (img->map[img->pos_of_P_y + y][img->pos_of_P_x + x] == 'E')
			ft_for_message(img, 1);
		else
			ft_for_message(img, 0);
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
		ft_animation(img, 1, x, y);
	else if (img->map[hei][wid] == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, x, y);
	else if (img->map[hei][wid] == 'P')
	{
		ft_animation(img, 0, x, y);
		img->pos_of_P_y = hei;
		img->pos_of_P_x = wid;
	}
	else if (img->map[hei][wid] == 'M')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->monster, x, y);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->water, x, y);
	ft_output_steps_img(img);
}

int	ft_put(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->time++;
	if (img->time % 4 == 0)
		img->two_time++;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_width)
			ft_position(img, y, x++);
		y++;
	}
	return (0);
}
