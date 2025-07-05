/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:19 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/05 18:42:39 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

int				ft_atoi(const char *str);
int				ft_parsin(int argc, char **argv);
void			ft_putstr_fd(char const *s, int fd);
size_t			ft_strlen(const char *s);

#endif