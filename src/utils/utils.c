/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:39:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/26 21:12:00 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ansi_colors.h"
#include "messages.h"
#include <stdio.h>

bool	is_space(const char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc (bytes);
	if (NULL == ret)
	{
		error_print(MSG_ERR_MEMORY_ALLOC);
		return (NULL);
	}
	return (ret);
}

void	error_print(const char *message)
{
	printf(COLOR_RED MSG_ERR COLOR_RESET "%s\n", message);
}

void	print_usage(void)
{
	printf(COLOR_YELLOW MSG_USAGE COLOR_RESET);
}
