/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:39:27 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 15:51:19 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->state_mutex);
	if (!philo->sim->stop)
	{
		pthread_mutex_lock(philo->sim->print_mutex);
		printf("%lld %d %s\n", f_get_time() - philo->sim->start_time, philo->id,
			status);
		pthread_mutex_unlock(philo->sim->print_mutex);
	}
	pthread_mutex_unlock(&philo->state_mutex);
}
