/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:56:42 by glevin            #+#    #+#             */
/*   Updated: 2024/12/28 20:10:15 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_sim *sim)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * sim->num_philos);
	if (!philos)
		return (NULL);
	i = -1;
	while (++i)
	{
		philos[i].id = i + 1;
		philos[i].meal_cnt = 0;
		philos[i].left_fork = &sim->forks[i];
		philos[i].right_fork = &sim->forks[(i + 1) % sim->num_philos];
		philos[i].simulation = sim;
		philos[i].last_meal_time = 0;
	}
	return (philos);
}
