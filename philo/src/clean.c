/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:48:35 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:18:46 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_philos(t_philo *philo)
{
	t_philo	*next_philo;

	while (philo)
	{
		next_philo = philo->next;
		pthread_mutex_destroy(&philo->philo_m);
		free(philo);
		philo = next_philo;
	}
}

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	destroy_philos(data->philos);
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks_m[i]);
		i++;
	}
	free(data->forks_m);
	pthread_mutex_destroy(&data->data_m);
	pthread_mutex_destroy(&data->print_m);
	free(data);
}
