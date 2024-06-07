/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:26:17 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/07 06:48:31 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

time_t	get_last_meal(t_philo *philo)
{
	time_t	last_meal;

	pthread_mutex_lock(&philo->philo_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->philo_mutex);
	return (last_meal);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->philo_mutex);
	state = philo->state;
	pthread_mutex_unlock(&philo->philo_mutex);
	return (state);
}

bool	is_dead(t_data *data)
{
	bool	dead;
	
	pthread_mutex_lock(&data->data_mutex);
	dead = data->dead;
	pthread_mutex_unlock(&data->data_mutex);
	return (dead);
}

size_t	get_meals(t_philo *philo)
{
	size_t	meals;

	pthread_mutex_lock(&philo->philo_mutex);
	meals = philo->meals;
	pthread_mutex_unlock(&philo->philo_mutex);
	return (meals);
}

int	get_philo_id(t_philo *philo)
{
	int	id;

	pthread_mutex_lock(&philo->philo_mutex);
	id = philo->id;
	pthread_mutex_unlock(&philo->philo_mutex);
	return (id);
}

time_t	get_time_to_eat(t_data *data)
{
	time_t	time_to_eat;

	pthread_mutex_lock(&data->data_mutex);
	time_to_eat = data->time_to_eat;
	pthread_mutex_unlock(&data->data_mutex);
	return (time_to_eat);
}

time_t	get_time_to_sleep(t_data *data)
{
	time_t	time_to_sleep;

	pthread_mutex_lock(&data->data_mutex);
	time_to_sleep = data->time_to_sleep;
	pthread_mutex_unlock(&data->data_mutex);
	return (time_to_sleep);
}

time_t	get_time_to_die(t_data *data)
{
	time_t time_to_die;

	pthread_mutex_lock(&data->data_mutex);
	time_to_die = data->time_to_die;
	pthread_mutex_unlock(&data->data_mutex);
	return (time_to_die);
}
