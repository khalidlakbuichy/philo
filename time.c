/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:58:46 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/20 15:00:20 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

time_t	get_time(void)
{
	struct timeval	*time;

	if (gettimeofday(time, NULL) == -1)
		ft_error("Error: gettimeofday failed\n");
	return ((time->tv_sec * 1000) + (time->tv_usec / 1000));
}

void	ft_usleep(size_t micro_sec)
{
	long start;

	start = get_time();
	while (get_time() - start < micro_sec)
		usleep(500);
}