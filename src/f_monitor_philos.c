/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_monitor_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:58:40 by glevin            #+#    #+#             */
/*   Updated: 2025/01/01 15:36:55 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	f_monitor_philosophers(t_sim *sim)
{
    int			i;
    long long	current_time;

    while (!sim->stop)
    {
        i = -1;
        while (++i < sim->num_philos)
        {
            current_time = f_get_time();
            if (current_time - sim->philos[i].last_meal_time > sim->time_to_die)
            {
                f_print_status(&sim->philos[i], "died");
                sim->stop = true;
                break;
            }
            if (sim->num_meals > 0 && 
                sim->philos[i].meal_cnt >= sim->num_meals)
            {
                sim->stop = true;
                break;
            }
        }
        usleep(1000);
    }
}