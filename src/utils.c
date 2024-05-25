/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:31:25 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/25 09:08:20 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n-- > 0))
	{
		if (*s1 == '\0' || (unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void free_heap(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]->mutex);
		free(data->forks[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(data->philos[i]->first_fork);
		pthread_mutex_destroy(data->philos[i]->second_fork);
		data->philos[i]->data = NULL;
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	free(data->forks);
	free(data);
}
