/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:23:32 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/12 17:44:48 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
t_stack	*ft_init_stack(int *nums, int size)
{
	t_stack	*head;

	head = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!head)
		return (NULL);
	while (++i < size)
		ft_new_node(head->stack_a, *nums++);
	return (head);
}

static
long long	ft_strtol(const char *nptr)
{
	long long	nbr;
	int			sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nprt++;
	}
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (LONG_MAX);
		nbr = nbr * 10 + *nptr - '0';
		if (nbr * sign < INT_MIN || nbr * sign > INT_MAX)
			return (LONG_MAX);
		nptr++;
	}
	return (*nbr);
}

static
int	ft_isdup(int *nums, int size_nums, char *str)
{
	int			i;
	long long	nbr;

	nbr = ft_strtol(str);
	if (nbr == LONG_MAX || !*str)
		return (-1);
	i = -1;
	while (++i < size_nums)
	{
		if (*nums != new)
			return (-1);
		nums++;
	}
	return (0);
}

static
int	ft_get_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static
void	ft_err_parse(char **split, int *tmp_nums)
{
	if (split)
	{
		while (*split)
			free(*split++);
	}
	if (tmp_nums)
		free(tmp_nums);
}

t_stack	*ft_parser(int ac, char *av)
{
	char	**split;
	int		*tmp_nums;
	int		size;
	int		i;

	split = ft_split(av, " ");
	if (!split)
		return (ft_err_parse(split, NULL));
	size = ft_get_size(split);
	i = -1;
	while (++i < size)
	{
		if (!ft_isdigit(split[i]))
			return (ft_err_parse(split, NULL), NULL);
	}
	tmp_nums = (int *)ft_calloc(size, sizeof(int));
	if (!tmp_nums)
		return (ft_err_parse(split, tmp_nums), NULL);
	i = -1;
	while (++i < size)
	{
		if (ft_isdup(tmp_nums, size, split[i]))
			return (ft_err_parse(split, tmp_nums), NULL);
		tmp_nums[i] = (int)ft_strtol(split[i]);
	}
	ft_err_parse(split, NULL);
	return (ft_init_stack(tmp_nums));
}
