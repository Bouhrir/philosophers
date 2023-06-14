/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:15:51 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 20:13:55 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mut(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->nmb_ph)
		if (pthread_mutex_init(&p->fork[i++], NULL))
			printf("can't init mutex\n");
	if (pthread_mutex_init(&p->mute, NULL)
		|| pthread_mutex_init(&p->eatt, NULL))
		printf("can't iniiiit mutex\n");
	return (0);
}

void	fill_param(t_philo *philos, t_data *p)
{
	int	i;

	i = 0;
	while (i < p->nmb_ph)
	{
		philos[i].data = p;
		philos[i].left_fork = &p->fork[i];
		philos[i].right_fork = &p->fork[(i + 1) % p->nmb_ph];
		i++;
	}
}

int	creat_phil(t_data *p, t_philo *philos)
{
	int			i;
	long int	time;

	if (init_mut(p))
		return (1);
	fill_param(philos, p);
	p->dead = 0;
	i = 0;
	philos->data->phil_count = p->nmb_ph;
	p->first_time = timeof();
	time = timeof();
	while (i < p->nmb_ph)
	{
		philos[i].eata = time;
		philos[i].id = i + 1;
		philos[i].meal = p->eat_count;
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
		{
			printf("Failed to create the thread\n");
			return (1);
		}
		usleep(200);
		i++;
	}
	return (0);
}
