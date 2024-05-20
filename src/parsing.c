/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:47:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/20 15:52:17 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static int	is_white(int c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

static int	check_int_overflow(char *arg)
{
	while (*arg == '0')
		arg++;
	if (ft_strlen(arg) < MAX_INT_LEN)
		return (0);
	if (ft_strlen(arg) > MAX_INT_LEN)
		return (1);
	if (ft_strlen(arg) == MAX_INT_LEN)
	{
		if (ft_strncmp(arg, INT_MAX, MAX_INT_LEN) <= 0)
			return (0);
	}
	return (1);
}

static int	is_valid_arg(char *arg)
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

void	parsing_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_arg(av[i]))
			ft_error("Error: invalid argument\n");
		i++;
	}
}
