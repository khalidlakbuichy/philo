/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 09:06:42 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static int	one_philo(t_data *data)
{
	return (data->max_meals);
}

static int	check_dead_philo(t_data *data)
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
			printf("%ld %d %s\n", getcurrtime() - data->start_time,
				data->philos[i]->id, DEAD_STAT);
			pthread_mutex_unlock(&data->print_mutex);
			return (0);
		}
		i++;
		if (i == data->nb_philos)
			i = 0;
	}
}

static int check_meals(t_data *data)
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

int	main(int ac, char **av)
{
	// size_t	i;
	t_data	*data;

	if ((ac - 1) < 4 || (ac - 1) > 5)
		ft_error("Error: invalid number of arguments");
	else
	{
		parsing_input(ac, av);
		data = init(ac, av);
		if (data->nb_philos == 1)
			return (one_philo(data));
		// i = 0;
		start_simulation(data);
		if(check_dead_philo(data) == 0 || check_meals(data) == 0)
		{
			free_heap(data);
			return (EXIT_SUCCESS);
		}
		for (size_t j = 0; j < data->nb_philos; j++)
		{
			pthread_join(data->philos[j]->thread, NULL);
		}
	}
	return (EXIT_SUCCESS);
}
