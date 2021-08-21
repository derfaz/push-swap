#include "../headers/push.h"
#include "../headers/libft.h"

void	check_chunk(t_dlist **chunk_lst, t_ab *ab, char **text)
{
	t_dlist	*new_chunk;
	char	*text2;
	t_ab	*new_ab;

	new_chunk = malloc_chunk(chunk_lst, ab);
	if (is_sort(new_chunk, ab))
	{
		chunk_sort(new_chunk, chunk_lst, &ab, text);
		push_till_ch_lst(&ab, chunk_lst, text);
	}
	else
	{
		text2 = 0;
		new_ab = (t_ab *)malloc(sizeof (t_ab));
		if (!new_ab)
			exit(0);
		create_ab(ab, &new_ab, new_chunk);
		new_ab = move_half_rr(new_ab, &ab, &text2, chunk_lst);
		*text = ft_strjoin_free(*text, text2, 1, 1);
		push_till_ch_lst(&ab, chunk_lst, text);
		clear_ab(new_ab);
	}
}

void	game(t_ab *ab, char **text)
{
	t_dlist	**chunk_lst;

	chunk_lst = move_half(ab, text, ab->pa->data);
	while (*chunk_lst)
		check_chunk(chunk_lst, ab, text);
}

void	exec_text2_end(t_ab *ab, char *text2)
{
	if (*text2 == 'r' && *(text2 + 1) == 'r' && *(text2 + 2) == 'a')
		rr_lst(ab->pa);
	else if (*text2 == 'r' && *(text2 + 1) == 'r' && *(text2 + 2) == 'b')
		rr_lst(ab->pb);
}

void	exec_text2(char **text, t_ab *ab, char *text2)
{
	*text = ft_strjoin_free(*text, text2, 1, 0);
	while (text2 && *text2)
	{
		if (*text2 == 's' && *(text2 + 1) == 'a')
			ab->pa = s_lst(ab->pa);
		else if (*text2 == 's' && *(text2 + 1) == 'b')
			ab->pb = s_lst(ab->pb);
		else if (*text2 == 'p' && *(text2 + 1) == 'a')
			*ab = p_lst(ab->pb, ab->pa, ab);
		else if (*text2 == 'p' && *(text2 + 1) == 'b')
			*ab = p_lst(ab->pa, ab->pb, ab);
		else if (*text2 == 'r' && *(text2 + 1) == 'a')
			ab->pa = r_lst(ab->pa);
		else if (*text2 == 'r' && *(text2 + 1) == 'b')
			ab->pb = r_lst(ab->pb);
		else
		{
			exec_text2_end(ab, text2);
			text2 += 4;
			return ;
		}
		text2 += 3;
	}
}

void	push_till_ch_lst(t_ab **ab, t_dlist **chunk_lst, char **text)
{
	if (*chunk_lst)
	{
		if (find_src(*ab, (*chunk_lst)->data) == (*ab)->pa)
		{
			while ((*ab)->pa->data != (*chunk_lst)->data)
			{
				**ab = p_lst((*ab)->pa, (*ab)->pb, *ab);
				*text = ft_strjoin_free(*text, "pb\n", 1, 0);
			}
		}
		else
		{
			while ((*ab)->pb->data != (*chunk_lst)->data)
			{
				**ab = p_lst((*ab)->pb, (*ab)->pa, *ab);
				*text = ft_strjoin_free(*text, "pa\n", 1, 0);
			}
		}
		return ;
	}
	while ((*ab)->pb)
	{
		**ab = p_lst((*ab)->pb, (*ab)->pa, *ab);
		*text = ft_strjoin_free(*text, "pa\n", 1, 0);
	}
}
