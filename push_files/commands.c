#include "../headers/push.h"
#include "../headers/libft.h"

t_dlist	*s_lst(t_dlist *list)
{
	t_dlist	*old2;

	if (list->next)
	{
		old2 = list->next;
		list->next = list->next->next;
		old2->prev = 0;
		old2->next = list;
		list->prev = old2;
		if (list->next)
			list->next->prev = list;
		return (old2);
	}
	return (list);
}

t_dlist	*r_lst(t_dlist *list)
{
	t_dlist	*new1;

	if (list->next)
	{
		new1 = list->next;
		list->prev = ft_find_bot_elem(list);
		ft_find_bot_elem(new1)->next = list;
		list->next = 0;
		new1->prev = 0;
		return (new1);
	}
	return (list);
}

t_dlist	*rr_lst(t_dlist *list)
{
	t_dlist	*new1;
	int		len;

	len = lst_size(list);
	if (list->next)
	{
		new1 = ft_find_bot_elem(list);
		ft_find_bot_elem(list)->prev->next = 0;
		new1->prev = 0;
		new1->next = list;
		if (len == 2 && new1->next)
		{
			new1->next->next = 0;
			new1->next->prev = new1;
		}
		else
		{
			list->next->prev->prev = new1;
			new1->next->prev = new1;
		}
		return (new1);
	}
	return (list);
}

static t_ab	p_lst2(t_dlist *src, t_dlist *dst,
					  t_ab *old_ab, t_dlist	*old_src2)
{
	t_ab	ab;

	if (src == old_ab->pa)
	{
		ab.pa = old_src2;
		ab.pb = src;
		if (ab.pa->next->prev)
			ab.pa->next->prev->prev = 0;
	}
	else
	{
		ab.pb = old_src2;
		ab.pa = src;
	}
	return (ab);
}

t_ab	p_lst(t_dlist *src, t_dlist *dst, t_ab *old_ab)
{
	t_dlist	*old_src2;

	old_src2 = src->next;
	if (old_src2)
		old_src2->prev = 0;
	src->next = dst;
	if (dst)
	{
		dst->prev = src;
		if (dst->next)
			dst->next->prev = dst;
	}
	return (p_lst2(src, dst, old_ab, old_src2));
}
