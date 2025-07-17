/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:03:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/17 11:35:26 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_ctrl(t_controller **ctrl, char **argv)
{
	int	nb_philo;

	*ctrl = malloc(sizeof(t_controller));
	if (!*ctrl)
		return (-1);
	nb_philo = ft_atoi(argv[1]);
	(*ctrl)->philos = malloc(sizeof(t_philo *) * nb_philo);
	if (!(*ctrl)->philos)
		return (-1);
	(*ctrl)->philo_count = nb_philo;
	(*ctrl)->simulation_stop = false;
	(*ctrl)->forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!(*ctrl)->forks)
		return (-1);
	return (0);
}

int	init_all_mutex(t_controller **ctrl)
{
	int	i;

	i = 0;
	while (i < (*ctrl)->philo_count)
	{
		if (pthread_mutex_init(&(*ctrl)->forks[i], NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&(*ctrl)->print_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*ctrl)->num_eat_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*ctrl)->last_meal_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*ctrl)->stop_mutex, NULL))
		return (-1);
	return (0);
}

t_philo	*new_philo(t_philo *ph, char **argv)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	ph = malloc(sizeof(t_philo));
	if (!ph)
		return (NULL);
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	ph->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ph->last_meal = ph->start_time;
	if (argv[5])
		ph->eat_count = ft_atoi(argv[5]);
	else
		ph->eat_count = -1;
	return (ph);
}

int	setup_philos(t_controller **ctrl, char **argv)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < (*ctrl)->philo_count)
	{
		philo = new_philo((*ctrl)->philos[i], argv);
		if (!philo)
			return (-1);
		(*ctrl)->philos[i] = philo;
		(*ctrl)->philos[i]->id = i + 1;
		(*ctrl)->philos[i]->controller = *ctrl;
		i++;
	}
	return (0);
}

int	prepare_simulation(char **argv, t_controller **cntrl)
{
	if (init_ctrl(cntrl, argv))
		return (1);
	if (init_all_mutex(cntrl))
		return (1);
	if (setup_philos(cntrl, argv))
		return (1);
	return (0);
}
