/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:53 by glevin            #+#    #+#             */
/*   Updated: 2025/01/01 15:25:10 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	f_atol(char *str)
{
    long	num;
    int		i;

    num = 0;
    i = 0;
    if (str[i] == '-')
        return (-1);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if (num > INT_MAX)
    {
        printf(MAXINT_ERROR);
        return (-1);
    }
    return (num);
}

void	f_init_sim(char **av, t_sim *sim)
{
	sim->num_philos = f_atol(av[1]);
	sim->time_to_die = f_atol(av[2]);
	sim->time_to_eat = f_atol(av[3]);
	sim->time_to_sleep = f_atol(av[4]);
	if (av[5])
		sim->num_meals = f_atol(av[5]);
	else
		sim->num_meals = 0;
}
