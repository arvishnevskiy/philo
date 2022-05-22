/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:21:34 by kelisabe          #+#    #+#             */
/*   Updated: 2022/05/22 19:00:33 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct timeval	t_timeval;

typedef struct s_data
{
	int number_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int numb_must_eat;
	int numb_philo_ate;
	t_timeval start_time;
	pthread_mutex_t forks[200];
	pthread_mutex_t mutex_write;
	pthread_mutex_t mutex_eat;
}	t_data;

typedef struct s_philo
{
	int id;
	int id_right_fork;
	int id_left_fork;
	int philo_status_eating;
	t_timeval last_time_to_eat;
	pthread_t philo_thread;
	t_data *data;
}	t_philo;

int				ft_atoi(const char *str);
void			parsing_data(t_data *data, int argc, char **argv);
void			exit_message(char *str);
void			phils_init(t_data *data, t_philo *philos);
void			insert_message(t_data *data, int id, char *str);
void			philo_launch(t_data *data, t_philo *philos);
void			ft_usleep(int time);
unsigned long	timeval_to_ms(t_timeval time);

#endif
