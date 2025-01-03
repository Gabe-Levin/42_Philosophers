/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:12:25 by glevin            #+#    #+#             */
/*   Updated: 2025/01/03 10:40:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	f_eat(t_philo *philo);
static void	f_sleep(t_philo *philo);
static void	f_think(t_philo *philo);

void	*f_philo_routine(void *arg)
{
	t_philo	*philo;

	bool should_continue ;
	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_meal_time = f_get_time();
	pthread_mutex_unlock(&philo->state_mutex);
	if (philo->id % 2 == 0)
		usleep(100);
	should_continue = true;
	while (should_continue)
	{
		pthread_mutex_lock(philo->sim->stop_mutex);
		should_continue = !philo->sim->stop;
		pthread_mutex_unlock(philo->sim->stop_mutex);
		if (should_continue)
		{
			f_take_forks(philo);
			f_eat(philo);
			f_release_forks(philo);
			f_sleep(philo);
			f_think(philo);
		}
	}
	return (NULL);
}

static void	f_eat(t_philo *philo)
{
	f_print_status(philo, "is eating");
	pthread_mutex_lock(&philo->state_mutex);
	philo->last_meal_time = f_get_time();
	philo->meal_cnt++;
	pthread_mutex_unlock(&philo->state_mutex);
	usleep(philo->sim->time_to_eat * 1000);
}

static void	f_sleep(t_philo *philo)
{
	f_print_status(philo, "is sleeping");
	usleep(philo->sim->time_to_sleep * 1000);
}

static void	f_think(t_philo *philo)
{
	f_print_status(philo, "is thinking");
	if (philo->sim->num_philos % 2 != 0)
		usleep(philo->sim->min_time_to_think * 1000);
}
