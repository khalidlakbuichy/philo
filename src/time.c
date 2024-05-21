/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:58:46 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/21 15:11:23 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

time_t	get_time(void)
{
	struct timeval	*time;

	time = NULL;
	if (gettimeofday(time, NULL) == -1)
		ft_error("Error: gettimeofday failed\n");
	return ((time->tv_sec * 1000) + (time->tv_usec / 1000));
}

void	ft_usleep(time_t micro_sec)
{
	time_t start;

	start = get_time();
	while ((get_time() - start) < micro_sec)
		usleep(500);
}
