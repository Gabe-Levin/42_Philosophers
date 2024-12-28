/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:00:58 by glevin            #+#    #+#             */
/*   Updated: 2024/12/28 20:05:03 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_sim *sim;

	if (ac < 5 || ac > 6)
    {
        printf(WRONG_INPUT_NUMER);
		return (1);
    }
	init_sim(av, &sim);
    init_forks(&sim);
	init_philos(&sim);
	// parse arguments
	// create threads
	return (0);
}