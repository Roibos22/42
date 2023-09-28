/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:48:08 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:26:24 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_data_status(t_data *data, int status)
{
	pthread_mutex_lock(&data->data_m);
	data->status = status;
	pthread_mutex_unlock(&data->data_m);
}

void	set_philo_status(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->philo_m);
	philo->status = status;
	pthread_mutex_unlock(&philo->philo_m);
}

void	set_last_meal_ts(t_philo *philo, long long value)
{
	pthread_mutex_lock(&philo->philo_m);
	philo->last_meal_ts = value;
	pthread_mutex_unlock(&philo->philo_m);
}

void	set_meals_count_plus_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_m);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->philo_m);
}
