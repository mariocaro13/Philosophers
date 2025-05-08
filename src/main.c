/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/08 13:39:41 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (5 == argc || 6 == argc)
	{
		printf("Starting simulation with %s philosophers.\n", argv[1]);
		printf("Time to die: %s ms\n", argv[2]);
		printf("Time to eat: %s ms\n", argv[3]);
		printf("Time to sleep: %s ms\n", argv[4]);
		if (6 == argc)
			printf("Number of meals limit: %s\n", argv[5]);
		else
			printf("No meal limit.\n");
		printf("Simulation started.\n");
		return (1);
	}
	else
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	return (0);
}
