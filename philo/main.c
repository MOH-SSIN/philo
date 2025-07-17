/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:03 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/17 15:48:00 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	end_threads(t_controller **ctrl)
{
	int	i;

	i = 0;
	if ((*ctrl)->philo_count == 1)
	{
		if (pthread_join((*ctrl)->philos[0]->thread, NULL))
			return (-1);
	}
	else
	{
		while (i < (*ctrl)->philo_count)
		{
			if (pthread_join((*ctrl)->philos[i]->thread, NULL))
				return (-1);
			i++;
		}
	}
	if (pthread_join((*ctrl)->monitor_thread, NULL))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_controller	*cntrl;

	cntrl = NULL;
	if (ft_parsin(argc, argv))
		return (ft_putstr_fd("invalid arguments \n", 2), 1);
	if (prepare_simulation(argv, &cntrl))
		return (1);
	lancer_simulation(&cntrl);
	end_threads(&cntrl);
	free_controller(cntrl);
	return (0);
}
