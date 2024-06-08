/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:09 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/08 09:00:15 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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
	}
}

void	*sumilation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(50);
	while (!is_dead(philo->data))
	{
		if (is_dead(philo->data))
			break ;
		take_forks(philo);
		if (is_dead(philo->data) && leave_forks(philo))
			break ;
		eating(philo);
		if (is_dead(philo->data))
			break ;
		if ((int)get_meals(philo) == philo->data->max_meals)
			break ;
		sleeping(philo);
		if (is_dead(philo->data))
			break ;
		thinking(philo);
	}
	return (NULL);
}
