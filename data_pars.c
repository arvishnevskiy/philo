/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:55:08 by kelisabe          #+#    #+#             */
/*   Updated: 2022/05/22 12:34:24 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_data(t_data *data, int argc, char **argv)
{
	memset(data, 0, sizeof(data));
	data->number_of_philos = ft_atoi(argv[1]);
	if (data->number_of_philos > 200)
		exit_message("too many philos\n");
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->numb_must_eat = -1;
	if (argc == 6)
		data->numb_must_eat = ft_atoi(argv[5]);
}

void	check_data(int argc, char **argv, t_data *data)
{
	if (argc != 5 || argc != 6)
		exit_message("wrong number of args\n");
	if (data->number_of_philos < 0 || data->time_to_die < 1 \
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		exit_message("wrong parameters\n");
}
