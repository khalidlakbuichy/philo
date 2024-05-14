/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/14 15:27:43 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	*data;
	if ((ac - 1) < 4 || (ac - 1) > 5)
	{
		puts("Error: invalid number of arguments");
		/* Failure */
	}
	else
	{
		parsing_input(ac, av);
		data = init(ac, av);
		for (int i = 0; i < data->nb_philo; i++)
		{
			pthrad_create(&data->philo[i].thread, NULL, &philo, &data->philo[i]);
		}
		
		/* Success */  
	}
}
