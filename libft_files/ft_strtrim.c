#include "libft.h"

static int	check_if_in_set(char c, char const *sset)
{
	int	i;

	i = 0;
	while (sset[i])
	{
		if (c == sset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	int		first;
	int		last;
	int		i;

	first = 0;
	if (!s1)
		return (NULL);
	last = (int)ft_strlen(s1) - 1;
	while (check_if_in_set(s1[first], set))
		first++;
	while (check_if_in_set(s1[last], set) && (first < last))
		last--;
	tr = (char *)malloc(sizeof(char) * (last - first + 2));
	i = 0;
	if (tr == NULL)
		return (NULL);
	while (i < last - first + 2 - 1)
	{
		tr[i] = s1[i + first];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
