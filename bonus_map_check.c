#include "so_long.h"

void	ft_wall_check(t_data *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < img->map_width - 1)
	{
		if (img->map[0][x] != '1' || img->map[img->map_height - 1][x] != '1')
			ft_error("\033[0;31mOops! You can't play! Map is not valid!\n");
	}
	y = -1;
	while (++y < img->map_height - 1)
	{
		if (img->map[y][0] != '1' || img->map[y][img->map_width - 1] != '1')
			ft_error("\033[0;31mOops! You can't play! Map is not valid!\n");
	}
	y = 0;
	while (++y < img->map_height)
	{
		if (ft_strlen(img->map[y]) != (size_t) img->map_width)
			ft_error("\033[0;31mOops! You can't play! Map is not valid!\n");
	}	
}

void	ft_map_check(t_data *img)
{
	int	x;
	int	y;

	y = -1;
	while (img->map[++y])
	{
		x = -1;
		while (img->map[y][++x])
			ft_map_elem(img, y, x);
	}
	if (img->E_count < 1 || img->C_count < 1 || img->P_count != 1)
		ft_error("\033[0;31mOops! You can't play! Map is not valid!\n");
}

int	ft_strlen_line(char **str)
{
	int	line;

	line = 0;
	while (str[line])
		line++;
	return (line);
}

char	**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = -1;
	map = ft_calloc(size + 1, sizeof(char *));
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		free(tmp);
		tmp = tmp->next;
	}
	return (map);
}

void	ft_read_map(t_data *img, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	img->map = make_map(&head, ft_lstsize(head));
	img->map_width = ft_strlen(*img->map);
	img->map_height = ft_strlen_line(img->map);
}
