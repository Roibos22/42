/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_activities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:10:41 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/28 18:08:57 by lgrimmei         ###   ########.fr       */
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
	my_sleep(philo, philo->data->sleep_t);
}

void	go_eat(t_philo *philo)
{
	my_sleep(philo, 0);
	lock_forks(philo);
	set_philo_status(philo, EATING);
	set_meals_count_plus_one(philo);
	print_log(philo, MSG_EAT);
	set_last_meal_ts(philo, get_timestamp());
	my_sleep(philo, philo->data->eat_t);
	unlock_forks(philo);
}

void	my_sleep(t_philo *philo, long long ms)
{
	struct timeval	start_ts;

	gettimeofday(&start_ts, NULL);
	while (1)
	{
		usleep(100);
		ask_to_continue(philo);
		if (get_time_passed(start_ts) >= ms)
			return ;
	}
}
