#include "../headers/push.h"
#include "../headers/libft.h"

int	lst_size(t_dlist *list)
{
	int	size;

	if (!list)
		return (0);
	size = 1;
	while (list->next)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_dlist	*find_elem(t_dlist *list, int index)
{
	if (index == 0)
		return (list);
	if (index < 0 || index > lst_size(list) - 1)
		return (0);
	while (index--)
		list = list->next;
	return (list);
}

t_dlist	*find_data_elem(t_dlist *src, int ddata)
{
	if (!src)
		return (0);
	while (ddata != src->data)
		src = src->next;
	return (src);
}
