/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:06 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/13 16:32:18 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*  Includes  */
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*  Defines  */
# define MAX_INT_LEN 10
# define INT_MAX "2147483647"

/* TYPEDEFS */
typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

/* STRCUTS */

struct					s_data
{
	size_t				nb_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				nb_meals;
};

struct					s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print;
	int					*stop;
	int					*meals;
	int					*last_meal;
	int					*nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
};

/* Prototypes */
int						ft_atoi_enhanced(char *str, int *flag);
void					parsing_input(int ac, char **av);
size_t					ft_strlen(char *str);
void					ft_error(char *msg);

#endif /* HEADER_H */