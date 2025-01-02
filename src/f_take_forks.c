/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_take_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:58:12 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 16:00:56 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		f_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		f_print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		f_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		f_print_status(philo, "has taken a fork");
	}
}
