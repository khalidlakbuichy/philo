/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:05:59 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/13 16:52:21 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white(int c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int signe;
	unsigned int nb;

	signe = 1;
	nb = 0;
	while (is_white(*str))
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		nb = (nb * 10) + ((*str++ - '0'));
	return ((int)nb * signe);
}
