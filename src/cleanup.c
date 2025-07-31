/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:53:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/08/01 00:26:25 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args.num_philos)
	{
		pthread_mutex_destroy(&table->forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->end_simulation_mutex);
	i = 0;
	while (i < table->args.num_philos)
	{
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
		i++;
	}
	free(table->philos);
	free(table->forks);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while (len > 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
		len--;
	}
	return ((unsigned char *)ptr);
}
