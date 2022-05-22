/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:21:38 by kelisabe          #+#    #+#             */
/*   Updated: 2022/05/22 13:35:15 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philos[200];

	if(argc != 5 && argc != 6)
		exit_message("wrong number of arguments");
	parsing_data(&data, argc, argv);
	phils_init(&data, philos);

	return (0);
}
