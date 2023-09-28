/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:47:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:26:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_data_status(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->data_m);
	result = data->status;
	pthread_mutex_unlock(&data->data_m);
	return (result);
}

int	get_philo_status(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->philo_m);
	result = philo->status;
	pthread_mutex_unlock(&philo->philo_m);
	return (result);
}

long long	get_last_meal_ts(t_philo *philo)
{
	long long	result;

	pthread_mutex_lock(&philo->philo_m);
	result = philo->last_meal_ts;
	pthread_mutex_unlock(&philo->philo_m);
	return (result);
}

int	get_meals_count(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->philo_m);
	result = philo->meals_count;
	pthread_mutex_unlock(&philo->philo_m);
	return (result);
}
