/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:58:46 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/05 14:59:38 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	print_state(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->state == THINKING && !is_dead(philo))
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, THINKING_STAT);
	else if (philo->state == EATING && !is_dead(philo))
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, EATING_STAT);
	else if (philo->state == SLEEPING && !is_dead(philo))
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, SLEEPING_STAT);
	else if (philo->state == TAKEN_FORK && !is_dead(philo))
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, FORK_TAKEN);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

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
