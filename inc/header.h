/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:06 by klakbuic          #+#    #+#             */
/*   Updated: 2024/05/21 14:39:59 by klakbuic         ###   ########.fr       */
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
# define FORK_TAKEN "has taken a fork"
# define THINKING_STAT "is thinking"
# define EATING_STAT "is eating"
# define SLEEPING_STAT "is sleeping"
# define DEAD_STAT "died"

/* TYPEDEFS */
typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_forks	t_forks;
typedef enum e_state	t_state;

/* ENUMS */
enum					e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD,
	FULL
};

/* STRCUTS */
struct					s_forks
{
	int					id;
	pthread_mutex_t		mutex;
};

struct					s_data
{
	size_t				nb_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					max_meals;
	pthread_mutex_t		print;
	t_philo				**philos;
	t_forks				**forks;
};

struct					s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*second_fork;
	size_t				meals;
	time_t				last_meal;
	t_state				state;
	t_data				*data;
};

/* Prototypes */
void					parsing_input(int ac, char **av);
size_t					ft_strlen(char *str);
void					ft_error(char *msg);
int						ft_atoi(const char *str);
t_data					*init(int ac, char **av);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isdigit(int c);
time_t					get_time(void);
void					ft_usleep(time_t micro_sec);
void					print_state(t_philo *philo);
void					*sumilation(void *arg);

#endif /* HEADER_H */