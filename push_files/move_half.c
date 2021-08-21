#include "../headers/push.h"
#include "../headers/libft.h"

void	move_half3a1(t_dlist *list, t_ab *ab, char **text)
{
	if (list->data > list->next->next->data)
	{
		ab->pa = rr_lst(ab->pa);
		*text = ft_strjoin_free(*text, "rra\n", 1, 0);
	}
	else
	{
		ab->pa = s_lst(ab->pa);
		ab->pa = r_lst(ab->pa);
		*text = ft_strjoin_free(*text, "sa\nra\n", 1, 0);
	}
}

void	move_half3a(t_dlist *list, t_ab *ab, char **text)
{
	if (list->next->data > list->data
		&& list->next->data > list->next->next->data)
	{
		move_half3a1(list, ab, text);
		return ;
	}
	else if (list->next->data < list->next->next->data
		&& list->data > list->next->data && list->data > list->next->next->data)
	{
		ab->pa = r_lst(ab->pa);
		*text = ft_strjoin_free(*text, "ra\n", 1, 0);
		return ;
	}
	else if (list->data < list->next->next->data)
	{
		ab->pa = s_lst(ab->pa);
		*text = ft_strjoin_free(*text, "sa\n", 1, 0);
		return ;
	}
	ab->pa = r_lst(ab->pa);
	ab->pa = s_lst(ab->pa);
	*text = ft_strjoin_free(*text, "ra\nsa\n", 1, 0);
}

void	move_half23(int size, t_dlist *src, t_ab *ab, char **text)
{
	if (size == 2 || (size == 3 && ft_find_bot_elem(src)->data
			> src->data && ft_find_bot_elem(src)->data > src->next->data))
	{
		src = s_lst(src);
		src_to_ab(ab, src);
		if (src == ab->pa)
			*text = ft_strjoin_free(*text, "sa\n", 1, 0);
		else
			*text = ft_strjoin_free(*text, "sb\n", 1, 0);
	}
	else
		move_half3a(ab->pa, ab, text);
}

t_dlist	**move_half(t_ab *ab, char **text, int ddata)
{
	t_size_mid		sm;
	static t_dlist	*chunk_lst = 0;
	t_dlist			*tmp;
	t_dlist			*src;

	src = find_src(ab, ddata);
	sm.size = lst_size(src);
	if (is_sort(src, ab))
		return (&chunk_lst);
	if (sm.size == 2 || sm.size == 3)
	{
		move_half23(sm.size, src, ab, text);
		return (&chunk_lst);
	}
	tmp = dup_lst(src);
	tmp = srt_part(tmp);
	sm.mid = find_elem(tmp, sm.size / 2)->data;
	clear_lst(tmp);
	chunk_lst = add_chunk1(sm, ab, text, &chunk_lst);
	move_half(ab, text, sm.mid);
	return (&chunk_lst);
}
