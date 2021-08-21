#include "../headers/push.h"
#include "../headers/libft.h"

static t_dlist	*srt_part2(t_dlist *pmid, t_dlist *list)
{
	if (pmid->next)
		pmid->next->prev = pmid;
	if (list)
	{
		pmid->prev = ft_find_bot_elem(list);
		ft_find_bot_elem(list)->next = pmid;
		return (list);
	}
	else
		return (pmid);
}

t_dlist	*srt_part(t_dlist *list)
{
	int		mid_num;
	int		size;
	t_dlist	*tmp;
	t_dlist	*pmid;

	size = lst_size(list);
	if (size <= 1 || (size == 2 && (list->data < list->next->data)))
		return (list);
	if (size == 2)
		return (s_lst(list));
	mid_num = find_elem(list, size / 2)->data;
	list = srt_left_check(list, mid_num);
	list = srt_right_check(list, mid_num);
	tmp = list;
	while (tmp->data != mid_num)
		tmp = tmp->next;
	pmid = tmp;
	if (tmp->prev)
		tmp->prev->next = 0;
	else
		list = 0;
	list = srt_part(list);
	pmid->next = srt_part(pmid->next);
	return (srt_part2(pmid, list));
}
