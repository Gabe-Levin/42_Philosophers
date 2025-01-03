/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cleanup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:00 by glevin            #+#    #+#             */
/*   Updated: 2025/01/03 10:50:25 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_destroy_forks(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->num_philos)
		pthread_mutex_destroy(&sim->forks[i]);
	free(sim->forks);
}

void	f_cleanup(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->num_philos)
	{
		pthread_mutex_destroy(&sim->philos[i].state_mutex);
	}
	pthread_mutex_destroy(sim->print_mutex);
	pthread_mutex_destroy(sim->stop_mutex);
	f_destroy_forks(sim);
	free(sim->print_mutex);
	free(sim->stop_mutex);
	free(sim->philos);
}
