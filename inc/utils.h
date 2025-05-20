/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:37:00 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/20 19:34:24 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/**
*  ____            _        _                         
* |  _ \ _ __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
* | |_) | '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
* |  __/| | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
* |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
*                               |___/|_|              
*/

/**
 * @brief Checks if the given character is a whitespace character.
 *
 * @param c The character to check.
 * @return true if the character is a whitespace (such as space, tab, etc.)
 * , false otherwise.
 */
bool	is_space(const char c);

/**
 * @brief Checks if the given character is a digit (0-9).
 *
 * @param c The character to check.
 * @return true if the character is a digit, false otherwise.
 */
bool	is_digit(const char c);

/**
 * @brief Converts a string to a long integer.
 *
 * This function parses the input string, skipping any leading whitespace,
 * and converts the subsequent numeric characters into a long integer.
 * Handles optional '+' or '-' sign.
 *
 * @param str The string to convert.
 * @return The converted long integer value.
 */
long	ft_atol(const char *str);

void	*safe_malloc(size_t bytes);

#endif
