/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:12:25 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 13:01:58 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	f_take_forks(t_philo *philo)
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

static void	f_release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	*f_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_time = f_get_time();
	if (philo->id % 2 == 0)
		usleep(100);
	while (!philo->sim->stop)
	{
		f_take_forks(philo);
		f_print_status(philo, "is eating");
		philo->last_meal_time = f_get_time();
		usleep(philo->sim->time_to_eat * 1000);
		philo->meal_cnt++;
		f_release_forks(philo);
		f_print_status(philo, "is sleeping");
		usleep(philo->sim->time_to_sleep * 1000);
		f_print_status(philo, "is thinking");
		if (philo->sim->num_philos % 2 != 0)
			usleep(philo->sim->min_time_to_think * 1000);
	}
	return (NULL);
}
