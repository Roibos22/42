/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:56:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/28 18:09:13 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define DEBUG 0

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	struct s_philo	*next;
	int				status;
	int				fork_r;
	int				fork_l;
	int				meals_count;
	long long		last_meal_ts;
	pthread_mutex_t	philo_m;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				philo_count;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	data_m;
	pthread_mutex_t	print_m;
	long long		eat_t;
	long long		sleep_t;
	long long		die_t;
	long long		start_t;
	int				max_meals;
	int				status;
}	t_data;

// MAIN
int				main(int argc, char **argv);
int				check_input(int argc, char **argv);
void			simulation(t_data *data);
int				update_times(t_data *data);
int				check_all_finished(t_data *data);

// PARSE DATA
t_data			*parse_data(int argc, char **argv);
pthread_mutex_t	*create_forks(int count);
t_philo			*init_philo(int id, t_data *data);
t_philo			*create_philos(int count, t_data *data);
void			assign_forks(t_philo *philo, int count);

// UTILS AND ACTIVITIES
long int		ft_atoi(const char *nptr);
void			go_think(t_philo *philo);
void			go_sleep(t_philo *philo);
void			go_eat(t_philo *philo);
void			my_sleep(t_philo *philo, long long ms);

// TIME AND LOG
void			print_timestamp(long long start_time);
long long		get_timestamp(void);
void			print_log(t_philo *philo, int msg);
void			print_data(t_data *data);
int				get_time_passed(struct timeval start);

// ROUTINE
void			*routine(void *arg);
void			lock_forks(t_philo *philo);
void			unlock_forks(t_philo *philo);
int				ask_to_continue(t_philo	*philo);

// SETTERS
void			set_last_meal_ts(t_philo *philo, long long value);
void			set_philo_status(t_philo *philo, int status);
void			set_data_status(t_data *data, int status);
void			set_meals_count_plus_one(t_philo *philo);

// GETTERS
long long		get_last_meal_ts(t_philo *philo);
int				get_philo_status(t_philo *philo);
int				get_data_status(t_data *data);
int				get_meals_count(t_philo *philo);

// CLEAN
void			destroy_philos(t_philo *philo);
void			clean_data(t_data *data);

// DATA STATUS
# define RUNNING 0
# define ONE_DEAD 1
# define ALL_DONE 2

// PHILO STATUS
# define BORED 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define DONE 5

// MESSAGES
# define MSG_FORK 1
# define MSG_EAT 2
# define MSG_SLEEP 3
# define MSG_THINK 4
# define MSG_DIED 5

#endif