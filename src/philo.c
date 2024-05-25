/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:33:11 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 10:06:57 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	one_philo(t_data *data)
{
	return (data->max_meals);
}

int	check_dead_philo(t_data *data)
{
	size_t	i;

	i = 0;
	while (true)
	{
		if (((getcurrtime() - data->philos[i]->last_meal) > data->time_to_die)
			&& data->philos[i]->state != EATING)
		{
			data->dead = true;
			pthread_mutex_lock(&data->print_mutex);
			printf(COLOR_RED "\t%ld \t\t%d %s\n" COLOR_RESET, getcurrtime() - data->start_time,
				data->philos[i]->id, DEAD_STAT);
			pthread_mutex_unlock(&data->print_mutex);
			return (0);
		}
		i++;
		if (i == data->nb_philos)
			i = 0;
	}
}

int	check_meals(t_data *data)
{
	size_t	i;
	size_t	meals;

	i = 0;
	meals = 0;
	if (data->max_meals == -1)
		return (1);
	while (i < data->nb_philos)
	{
		if ((int)data->philos[i]->meals >= data->max_meals)
			meals++;
		i++;
	}
	if (meals == data->nb_philos)
	{
		data->dead = true;
		return (0);
	}
	return (1);
}

void	wait_pthread(t_data *data)
{
	size_t i;
	
	i = 0;
	
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
}
