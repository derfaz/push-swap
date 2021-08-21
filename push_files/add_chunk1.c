#include "../headers/push.h"
#include "../headers/libft.h"

void	add_chunk_b(int size, t_ab *ab, int mid_num, char **text)
{
	int	pcounter;

	pcounter = 0;
	while (pcounter < size / 2)
	{
		if (ab->pa->data < mid_num)
		{
			*ab = p_lst(ab->pa, ab->pb, ab);
			*text = ft_strjoin_free(*text, "pb\n", 1, 0);
			pcounter++;
		}
		else
		{
			ab->pa = r_lst(ab->pa);
			*text = ft_strjoin_free(*text, "ra\n", 1, 0);
		}
	}
}

void	add_chunk_a(int size, t_ab *ab, int mid_num, char **text)
{
	int	pcounter;

	pcounter = 0;
	while (((size % 2) && (pcounter < size / 2))
		|| (!(size % 2) && (pcounter < size / 2 - 1)))
	{
		if (ab->pb->data > mid_num)
		{
			*ab = p_lst(ab->pb, ab->pa, ab);
			*text = ft_strjoin_free(*text, "pa\n", 1, 0);
			pcounter++;
		}
		else
		{
			ab->pb = r_lst(ab->pb);
			*text = ft_strjoin_free(*text, "rb\n", 1, 0);
		}
	}
}
/*
void	add_chunk_b1(int size, t_ab *ab, int mid_num, char **text)
{
	int		pcounter;
	char	*tmp;

	tmp = NULL;
	pcounter = 0;
	while (pcounter < size / 2)
	{
		if (ab->pa->data < mid_num)
		{
			*ab = p_lst(ab->pa, ab->pb, ab);
			tmp = ft_strjoin_free(tmp, "pb\n", 1, 0);
			pcounter++;
		}
		else if (ft_find_bot_elem(ab->pa)->data < mid_num)
		{
			(*ab).pa = rr_lst((*ab).pa);
			*ab = p_lst(ab->pa, ab->pb, ab);
			tmp = ft_strjoin_free(tmp, "rra\npb\n", 1, 0);
			pcounter++;
		}
		else
		{
			ab->pa = r_lst(ab->pa);
			tmp = ft_strjoin_free(tmp, "ra\n", 1, 0);
		}
	}
	*text = ft_strjoin_free(*text, tmp, 1, 1);
}*/

void	add_chunk_b1(int size, t_ab *ab, int mid_num, char **text)
{
	int		pcounter;

	pcounter = 0;
	while (pcounter < size / 2)
	{
		if (ab->pa->data < mid_num)
		{
			*ab = p_lst(ab->pa, ab->pb, ab);
			*text = ft_strjoin_free(*text, "pb\n", 1, 0);
			pcounter++;
		}
		else if (ft_find_bot_elem(ab->pa)->data < mid_num)
		{
			(*ab).pa = rr_lst((*ab).pa);
			*ab = p_lst(ab->pa, ab->pb, ab);
			*text = ft_strjoin_free(*text, "rra\npb\n", 1, 0);
			pcounter++;
		}
		else
		{
			ab->pa = r_lst(ab->pa);
			*text = ft_strjoin_free(*text, "ra\n", 1, 0);
		}
	}
}

void	check_is_last(t_dlist *nonsrc, int *arr)
{
	if (!nonsrc)
		*arr = 1;
	else
	{
		*arr = 0;
		*(arr + 1) = nonsrc->data;
	}
}

void	find_len(t_dlist **chunk_lst, int *arr, t_dlist *nonsrc)
{
	(*chunk_lst)->len = 0;
	if (!(*arr))
	{
		while (nonsrc->data != *(arr + 1))
		{
			(*chunk_lst)->len++;
			nonsrc = nonsrc->next;
		}
	}
	else
		(*chunk_lst)->len = lst_size(nonsrc);
}
