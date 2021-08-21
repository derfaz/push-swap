#include "../headers/push.h"
#include "../headers/libft.h"

t_dlist	*find_src(t_ab *ab, int ddata)
{
	t_dlist	*p;

	p = ab->pa;
	while (p && p->data != ddata)
		p = p->next;
	if (p)
		return (ab->pa);
	else
		return (ab->pb);
}

void	src_to_ab(t_ab *ab, t_dlist *src)
{
	if (ab->pa && (find_src(ab, src->next->data)
			== find_src(ab, ab->pa->data)))
		ab->pa = src;
	else
		ab->pb = src;
}

t_dlist	*malloc_chunk(t_dlist **chunk_lst, t_ab *ab)
{
	t_dlist	*new;
	t_dlist	*src;

	src = find_src(ab, (*chunk_lst)->data);
	if ((*chunk_lst)->next)
	{
		new = dup_part_lst2(find_data_elem
				(src, (*chunk_lst)->data), (*chunk_lst)->len);
		*chunk_lst = del_first(*chunk_lst);
	}
	else
	{
		new = dup_part_lst2
			(find_data_elem(src, (*chunk_lst)->data), (*chunk_lst)->len);
		*chunk_lst = del_first(*chunk_lst);
	}
	return (new);
}

int	is_sort(t_dlist *list, t_ab *ab)
{
	if (lst_size(list) <= 1)
		return (1);
	if (find_src(ab, list->data) == ab->pa)
	{
		while (list && list->next)
		{
			if (list->data > list->next->data)
				return (0);
			list = list->next;
		}
	}
	else
	{
		while (list && list->next)
		{
			if (list->data < list->next->data)
				return (0);
			list = list->next;
		}
	}
	return (1);
}

void	create_ab(t_ab *old_ab, t_ab **new_ab, t_dlist *chunk)
{
	if (find_src(old_ab, chunk->data) == old_ab->pb)
	{
		(*new_ab)->pa = 0;
		(*new_ab)->pb = chunk;
	}
	else
	{
		(*new_ab)->pb = 0;
		(*new_ab)->pa = chunk;
	}
}
