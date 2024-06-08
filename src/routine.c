/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/08 07:29:21 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	take_forks(t_philo *philo)
{
	if (!is_dead(philo->data))
	{
		set_state(philo, TAKEN_FORK);
		pthread_mutex_lock(philo->first_fork);
		pthread_mutex_lock(philo->second_fork);
		print_state(philo);
		print_state(philo);
	}
}

bool	leave_forks(t_philo *philo)
{

		// pthread_mutex_lock(&philo->philo_mutex);
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(philo->second_fork);
		return(true);
		// pthread_mutex_unlock(&philo->philo_mutex);
}

void	thinking(t_philo *philo)
{
	if (!is_dead(philo->data))
	{
		set_state(philo, THINKING);
		print_state(philo);
	}
}

void	sleeping(t_philo *philo)
{
	t_data	*data;

	if (!is_dead(philo->data))
	{
		data = philo->data;
		set_state(philo, SLEEPING);
		print_state(philo);
		ft_usleep(get_time_to_sleep(data));
	}
}

void	eating(t_philo *philo)
{
	t_data	*data;

	if (!is_dead(philo->data))
	{
		data = philo->data;
		set_state(philo, EATING);
		set_last_meal(philo, getcurrtime());
		print_state(philo);
		increment_meal(philo);
		ft_usleep(get_time_to_eat(data));
		leave_forks(philo);
		// pthread_mutex_unlock(philo->first_fork);
		// pthread_mutex_unlock(philo->second_fork);
	}
}

void	*sumilation(void *arg)
{
	t_philo	*philo;
	size_t max_meals;
	
	max_meals = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(50);
	while (!is_dead(philo->data))
	{
		// printf("bidayaaaaaaaaaaaaaaaaaaaaaaat --------- %d\n", philo->id);
		// printf("beginning philo id: %d is dead: %d\n", philo->id, is_dead(philo->data));
		if (is_dead(philo->data))
			break ;
		// printf("9abllllllll forrrrrks %d\n", philo->id);
		take_forks(philo);
		// printf("forks %d\n", philo->id);	
		if (is_dead(philo->data) && leave_forks(philo))
			break ;
		eating(philo);
		// printf("eating %d\n", philo->id);	
		if (is_dead(philo->data))
			break ;
		if ((int)get_meals(philo) == philo->data->max_meals)
			break ;
		sleeping(philo);
		// printf("sleeping %d\n", philo->id);	
		if (is_dead(philo->data))
			break ;
		thinking(philo);
		// puts("darni rassi btafkir weeeeeeeeeeeeeeee");
		if (is_dead(philo->data))
			break ;
		// printf("thinking %d\n", philo->id);	
		// printf("ending philo id: %d is dead: %d\n", philo->id, is_dead(philo->data));
	}
	return (NULL);
}
