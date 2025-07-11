/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lancer_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:22:06 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/10 17:32:17 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Vérifie si un philosophe est mort
void	check_if_dead(t_controller *ctrl, bool *someone_died)
{
	int	i;

	i = 0;
	while (i < ctrl->philo_count)
	{
		pthread_mutex_lock(&ctrl->last_meal_mutex);
		if ((get_time_now() - ctrl->philos[i]->last_meal)
			> ctrl->philos[i]->time_to_die)
		{
			pthread_mutex_lock(&ctrl->print_mutex);
			*someone_died = true;
			printf("%ld %d died\n",
				get_time_now() - ctrl->philos[i]->start_time,
				ctrl->philos[i]->id);
			pthread_mutex_unlock(&ctrl->last_meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&ctrl->last_meal_mutex);
		i++;
	}
}

// Thread qui surveille tous les philosophes
void	*controller_philos(void *arg)
{
	t_controller	*ctrl;
	bool			someone_died;

	someone_died = false;
	ctrl = (t_controller *)arg;
	if (ctrl->philo_count == 1)
		return (NULL);
	while (1)
	{
		if (all_philos_done(ctrl))
			break ;
		check_if_dead(ctrl, &someone_died);
		if (someone_died)
			break ;
		ft_usleep(1);
	}
	return (NULL);
}

// Cas spécial : un seul philosophe
void	handle_one_philo(t_philo *philo)
{
	printf("%ld %d has taken a fork\n",
		get_time_now() - philo->start_time, philo->id);
	ft_usleep(philo->time_to_die);
	printf("%ld %d died\n",
		get_time_now() - philo->start_time, philo->id);
}

// Routine principale pour chaque philosophe
void	*routine(void *arg)
{
	t_philo	*philo;
	int		nb;

	philo = (t_philo *)arg;
	nb = philo->controller->philo_count;
	if (nb == 1)
		return (handle_one_philo(philo), NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		if (all_philos_done(philo->controller))
			break ;
		pthread_mutex_lock(&philo->controller->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->controller->forks[philo->id % nb]);
		display_state(philo, "has taken a fork");
		display_state(philo, "has taken a fork");
		philo_eat(philo);
		pthread_mutex_unlock(&philo->controller->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->controller->forks[philo->id % nb]);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

// Lancement de tous les threads (philosophes + moniteur)
int	lancer_simulation(t_controller **cntrl)
{
	int	i;

	i = 0;
	while (i < (*cntrl)->philo_count)
	{
		if (pthread_create(
				&(*cntrl)->philos[i]->thread,
				NULL,
				&routine,
				(*cntrl)->philos[i]))
			return (ft_putstr_fd("Erreur création philo\n", 2), -1);
		i++;
	}
	if (pthread_create(&(*cntrl)->monitor_thread, NULL,
			&controller_philos, (*cntrl)))
		return (ft_putstr_fd("Erreur création moniteur\n", 2), -1);
	return (0);
}
