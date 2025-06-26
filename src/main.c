/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/26 21:11:13 by mcaro-ro         ###   ########.fr       */
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
	if (init_table(&table, &table.args) != EXIT_SUCCESS)
	{
		error_print(MSG_ERR_INIT);
		return (EXIT_FAILURE);
	}
	cleanup(&table);
	return (EXIT_SUCCESS);
}
