#include "libft.h"

void	*ft_strchr(const void *s, int c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(s);
	while (i < n && ((unsigned char *)s)[i] != (unsigned char)c)
		i++;
	if (((unsigned char *)s)[i] == '\0' && c == 0)
		return ((unsigned char *)(s + i));
	if (i == n)
		return (NULL);
	else
		return ((unsigned char *)(s + i));
}
