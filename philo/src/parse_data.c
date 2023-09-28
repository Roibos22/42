/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:52:14 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/26 18:18:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*parse_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->philo_count = ft_atoi(argv[1]);
	data->die_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	data->start_t = get_timestamp();
	data->status = 0;
	pthread_mutex_init(&data->print_m, NULL);
	pthread_mutex_init(&data->data_m, NULL);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = 0;
	data->forks_m = create_forks(ft_atoi(argv[1]));
	data->philos = create_philos(ft_atoi(argv[1]), data);
	assign_forks(data->philos, data->philo_count);
	return (data);
}

void	assign_forks(t_philo *philo, int count)
{
	int	i;

	i = 0;
	while (philo)
	{
		if (philo->tid == 1)
		{
			philo->fork_l = 0;
			philo->fork_r = count - 1;
			i++;
		}
		else if ((int)philo->tid == count)
		{
			philo->fork_l = count - 1;
			philo->fork_r = count - 2;
			i++;
		}
		else
		{
			philo->fork_l = i;
			philo->fork_r = i - 1;
			i++;
		}
		philo = philo->next;
	}
}

pthread_mutex_t	*create_forks(int count)
{
	pthread_mutex_t	*forks_m;
	int				i;

	i = 0;
	forks_m = malloc(count * sizeof(pthread_mutex_t));
	while (i < count)
	{
		pthread_mutex_init(&forks_m[i], NULL);
		i++;
	}
	if (DEBUG)
		printf("%i forks created\n", i);
	return (forks_m);
}

t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->status = BORED;
	philo->tid = id;
	philo->id = id;
	philo->last_meal_ts = data->start_t;
	philo->data = data;
	philo->meals_count = 0;
	philo->next = NULL;
	pthread_mutex_init(&philo->philo_m, NULL);
	return (philo);
}

t_philo	*create_philos(int count, t_data *data)
{
	t_philo	*philos;
	t_philo	*current_philo;
	int		i;

	i = 1;
	if (count <= 0)
		return (NULL);
	current_philo = init_philo(i, data);
	philos = current_philo;
	while (i < count)
	{
		i++;
		current_philo->next = init_philo(i, data);
		current_philo = current_philo->next;
	}
	current_philo = NULL;
	if (DEBUG)
		printf("%i philos created\n", i);
	return (philos);
}
