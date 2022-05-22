/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:55:28 by kelisabe          #+#    #+#             */
/*   Updated: 2022/05/22 13:35:24 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_init(t_data *data)
{
	int	i;

	i = -1;
	// init fork mutexes
	while(++i < data->number_of_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			exit_message("mutex init failed\n");
	}
	// init mutex mutex_write and mutex mutex_eat
	if (pthread_mutex_init(&(data->mutex_write), NULL) != 0 \
		|| pthread_mutex_init(&(data->mutex_eat), NULL) != 0)
			exit_message("mutex init failed\n");
}

void	phils_init(t_data *data, t_philo *philos)
{
	int	i;

	// call mutex_init
	mutex_init(data);
	// set up start time
	if (gettimeofday(&(data->start_time), NULL) != 0)
		exit_message("init start time failed\n");
	// init each philo
	i = -1;
	while (++i < data->number_of_philos)
	{
		philos[i].id = i;
		philos[i].id_right_fork = i;
		philos[i].id_left_fork = (i + 1) % data->number_of_philos;
		philos[i].numb_ate = 0;
		philos[i].last_time_to_eat = data->start_time;
		philos[i].data = data;
	}
}
