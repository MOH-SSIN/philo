/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:38:07 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/17 11:35:51 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_simulation_stopped(t_controller *ctrl)
{
	bool	stopped;

	pthread_mutex_lock(&ctrl->stop_mutex);
	stopped = ctrl->simulation_stop;
	pthread_mutex_unlock(&ctrl->stop_mutex);
	return (stopped);
}

void	stop_simulation(t_controller *ctrl)
{
	pthread_mutex_lock(&ctrl->stop_mutex);
	ctrl->simulation_stop = true;
	pthread_mutex_unlock(&ctrl->stop_mutex);
}

bool	all_philos_done(t_controller *ctrl)
{
	int	i;

	if (is_simulation_stopped(ctrl))
		return (true);
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

void	display_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->controller->print_mutex);
	if (!is_simulation_stopped(philo->controller))
	{
		printf("%ld %d %s\n",
			get_time_now() - philo->start_time,
			philo->id, msg);
	}
	pthread_mutex_unlock(&philo->controller->print_mutex);
}

size_t	get_time_now(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("Erreur gettimeofday()\n", 2);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(size_t ms)
{
	size_t	start;
	size_t	chek;

	start = get_time_now();
	chek = get_time_now() - start;
	while (chek < ms)
	{
		usleep(100);
		chek = get_time_now() - start;
	}
}
