/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:05:05 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/09 19:41:52 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	long	current_time;

	current_time = ft_get_current_time();
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->controller->last_meal_mutex);
	philo->last_meal = current_time;
	pthread_mutex_unlock(&philo->controller->last_meal_mutex);
	pthread_mutex_lock(&philo->controller->num_eat_mutex);
	if (philo->eat_count > 0)
		philo->eat_count--;
	pthread_mutex_unlock(&philo->controller->num_eat_mutex);
	ft_usleep(philo->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	// long	current_time;

	// current_time = ft_get_current_time();
	print_status(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	// long	current_time;

	// current_time = ft_get_current_time();
	print_status(philo, "is thinking");
}
