/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:05:58 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/27 12:12:06 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_input(argc, argv))
		data = parse_data(argc, argv);
	else
	{
		printf("Usage: ./philosophers number_of_philosophers time_to_die tim\
e_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	if (DEBUG)
		print_data(data);
	simulation(data);
	clean_data(data);
	return (0);
}

int	check_input(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (ft_atoi(argv[1]) <= 0)
		return (0);
	if (ft_atoi(argv[2]) < 0)
		return (0);
	if (ft_atoi(argv[3]) < 0)
		return (0);
	if (ft_atoi(argv[4]) < 0)
		return (0);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (0);
	}
	return (1);
}

void	simulation(t_data *data)
{
	t_philo	*philo;

	philo = data->philos;
	while (philo)
	{
		if (pthread_create(&philo->tid, NULL, &routine, philo) != 0)
			return ;
		philo = philo->next;
	}
	while (1)
	{
		if (update_times(data) != 1)
			break ;
		if (check_all_finished(data))
			break ;
	}
	philo = data->philos;
	while (philo)
	{
		pthread_join(philo->tid, NULL);
		philo = philo->next;
	}
}

int	update_times(t_data *data)
{
	t_philo	*philo;
	int		time_left;

	philo = data->philos;
	while (philo)
	{
		time_left = data->die_t - (get_timestamp() - get_last_meal_ts(philo));
		if (time_left <= 0)
		{
			print_log(philo, MSG_DIED);
			set_data_status(data, ONE_DEAD);
			set_philo_status(philo, DEAD);
			return (0);
		}
		philo = philo->next;
	}
	return (1);
}

int	check_all_finished(t_data *data)
{
	t_philo	*philo;

	philo = data->philos;
	while (philo)
	{
		if (get_philo_status(philo) != DONE)
			return (0);
		philo = philo->next;
	}
	set_data_status(data, ALL_DONE);
	return (1);
}
