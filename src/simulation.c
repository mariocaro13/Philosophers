/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:18:57 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/07/31 23:47:57 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static void	*one_philo_case(t_philo *philo, t_table *data)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(philo, "has taken a fork");
	smart_sleep(data->args.time_to_die);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	return (NULL);
}

static void	*simulation(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = arg;
	table = philo->table;
	if (table->args.num_philos == 1)
		return (one_philo_case(philo, table));
	while (!is_simulation_over(table) && !philo->is_full)
	{
		think(philo);
		if (take_forks(philo))
		{
			if (!is_simulation_over(table))
				eat(philo);
			release_forks(philo);
		}
		if (philo->is_full || is_simulation_over(table))
			break ;
		sleep_philo(philo);
	}
	return (NULL);
}

bool	is_simulation_over(t_table *data)
{
	bool	result;

	pthread_mutex_lock(&data->end_simulation_mutex);
	result = data->is_simulation_ended;
	pthread_mutex_unlock(&data->end_simulation_mutex);
	return (result);
}

void	start_simulation(t_table *table)
{
	int			i;
	pthread_t	monitor_thread;

	table->start_simulation_ts = ft_get_time();
	i = 0;
	while (i < table->args.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		table->philos[i].last_meal_ts = table->start_simulation_ts;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor, table);
	usleep(1000);
	i = -1;
	while (++i < table->args.num_philos)
		pthread_create(&table->philos[i].thread_id, NULL, &simulation,
			&table->philos[i]);
	i = -1;
	while (++i < table->args.num_philos)
		pthread_join(table->philos[i].thread_id, NULL);
	pthread_join(monitor_thread, NULL);
}
