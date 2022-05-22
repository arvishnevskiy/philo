/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:18:08 by kelisabe          #+#    #+#             */
/*   Updated: 2022/05/22 18:56:19 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	timeval_to_ms(t_timeval time)
{
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	// start timepoint
	t_timeval		current_time;
	// end timepoint
	unsigned long	till_time;
	gettimeofday(&current_time, NULL);
	// updating current_time
	till_time = timeval_to_ms(current_time) + time;
	while (timeval_to_ms(current_time) < till_time)
	{
		gettimeofday(&current_time, NULL);
		usleep(200);
	}
}
