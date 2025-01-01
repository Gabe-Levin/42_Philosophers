/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:16:38 by glevin            #+#    #+#             */
/*   Updated: 2025/01/01 15:38:32 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	f_create_threads(t_sim *sim)
{
    pthread_t	*threads;     
    int			i;

    threads = malloc(sizeof(pthread_t) * sim->num_philos);
    if (!threads)
        return (1);
    i = -1;
    sim->stop = false;
    while (++i < sim->num_philos)
    {
        if (pthread_create(&threads[i], NULL, f_philo_routine, 
            &sim->philos[i]) != 0)
        {
            sim->stop = true;
            return (1);
        }
    }
    usleep(10);
    f_monitor_philosophers(sim);
    i = -1;
    while (++i < sim->num_philos)
        pthread_join(threads[i], NULL);
    free(threads);
    return (0);
}   