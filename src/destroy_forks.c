/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:59:25 by glevin            #+#    #+#             */
/*   Updated: 2024/12/28 18:01:15 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void destory_forks(t_sim *sim)
{
    int i;

    i = -1;
    while (++i < sim->num_philos)
        pthread_mutex_destroy(&sim->forks[i]);
    free(sim->forks);
}
