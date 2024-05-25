/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 10:20:34 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if ((ac - 1) < 4 || (ac - 1) > 5)
	{
		ft_error("Error: invalid number of arguments");
		return (EXIT_FAILURE);
	}
	else
	{
		if (parsing_input(ac, av) == ERROR)
			return (EXIT_FAILURE);
		data = init(ac, av);
		if (data->nb_philos == 1)
		{
			one_philo(data);
			return (free_heap(data), EXIT_SUCCESS);
		}
		start_simulation(data);
		if (check_dead_philo(data) == 0 || check_meals(data) == 0)
			return (free_heap(data), EXIT_SUCCESS);
		wait_pthread(data);
	}
}
