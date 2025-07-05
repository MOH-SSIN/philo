/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:03 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/05 18:29:05 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	if (ft_parsin(argc, argv))
		return (ft_putstr_fd("invalid arguments \n", 2), 1);
	return (0);
}
