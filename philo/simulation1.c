/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:12:29 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 17:48:10 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meals(t_data *data, int ac)
{
	int	m_nmb;

	m_nmb = 0;
	if (ac == 6)
	{
		m_nmb = data->eat_count;
		if (m_nmb == -1)
			return (0);
	}
	return (1);
}

int	death(t_philo *philo, int i)
{
	long int	time;

	pthread_mutex_lock(&philo[i].data->mute);
	pthread_mutex_lock(&philo[i].data->eatt);
	time = timeof() - philo[i].eata;
	if (time >= philo->data->tt_d)
	{
		pthread_mutex_unlock(&philo[i].data->eatt);
		philo->data->dead = 1;
		printf("%05ld %d %s\n",
			timeof() - philo[i].data->first_time, philo[i].id, "died");
		pthread_mutex_unlock(&philo[i].data->mute);
		return (0);
	}
	pthread_mutex_unlock(&philo[i].data->eatt);
	pthread_mutex_unlock(&philo[i].data->mute);
	return (1);
}

int	check_meals(t_philo *philo, int ac)
{
	pthread_mutex_lock(&philo->data->mute);
	if (philo->data->phil_count == 0 && ac == 6)
	{
		pthread_mutex_unlock(&philo->data->mute);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->mute);
	return (1);
}

void	join(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nmb_ph)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	check_it_out(t_philo *philo, int ac, t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!check_meals(philo, ac))
			break ;
		if (!death(philo, i))
			break ;
		i++;
		if (i == philo->data->nmb_ph)
			i = 0;
	}
	join(philo);
	destroy_mutex(philo, data);
}
