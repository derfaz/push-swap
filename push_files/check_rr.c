#include "../headers/push.h"
#include "../headers/libft.h"

void	check_rr_pa2(t_ab **ab, char **text)
{
	t_dlist	*fake_pa;
	int		lim;

	fake_pa = dup_lst((*ab)->pa);
	fake_pa->len = lst_size(fake_pa);
	lim = max_of_chunk(&fake_pa, *ab);
	while (ft_find_bot_elem((*ab)->pa)->data < lim)
	{
		(*ab)->pa = rr_lst((*ab)->pa);
		*text = ft_strjoin_free(*text, "rra\n", 1, 0);
	}
	clear_lst(fake_pa);
}

void	check_rr_pb2(t_ab **ab, char **text)
{
	t_dlist	*fake_pa;
	int		lim;

	fake_pa = dup_lst((*ab)->pb);
	fake_pa->len = lst_size(fake_pa);
	lim = min_of_chunk(&fake_pa, *ab);
	while (ft_find_bot_elem((*ab)->pb)->data > lim)
	{
		(*ab)->pb = rr_lst((*ab)->pb);
		*text = ft_strjoin_free(*text, "rrb\n", 1, 0);
	}
	clear_lst(fake_pa);
}

void	check_rr_pb1(t_ab **ab, char **text, t_dlist **chunk_lst, t_dlist *src)
{
	int	lim;

	lim = max_of_chunk(chunk_lst, *ab);
	while (ft_find_bot_elem(src)->data > lim)
	{
		(*ab)->pb = rr_lst((*ab)->pb);
		*text = ft_strjoin_free(*text, "rrb\n", 1, 0);
	}
}

void	check_rr_pa1(t_ab **ab, char **text, t_dlist **chunk_lst, t_dlist *src)
{
	int	lim;

	lim = min_of_chunk(chunk_lst, *ab);
	while (ft_find_bot_elem(src)->data < lim)
	{
		(*ab)->pa = rr_lst((*ab)->pa);
		*text = ft_strjoin_free(*text, "rra\n", 1, 0);
	}
}

void	check_rr(t_ab **ab, t_dlist *chunk_lst, char **text, int mid)
{
	t_dlist	*src;
	t_dlist	*tmp_pb;
	int		bsort1;

	tmp_pb = (*ab)->pb;
	bsort1 = def_bsort((*ab)->pb);
	(*ab)->pb = tmp_pb;
	src = find_src(*ab, mid);
	while (chunk_lst)
	{
		if (src == (*ab)->pb && src == find_src(*ab, chunk_lst->data))
			check_rr_pb1(ab, text, &chunk_lst, src);
		else if (src == (*ab)->pa && src == find_src(*ab, chunk_lst->data))
			check_rr_pa1(ab, text, &chunk_lst, src);
		else if (src == (*ab)->pa && src != find_src(*ab, chunk_lst->data)
			&& !is_sort((*ab)->pa, *ab))
			check_rr_pa2(ab, text);
		else if (src == (*ab)->pb && src != find_src(*ab, chunk_lst->data)
			&& !is_sort((*ab)->pb, *ab) && bsort1)
			check_rr_pb2(ab, text);
		chunk_lst = chunk_lst->next;
	}
}
