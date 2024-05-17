/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:47:31 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/15 11:37:29 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*safe_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error("Error: malloc failed\n");
	return (ptr);
}

void safe_mutex(pthread_mutex_t *mutex)
{
    if (pthread_mutex_init(mutex, NULL))
        ft_error("Error: mutex init failed\n");
}