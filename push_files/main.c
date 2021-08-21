#include "../headers/push.h"
#include "../headers/libft.h"

int	write_error(long x)
{
	if (x > 2147483647 || x < -2147483648)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	return ((int)x);
}

void	is_sorted_dup(int *arg_arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < argc)
	{
		j = 1;
		while (i + j < argc)
		{
			if (arg_arr[i] == arg_arr[i + j])
				write_error(2147483648);
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= argc - 2 && arg_arr[i] < arg_arr[i + 1])
		i++;
	if (i == argc - 1 || argc == 1)
		exit (0);
}

int	*is_error(int argc, char **argv)
{
	int	*arg_arr;
	int	i;
	int	tmp;

	arg_arr = (int *)malloc(sizeof(int) * argc);
	if (!arg_arr)
		exit (0);
	tmp = argc;
	while (argc-- > 1)
	{
		i = 0;
		while (*(argv[argc] + i))
		{
			if (!((i == 0 && *(argv[argc] + i) == '-')
					|| (*(argv[argc] + i) > 47
						&& *(argv[argc] + i) < 58)))
				write_error(2147483648);
			i++;
		}
		arg_arr[argc - 1] = write_error(ft_atoi(argv[argc]));
	}
	is_sorted_dup(arg_arr, tmp - 1);
	return (arg_arr);
}

t_dlist	*create_list(int *arg_arr, int argc)
{
	t_dlist	*a;

	a = ft_create_elem(*arg_arr);
	arg_arr++;
	while (argc-- > 1)
	{
		a = ft_add_bottom_elem(a, *arg_arr);
		arg_arr++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_ab	ab;
	int		*arg_arr;
	char	*text;

	text = 0;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	arg_arr = is_error(argc, argv);
	ab.pa = create_list(arg_arr, argc - 1);
	ab.pb = 0;
	game(&ab, &text);
	cut_text(&text);
	write(1, text, ft_strlen(text));
	free(text);
	free(arg_arr);
	clear_lst(ab.pa);
	clear_lst(ab.pb);
}
