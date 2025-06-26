/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:47:24 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/26 21:26:44 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "utils.h"
#include "messages.h"

static long	parse_long_arg(const char *str, const char *err_msg, long min_val)
{
	long	val;

	val = ft_atol(str);
	if (val < 0)
		return (-1);
	if (val < min_val)
	{
		error_print(err_msg);
		return (-1);
	}
	return (val);
}

static int	init_num_times_philo_must_eat(t_args *args, int argc, char **argv)
{
	long	val;

	if (argc == 6)
	{
		val = parse_long_arg(argv[5], MSG_ERR_NUM_TIMES_PHILO_MUST_EAT, 0);
		if (val < 0)
			return (EXIT_FAILURE);
		args->num_meal_limit = (int)val;
	}
	else
		args->num_meal_limit = 0;
	return (EXIT_SUCCESS);
}

int	parse_args(int argc, char **argv, t_args *args)
{
	if (argc != 5 && argc != 6)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	args->num_philos = (int)parse_long_arg(argv[1], MSG_ERR_NUM_PHILOS, 1);
	if (args->num_philos < 0)
		return (EXIT_FAILURE);
	args->time_to_die = (unsigned long)parse_long_arg(argv[2],
			MSG_ERR_TIME_TO_DIE, 1);
	if ((long)args->time_to_die < 0)
		return (EXIT_FAILURE);
	args->time_to_eat = (unsigned long)parse_long_arg(argv[3],
			MSG_ERR_TIME_TO_EAT, 1);
	if ((long)args->time_to_eat < 0)
		return (EXIT_FAILURE);
	args->time_to_sleep = (unsigned long)parse_long_arg(argv[4],
			MSG_ERR_TIME_TO_SLEEP, 1);
	if ((long)args->time_to_sleep < 0)
		return (EXIT_FAILURE);
	if (init_num_times_philo_must_eat(args, argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
