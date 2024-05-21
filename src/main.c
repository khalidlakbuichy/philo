/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:44 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/21 15:14:33 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int ac, char **av)
{
	size_t	i;
	t_data	*data;

	if ((ac - 1) < 4 || (ac - 1) > 5)
	{
		puts("Error: invalid number of arguments");
	}
	else
	{
		parsing_input(ac, av);
		data = init(ac, av);
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_create(&data->philos[i]->thread, NULL, sumilation, &data->philos[i]);
		}
		for (size_t j = 0; j < data->nb_philos; j++)
		{
			pthread_join(data->philos[j]->thread, NULL);
		}
	}
}
