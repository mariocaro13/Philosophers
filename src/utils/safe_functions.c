/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:31:33 by mcaro-ro          #+#    #+#             */
/*   Updated: 2025/05/20 20:02:57 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc (bytes);
	if (NULL == ret)
	{
		error_print("Memory allocation failed.");
		return (NULL);
	}
	return (ret);
}

static int	handle_mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return (0);
	if ((EINVAL == status) && (LOCK == opcode || UNLOCK == opcode
			|| DESTROY == opcode))
		error_print(MESSAGE_EINVAL_MUTEX);
	else if ((EINVAL == status) && (INIT == opcode))
		error_print(MESSAGE_EINVAL_ATTR);
	else if (EDEADLK == status)
		error_print(MESSAGE_EDEADLK_MUTEX);
	else if (EPERM == status)
		error_print(MESSAGE_EPERM_MUTEX);
	else if (ENOMEM == status)
		error_print(MESSAGE_ENOMEN);
	else if (EBUSY == status)
		error_print(MESSAGE_EBUSY);
	return (1);
}

int	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
	{
		if (handle_mutex_error(pthread_mutex_lock(mutex), opcode) == 0)
			return (0);
	}
	else if (UNLOCK == opcode)
	{
		if (handle_mutex_error(pthread_mutex_unlock(mutex), opcode) == 0)
			return (0);
	}
	else if (INIT == opcode)
	{
		if (handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode) == 0)
			return (0);
	}
	else if (DESTROY == opcode)
	{
		if (handle_mutex_error(pthread_mutex_destroy(mutex), opcode) == 0)
			return (0);
	}
	else
		error_print(MESSAGE_WRONG_OPCODE_MUTEX);
	return (1);
}

static int	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return (0);
	if (EAGAIN == status)
		error_print(MESSAGE_EAGAIN);
	else if (EPERM == status)
		error_print(MESSAGE_EPERM_THREAD);
	else if ((EINVAL == status) && (CREATE == opcode))
		error_print(MESSAGE_EINVAL_ATTR);
	else if ((EINVAL == status) && (JOIN == opcode || DETACH == opcode))
		error_print(MESSAGE_EINVAL_THREAD);
	else if (ESRCH == status)
		error_print(MESSAGE_ESRCH);
	else if (EDEADLK == status)
		error_print(MESSAGE_EDEADLK_THREAD);
	return (1);
}

int	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
	void *data, t_opcode opcode)
{
	if (CREATE == opcode)
	{
		if (handle_thread_error(pthread_create(thread, NULL, foo, data),
				opcode) == 0)
			return (0);
	}
	else if (JOIN == opcode)
	{
		if (handle_thread_error(pthread_join(*thread, NULL), opcode) == 0)
			return (0);
	}
	else if (DETACH == opcode)
	{
		if (handle_thread_error(pthread_detach(*thread), opcode) == 0)
			return (0);
	}
	else
		error_print(MESSAGE_WRONG_OPCODE_THREAD);
	return (1);
}
