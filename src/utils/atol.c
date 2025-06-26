/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:19:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/19 22:00:54 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <limits.h>

static bool	is_negative(const char c)
{
	if (c == '-')
	{
		error_print("Invalid input: Negative numbers are not allowed.");
		return (true);
	}
	return (false);
}

static bool	is_valid_digit(const char c)
{
	if (!is_digit(c))
	{
		error_print("Invalid input: Non-numeric characters are not allowed.");
		return (false);
	}
	return (true);
}

static bool	is_too_long(const char *str)
{
	int	len;

	len = 0;
	while (is_digit(*str++))
		len++;
	if (len > 10)
	{
		error_print("Invalid input: Value too big, INT_MAX is the limit.");
		return (true);
	}
	return (false);
}

static const char	*validate_input(const char *str)
{
	const char	*result;

	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	if (is_negative(*str) || !is_valid_digit(*str))
		return (NULL);
	result = str;
	if (is_too_long(str))
		return (NULL);
	return (result);
}

long	ft_atol(const char *str)
{
	long	result;

	result = 0;
	str = validate_input(str);
	if (!str)
		return (-1);
	while (is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (result > INT_MAX)
	{
		error_print("Invalid input: Value too big, INT_MAX is the limit.");
		return (-1);
	}
	return (result);
}
