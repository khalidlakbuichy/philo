/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:45:54 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/23 16:32:31 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	assign_forks(t_philo *philo, int philo_pos)
{
	size_t	nb_philos;

	nb_philos = philo->data->nb_philos;
	philo->first_fork = &philo->data->forks[philo_pos]->mutex;
	philo->second_fork = &philo->data->forks[(philo_pos + 1) % nb_philos]->mutex;
	if (philo->id % 2)
	{
		philo->first_fork = &philo->data->forks[(philo_pos + 1) % nb_philos]->mutex;
		philo->second_fork = &philo->data->forks[philo_pos]->mutex;
	}
	// printf("assign philo id: %d fork %p\n", philo->id, philo->first_fork);
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
		philos[i]->last_meal = 0;
		philos[i]->state = THINKING;
		philos[i]->data = data;
		assign_forks(philos[i], i);
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
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->max_meals = -1;
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	data->forks = init_forks(data);
	data->philos = init_philos(data);
	pthread_mutex_init(&data->print, NULL);
	return (data);
}
