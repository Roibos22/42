/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_activities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:10:41 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:18:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	number;
	int			multiplier;

	number = 0;
	i = 0;
	multiplier = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			multiplier = multiplier * (-1);
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (multiplier * number);
}

void	go_think(t_philo *philo)
{
	set_philo_status(philo, THINKING);
	print_log(philo, MSG_THINK);
}

void	go_sleep(t_philo *philo)
{
	set_philo_status(philo, SLEEPING);
	print_log(philo, MSG_SLEEP);
	usleep(philo->data->sleep_t * 1000);
}

void	go_eat(t_philo *philo)
{
	usleep(100);
	lock_forks(philo);
	set_philo_status(philo, EATING);
	set_meals_count_plus_one(philo);
	print_log(philo, MSG_EAT);
	set_last_meal_ts(philo, get_timestamp());
	usleep(philo->data->eat_t * 1000);
	unlock_forks(philo);
}
