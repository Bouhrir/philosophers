/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_dest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:39:30 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 19:57:55 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_every(t_data *data, t_philo *philo)
{
	free(data->fork);
	free(philo);
	free(data);
}

void	destroy_mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->nmb_ph)
	{
		pthread_mutex_destroy(&philo->data->fork[i]);
		i++;
	}
	free(philo->data->fork);
	pthread_mutex_destroy(&philo->data->eatt);
	pthread_mutex_destroy(&philo->data->mute);
	free(philo);
	free(data);
}

int	alloc_phil(t_data *data, t_philo **philosopher, char **av)
{
	t_philo	*philo;

	data->nmb_ph = ft_atoi(av[1]);
	data->tt_d = ft_atoi(av[2]);
	data->tt_e = ft_atoi(av[3]);
	data->tt_s = ft_atoi(av[4]);
	if (av[5])
		data->eat_count = ft_atoi(av[5]);
	else
		data->eat_count = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nmb_ph);
	if (!data->fork)
		return (1);
	philo = malloc(sizeof(t_philo) * data->nmb_ph);
	if (!philo)
	{
		free(data->fork);
		data->fork = NULL;
		return (1);
	}
	*philosopher = philo;
	return (0);
}
