#include "../headers/push.h"
#include "../headers/libft.h"

int	min_lst(t_dlist *list)
{
	int		min;
	t_dlist	*tmp;

	tmp = list;
	min = tmp->data;
	while (tmp->next)
	{
		if (tmp->next->data < min)
			min = tmp->next->data;
		tmp = tmp->next;
	}
	return (min);
}

int	min_ab(t_ab *ab)
{
	int		min_a;
	int		min_b;
	t_dlist	*tmp;

	if (ab->pa)
		min_a = min_lst(ab->pa);
	if (ab->pb)
		min_b = min_lst(ab->pb);
	if (!(ab->pa) || min_a > min_b)
		return (min_b);
	else
		return (min_a);
}

int	max_of_chunk(t_dlist **chunk, t_ab *ab)
{
	t_dlist	*tmp;
	int		max;

	tmp = malloc_chunk_par(chunk, ab);
	max = tmp->data;
	while (tmp->next)
	{
		if (tmp->next->data > max)
			max = tmp->next->data;
		tmp = tmp->next;
	}
	clear_lst(tmp);
	return (max);
}

int	min_of_chunk(t_dlist **chunk, t_ab *ab)
{
	t_dlist	*tmp;
	int		min;

	tmp = malloc_chunk_par(chunk, ab);
	min = tmp->data;
	while (tmp->next)
	{
		if (tmp->next->data < min)
			min = tmp->next->data;
		tmp = tmp->next;
	}
	clear_lst(tmp);
	return (min);
}

int	def_bsort(t_dlist *pb)
{
	while (pb)
	{
		if (pb->bsort == 1)
			return (1);
		pb = pb->next;
	}
	return (0);
}
