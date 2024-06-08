/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:31:25 by klakbuic          #+#    #+#             */
/*   Updated: 2024/06/08 09:42:07 by klakbuic         ###   ########.fr       */
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
	write(STDERR_FILENO, COLOR_RED, ft_strlen(COLOR_RED));
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, COLOR_RESET, ft_strlen(COLOR_RESET));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	free_heap(t_data *data)
{
	size_t			i;
	pthread_mutex_t	mutex;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&data->data_mutex);
	while (i < data->nb_philos)
	{
		free(data->forks[i]);
		free(data->philos[i]);
		i++;
	}
	pthread_mutex_unlock(&data->data_mutex);
	pthread_mutex_lock(&mutex);
	free(data->forks);
	free(data->philos);
	free(data);
	pthread_mutex_unlock(&mutex);
}
