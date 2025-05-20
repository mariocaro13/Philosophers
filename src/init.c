/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:28:26 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/20 18:39:35 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_table *table)
{
	table->is_simulation_ended = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->num_philos);
}
