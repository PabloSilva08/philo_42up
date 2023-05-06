/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:24:01 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 17:31:43 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_finish(t_hall *hall)
{
	int	i;

	i = 0;
	while (i < hall->n_philo)
	{
		pthread_join(hall->ph[i].th, NULL);
		i++;
	}
}

static	void	print_and_sleep(t_philo *ph)
{
	print_msn(ph, v_fork);
	usleep((ph->hl->time_to_die + 1) * 1000);
}

static void	routine_2(t_philo *ph)
{
	take_fork(ph);
	eating(ph);
	pthread_mutex_lock(&ph->hl->m_last_eat);
	if (ph->my_dinner_number > 0)
		ph->my_dinner_number--;
	pthread_mutex_unlock(&ph->hl->m_last_eat);
	sleeping(ph);
	thinking(ph);
}

static void	*routine(void *t)
{
	t_philo	*ph;

	ph = (t_philo *) t;
	if (ph->id % 2 == 0)
		usleep(200);
	while (1)
	{
		if (ph->hl->n_philo == 1)
		{
			print_and_sleep(ph);
			break ;
		}
		pthread_mutex_lock(&ph->hl->m_last_eat);
		if (ph->hl->dead == 0 || ph->hl->dinner_number == 0)
		{
			pthread_mutex_unlock(&ph->hl->m_last_eat);
			break ;
		}
		pthread_mutex_unlock(&ph->hl->m_last_eat);
		routine_2(ph);
	}
	return (NULL);
}

void	thread_init(t_hall *hall)
{
	int	i;

	i = 0;
	if (hall->dinner_number != -1)
		hall->dinner_number = hall->n_philo;
	while (i < hall->n_philo)
	{
		pthread_create(&hall->ph[i].th, NULL, &routine, &hall->ph[i]);
		i++;
	}
	if (hall->n_philo >= 1)
		monitoring_philo(hall);
}
