/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:03:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/08 16:32:21 by mez-zahi         ###   ########.fr       */
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

int	init_mutexes(t_controller **cntrl)
{
	int	i;

	i = 0;
	while (i < (*cntrl)->philo_count)
		if (pthread_mutex_init(&(*cntrl)->forks[i++], NULL))
			return (-1);
	if (pthread_mutex_init(&(*cntrl)->print_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*cntrl)->num_eat_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*cntrl)->last_meal_mutex, NULL))
		return (-1);
	return (0);
}

t_philo	*creat_philo(t_philo *philo, char *av[])
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	philo->last_meal = philo->start_time;
	if (av[5])
		philo->eat_count = ft_atoi(av[5]);
	else
		philo->eat_count = -1;
	if (pthread_mutex_init(&philo->meal_mutex, NULL))
		return (NULL);
	return (philo);
}

int	init_philos(t_controller **cntrl, char *av[])
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < (*cntrl)->philo_count)
	{
		philo = creat_philo((*cntrl)->philos[i], av);
		if (!philo)
			return (-1);
		(*cntrl)->philos[i] = philo;
		(*cntrl)->philos[i]->id = i + 1;
		(*cntrl)->philos[i]->controller = (*cntrl);
		i++;
	}
	return (0);
}

int	prepare_simulation(char **argv, t_controller **cntrl)
{
    if (init_controller(cntrl, argv))
		return (1);
	if (init_mutexes(cntrl))// j'ai ici !!!
		return (1);
	if (init_philos(cntrl, argv))
		return (1);
	return (0);

}