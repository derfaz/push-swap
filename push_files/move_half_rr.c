#include "../headers/push.h"
#include "../headers/libft.h"

void	after_only(t_ab *new_ab, t_dlist *src, char **text2)
{
	src = s_lst(src);
	src_to_ab(new_ab, src);
	if (src == new_ab->pa)
		*text2 = ft_strjoin_free(*text2, "sa\n", 1, 0);
	else
		*text2 = ft_strjoin_free(*text2, "sb\n", 1, 0);
}

static int	only_s(int size, t_dlist *src, t_ab *new_ab)
{
	t_dlist	*tmp;

	if (size == 2)
		return (1);
	tmp = dup_lst(src);
	if (is_sort(s_lst(tmp), new_ab))
	{
		clear_lst(tmp);
		return (1);
	}
	clear_lst(tmp);
	return (0);
}

t_dlist	*find_src2(t_ab *new_ab)
{
	if (!(new_ab->pa))
		return (new_ab->pb);
	else
		return (new_ab->pa);
}

void	set_bsort(t_ab *ab)
{
	if (ab->pb && ft_find_bot_elem(ab->pb)->data == min_ab(ab))
		ft_find_bot_elem(ab->pb)->bsort = 1;
}

t_ab	*move_half_rr(t_ab *new_ab, t_ab **ab,
					   char **text, t_dlist **chunk_lst)
{
	t_size_mid	sm;
	t_dlist		*src;
	char		*text2;

	text2 = 0;
	src = find_src2(new_ab);
	sm.size = lst_size(src);
	if (is_sort(src, new_ab))
		return (new_ab);
	if (only_s(sm.size, src, new_ab))
	{
		after_only(new_ab, src, &text2);
		exec_text2(text, *ab, text2);
		ft_memdel((void **)&text2);
		return (new_ab);
	}
	sm.mid = find_mid_num(src, sm.size);
	*chunk_lst = add_chunk(sm, new_ab, &text2, chunk_lst);
	set_bsort(*ab);
	exec_text2(text, *ab, text2);
	check_rr(ab, *chunk_lst, text, sm.mid);
	src = find_new_chunk(sm.size, text2, *ab, sm.mid);
	ft_memdel((void **)&text2);
	find_new_ab(&new_ab, src, *ab);
	return (move_half_rr(new_ab, ab, text, chunk_lst));
}
