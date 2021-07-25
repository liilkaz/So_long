#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "Get_Next_Line/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;

	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
	void	*background;
	void	*water;
	void	*monster;

	void	*counter;
	void	*animate;
	void	*an_P;

	int		map_width;
	int		map_height;
	int		icon_size;
	char	**map;

	int		win_width;
	int		win_height;

	int		pos_of_P_y;
	int		pos_of_P_x;

	int		collection_count;
	int		C_count;
	int		E_count;
	int		P_count;
	int		M_count;
	int		empt_count;
	int		wall_count;
	int		steps;

	int		time;
	int		two_time;

}				t_data;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
void	ft_wall_check(t_data *img);
void	ft_map_check(t_data *img);
int		ft_strlen_line(char **str);
char	**make_map(t_list **head, int size);
void	ft_read_map(t_data *img, char **argv);
void	ft_action(t_data *img, int y, int x);
int		ft_keycode(int keycode, t_data *img);
void	ft_position(t_data *img, int hei, int wid);
int		ft_put(t_data *img);
int		ft_error(char *str);
int		ft_exit (void);
char	*ft_itoa(int n);
void	ft_output_steps(t_data *img);
void	ft_output_steps_img(t_data *img);
void	ft_animation(t_data *img, int i, int x, int y);
void	ft_for_message(t_data *img, int i);
void	ft_map_elem(t_data *img, int y, int x);

#endif
