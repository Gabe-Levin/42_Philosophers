/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:55:15 by glevin            #+#    #+#             */
/*   Updated: 2025/01/02 13:38:46 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
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
# define MAXINT_ERROR "Error: TOO BIG DUMMY\n"
# define WRONG_INPUT_NUMBER "Error: Invalid # of inputs dummy\n"
# define INVALID_INPUT "Error: Invalid inputs dummy\n"
# define MUTEX_INIT_FAIL "Error: Mutex initialization failed\n"

/*
 *  Structs
 */
typedef struct s_philo
{
	int				id;
	long			meal_cnt;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_sim	*sim;
	long			last_meal_time;
}					t_philo;

typedef struct s_sim
{
	long			num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			min_time_to_think;
	long			num_meals;
	long			start_time;
	bool			stop;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_sim;

/*
 *  Prototypes
 */
void				*f_philo_routine(void *arg);
int					f_init_philos(t_sim *sim);
int					f_init_sim(char **av, t_sim *sim);
int					f_init_forks(t_sim *sim);
void				f_destroy_forks(t_sim *sim);
long long			f_get_time(void);
void				f_print_status(t_philo *philo, char *status);
int					f_create_threads(t_sim *sim);
void				f_monitor_philosophers(t_sim *sim);
void				f_destroy_threads(t_sim *sim);
int					f_validate_input(t_sim *sim);

#endif
