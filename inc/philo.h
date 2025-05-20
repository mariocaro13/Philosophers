/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:06 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/20 19:35:51 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
*  ___       _                _           
* |_ _|_ __ | | ___ _   _  __| | ___  ___ 
*  | || '_ \| |/ __| | | |/ _` |/ _ \/ __|
*  | || | | | | (__| |_| | (_| |  __/\__ \
* |___|_| |_|_|\___|\__,_|\__,_|\___||___/
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>
# include <sys/time.h>

# include "ansi_colors.h"
# include "utils.h"
# include "messages.h"

/**
*  _____                     _       __     
* |_   _|   _ _ __   ___  __| | ___ / _|___ 
*   | || | | | '_ \ / _ \/ _` |/ _ \ |_/ __|
*   | || |_| | |_) |  __/ (_| |  __/  _\__ \
*   |_| \__, | .__/ \___|\__,_|\___|_| |___/
*       |___/|_|                            
*/

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

/**
 * @brief Represents a fork in the dining philosophers simulation.
 * 
 * @fork: Mutex for thread-safe fork access.
 * @fork_id: Unique identifier for the fork.
 */
typedef struct s_fork
{
	pthread_mutex_t	fork;
	long			fork_id;
}	t_fork;

/**
 * @brief Represents a philosopher in the simulation.
 * 
 * struct s_philo - Represents a philosopher in the simulation.
 * @id: Unique identifier for the philosopher.
 * @meals_counter: Number of meals the philosopher has eaten.
 * @full: Boolean indicating if the philosopher is full.
 * @last_meal_time: Timestamp of the last meal eaten by the philosopher.
 * 					Tracks time since the last meal to check for starvation.
 * @left_fork: Pointer to the left fork.
 * @right_fork: Pointer to the right fork.
 * @thread_id: Thread ID associated with the philosopher.
 */
typedef struct s_philo
{
	long			id;
	long			meals_counter;
	bool			full;
	struct timeval	last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	t_table			*table;
}	t_philo;

/**
 * @struct s_table
 * @brief Represents the dining philosophers' table and its associated data.
 * 
 * This structure contains all the necessary information to manage the simulation
 * of the dining philosophers problem, including the number of philosophers, 
 * timing constraints, and synchronization mechanisms.
 * 
 * @var s_table::num_philos
 * Number of philosophers participating in the simulation.
 * 
 * @var s_table::time_to_die
 * Maximum time (milliseconds) a philosopher can go without eating before dying.
 * 
 * @var s_table::time_to_eat
 * Time (in milliseconds) it takes for a philosopher to eat.
 * 
 * @var s_table::time_to_sleep
 * Time (in milliseconds) a philosopher spends sleeping after eating.
 * 
 * @var s_table::num_meal_limit
 * Limit on the number of meals each philosopher must eat before simulation ends.
 * If set to 0, there is no meal limit.
 * 
 * @var s_table::start_simulation_time
 * Timestamp (in milliseconds) marking the start of the simulation.
 * 
 * @var s_table::simulation_ended
 * Boolean flag indicating whether the simulation has ended.
 * 
 * @var s_table::forks
 * Pointer to an array of t_fork structures representing the forks on the table.
 * 
 * @var s_table::philos
 * Pointer to an array of t_philo structures representing the philosophers.
 */
typedef struct s_table
{
	long	num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_meal_limit;
	long	start_simulation_time;
	bool	is_simulation_ended;
	t_fork	*forks;
	t_philo	*philos;
}	t_table;

/**
*  _____                           
* | ____|_ __  _   _ _ __ ___  ___ 
* |  _| | '_ \| | | | '_ ` _ \/ __|
* | |___| | | | |_| | | | | | \__ \
* |_____|_| |_|\__,_|_| |_| |_|___/
*/

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

/**
*  ____            _        _                         
* |  _ \ _ __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
* | |_) | '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
* |  __/| | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
* |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
*                               |___/|_|              
*/

/**
 * @brief Prints an error message to the standard error output.
 *
 * This function displays the specified error message, typically used to
 * report errors encountered during program execution.
 *
 * @param message The error message to be printed.
 */
void	error_print(const char *message);

/**
 * @brief Prints the usage instructions for the program.
 *
 * This function displays information on how to use the program,
 * including the expected command-line arguments and their descriptions.
 * It is typically called when the user provides incorrect arguments
 * or requests help.
 */
void	error_usage(void);

/**
 * @brief Parses the command-line input arguments and initializes the table
 * structure.
 *
 * This function processes the arguments provided in argv, extracts the necessary
 * parameters, and populates the fields of the t_table structure accordingly.
 *
 * @param table Pointer to the t_table structure to be initialized.
 * @param argv  Array of strings containing the command-line arguments.
 */
void	parse_input(t_table *table, char **argv);

void	init_data(t_table *table);

#endif
