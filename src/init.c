/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:28:26 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/08/07 15:02:40 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include "ansi_colors.h"

static void	init_philo_data(t_table *table, int i)
{
	table->philos[i].id = i + 1;
	table->philos[i].meals_counter = 0;
	table->philos[i].is_alive = true;
	table->philos[i].is_full = false;
	table->philos[i].table = table;
	table->philos[i].last_meal_ts = ft_get_time();
	pthread_mutex_init(&table->philos[i].eaten_mutex, NULL);
	pthread_mutex_init(&table->philos[i].meal_mutex, NULL);
}

static void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args.num_philos)
	{
		init_philo_data(table, i);
		if (table->philos[i].id % 2 == 0)
		{
			table->philos[i].left_fork = &table->forks[table->philos[i].id - 1];
			table->philos[i].right_fork = &table->forks[(table->philos[i].id)
				% table->args.num_philos];
		}
		else
		{
			table->philos[i].left_fork = &table->forks[(table->philos[i].id)
				% table->args.num_philos];
			table->philos[i].right_fork = &table->forks[table->philos[i].id
				- 1];
		}
		i++;
	}
}

static int	assign_table_data(t_table *table)
{
	table->start_simulation_ts = 0;
	table->is_simulation_ended = false;
	table->philos = ft_calloc(table->args.num_philos, sizeof(t_philo));
	table->forks = ft_calloc(table->args.num_philos, sizeof(t_fork));
	if (!table->philos || !table->forks)
		return (ft_putstr_fd(COLOR_RED_BOLD"Error allocating memory.\n"
				COLOR_RESET, 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_table(t_table *table)
{
	int	index;

	index = 0;
	if (assign_table_data(table) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->end_simulation_mutex, NULL);
	if (!table->philos || !table->forks)
		return (ft_putstr_fd(COLOR_RED_BOLD"Error allocating memory.\n"
				COLOR_RESET, 2), false);
	while (index < table->args.num_philos)
	{
		table->forks[index].id = index;
		pthread_mutex_init(&table->forks[index].mutex, NULL);
		index++;
	}
	init_philos(table);
	return (EXIT_SUCCESS);
}
