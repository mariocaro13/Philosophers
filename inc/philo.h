/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:06 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/06/26 21:15:48 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

/**
 *  ____  _                   _       
 * / ___|| |_ _ __ _   _  ___| |_ ___ 
 * \___ \| __| '__| | | |/ __| __/ __|
 *  ___) | |_| |  | |_| | (__| |_\__ \
 * |____/ \__|_|   \__,_|\___|\__|___/
 */

/**
 * @struct s_args
 * @brief Stores the configuration arguments for the simulation.
 *
 * Holds the main parameters that define the simulation's behavior.
 * @var num_philos Number of philosophers participating in the simulation.
 * @var time_to_die Maximum time (in ms) a philosopher can go without eating
 * before dying.
 * @var time_to_eat Time (in ms) it takes for a philosopher to eat.
 * @var time_to_sleep Time (in ms) a philosopher spends sleeping after eating.
 * @var num_meal_limit Number of meals each philosopher must eat before the
 * simulation ends (0 = no limit).
 */
typedef struct s_args
{
	int				num_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_meal_limit;
}	t_args;

/**
 * @struct s_philo
 * @brief Represents a philosopher in the simulation.
 *
 * Stores the individual state of each philosopher and references to the
 * resources they use.
 * @var id Unique identifier for the philosopher.
 * @var meals_counter Number of meals the philosopher has eaten.
 * @var last_meal_ts Timestamp (in ms) of the last meal eaten.
 * @var left_fork Pointer to the left fork (mutex).
 * @var right_fork Pointer to the right fork (mutex).
 * @var table Reference to the main table structure.
 */
typedef struct s_philo
{
	int				id;
	int				meals_counter;
	unsigned long	last_meal_ts;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}	t_philo;

/**
 * @struct s_table
 * @brief Represents the dining table and the global state of the simulation.
 *
 * Manages shared resources, philosophers, and synchronization.
 * @var args Configuration arguments.
 * @var philos Array of philosophers.
 * @var threads Array of philosopher threads.
 * @var forks Array of mutexes for the forks.
 * @var print_mutex Mutex for synchronized printing.
 * @var end_mutex Mutex that guards access to is_simulation_ended.
 * @var is_simulation_ended Flag indicating if the simulation has ended.
 * @var start_simulation_ts Timestamp (in ms) marking the start of the
 * simulation.
 */
typedef struct s_table
{
	t_args			args;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
	bool			is_simulation_ended;
	unsigned long	start_simulation_ts;
}	t_table;

/**
 * @brief Parses and validates the input arguments.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param args Pointer to the arguments structure to fill.
 * @return 0 on success, non-zero on error.
 */
int		parse_args(int argc, char **argv, t_args *args);

/**
 * @brief Initializes the table, philosophers, and resources.
 * @param table Pointer to the table structure.
 * @param args Pointer to the arguments structure.
 * @return 0 on success, non-zero on error.
 */
int		init_table(t_table *table, t_args *args);

/**
 * @brief Main routine for each philosopher (thread function).
 * @param arg Pointer to the philosopher (t_philo*).
 * @return NULL.
 */
void	*philo_routine(void *arg);

/**
 * @brief Monitors the state of philosophers and detects end conditions.
 * @param table Pointer to the table structure.
 */
void	monitor_routine(t_table *table);

/**
 * @brief Frees all resources and memory used in the simulation.
 * @param table Pointer to the table structure.
 */
void	cleanup(t_table *table);

#endif
