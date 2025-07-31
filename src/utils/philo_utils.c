/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:15:25 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/08/01 00:26:32 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	are_philos_full(t_table *table)
{
	bool	is_full;
	int		i;

	i = 0;
	while (i < table->args.num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		is_full = table->philos[i].is_full;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		if (!is_full)
			return (false);
		i++;
	}
	return (true);
}

bool	is_philo_dead_or_full(t_table *table, int i)
{
	unsigned long	time_since_last;
	bool			is_full;

	pthread_mutex_lock(&table->philos[i].meal_mutex);
	is_full = table->philos[i].is_full;
	time_since_last = ft_get_time() - table->philos[i].last_meal_ts;
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	if (is_full)
		return (false);
	return (!die_check(table, i, time_since_last));
}
