/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:50:51 by glevin            #+#    #+#             */
/*   Updated: 2025/01/01 15:02:10 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	f_init_forks(t_sim *sim)
{
	int i;
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philos);
	if (!sim->forks)
		return (1);
	i = -1;
	while (++i < sim->num_philos)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
		{
			printf(MUTEX_INIT_FAIL);
			return (1);
		}
	}
	return (0);
}
