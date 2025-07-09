/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lancer_simulation_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:22:06 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/09 20:23:59 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_philos_death(t_controller *mtr, bool *check_is_died)
{
	int	i;

	i = 0;
	while (i < mtr->philo_count)
	{
		pthread_mutex_lock(&mtr->last_meal_mutex);
		if ((ft_get_current_time() - mtr->philos[i]->last_meal)
			> mtr->philos[i]->time_to_die)
		{
			pthread_mutex_lock(&mtr->print_mutex);
			*check_is_died = true;
			printf("%ld %d died\n",
				ft_get_current_time() - mtr->philos[i]->start_time,
				mtr->philos[i]->id);
			pthread_mutex_unlock(&mtr->last_meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&mtr->last_meal_mutex);
		i++;
	}
}

void	*contoller_philo(void *arg)
{
	t_controller	*cntrl;
	bool	check_is_died;

	check_is_died = false;
	cntrl = (t_controller *)arg;
	if (cntrl->philo_count == 1)
		return (NULL);
	while (1337)
	{
		if (must_eat(cntrl))
			break ;
		check_philos_death(cntrl, &check_is_died);
		if (check_is_died)
			break ;
		ft_usleep(1);
	}
	return (NULL);
}

void	one_philo(t_philo *philo)
{
	printf("%ld %d has taken a fork\n",
		ft_get_current_time() - philo->start_time, philo->id);
	ft_usleep(philo->time_to_die);
	printf("%ld %d died\n",
		ft_get_current_time() - philo->start_time, philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		nbr_philo;

	philo = (t_philo *)arg;
	nbr_philo = philo->controller->philo_count;
	if (nbr_philo == 1)
		return (one_philo(philo), NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		if (must_eat(philo->controller))
			break ;
		pthread_mutex_lock(&philo->controller->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->controller->forks[philo->id % nbr_philo]);
		print_status(philo, "has taken a fork");
		print_status(philo, "has taken a fork");
		ft_eat(philo);
		pthread_mutex_unlock(&philo->controller->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->controller->forks[philo->id % nbr_philo]);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int    lancer_simulation(t_controller **cntrl)
{
    int	i;

	i = 0;
	while (i < (*cntrl)->philo_count)
	{
		if (pthread_create(&(*cntrl)->philos[i]->thread, NULL, &routine, (*cntrl)->philos[i]))
			return(ft_putstr_fd("error create philo\n",2), -1);
		i++;	
	}
	if (pthread_create(&(*cntrl)->monitor_thread, NULL, &contoller_philo, (*cntrl)))
			return(ft_putstr_fd("error create philo\n",2), -1);
	return (0);
}