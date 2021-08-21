#include "../headers/push.h"
#include "../headers/libft.h"

static	t_dlist	*move_bot(t_dlist *list, t_dlist *tmp)
{
	t_dlist	*cut;
	t_dlist	*new;

	if (tmp == list)
		return (r_lst(list));
	cut = tmp;
	new = list;
	while (list->next->data != tmp->data)
		list = list->next;
	list->next = list->next->next;
	list->next->prev = list;
	cut->prev = ft_find_bot_elem(list);
	ft_find_bot_elem(list)->next = cut;
	cut->next = 0;
	return (new);
}

static	t_dlist	*move_top(t_dlist *list, t_dlist *tmp)
{
	t_dlist	*old1;

	old1 = list;
	if (tmp == ft_find_bot_elem(list))
		return (rr_lst(list));
	while (list->next->data != tmp->data)
		list = list->next;
	list->next = list->next->next;
	if (list->next)
		list->next->prev = list;
	tmp->prev = 0;
	tmp->next = old1;
	old1->prev = tmp;
	old1->next->prev = old1;
	old1->next->prev->prev = tmp;
	return (tmp);
}

t_dlist	*srt_left_check(t_dlist *list, int mid_num)
{
	t_dlist	*tmp;
	t_dlist	*tmp_next;

	tmp = list;
	while (tmp->data != mid_num)
	{
		if (tmp->data > mid_num)
		{
			tmp_next = tmp->next;
			list = move_bot(list, tmp);
			tmp = tmp_next;
		}
		else
			tmp = tmp->next;
	}
	return (list);
}

t_dlist	*srt_right_check(t_dlist *list, int mid_num)
{
	t_dlist	*tmp;
	t_dlist	*tmp_next;

	tmp = ft_find_bot_elem(list);
	while (tmp->data != mid_num)
	{
		if (tmp->data < mid_num)
		{
			tmp_next = tmp->prev;
			list = move_top(list, tmp);
			tmp = tmp_next;
		}
		else
			tmp = tmp->prev;
	}
	return (list);
}
