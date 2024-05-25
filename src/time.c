/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:58:46 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 08:22:31 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

time_t	getcurrtime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("gettimeofday() error\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(time_t milliseconds)
{
	time_t	start;

	start = getcurrtime();
	while ((getcurrtime() - start) < milliseconds)
		usleep(100);
}
