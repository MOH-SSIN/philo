/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:19 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/15 13:53:09 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_controller	t_controller;

typedef struct s_philo
{
	int				id;
	long			start_time;
	size_t			last_meal;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;

	pthread_t		thread;

	t_controller	*controller;
}	t_philo;

typedef struct s_controller
{
	int				philo_count;

	t_philo			**philos;
	pthread_t		monitor_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	num_eat_mutex;
}	t_controller;

int		ft_atoi(const char *str);
int		ft_parsin(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);

int		init_ctrl(t_controller **ctrl, char **argv);
int		prepare_simulation(char **argv, t_controller **ctrl);
int		lancer_simulation(t_controller **ctrl);
void	free_controller(t_controller *ctrl);

void	*routine(void *arg);
void	*monitor_philos(void *arg);
void	handle_one_philo(t_philo *philo);

void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

bool	all_philos_done(t_controller *ctrl);
void	display_state(t_philo *philo, char *msg);
size_t	get_time_now(void);
void	ft_usleep(size_t ms);

#endif