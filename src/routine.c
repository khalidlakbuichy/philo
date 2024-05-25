/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 09:00:24 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	print_state(t_philo *philo)
{
	if (philo->data->dead)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->state == THINKING && !philo->data->dead)
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, THINKING_STAT);
	else if (philo->state == EATING && !philo->data->dead)
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, EATING_STAT);
	else if (philo->state == SLEEPING && !philo->data->dead)
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, SLEEPING_STAT);
	else if (philo->state == TAKEN_FORK && !philo->data->dead)
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, FORK_TAKEN);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

static void	take_forks(t_philo *philo)
{
	// t_data	*data;

	// if (philo->data->dead)
	// 	return ;
	// data = philo->data;
	philo->state = TAKEN_FORK;
	pthread_mutex_lock(philo->first_fork);
	print_state(philo);
	// printf("%ld %d has taken a fork\n", getcurrtime() - data->start_time, philo->id);
	pthread_mutex_lock(philo->second_fork);
	print_state(philo);
	// printf("%ld %d has taken a fork\n", getcurrtime() - data->start_time, philo->id);
}

static void	thinking(t_philo *philo)
{
	// if (philo->data->dead)
	// 	return ;
	philo->state = THINKING;
	print_state(philo);
}

static void	sleeping(t_philo *philo)
{
	t_data	*data;

	// if (philo->data->dead)
	// 	return ;
	data = philo->data;
	philo->state = SLEEPING;
	print_state(philo);
	ft_usleep(data->time_to_sleep);
}

static void	eating(t_philo *philo)
{
	t_data	*data;

	// if (philo->data->dead)
	// 	return ;
	data = philo->data;
	philo->state = EATING;
	philo->last_meal = getcurrtime();
	philo->meals++;
	print_state(philo);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

void	*sumilation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	// philo->last_meal = getcurrtime();
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