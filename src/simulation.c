/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/23 16:03:39 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	print_state(t_philo *philo)
{
	if (philo->state == THINKING)
		printf("%ld %d %s\n", get_time(), philo->id, THINKING_STAT);
	else if (philo->state == EATING)
		printf("%ld %d %s\n", get_time(), philo->id, EATING_STAT);
	else if (philo->state == SLEEPING)
		printf("%ld %d %s\n", get_time(), philo->id, SLEEPING_STAT);
}

void	*sumilation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	philo->last_meal = get_time();
	while (philo->state != DEAD)
	{
		pthread_mutex_lock(philo->first_fork);
		pthread_mutex_lock(philo->second_fork);
		printf("%ld %d has taken a fork\n", get_time(), philo->id);
		printf("%ld %d has taken a fork\n", get_time(), philo->id);
		philo->state = EATING;
		print_state(philo);
		ft_usleep(philo->data->time_to_eat);
		philo->last_meal = get_time();
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(philo->second_fork);
		printf("%ld %d is sleeping\n", get_time(), philo->id);
		ft_usleep(philo->data->time_to_sleep);
		printf("%ld %d is thinking\n", get_time(), philo->id);
	}
	return (NULL);
}
