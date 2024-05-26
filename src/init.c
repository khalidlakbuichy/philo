/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:45:54 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 15:33:40 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static void	assign_forks(t_philo *philo)
{
	size_t	nb_philos;

	nb_philos = philo->data->nb_philos;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &philo->data->forks[philo->id % nb_philos]->mutex;
		philo->second_fork = &philo->data->forks[philo->id - 1]->mutex;
	}
	else
	{
		philo->first_fork = &philo->data->forks[philo->id - 1]->mutex;
		philo->second_fork = &philo->data->forks[philo->id % nb_philos]->mutex;
	}
}

t_forks	**init_forks(t_data *data)
{
	size_t	i;
	t_forks	**forks;

	forks = (t_forks **)malloc(sizeof(t_forks *) * data->nb_philos);
	if (!forks)
		ft_error("Error: malloc failed\n");
	i = 0;
	while (i < data->nb_philos)
	{
		forks[i] = (t_forks *)malloc(sizeof(t_forks));
		if (!forks[i])
			ft_error("Error: malloc failed\n");
		forks[i]->id = i;
		pthread_mutex_init(&forks[i]->mutex, NULL);
		i++;
	}
	return (forks);
}

t_philo	**init_philos(t_data *data)
{
	size_t	i;
	t_philo	**philos;

	philos = (t_philo **)malloc(sizeof(t_philo *) * data->nb_philos);
	if (!philos)
		ft_error("Error: malloc failed\n");
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			ft_error("Error: malloc failed\n");
		philos[i]->id = i + 1;
		philos[i]->meals = 0;
		philos[i]->state = THINKING;
		philos[i]->data = data;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

t_data	*init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error("Error: malloc failed\n");
	data->nb_philos = ft_atoi(av[1]);
	if (data->nb_philos == 0)
		return (NULL);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->max_meals = -1;
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	data->forks = init_forks(data);
	data->philos = init_philos(data);
	data->dead = false;
	pthread_mutex_init(&data->print_mutex, NULL);
	return (data);
}
