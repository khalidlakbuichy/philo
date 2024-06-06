/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/06 10:10:15 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	take_forks(t_philo *philo)
{
	if (!is_dead(philo))
	{
		
	set_state(philo, TAKEN_FORK);
	pthread_mutex_lock(philo->first_fork);
	print_state(philo);
	pthread_mutex_lock(philo->second_fork);
	print_state(philo);
	}
}

void	thinking(t_philo *philo)
{
	if (!is_dead(philo))
	{
		
	set_state(philo, THINKING);
	print_state(philo);
	}
}

void	sleeping(t_philo *philo)
{
	t_data	*data;

	if (!is_dead(philo))
	{		
	data = philo->data;
	set_state(philo, SLEEPING);
	print_state(philo);
	ft_usleep(data->time_to_sleep);
	}
}

void	eating(t_philo *philo)
{
	t_data	*data;

	if (!is_dead(philo))
	{	
		data = philo->data;
		set_state(philo, EATING);
		set_last_meal(philo, getcurrtime());
		print_state(philo);
		increment_meal(philo);
		ft_usleep(data->time_to_eat);
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(philo->second_fork);
	}
}

void	*sumilation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (get_philo_id(philo) % 2)
	{
		
		while (!is_dead(philo))
		{
			if (is_dead(philo))
				break ;
			take_forks(philo);
			if (is_dead(philo))
				break ;
			eating(philo);
			if (is_dead(philo))
				break ;
			sleeping(philo);
			if (is_dead(philo))
				break ;
			thinking(philo);
		}
	}
	return (NULL);
}
