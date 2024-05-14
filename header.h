/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:06 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/14 16:31:21 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*  Includes  */
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*  Defines  */
# define MAX_INT_LEN 10
# define INT_MAX "2147483647"

/* TYPEDEFS */
typedef struct s_data		t_data;
typedef struct s_philo		t_philo;
typedef struct s_forks_s	t_forks;

/* STRCUTS */

struct						forks_s
{
	int						id;
	pthread_mutex_t			mutex;
};

struct						s_data
{
	size_t					nb_philos;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	int						nb_meals;
	t_philo					**philos;
	t_forks					**forks;
};

struct						s_philo
{
	int						id;
	pthread_t				thread;
	pthread_mutex_t			*first_fork;
	pthread_mutex_t			*second_fork;
	pthread_mutex_t			*print;
	int						*stop;
	int						meals;
	time_t					*last_meal;
	int						nb_meals;
	t_data					*data;
};

/* Prototypes */
void						parsing_input(int ac, char **av);
size_t						ft_strlen(char *str);
void						ft_error(char *msg);
int							ft_atoi(const char *str);
t_data						*init(int ac, char **av);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
int							ft_isdigit(int c);

#endif /* HEADER_H */