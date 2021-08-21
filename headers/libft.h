#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

long	ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_strchr(const void *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin_free(char *s1, char *s2, int free1, int free2);
void	ft_memdel(void **str);

#endif