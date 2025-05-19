/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:16:28 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/19 20:37:52 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_print(const char *message)
{
	printf(ANSI_RED "Error: %s\n" ANSI_RESET, message);
}

void	error_usage(void)
{
	error_print("Invalid number of arguments.");
	printf(ANSI_BLUE USAGE ANSI_RESET);
}
