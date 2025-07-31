/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:06 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/07/31 23:39:55 by mcaro-ro         ###   ########.fr       */
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

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_args
{
	int		num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_meal_limit;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				meals_counter;
	bool			is_full;
	bool			is_alive;
	long			last_meal_ts;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	eaten_mutex;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_args			args;
	long			start_simulation_ts;
	bool			is_simulation_ended;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	end_simulation_mutex;
	pthread_mutex_t	print_mutex;
}	t_table;

/**
*  ____   _    ____  ____  _____ ____  
* |  _ \ / \  |  _ \/ ___|| ____|  _ \ 
* | |_) / _ \ | |_) \___ \|  _| | |_) |
* |  __/ ___ \|  _ < ___) | |___|  _ < 
* |_| /_/   \_\_| \_\____/|_____|_| \_\
*/

int		parse_args(int argc, char **argv, t_args *args);

/**
*  ___ _   _ ___ _____ 
* |_ _| \ | |_ _|_   _|
*  | ||  \| || |  | |  
*  | || |\  || |  | |  
* |___|_| \_|___| |_|  
*/

int		init_table(t_table *table);

/**
*   ____ _     _____    _    _   _ _   _ ____  
*  / ___| |   | ____|  / \  | \ | | | | |  _ \ 
* | |   | |   |  _|   / _ \ |  \| | | | | |_) |
* | |___| |___| |___ / ___ \| |\  | |_| |  __/ 
*  \____|_____|_____/_/   \_\_| \_|\___/|_|    
*/

void	cleanup(t_table *table);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *str, int fd);

/**
*  ____ ___ __  __ _   _ _        _  _____ ___ ___  _   _ 
* / ___|_ _|  \/  | | | | |      / \|_   _|_ _/ _ \| \ | |
* \___ \| || |\/| | | | | |     / _ \ | |  | | | | |  \| |
*  ___) | || |  | | |_| | |___ / ___ \| |  | | |_| | |\  |
* |____/___|_|  |_|\___/|_____/_/   \_\_| |___\___/|_| \_|
*/

void	start_simulation(t_table *table);
bool	is_simulation_over(t_table *table);

/**
*  __  __  ___  _   _ ___ _____ ___  ____  
* |  \/  |/ _ \| \ | |_ _|_   _/ _ \|  _ \ 
* | |\/| | | | |  \| || |  | || | | | |_) |
* | |  | | |_| | |\  || |  | || |_| |  _ < 
* |_|  |_|\___/|_| \_|___| |_| \___/|_| \_\
*/

void	*monitor(void *arg);
void	print_status(t_philo *philo, const char *msg);
long	ft_get_time(void);
void	smart_sleep(long sleep_time);
bool	die_check(t_table *table, int i, long time_since_last);

/**
*  ____  _   _ ___ _     ___  
* |  _ \| | | |_ _| |   / _ \ 
* | |_) | |_| || || |  | | | |
* |  __/|  _  || || |__| |_| |
* |_|   |_| |_|___|_____\___/ 
*/

void	think(t_philo *philo);
bool	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	release_forks(t_philo *philo);
void	sleep_philo(t_philo *philo);

/**
*  ____  _   _ ___ _     ___    _   _ _____ ___ _     ____  
* |  _ \| | | |_ _| |   / _ \  | | | |_   _|_ _| |   / ___| 
* | |_) | |_| || || |  | | | | | | | | | |  | || |   \___ \ 
* |  __/|  _  || || |__| |_| | | |_| | | |  | || |___ ___) |
* |_|   |_| |_|___|_____\___/   \___/  |_| |___|_____|____/ 
*/

bool	are_philos_full(t_table *table);
bool	is_philo_dead_or_full(t_table *data, int i);

#endif
