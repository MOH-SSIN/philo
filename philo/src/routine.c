/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:05:05 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/11 18:18:02 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Le philosophe mange
void	philo_eat(t_philo *philo)
{
	long	now;

	now = get_time_now();
	display_state(philo, "is eating");
	pthread_mutex_lock(&philo->controller->last_meal_mutex);
	philo->last_meal = now;
	pthread_mutex_unlock(&philo->controller->last_meal_mutex);
	pthread_mutex_lock(&philo->controller->num_eat_mutex);
	if (philo->eat_count > 0)
		philo->eat_count--;
	pthread_mutex_unlock(&philo->controller->num_eat_mutex);
	ft_usleep(philo->time_to_eat);
}

// Le philosophe dort
void	philo_sleep(t_philo *philo)
{
	display_state(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

// Le philosophe réfléchit
void	philo_think(t_philo *philo)
{
	display_state(philo, "is thinking");
}
