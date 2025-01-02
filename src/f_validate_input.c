/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_validate_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:17:52 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 13:51:59 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	f_validate_input(t_sim *sim)
{
	if (sim->time_to_die == -1 || sim->time_to_die < 60)
	{
		printf(INVALID_INPUT);
		return (1);
	}
	if (sim->time_to_eat == -1 || sim->time_to_eat < 60)
	{
		printf(INVALID_INPUT);
		return (1);
	}
	if (sim->time_to_sleep == -1 || sim->time_to_sleep < 60)
	{
		printf(INVALID_INPUT);
		return (1);
	}
	if (sim->num_meals == -1 || sim->num_philos < 1 || sim->num_philos > 200)
	{
		printf(INVALID_INPUT);
		return (1);
	}
	return (0);
}
