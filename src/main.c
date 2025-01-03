/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:00:58 by glevin            #+#    #+#             */
/*   Updated: 2025/01/03 10:50:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_sim	sim;

	if (ac < 5 || ac > 6)
	{
		printf(WRONG_INPUT_NUMBER);
		return (1);
	}
	if (f_init_sim(av, &sim))
		return (2);
	if (f_init_forks(&sim))
		return (3);
	if (f_init_philos(&sim))
		return (4);
	if (f_create_threads(&sim))
	{
		f_cleanup(&sim);
		return (5);
	}
	f_cleanup(&sim);
	return (0);
}
