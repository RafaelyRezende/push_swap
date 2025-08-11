/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:07 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/08/09 09:36:13 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	ft_argsize(char **av)
{
	int	count;

	count = 0;
	while (av[count])
		count++;
	return (count);
}

static
int	ft_error_alpha(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			return (-1);
		else
			str++;
	}
	return (0);
}

static
int	*ft_parser(char **av, int *size_numbers)
{
	int		*buf;
	int		i;

	av++;
	*size_numbers = ft_argsize(av);
	buf = (int *)ft_calloc(*size_numbers, sizeof(int));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < *size_numbers)
	{
		if (ft_error_alpha(av[i]))
			return (free(buf), NULL);
		buf[i] = ft_atoi(av[i]);
		i++;
	}
	return (buf);
}

int	main(int argc, char **argv)
{
	int	i;
	int	size_numbers;
	int	*numbers;

	if (argc < 2)
			return (-1);
	if (argc > 2)
	{
		numbers = ft_parser(argv, &size_numbers);
		if (!numbers)
		{
			printf("Error: only numbers allowed.");
			return (-1);
		}
	}
	i = 0;
	while (i < size_numbers)
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}
