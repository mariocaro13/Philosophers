/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:37:00 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/26 21:54:53 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdbool.h>

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
 * Parses the input string, skipping any leading whitespace, and converts the
 * subsequent numeric characters into a long integer.
 * Handles optional '+' or '-' sign.
 *
 * @param str The string to convert.
 * @return The converted long integer value.
 */
long	ft_atol(const char *str);

/**
 * @brief Allocates memory safely.
 *
 * Allocates the specified number of bytes and returns a pointer to the allocated
 * memory.
 * If allocation fails, the program will exit with an error.
 *
 * @param bytes Number of bytes to allocate.
 * @return Pointer to the allocated memory.
 */
void	*safe_malloc(size_t bytes);

/**
 * @brief Prints usage instructions for the program.
 *
 * Displays information on how to use the program and its arguments.
 */
void	print_usage(void);

/**
 * @brief Prints an error message to standard error.
 *
 * @param message The error message to display.
 */
void	error_print(const char *message);

#endif
