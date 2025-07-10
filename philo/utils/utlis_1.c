/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:38:07 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/10 17:41:52 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


#include "../include/philo.h"

// Vérifie si tous les philosophes ont fini de manger
bool	all_philos_done(t_controller *ctrl)
{
	int	i;

	i = 0;
	while (i < ctrl->philo_count)
	{
		pthread_mutex_lock(&ctrl->num_eat_mutex);
		if (ctrl->philos[i]->eat_count != 0)
		{
			pthread_mutex_unlock(&ctrl->num_eat_mutex);
			return (false);
		}
		pthread_mutex_unlock(&ctrl->num_eat_mutex);
		i++;
	}
	return (true);
}

// Affiche l'état d'un philosophe avec son timestamp
void	display_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->controller->print_mutex);
	printf("%ld %d %s\n",
		get_time_now() - philo->start_time,
		philo->id, msg);
	pthread_mutex_unlock(&philo->controller->print_mutex);
}

// Retourne l'heure actuelle en millisecondes
size_t	get_time_now(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("Erreur gettimeofday()\n", 2);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// Usleep personnalisé pour une attente précise
void	ft_usleep(size_t ms)
{
	size_t	start;
	size_t	elapsed;

	start = get_time_now();
	elapsed = get_time_now() - start;
	while (elapsed < ms)
	{
		usleep(100);
		elapsed = get_time_now() - start;
	}
}

//
// bool	must_eat(t_controller *cntrl)
// {
// 	int	i;

// 	i = 0;
// 	while (i < cntrl->philo_count)
// 	{
// 		pthread_mutex_lock(&cntrl->num_eat_mutex);
// 		if (cntrl->philos[i]->eat_count != 0)
// 		{
// 			pthread_mutex_unlock(&cntrl->num_eat_mutex);
// 			return (false);
// 		}
// 		pthread_mutex_unlock(&cntrl->num_eat_mutex);
// 		i++;
// 	}
// 	return (true);
// }

// void	print_status(t_philo *philo, char *status)
// {
// 	pthread_mutex_lock(&philo->controller->print_mutex);
// 	printf("%ld %d %s\n",
// 		ft_get_current_time() - philo->start_time,
// 		philo->id, status);
// 	pthread_mutex_unlock(&philo->controller->print_mutex);
// }

// size_t	ft_get_current_time(void)
// {
// 	struct timeval	tv;

// 	if (gettimeofday(&tv, NULL) == -1)
// 		ft_putstr_fd("gettimeofday() error\n", 2);
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }


// void	ft_usleep(size_t milliseconds)
// {
// 	size_t	start;
// 	size_t	test;

// 	start = ft_get_current_time();
// 	test = ft_get_current_time() - start;
// 	while (test < milliseconds)
// 	{
// 		usleep(100);
// 		test = ft_get_current_time() - start;
// 	}
// }