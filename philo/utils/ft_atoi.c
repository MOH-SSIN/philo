/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:50:43 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/15 09:47:48 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_is_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_overflow(long result, int sign)
{
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return (1);
	return (0);
}

static int	ft_is_invalid(const char *str, int i)
{
	while (ft_is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i] || (str[i] < '0' || str[i] > '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i++] - '0') + (result * 10);
		if (ft_overflow(result, sign))
			return (-1);
	}
	if (ft_is_invalid(str, i))
		return (-1);
	return (result * sign);
}
