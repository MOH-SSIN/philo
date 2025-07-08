/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:03 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/08 18:13:16 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_controller	*cntrl;

	cntrl = NULL;
	if (ft_parsin(argc, argv))
		return (ft_putstr_fd("invalid arguments \n", 2), 1);
	if (prepare_simulation(argv,&cntrl))
		return (1);
	// lance_routine(&cntrl);
	return (0);
}

/*
num_philo = ft_atoi_parsing(argv[1])

time_die = argv[2]

time_eat = argv[3]

time_sleep = argv[4]

*/