/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/07 16:29:54 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if ((ac - 1) < 4 || (ac - 1) > 5)
	{
		ft_error("Error: invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	else
	{
		if (parsing_input(ac, av) == ERROR)
			return (EXIT_FAILURE);
		data = init(ac, av);
		if (!data)
			return (EXIT_FAILURE);
		if (data->nb_philos == 1)
		{
			one_philo(data);
			return (free_heap(data), EXIT_SUCCESS);
		}
		start_simulation(data);
		check_dead_philo(data);
		printf("Simulation ended\n");
		wait_pthread(data);
		printf("Threads joined\n");
		free_heap(data);
	}
}
