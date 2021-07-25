#include "so_long.h"

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (0);
}

void	ft_output_steps(t_data *img)
{
	write(1, "\033[0;32msteps: \033[0m", 19);
	ft_putnbr_fd(++img->steps, 1);
	write(1, "\n", 1);
}

void	ft_output_steps_img(t_data *img)
{
	char	*step;

	step = ft_itoa(img->steps);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->counter, \
						img->win_width * 0.9, img->win_height * 0.9);
	mlx_string_put(img->mlx, img->mlx_win, img->win_width * 0.9, \
						img->win_height * 0.9, 0x00FF0000, "STEPS:");
	mlx_string_put(img->mlx, img->mlx_win, img->win_width * 0.943, \
				img->win_height * 0.9, 0x00000000, step);
	free(step);
}

void	ft_animation(t_data *img, int i, int x, int y)
{
	if (i == 1)
	{
		if (img->two_time % 2 == 0)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->collect, x, y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->animate, x, y);
	}
	else
	{
		if (img->two_time % 2 == 0)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->player, x, y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->an_P, x, y);
	}
}

void	ft_for_message(t_data *img, int i)
{
	if (i == 1)
	{
		if (img->collection_count == img->C_count)
		{
			ft_output_steps(img);
			write (1, "\033[0;33mYOU ARE WIN!\n", 21);
			ft_exit();
		}
		else
			write (1, "\033[0;34mYou can't go out without shells!\n", 41);
	}
	else
	{
		write (1, "\033[0;31mOops! The monster defeated you!\n", 40);
		write (1, "YOU LOSE!\n", 10);
		ft_exit();
	}
}
