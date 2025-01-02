/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_monitor_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:58:40 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 16:53:16 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	f_is_sim_stopped(t_sim *sim);
static int	f_is_philo_dead(t_sim *sim, t_philo *philo);
static int	f_is_philo_full(t_sim *sim, t_philo *philo);

void	f_monitor_philosophers(t_sim *sim)
{
	int		i;
	bool	is_everyone_full;

	while (1)
	{
		if (f_is_sim_stopped(sim))
			break ;
		is_everyone_full = true;
		i = -1;
		while (++i < sim->num_philos)
		{
			if (f_is_philo_dead(sim, &sim->philos[i]))
				break ;
			if (!f_is_philo_full(sim, &sim->philos[i]))
				is_everyone_full = false;
		}
		if (is_everyone_full)
		{
			pthread_mutex_lock(sim->stop_mutex);
			sim->stop = true;
			pthread_mutex_unlock(sim->stop_mutex);
			break ;
		}
		usleep(10);
	}
}

static int	f_is_sim_stopped(t_sim *sim)
{
	pthread_mutex_lock(sim->stop_mutex);
	if (sim->stop)
	{
		pthread_mutex_unlock(sim->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(sim->stop_mutex);
	return (0);
}

static int	f_is_philo_dead(t_sim *sim, t_philo *philo)
{
	long long	current_time;

	current_time = f_get_time();
	pthread_mutex_lock(&philo->state_mutex);
	if (current_time - philo->last_meal_time > sim->time_to_die)
	{
		pthread_mutex_unlock(&philo->state_mutex);
		f_print_status(philo, "died");
		pthread_mutex_lock(sim->stop_mutex);
		sim->stop = true;
		pthread_mutex_unlock(sim->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->state_mutex);
	return (0);
}

static int	f_is_philo_full(t_sim *sim, t_philo *philo)
{
	pthread_mutex_lock(&philo->state_mutex);
	if (sim->num_meals > 0 && philo->meal_cnt >= sim->num_meals)
	{
		pthread_mutex_unlock(&philo->state_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->state_mutex);
	return (0);
}
