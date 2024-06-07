/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:40:26 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/07 06:21:45 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	set_last_meal(t_philo *philo, time_t last_meal)
{
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal = last_meal;
	pthread_mutex_unlock(&philo->philo_mutex);
}

void	set_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->philo_mutex);
	philo->state = state;
	pthread_mutex_unlock(&philo->philo_mutex);
}

void	dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->data->dead = true;
	pthread_mutex_unlock(&philo->data->data_mutex);
}

void	increment_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	philo->meals++;
	pthread_mutex_unlock(&philo->philo_mutex);
}
