#include "../headers/push.h"
#include "../headers/libft.h"

static void	cut_substr2(char **text, char *str, char *substr, char **new_text)
{
	int	len;
	int	str_len;
	int	i;

	len = ft_strlen(substr);
	str_len = ft_strlen(str);
	i = 0;
	while (ft_strncmp((*text) + i, str, str_len))
		i++;
	while (len - str_len >= 0)
	{
		(*new_text)[i + len - str_len] = *(substr + len);
		len--;
	}
}

static void	cut_substr(char **text, char *str)
{
	char		*substr;

	if (ft_strlen(*text) < ft_strlen(str))
		return ;
	substr = ft_strnstr(*text, str, ft_strlen(*text));
	if (!substr)
		return ;
	ft_memmove(substr, substr + ft_strlen(str),
		ft_strlen(substr) - ft_strlen(str) + 1);
	cut_substr(text, str);
}

void	def_arr_i_s(char **s_arr)
{
	(*s_arr) = "pb\npa\n";
	*(s_arr + 1) = "pa\npb\n";
	*(s_arr + 2) = "\nra\nrra";
	*(s_arr + 3) = "\nrb\nrrb";
	*(s_arr + 4) = "rra\nra\n";
	*(s_arr + 5) = "rrb\nrb\n";
}

void	cut_text(char **text)
{
	char	*s;
	char	*s_arr[6];
	int		i;

	def_arr_i_s(s_arr);
	i = 0;
	s = 0;
	while (i < 6 && !s)
	{
		s = ft_strnstr(*text, s_arr[i], ft_strlen(*text));
		i++;
	}
	if (i == 6 && !s)
		return ;
	i = 0;
	while (i < 6)
	{
		cut_substr(text, s_arr[i]);
		i++;
	}
	cut_text(text);
}
