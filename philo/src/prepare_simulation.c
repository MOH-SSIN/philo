/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:03:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/07 18:17:45 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_controller(t_controller **ctrl, char **argv)
{
	int nb_philo;

	*ctrl = (t_controller *)malloc(sizeof(t_controller));
	if (!*ctrl)
		return (-1);
	nb_philo = ft_atoi(argv[1]);
	(*ctrl)->philos = (t_philo **)malloc(sizeof(t_philo *) * nb_philo);
	if (!(*ctrl)->philos)
		return (-1);
	(*ctrl)->philo_count = nb_philo;
	(*ctrl)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!(*ctrl)->forks)
		return (-1);
	(*ctrl)->ready_count = 0;
	return (0);
}


int	prepare_simulation(char **argv, t_controller **cntrl)
{
    if (init_controller(cntrl, argv))
		return (1);
	// if (init_mutexes(cntrl))/ j'ai ici !!!
	// 	return (1);
	// if (init_philos(cntrl, argv))
	// 	return (1);
	return (0);

}