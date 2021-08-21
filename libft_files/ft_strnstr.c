#include "libft.h"

static int	find_max(const char *hhaystack, size_t llen)
{
	if (llen <= ft_strlen(hhaystack))
		return ((int) llen);
	else
		return (ft_strlen(hhaystack));
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*s;
	int		j;
	int		max;

	if (needle[0] == '\0')
		return ((char *)haystack);
	s = ft_strchr(haystack, needle[0]);
	if (!s)
		return (NULL);
	max = find_max(haystack, len);
	j = 0;
	while (s + j < s + max)
	{
		i = 0;
		while (*(s + i + j) && s[i + j] == needle[i] && (s + i + j)
			< (haystack + max) && !(s[i + j] == '\0' && needle[i] == '\0'))
			i++;
		if (i == (int)ft_strlen(needle))
			return (s + j);
		else
			j++;
	}
	return (NULL);
}
