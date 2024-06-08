/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumilation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:32:49 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/08 08:58:31 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	take_forks(t_philo *philo)
{
	if (!is_dead(philo->data))
	{
		set_state(philo, TAKEN_FORK);
		pthread_mutex_lock(philo->first_fork);
		pthread_mutex_lock(philo->second_fork);
		print_state(philo);
		print_state(philo);
	}
}

bool	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return (true);
}

void	start_simulation(t_data *data)
{
	size_t	i;

	data->start_time = getcurrtime();
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i]->last_meal = data->start_time;
		pthread_create(&data->philos[i]->thread, NULL, sumilation,
			data->philos[i]);
		i++;
	}
}
