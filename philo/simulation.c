/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:34:45 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/12 23:37:20 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_usleep(t_philo *philo, int time)
{
	long	start;

	start = timeof() + time;
	while (timeof() < start)
	{
		pthread_mutex_lock(&philo->data->mute);
		if (philo->data->dead == 1)
		{
			pthread_mutex_unlock(&philo->data->mute);
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->mute);
		usleep(100);
	}
	return (0);
}

int	_print_(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->mute);
	if (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->mute);
		pthread_mutex_lock(&philo->data->mute);
		printf("%05ld %d %s\n",
			timeof() - philo->data->first_time, philo->id, str);
		pthread_mutex_unlock(&philo->data->mute);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mute);
		return (1);
	}
	return (0);
}

int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mute);
	if (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->mute);
		if (_print_(philo, "is thinking"))
			return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mute);
		return (1);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mute);
	if (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->mute);
		if (_print_(philo, "has taken a fork"))
			return (1);
		if (_print_(philo, "is eating"))
			return (1);
		pthread_mutex_lock(&philo->data->eatt);
		philo->eata = timeof();
		pthread_mutex_unlock(&philo->data->eatt);
		if (my_usleep(philo, philo->data->tt_e))
			return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mute);
		return (1);
	}
	return (0);
}

int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mute);
	if (philo->data->dead == 0)
	{
		pthread_mutex_unlock(&philo->data->mute);
		if (_print_(philo, "is sleeping"))
			return (1);
		if (my_usleep(philo, philo->data->tt_s))
			return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mute);
		return (1);
	}
	return (0);
}
