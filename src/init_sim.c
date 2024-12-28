/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:53 by glevin            #+#    #+#             */
/*   Updated: 2024/12/28 17:55:59 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	atol(char *str)
{
	long	num;
	int		i;

	i = -1;
	while (str[++i])
		num = num * 10 + (str[i] - 48);
	if (num > INT_MAX)
		printf(MAXINT_ERROR);
	return (num);
}

void	*init_sim(char **av, t_sim *sim)
{
	sim->num_philos = atol(av[1]);
	sim->time_to_die = atol(av[2]);
	sim->time_to_eat = atol(av[3]);
	sim->time_to_sleep = atol(av[4]);
	if (av[5])
		sim->num_meals = atol(av[5]);
	else
		sim->num_meals = 0;
}
