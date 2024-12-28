/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:55:15 by glevin            #+#    #+#             */
/*   Updated: 2024/12/28 20:10:29 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
 *  ANSI Sequences for Bold Colors
 */
# define RESET "\033[0m"
# define B_BLK "\033[1;30m" // Bold Black
# define B_RED "\033[1;31m" // Bold Red
# define B_GRN "\033[1;32m" // Bold Green
# define B_YEL "\033[1;33m" // Bold Yellow
# define B_BLU "\033[1;34m" // Bold Blue
# define B_MAG "\033[1;35m" // Bold Magenta
# define B_CYN "\033[1;36m" // Bold Cyan
# define B_WHT "\033[1;37m" // Bold White

/*
 *  Messages
 */
# define MAXINT_ERROR B_RED "Error: TOO BIG DUMMY" RESET
# define WRONG_INPUT_NUMER B_RED "Error: INVALID # OF INPUTS DUMMY" RESET
# define MUTEX_INIT_FAIL B_RED "Error: Mutex initialization failed\n" RESET
/*
 *  Structs
 */
typedef struct s_philo
{
	int				id;
	long			meal_cnt;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_sim	*simulation;
	long			last_meal_time;
}					t_philo;

typedef struct s_sim
{
	long			num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_meals;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_sim;

/*
 *  Prototypes
 */
void				*philosopher_routine(void *arg);
void				init_philos(t_sim *sim);
t_sim				*init_sim(char **av, t_sim *sim);
int					init_forks(t_sim *sim);
void				destory_forks(t_sim *sim);

#endif
