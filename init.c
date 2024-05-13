/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:45:54 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/13 16:52:45 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data	init(int ac, char **av)
{
	data = malloc(sizeof(t_data));
	if (!data)
		ft_error("Error: malloc failed\n");
    
}