/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:45:54 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/14 15:54:57 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_forks	**init_forks(void)
{
	int		i;
	t_forks	**forks;

	forks = (t_forks **)malloc(sizeof(t_forks *) * data->nb_philo);
	if (!forks)
		ft_error("Error: malloc failed\n");
	i = -1;
	while (++i < data->nb_philo)
	{
		forks[i] = (t_forks *)malloc(sizeof(t_forks));
		if (!forks[i])
			ft_error("Error: malloc failed\n");
		forks[i]->id = i + 1;
		pthread_mutex_init(&forks[i]->mutex, NULL);
	}
	return (forks);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	**philos;

	philos = (t_philo **)malloc(sizeof(t_philo *) * data->nb_philo);
	if (!philos)
		ft_error("Error: malloc failed\n");
	for (int i = 0; i < data->nb_philo; i++)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			ft_error("Error: malloc failed\n");
		philos[i]->id = i + 1;
		philos[i]->left_fork = &data->forks[i];
		philos[i]->right_fork = &data->forks[(i + 1) % data->nb_philo];
		philos[i]->print = &data->print;
		philos[i]->stop = &data->stop;
	}
	return (philos);
}

t_data	*init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error("Error: malloc failed\n");
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	else
		data->nb_meals = -1;
	data->forks = init_forks(data);
	data->philos = init_philos(data);
	return (data);
}
