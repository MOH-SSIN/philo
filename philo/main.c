/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:03 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/09 20:44:30 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	join_threads(t_controller **cntrl)
{
	int	i;

	i = 0;
	if ((*cntrl)->philo_count == 1)
	{
		if (pthread_join((*cntrl)->philos[i]->thread, NULL))
			return (-1);
	}
	else
	{
		while (i < (*cntrl)->philo_count)
		{
			if (pthread_join((*cntrl)->philos[i]->thread, NULL))
				return (-1);
			i++;
		}
	}
	// if (pthread_join((*cntrl)->monitor_thread, NULL))
	// 	return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_controller	*cntrl;

	cntrl = NULL;
	if (ft_parsin(argc, argv))
		return (ft_putstr_fd("invalid arguments \n", 2), 1);
	if (prepare_simulation(argv,&cntrl))
		return (1);
	lancer_simulation(&cntrl);
	join_threads(&cntrl);
	free_controller(cntrl);
	return (0);
}

/*
num_philo = ft_atoi_parsing(argv[1])

time_die = argv[2]

time_eat = argv[3]

time_sleep = argv[4]

*/