/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumilation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:32:49 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 08:53:23 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	start_simulation(t_data *data)
{
	size_t i;

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
