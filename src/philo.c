/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:26:35 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/07/31 18:56:24 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	take_forks(t_philo *philo)
{
	t_table	*table;
	bool	is_alive;

	table = philo->table;
	pthread_mutex_lock(&philo->meal_mutex);
	is_alive = philo->is_alive;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (is_simulation_over(table) || !is_alive)
		return (false);
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_status(philo, "has taken a fork");
	return (true);
}

void	eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&philo->eaten_mutex);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->eaten_mutex);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_ts = ft_get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, "is eating");
	smart_sleep(table->args.time_to_eat);
	if (philo->meals_counter == table->args.num_meal_limit)
	{
		print_status(philo, "\001\033[32m\002has eaten enough\001\033[0m\002");
		pthread_mutex_lock(&philo->meal_mutex);
		philo->is_full = true;
		pthread_mutex_unlock(&philo->meal_mutex);
		if (are_philos_full(table))
		{
			pthread_mutex_lock(&table->end_simulation_mutex);
			table->is_simulation_ended = true;
			pthread_mutex_unlock(&table->end_simulation_mutex);
		}
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping");
	smart_sleep(philo->table->args.time_to_sleep);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
}
