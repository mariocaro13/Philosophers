/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/07/31 22:58:24 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "messages.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (parse_args(argc, argv, &table.args) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_table(&table) != EXIT_SUCCESS)
	{
		error_print(MSG_ERR_INIT);
		return (cleanup(&table), EXIT_FAILURE);
	}
	start_simulation(&table);
	cleanup(&table);
	return (EXIT_SUCCESS);
}
