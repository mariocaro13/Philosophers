/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:31:31 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/08/01 00:26:01 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	print_status(t_philo *philo, const char *message)
{
	unsigned long	timestamp;
	t_table			*table;

	table = philo->table;
	pthread_mutex_lock(&table->print_mutex);
	if (!is_simulation_over(table))
	{
		timestamp = ft_get_time() - table->start_simulation_ts;
		printf("%ld %d %s\n", timestamp, philo->id, message);
	}
	pthread_mutex_unlock(&table->print_mutex);
}

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	smart_sleep(long sleep_time)
{
	long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < sleep_time)
	{
		usleep(100);
	}
}

bool	die_check(t_table *table, int i, long time_since_last)
{
	pthread_mutex_lock(&table->philos[i].meal_mutex);
	if (time_since_last > table->args.time_to_die)
	{
		table->philos[i].is_alive = false;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		print_status(&table->philos[i], "\001\033[31m\002died\001\033[0m\002");
		pthread_mutex_lock(&table->end_simulation_mutex);
		table->is_simulation_ended = true;
		pthread_mutex_unlock(&table->end_simulation_mutex);
		return (false);
	}
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	return (true);
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		if (are_philos_full(table))
			return (NULL);
		i = -1;
		while (++i < table->args.num_philos)
			if (is_philo_dead_or_full(table, i))
				return (NULL);
		usleep(100);
	}
	return (NULL);
}
