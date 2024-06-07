/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:22:03 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/07 16:22:27 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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