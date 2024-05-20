/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/20 12:16:37 by klakbuic         ###   ########.fr       */
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
		for (int i = 0; i < data->nb_philos; i++)
		{
			pthread_create(&data->philos[i]->thread, NULL, NULL, &data->philos[i]);
		}
		
		/* Success */  
	}
}
