#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_dlist {
	int				data;
	int				len;
	int				bsort;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct s_ab {
	t_dlist	*pa;
	t_dlist	*pb;
}				t_ab;

typedef struct s_size_mid {
	int	size;
	int	mid;
}				t_size_mid;

t_dlist	*del_first(t_dlist *list);
t_dlist	*ft_create_elem(int data);
void	create_ab(t_ab *old_ab, t_ab **new_ab, t_dlist *chunk);
t_dlist	*ft_add_top_elem(t_dlist *list, int data);
t_dlist	*ft_find_bot_elem(t_dlist *list);
t_dlist	*ft_add_bottom_elem(t_dlist *list, int data);
void	display_list(t_dlist *list);
void	rdisplay_list(t_dlist *list);
void	exec_text(t_ab *ab, char *text2);
t_dlist	*s_lst(t_dlist *list);
t_dlist	*r_lst(t_dlist *list);
t_dlist	*rr_lst(t_dlist *list);
t_ab	p_lst(t_dlist *src, t_dlist *dst, t_ab *old_ab);
int		lst_size(t_dlist *list);
t_dlist	*find_elem(t_dlist *list, int index);
t_dlist	*find_data_elem(t_dlist *src, int ddata);
t_dlist	*find_src(t_ab *ab, int ddata);
t_dlist	*srt_part(t_dlist *list);
t_dlist	*srt_left_check(t_dlist *list, int mid_num);
t_dlist	*srt_right_check(t_dlist *list, int mid_num);
void	game(t_ab *ab, char **text);
t_dlist	*dup_lst(t_dlist *list);
t_dlist	*dup_part_lst2(t_dlist *first, int len);
void	clear_lst(t_dlist *list);
void	clear_ab(t_ab *ab);
int		str_counter(char *s);
void	check_chunk(t_dlist **chunk_lst, t_ab *ab, char **text);
t_ab	*move_half_rr(t_ab *new_ab, t_ab **ab, char **text,
			t_dlist **chunk_lst);
t_dlist	**move_half_rr_end(t_ab *new_ab, t_ab **ab, char **text,
			t_dlist **chunk_lst);
void	move_half3a(t_dlist *list, t_ab *ab, char **text);
void	move_half23(int size, t_dlist *src, t_ab *ab, char **text);
t_dlist	**move_half(t_ab *ab, char **text, int ddata);
void	src_to_ab(t_ab *ab, t_dlist *src);
int		is_sort(t_dlist *list, t_ab *ab);
void	chunk_sort(t_dlist *new_chunk, t_dlist **chunk_lst,
			t_ab **ab, char **text);
void	push_till_ch_lst(t_ab **ab, t_dlist **chunk_lst, char **text);
void	cut_text(char **text);
void	add_chunk_b(int size, t_ab *ab, int mid_num, char **text);
void	add_chunk_a(int size, t_ab *ab, int mid_num, char **text);
void	add_chunk_b1(int size, t_ab *ab, int mid_num, char **text);
t_dlist	*add_chunk1(t_size_mid sm, t_ab *ab,
			char **text, t_dlist **chunk_lst);
t_dlist	*add_chunk(t_size_mid sm, t_ab *ab,
			char **text, t_dlist **chunk_lst);
t_dlist	*malloc_chunk(t_dlist **chunk_lst, t_ab *ab);
t_dlist	*malloc_chunk_par(t_dlist **chunk_lst, t_ab *ab);
void	check_is_last(t_dlist *nonsrc, int *arr);
void	find_len(t_dlist **chunk_lst, int *arr, t_dlist *nonsrc);
void	exec_text2(char **text, t_ab *ab, char *text2);
int		min_ab(t_ab *ab);
int		min_lst(t_dlist *list);
void	check_rr(t_ab **ab, t_dlist *chunk_lst, char **text, int mid);
void	check_rr_pa2(t_ab **ab, char **text);
void	check_rr_pb2(t_ab **ab, char **text);
void	check_rr_pb1(t_ab **ab, char **text, t_dlist **chunk_lst, t_dlist *src);
void	check_rr_pa1(t_ab **ab, char **text, t_dlist **chunk_lst, t_dlist *src);
t_dlist	*find_new_chunk(int size, char *text2, t_ab *ab, int mid);
void	find_new_ab(t_ab **new_ab, t_dlist *new_chunk, t_ab *ab);
int		max_of_chunk(t_dlist **chunk, t_ab *ab);
int		min_of_chunk(t_dlist **chunk, t_ab *ab);
int		def_bsort(t_dlist *pb);
void	set_bsort(t_ab *ab);
int		find_mid_num(t_dlist *src, int size);

#endif
