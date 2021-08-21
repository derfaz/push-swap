#include "../headers/push.h"
#include "../headers/libft.h"

t_dlist	*dup_lst(t_dlist *list)
{
	t_dlist	*new;

	new = ft_create_elem(list->data);
	while (list->next)
	{
		new = ft_add_bottom_elem(new, list->next->data);
		list = list->next;
	}
	return (new);
}

t_dlist	*dup_part_lst2(t_dlist *first, int len)
{
	t_dlist	*new;
	t_dlist	*tmp;

	if (first == 0)
		return (0);
	new = ft_create_elem(first->data);
	first = first->next;
	tmp = new;
	while (len-- > 1 && first)
	{
		tmp = ft_add_bottom_elem(tmp, first->data);
		first = first->next;
	}
	return (new);
}

void	clear_lst(t_dlist *list)
{
	t_dlist	*tmp;

	if (!list)
		return ;
	while (list->next)
	{
		tmp = ft_find_bot_elem(list);
		tmp->prev->next = 0;
		free(tmp);
	}
	while (list->prev)
	{
		list = list->prev;
		free(list->next);
	}
	free(list);
}

t_dlist	*del_first(t_dlist *list)
{
	t_dlist	*tmp;

	if (!list)
		return (NULL);
	tmp = list->next;
	free(list);
	if (tmp)
		tmp->prev = NULL;
	return (tmp);
}

void	clear_ab(t_ab *ab)
{
	if (ab && ab->pa)
	{
		clear_lst(ab->pa);
		ab->pa = 0;
	}
	if (ab && ab->pb)
	{
		clear_lst(ab->pb);
		ab->pb = 0;
	}
	if (ab)
	{
		free(ab);
		ab = 0;
	}
}
