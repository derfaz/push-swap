#include "../headers/push.h"
#include "../headers/libft.h"

t_dlist	*ft_create_elem(int data)
{
	t_dlist	*elem;

	elem = (t_dlist *)malloc(sizeof(t_dlist));
	elem->next = NULL;
	elem->prev = NULL;
	elem->data = data;
	elem->bsort = 0;
	elem->len = -1;
	return (elem);
}

t_dlist	*ft_add_top_elem(t_dlist *list, int data)
{
	t_dlist	*elem;

	elem = ft_create_elem(data);
	elem->next = list;
	elem->prev = 0;
	elem->data = data;
	list->prev = elem;
	return (elem);
}

t_dlist	*ft_find_bot_elem(t_dlist *list)
{
	if (!list)
		return (0);
	while (list->next != 0)
		list = list->next;
	return (list);
}

t_dlist	*ft_add_bottom_elem(t_dlist *list, int data)
{
	t_dlist	*elem;

	elem = ft_create_elem(data);
	elem->next = NULL;
	elem->prev = ft_find_bot_elem(list);
	ft_find_bot_elem(list)->next = elem;
	elem->data = data;
	return (list);
}
