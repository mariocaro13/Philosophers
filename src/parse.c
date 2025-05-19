/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:47:24 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/19 22:05:20 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_table *table, char **argv)
{
	if (ft_atol(argv[1]) < 0 || ft_atol(argv[2]) < 0
		|| ft_atol(argv[3]) < 0 || ft_atol(argv[4]) < 0)
		return ;
	table->num_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 60e3
		|| table->time_to_eat < 60e3
		|| table->time_to_sleep < 60e3)
	{
		error_print("Invalid input: Time values must be greater than 60ms.");
		return ;
	}
	if (argv[5])
	{
		table->num_meal_limit = ft_atol(argv[5]);
		if (table->num_meal_limit < 1)
		{
			error_print("Invalid input: Meal limit must be greater than 0.");
			return ;
		}
	}
	else
		table->num_meal_limit = -1;
}
