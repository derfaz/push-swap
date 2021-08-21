#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i1;
	int		i2;

	if (!s1)
		return (s2);
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		new_str[i1] = s1[i1];
		i1++;
	}
	while (s2 && s2[i2])
	{
		new_str[i1 + i2] = s2[i2];
		i2++;
	}
	new_str[i1 + i2] = '\0';
	return (new_str);
}
