/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:38:07 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/09 17:55:01 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	must_eat(t_controller *cntrl)
{
	int	i;

	i = 0;
	while (i < cntrl->philo_count)
	{
		pthread_mutex_lock(&cntrl->num_eat_mutex);
		if (cntrl->philos[i]->eat_count != 0)
		{
			pthread_mutex_unlock(&cntrl->num_eat_mutex);
			return (false);
		}
		pthread_mutex_unlock(&cntrl->num_eat_mutex);
		i++;
	}
	return (true);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->controller->print_mutex);
	printf("%ld %d %s\n",
		ft_get_current_time() - philo->start_time,
		philo->id, status);
	pthread_mutex_unlock(&philo->controller->print_mutex);
}

size_t	ft_get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("gettimeofday() error\n", 2);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


void	ft_usleep(size_t milliseconds)
{
	size_t	start;
	size_t	test;

	start = ft_get_current_time();
	test = ft_get_current_time() - start;
	while (test < milliseconds)
	{
		usleep(100);
		test = ft_get_current_time() - start;
	}
}