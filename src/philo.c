/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:33:11 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/07 16:29:40 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	one_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->philos[0];
	data->start_time = getcurrtime();
	philo->last_meal = data->start_time;
	philo->state = TAKEN_FORK;
	pthread_mutex_lock(philo->first_fork);
	print_state(philo);
	pthread_mutex_unlock(philo->first_fork);
	ft_usleep(data->time_to_die);
	printf("%ld %d %s\n", getcurrtime() - philo->data->start_time, philo->id,
		DEAD_STAT);
}

bool	check_meals(t_data *data)
{
	size_t	i;
	size_t	meals;

	i = 0;
	meals = 0;
	if (data->max_meals == -1)
		return (false);
	while (i < data->nb_philos)
	{
		if (((int)get_meals(data->philos[i]) >= data->max_meals))
			meals++;
		i++;
	}
	if (meals == data->nb_philos)
	{
		pthread_mutex_lock(&data->data_mutex);
		data->dead = true;
		pthread_mutex_unlock(&data->data_mutex);
		return (true);
	}
	return (false);
}

bool	dead_philo(t_philo *philo)
{
	if (((getcurrtime() - get_last_meal(philo)) > philo->data->time_to_die)
		&& get_philo_state(philo) != EATING)
	{
		dead(philo);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d %s\n", getcurrtime() - philo->data->start_time,
			philo->id, DEAD_STAT);
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (true);
	}
	return (false);
}

bool	check_dead_philo(t_data *data)
{
	size_t	i;

	i = 0;
	while (true)
	{
		if (dead_philo(data->philos[i]))
			return (true);
		if (check_meals(data))
			return (true);
		i++;
		if (i == data->nb_philos)
			i = 0;
	}
}

void	wait_pthread(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i]->thread, NULL);
		printf("Thmaread %ld joined\n", i);
		i++;
	}
}
