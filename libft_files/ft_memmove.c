#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if ((char *)src >= (char *)dst)
		return (ft_memcpy(dst, src, n));
	else
		while ((int)n-- > 0)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
