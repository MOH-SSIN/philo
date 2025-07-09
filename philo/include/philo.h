/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:19 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/07/09 20:49:37 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
# include <sys/time.h>
# include <limits.h>


typedef struct s_controller	t_controller;
typedef struct s_philo
{
	pthread_mutex_t	meal_mutex;        // protège last_meal de CE philosophe
	pthread_t		thread;            // thread du philosophe

	int				id;                // son numéro (1, 2, 3, ...)
	long			start_time;        // heure de départ
	size_t			time_to_die;       // temps avant de mourir sans manger
	int				time_to_eat;       // combien de temps pour manger
	int				time_to_sleep;     // combien de temps pour dormir
	size_t			last_meal;         // moment du dernier repas
	int				eat_count;         // combien de repas faits

	t_controller	*controller;       // lien vers la structure principale
	int				eat_limit;         // nombre de repas à faire (par philosophe)
}	t_philo;

typedef struct s_controller
{
	pthread_mutex_t	print_mutex;       // protège printf
	pthread_mutex_t	last_meal_mutex;   // protège le champ last_meal
	pthread_mutex_t	num_eat_mutex;     // protège le nombre de repas

	pthread_mutex_t	*forks;            // tableau de fourchettes (1 par philosophe)
	pthread_t		monitor_thread;    // thread qui surveille les philosophes

	t_philo			**philos;          // tableau de pointeurs vers les philosophes
	int				philo_count;       // nombre total de philosophes
	int				stop_flag;         // indique si on doit arrêter (1 = oui)
	int				eat_goal;          // nombre de repas à faire (si précisé)
	int				ready_count;       // combien de philosophes sont prêts
}	t_controller;


int				ft_atoi(const char *str);
int				ft_parsin(int argc, char **argv);
void			ft_putstr_fd(char const *s, int fd);
size_t			ft_strlen(const char *s);
int				prepare_simulation(char **argv, t_controller **cntrl);

//
int				lancer_simulation(t_controller **cntrl);
void			*routine(void *arg);

bool			must_eat(t_controller *cntrl);
void			print_status(t_philo *philo, char *status);
size_t			ft_get_current_time(void);
void			ft_usleep(size_t milliseconds);


void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

//ft_free.c
void	free_controller(t_controller *cntrl);

#endif