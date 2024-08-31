/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:14:22 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 02:24:22 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_num(char *nums)
{
	const char	delimeter = ' ';

	while (*nums && *nums != delimeter)
		nums++;
	while (*nums && *nums == delimeter)
		nums++;
	return (nums);
}

static bool	is_substring_numeric(char *nums)
{
	const char	delimeter = ' ';

	while (*nums && *nums != delimeter)
	{
		if (!(!*nums || ft_isdigit(*nums) || *nums == '-' || *nums == '+'))
			return (false);
		nums++;
	}
	return (true);
}

static size_t	count_and_validate_args(char **argv)
{
	size_t	result;
	int		i;
	int64_t	num;
	char	*nums;

	result = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		nums = argv[i];
		while (*nums)
		{
			num = ft_atoi_int64(nums);
			if (!is_substring_numeric(nums) || num > INT_MAX || num < INT_MIN)
			{
				ft_printf("Error");
				return (0);
			}
			nums = get_next_num(nums);
			result++;
		}
		i++;
	}
	return (result);
}

int	**parse_nums(char **argv)
{
	int		**result;
	char	*nums;
	size_t	result_size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result_size = count_and_validate_args(argv);
	if (result_size == 0)
		return (NULL);
	result = ft_calloc(result_size + 1, sizeof(char *));
	while (argv[i])
	{
		nums = argv[i++];
		while (*nums)
		{
			result[j] = ft_calloc(1, sizeof(int));
			*result[j] = ft_atoi(nums);
			nums = get_next_num(nums);
			j++;
		}
	}
	return (result);
}
