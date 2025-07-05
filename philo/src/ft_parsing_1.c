/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:47:31 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/05 18:37:45 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_chek_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_parsin(int argc, char **argv)
{
	if (ft_chek_argv(argv))
		return (-1);
	if (argc < 5 || argc > 6)
		return (-1);
	if (ft_atoi(argv[1]) > 200)
		return (-1);
	return (0);
}
