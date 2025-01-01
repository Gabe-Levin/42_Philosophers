/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:00:58 by glevin            #+#    #+#             */
/*   Updated: 2025/01/01 15:00:42 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
    t_sim sim;

    if (ac < 5 || ac > 6)
    {
        printf(WRONG_INPUT_NUMBER);
        return (1);
    }
    f_init_sim(av, &sim);
    if (f_init_forks(&sim))
        return (1);
    f_init_philos(&sim);
    if (f_create_threads(&sim))
    {
        f_destroy_forks(&sim);
        free(sim.philos);
        return (1);
    }
    f_destroy_forks(&sim);
    free(sim.philos);
    return (0);
}