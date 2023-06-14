/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:29:42 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 20:20:37 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
			return (1);
		data = malloc(sizeof(t_data));
		if (alloc_phil(data, &philo, av))
			return (printf("Fail $ALLOC?\n"), free(data), 1);
		if (!meals(data, ac))
			return (free_every(data, philo), 1);
		if (creat_phil(data, philo))
			return (destroy_mutex(philo, data), 1);
		check_it_out(philo, ac, data);
	}
	else
	{
		printf("wrong arguments\n");
		return (1);
	}
	return (0);
}
