/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:19:10 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 19:59:24 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_data
{
	int				nmb_ph;
	int				tt_d;
	int				tt_e;
	int				tt_s;
	int				eat_count;
	int				dead;
	int				phil_count;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mute;
	pthread_mutex_t	eatt;
	long int		first_time;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long int		eata;
	int				meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

long		ft_atoi(char *str);
long int	timeof(void);
void		*routine(void *arg);
int			check_args(char **av);
int			alloc_phil(t_data *data, t_philo **philo, char **av);
int			creat_phil(t_data *data, t_philo *philo);
int			my_usleep(t_philo *philo, int time);
int			thinking(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
void		destroy_mutex(t_philo *philo, t_data *data);
int			meals(t_data *data, int ac);
int			_print_(t_philo *philo, char *str);
int			death(t_philo *philo, int i);
int			check_meals(t_philo *philo, int ac);
void		check_it_out(t_philo *philo, int ac, t_data *data);
void		free_every(t_data *data, t_philo *philo);

#endif
