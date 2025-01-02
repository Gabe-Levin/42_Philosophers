/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:56:42 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 15:50:43 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	f_init_philos(t_sim *sim)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * sim->num_philos);
	if (!philos)
	{
		f_destroy_forks(sim);
		return (1);
	}
	i = -1;
	while (++i < sim->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].meal_cnt = 0;
		philos[i].left_fork = &sim->forks[i];
		philos[i].right_fork = &sim->forks[(i + 1) % sim->num_philos];
		philos[i].sim = sim;
		philos[i].last_meal_time = 0;
		if (pthread_mutex_init(&philos[i].state_mutex, NULL) != 0)
		{
			printf(MUTEX_INIT_FAIL);
			while (--i >= 0)
				pthread_mutex_destroy(&philos[i].state_mutex);
			free(philos);
			return (1);
		}
	}
	sim->philos = philos;
	return (0);
}
