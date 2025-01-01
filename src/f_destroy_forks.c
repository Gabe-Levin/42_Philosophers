/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_destroy_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:59:25 by glevin            #+#    #+#             */
/*   Updated: 2025/01/01 15:11:37 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void f_destroy_forks(t_sim *sim)
{
    int i;

    i = -1;
    while (++i < sim->num_philos)
        pthread_mutex_destroy(&sim->forks[i]);
    free(sim->forks);
}
