#include "../headers/push.h"
#include "../headers/libft.h"

t_dlist	*add_chunk1(t_size_mid sm, t_ab *ab,
					   char **text, t_dlist **chunk_lst)
{
	t_dlist	*nonsrc;
	int		arr[2];

	if (find_src(ab, sm.mid) == ab->pa)
	{
		nonsrc = ab->pb;
		check_is_last(nonsrc, arr);
		add_chunk_b1(sm.size, ab, sm.mid, text);
		nonsrc = ab->pb;
	}
	else
	{
		nonsrc = ab->pa;
		check_is_last(nonsrc, arr);
		add_chunk_a(sm.size, ab, sm.mid, text);
		nonsrc = ab->pa;
	}
	if (!(*chunk_lst))
		*chunk_lst = ft_create_elem(nonsrc->data);
	else
		*chunk_lst = ft_add_top_elem(*chunk_lst, nonsrc->data);
	find_len(chunk_lst, arr, nonsrc);
	return (*chunk_lst);
}

t_dlist	*add_chunk(t_size_mid sm, t_ab *ab,
					  char **text, t_dlist **chunk_lst)
{
	t_dlist	*nonsrc;
	int		arr[2];

	if (find_src(ab, sm.mid) == ab->pa)
	{
		nonsrc = ab->pb;
		check_is_last(nonsrc, arr);
		add_chunk_b(sm.size, ab, sm.mid, text);
		nonsrc = ab->pb;
	}
	else
	{
		nonsrc = ab->pa;
		check_is_last(nonsrc, arr);
		add_chunk_a(sm.size, ab, sm.mid, text);
		nonsrc = ab->pa;
	}
	if (!(*chunk_lst))
		*chunk_lst = ft_create_elem(nonsrc->data);
	else
		*chunk_lst = ft_add_top_elem(*chunk_lst, nonsrc->data);
	find_len(chunk_lst, arr, nonsrc);
	return (*chunk_lst);
}

int	find_mid_num(t_dlist *src, int size)
{
	t_dlist	*tmp;
	int		mid_num;

	tmp = dup_lst(src);
	tmp = srt_part(tmp);
	mid_num = find_elem(tmp, size / 2)->data;
	clear_lst(tmp);
	return (mid_num);
}
