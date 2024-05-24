/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/24 10:28:54 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static int	one_philo(t_data *data)
{
	return (data->max_meals);
}

int	main(int ac, char **av)
{
	size_t	i;
	t_data	*data;

	if ((ac - 1) < 4 || (ac - 1) > 5)
	{
		puts("Error: invalid number of arguments");
	}
	else
	{
		parsing_input(ac, av);
		data = init(ac, av);
		data->start_time = get_current_time();
		if (data->nb_philos == 1)
			return (one_philo(data));
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_create(&data->philos[i]->thread, NULL, sumilation, data->philos[i]);
			i++;
		}
		i = 0;
		while (true)
		{
			if (((get_current_time() - data->philos[i]->last_meal) > data->time_to_die) && data->philos[i]->state != EATING)
			{
				data->philos[i]->state = DEAD;
				pthread_mutex_lock(&data->print_mutex);
				printf("%ld %d %s\n", get_current_time() - data->start_time, data->philos[i]->id, DEAD_STAT);
				return (EXIT_SUCCESS);
			}
			i++;
			if (i == data->nb_philos)
				i = 0;
		}
		for (size_t j = 0; j < data->nb_philos; j++)
		{
			pthread_join(data->philos[j]->thread, NULL);
		}
	}
}
