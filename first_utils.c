/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:08:04 by kelisabe          #+#    #+#             */
/*   Updated: 2022/05/22 13:34:36 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	insert_message(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->mutex_write);
	printf("%lu %d %s\n", get_current_time(data), id + 1, str);
	pthread_mutex_unlock(&data->mutex_write);
}

void	exit_message(char *str)
{
	printf("%s\n", str);
	exit(0);
}

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\n' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int				j;
	int				res;
	unsigned int	i;

	j = 1;
	i = 0;
	res = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * j);
}
