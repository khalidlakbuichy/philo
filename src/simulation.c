/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/24 09:58:55 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	print_state(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->state == THINKING)
		printf("%ld %d %s\n", get_current_time() - philo->data->start_time, philo->id, THINKING_STAT);
	else if (philo->state == EATING)
		printf("%ld %d %s\n", get_current_time() - philo->data->start_time, philo->id, EATING_STAT);
	else if (philo->state == SLEEPING)
		printf("%ld %d %s\n", get_current_time() - philo->data->start_time, philo->id, SLEEPING_STAT);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

static void take_forks(t_philo *philo)
{
	t_data	*data;
	
	data = philo->data;
	pthread_mutex_lock(philo->first_fork);
	printf("%ld %d has taken a fork\n", get_current_time() - data->start_time, philo->id);
	pthread_mutex_lock(philo->second_fork);
	printf("%ld %d has taken a fork\n", get_current_time() - data->start_time, philo->id);
}

static void thinking(t_philo *philo)
{
	philo->state = THINKING;
	print_state(philo);
}

static void sleeping(t_philo *philo)
{
	t_data	*data;
	
	data = philo->data;
	philo->state = SLEEPING;
	print_state(philo);
	ft_usleep(data->time_to_sleep);
}

static void eating(t_philo *philo)
{
	t_data	*data;
	
	data = philo->data;
	philo->state = EATING;
	philo->last_meal = get_current_time();
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
	// philo->last_meal = get_current_time();
	while (philo->state != DEAD)
	{
		take_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
