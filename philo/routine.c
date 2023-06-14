/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:28:10 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 18:05:55 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meals_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mute);
	philo->meal--;
	if (philo->meal == 0)
	{
		philo->data->phil_count--;
		if (philo->data->phil_count == 0)
		{
			philo->data->dead = 1;
			pthread_mutex_unlock(&philo->data->mute);
			return (0);
		}
	}
	pthread_mutex_unlock(&philo->data->mute);
	return (1);
}

int	check_died(t_philo *philo)
{
	if (philo->data->nmb_ph == 1)
	{
		if (my_usleep(philo, philo->data->tt_d))
			return (0);
		return (1);
	}
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(50);
	while (1)
	{
		if (thinking(philo))
			break ;
		pthread_mutex_lock(philo->left_fork);
		if (_print_(philo, "has taken a fork"))
			break ;
		if (check_died(philo))
			return (_print_(philo, "died"), NULL);
		pthread_mutex_lock(philo->right_fork);
		if (eating(philo))
			break ;
		drop_forks(philo);
		if (sleeping(philo))
			break ;
		if (!meals_check(philo))
			break ;
	}
	return (NULL);
}
