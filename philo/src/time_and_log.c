/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:11:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:26:38 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_log(t_philo *philo, int msg)
{
	pthread_mutex_lock(&philo->data->print_m);
	if (get_data_status(philo->data) == 0)
	{
		print_timestamp(philo->data->start_t);
		if (msg == MSG_FORK)
			printf("%i has taken a fork\n", philo->id);
		if (msg == MSG_EAT)
			printf("%i is eating\n", philo->id);
		if (msg == MSG_SLEEP)
			printf("%i is sleeping\n", philo->id);
		if (msg == MSG_THINK)
			printf("%i is thinking\n", philo->id);
		if (msg == MSG_DIED)
			printf("%i died\n", philo->id);
		if (DEBUG)
			printf("|---Philo %i, philo_s: %i, game_s %i, eaten: %i\n", \
			philo->id, philo->status, philo->data->status, philo->meals_count);
	}
	pthread_mutex_unlock(&philo->data->print_m);
}

void	print_timestamp(long long start_time)
{
	struct timeval	current_time;
	long long		timestamp_ms;

	if (gettimeofday(&current_time, NULL) == 0)
	{
		timestamp_ms = (long long)current_time.tv_sec * 1000 + \
		(long long)current_time.tv_usec / 1000;
		printf("%lld ", timestamp_ms - start_time);
	}
}

long long	get_timestamp(void)
{
	struct timeval	current_time;
	long long		timestamp_ms;

	if (gettimeofday(&current_time, NULL) == 0)
	{
		timestamp_ms = (long long)current_time.tv_sec * 1000 + \
		(long long)current_time.tv_usec / 1000;
		return (timestamp_ms);
	}
	else
		return (0);
}

void	print_data(t_data *data)
{
	printf("PARSED DATA:\n");
	printf("philo_count: %i\n", data->philo_count);
	printf("die_t: %lli\n", data->die_t);
	printf("eat_t: %lli\n", data->eat_t);
	printf("sleep__t: %lli\n", data->sleep_t);
	printf("max_meals: %i\n", data->max_meals);
	printf("start_t: %lli\n", data->start_t);
}
