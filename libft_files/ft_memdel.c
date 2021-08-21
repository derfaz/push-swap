#include "libft.h"

void	ft_memdel(void **str)
{
	if (!str)
		return ;
	free(*str);
	*str = NULL;
}
