#include "../headers/push.h"
#include "../headers/libft.h"

void	chunk_move(t_dlist *new_chunk, t_ab **ab, char **text)
{
	t_dlist	*src;
	t_dlist	*tmp;

	src = find_src(*ab, new_chunk->data);
	tmp = new_chunk;
	if (src == (*ab)->pa)
	{
		while (tmp)
		{
			**ab = p_lst((*ab)->pa, (*ab)->pb, *ab);
			*text = ft_strjoin_free(*text, "pb\n", 1, 0);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			**ab = p_lst((*ab)->pb, (*ab)->pa, *ab);
			*text = ft_strjoin_free(*text, "pa\n", 1, 0);
			tmp = tmp->next;
		}
	}
	clear_lst(new_chunk);
}

void	chunk_sort(t_dlist *new_chunk, t_dlist **chunk_lst,
				   t_ab **ab, char **text)
{
	if (!(*chunk_lst) && find_src(*ab, new_chunk->data)
		== (*ab)->pb)
	{
		chunk_move(new_chunk, ab, text);
		return ;
	}
	if (*chunk_lst && find_src(*ab, new_chunk->data)
		== find_src(*ab, (*chunk_lst)->data))
	{
		chunk_move(new_chunk, ab, text);
		return ;
	}
	else
		clear_lst(new_chunk);
}

t_dlist	*malloc_chunk_par(t_dlist **chunk_lst, t_ab *ab)
{
	t_dlist	*new;
	t_dlist	*src;

	src = find_src(ab, (*chunk_lst)->data);
	if ((*chunk_lst)->next)
		new = dup_part_lst2(find_data_elem
				(src, (*chunk_lst)->data), (*chunk_lst)->len);
	else
		new = dup_part_lst2(find_data_elem
				(src, (*chunk_lst)->data), (*chunk_lst)->len);
	return (new);
}

t_dlist	*find_new_chunk(int size, char *text2, t_ab *ab, int mid)
{
	t_dlist	*src;
	t_dlist	*fake_chunk_lst;
	t_dlist	*new_chunk;

	while (text2 && *text2)
	{
		if (*text2 == 'p')
			size--;
		text2++;
	}
	src = find_src(ab, mid);
	fake_chunk_lst = ft_create_elem(src->data);
	fake_chunk_lst->len = size;
	new_chunk = malloc_chunk_par(&fake_chunk_lst, ab);
	clear_lst(fake_chunk_lst);
	return (new_chunk);
}

void	find_new_ab(t_ab **new_ab, t_dlist *new_chunk, t_ab *ab)
{
	t_dlist	*src;

	src = find_src(ab, new_chunk->data);
	clear_ab(*new_ab);
	(*new_ab) = (t_ab *)malloc(sizeof(t_ab));
	if (src == ab->pa)
	{
		(*new_ab)->pa = new_chunk;
		(*new_ab)->pb = 0;
	}
	else
	{
		(*new_ab)->pb = new_chunk;
		(*new_ab)->pa = 0;
	}
}
