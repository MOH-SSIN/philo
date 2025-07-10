/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:39:14 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/10 17:47:57 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

#include "../include/philo.h"

// Libère la mémoire de chaque philosophe et détruit son mutex
void	clean_philos(t_controller *cntrl)
{
	int	i;

	i = 0;
	while (i < cntrl->philo_count)
	{
		if (cntrl->philos[i])
		{
			pthread_mutex_destroy(&cntrl->philos[i]->meal_mutex);
			free(cntrl->philos[i]);
		}
		i++;
	}
	free(cntrl->philos);
}

// Détruit les mutex globaux (print et eat counter)
void	clean_global_mutex(t_controller *cntrl)
{
	pthread_mutex_destroy(&cntrl->print_mutex);
	pthread_mutex_destroy(&cntrl->num_eat_mutex);
	pthread_mutex_destroy(&cntrl->last_meal_mutex);
}

// Libère toutes les ressources du contrôleur
void	free_controller(t_controller *cntrl)
{
	int	i;

	if (!cntrl)
		return ;
	if (cntrl->philos)
		clean_philos(cntrl);
	if (cntrl->forks)
	{
		i = 0;
		while (i < cntrl->philo_count)
			pthread_mutex_destroy(&cntrl->forks[i++]);
		free(cntrl->forks);
	}
	clean_global_mutex(cntrl);
	free(cntrl);
}

