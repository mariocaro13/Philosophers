/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:34:36 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/20 19:52:16 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/**
*  ____        __ _                 
* |  _ \  ___ / _(_)_ __   ___  ___ 
* | | | |/ _ \ |_| | '_ \ / _ \/ __|
* | |_| |  __/  _| | | | |  __/\__ \
* |____/ \___|_| |_|_| |_|\___||___/
*/

# define MESSAGE_USAGE "Usage: ./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

// EINVAL
# define MESSAGE_EINVAL_MUTEX "The value specified by mutex is invalid."
# define MESSAGE_EINVAL_ATTR "The value specified by attr is invalid."
# define MESSAGE_EINVAL_THREAD "The value specified by thread is not joinable."

// EDEADLK
# define MESSAGE_EDEADLK_MUTEX "A deadlock would occur if the thread blocked waiting for \
mutex."
# define MESSAGE_EDEADLK_THREAD "A deadlock was detected or the value of thread specifies \
the calling thread."

// EPERM
# define MESSAGE_EPERM_MUTEX "The current thread does not hold a lock on mutex."
# define MESSAGE_EPERM_THREAD "The caller does not have appropriate permission."

// ENOMEN
# define MESSAGE_ENOMEN "The process cannot allocate enough memory to create another\
 mutex."

// EBUSY
# define MESSAGE_EBUSY "Mutex is locked."
// EAGAIN
# define MESSAGE_EAGAIN "No resources to create another thread."

// ESRCH
# define MESSAGE_ESRCH "No thread could be found corresponding to that specified by \
the given thread ID, thread."

# define MESSAGE_WRONG_OPCODE_MUTEX "Wrong opcode for mutex handler."
# define MESSAGE_WRONG_OPCODE_THREAD "Wrong opcode for thread handler."

#endif
