/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:28:24 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:13:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(&philo->data->forks_m[philo->fork_l]);
		print_log(philo, MSG_FORK);
		pthread_mutex_unlock(&philo->data->forks_m[philo->fork_l]);
		return (NULL);
	}
	while (ask_to_continue(philo))
	{
		if (ask_to_continue(philo))
			go_eat(philo);
		if (ask_to_continue(philo))
			go_sleep(philo);
		if (ask_to_continue(philo))
			go_think(philo);
	}
	return (NULL);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks_m[philo->fork_l]);
		pthread_mutex_unlock(&philo->data->forks_m[philo->fork_r]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks_m[philo->fork_r]);
		pthread_mutex_unlock(&philo->data->forks_m[philo->fork_l]);
	}
}

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks_m[philo->fork_r]);
		print_log(philo, MSG_FORK);
		pthread_mutex_lock(&philo->data->forks_m[philo->fork_l]);
		print_log(philo, MSG_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks_m[philo->fork_l]);
		print_log(philo, MSG_FORK);
		pthread_mutex_lock(&philo->data->forks_m[philo->fork_r]);
		print_log(philo, MSG_FORK);
	}
}

int	ask_to_continue(t_philo	*philo)
{
	if (get_data_status(philo->data) == ONE_DEAD)
		return (0);
	if (philo->data->max_meals != 0)
	{
		if (get_meals_count(philo) >= philo->data->max_meals)
		{
			set_philo_status(philo, DONE);
			return (0);
		}
	}
	return (1);
}
