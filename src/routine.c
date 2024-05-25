/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 15:15:47 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	take_forks(t_philo *philo)
{
	philo->state = TAKEN_FORK;
	pthread_mutex_lock(philo->first_fork);
	print_state(philo);
	pthread_mutex_lock(philo->second_fork);
	print_state(philo);
}

void	thinking(t_philo *philo)
{
	philo->state = THINKING;
	print_state(philo);
}

void	sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	philo->state = SLEEPING;
	print_state(philo);
	ft_usleep(data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	philo->state = EATING;
	philo->last_meal = getcurrtime();
	print_state(philo);
	philo->meals++;
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	*sumilation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->dead)
	{
		if (philo->data->dead)
			break ;
		take_forks(philo);
		if (philo->data->dead)
			break ;
		eating(philo);
		if (philo->data->dead)
			break ;
		sleeping(philo);
		if (philo->data->dead)
			break ;
		thinking(philo);
	}
	return (NULL);
}
