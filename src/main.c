/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/19 21:51:06 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		parse_input(&table, argv);
		//init_data();//TODO: Create table and philosophers
		//simulation_start();//TODO: 
		//clean();//TODO: No leaks
	}
	else
	{
		error_usage();
		return (1);
	}
	return (0);
}
