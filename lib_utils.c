#include "so_long.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		buf = *lst;
		while (buf->next != NULL)
			buf = buf->next;
		buf->next = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			i;
	unsigned int	V;

	if (n < 0)
	{
		V = n * -1;
		write(fd, "-", 1);
	}
	else
		V = n;
	if (V >= 10)
		ft_putnbr_fd(V / 10, fd);
	i = (V % 10) + '0';
	write(fd, &i, 1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*buf;
	unsigned long	i;

	i = 0;
	buf = malloc(count * size);
	if (!buf)
		return (NULL);
	else
	{
		while (i < size * count)
		{
			buf[i] = 0;
			i++;
		}
	}
	return (buf);
}
