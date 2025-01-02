/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:53 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 16:17:31 by glevin           ###   ########.fr       */
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

int	f_init_sim(char **av, t_sim *sim)
{
	sim->num_philos = f_atol(av[1]);
	sim->time_to_die = f_atol(av[2]);
	sim->time_to_eat = f_atol(av[3]);
	sim->time_to_sleep = f_atol(av[4]);
	if (av[5])
		sim->num_meals = f_atol(av[5]);
	else
		sim->num_meals = 0;
	sim->min_time_to_think = (sim->time_to_eat + sim->time_to_sleep) / 2;
	sim->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!sim->print_mutex)
		return (1);
	if (pthread_mutex_init(sim->print_mutex, NULL) != 0)
	{
		printf(MUTEX_INIT_FAIL);
		free(sim->print_mutex);
		return (1);
	}
	sim->stop_mutex = malloc(sizeof(pthread_mutex_t));
	if (!sim->stop_mutex)
	{
		free(sim->print_mutex);
		return (1);
	}
	if (pthread_mutex_init(sim->stop_mutex, NULL) != 0)
	{
		printf(MUTEX_INIT_FAIL);
		free(sim->stop_mutex);
		return (1);
	}
	return (f_validate_input(sim));
}
