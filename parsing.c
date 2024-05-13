/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:47:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/13 16:45:40 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	is_white(int c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

static int	check_int_overflow(char *arg)
{
	if (ft_strlen(nbr) < MAX_INT_LEN)
		return (0);
	if (ft_strlen(nbr) > MAX_INT_LEN)
		return (1);
	if (ft_strlen(nbr) == MAX_INT_LEN)
	{
		if (ft_strncmp(nbr, INT_MAX, MAX_INT_LEN) <= 0)
			return (0);
	}
	return (1);
}
int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	while (is_white(*arg))
		arg++;
	if (*arg == '-')
		ft_error("Error: negative number\n");
	if (check_int_overflow(arg))
		ft_error("Error: integer overflow\n");
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_error("Error: invalid argument\n");
		i++;
	}
	return (true);
}
