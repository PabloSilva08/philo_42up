/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:52:47 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 23:45:46 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	smart_sleep(long duration, t_philo *ph)
{
	long	start_time;

	start_time = current_time(ph->hl);
	printf("C\n");
	while (start_time + duration >= current_time(ph->hl))
	{
		pthread_mutex_lock(&ph->hl->m_last_eat);
		if (ph->hl->dead == 0)
		{
		printf("D\n");
			pthread_mutex_unlock(&ph->hl->m_last_eat);
			break ;
		}
		pthread_mutex_unlock(&ph->hl->m_last_eat);
		usleep(100);
	}
}

void	take_fork(t_philo *ph)
{
	pthread_mutex_lock(&ph->hl->fork[ph->r_fork]);
	print_msn(ph, v_fork);
	pthread_mutex_lock(&ph->hl->fork[ph->l_fork]);
	print_msn(ph, v_fork);
}

void	eating(t_philo *ph)
{
	printf("A\n");
	print_msn(ph, v_eating);
	printf("B\n");
	smart_sleep(ph->hl->time_to_eat, ph);
	pthread_mutex_lock(&ph->hl->m_last_eat);
	ph->last_eat = current_time(ph->hl);
	pthread_mutex_unlock(&ph->hl->m_last_eat);
	pthread_mutex_unlock(&ph->hl->fork[ph->r_fork]);
	pthread_mutex_unlock(&ph->hl->fork[ph->l_fork]);
}

void	sleeping(t_philo *ph)
{
	if (ph->hl->dead == 0)
		return ;
	print_msn(ph, v_sleeping);
	smart_sleep(ph->hl->time_to_sleep, ph);
}

void	thinking(t_philo *ph)
{
	if (ph->hl->dead == 0)
		return ;
	print_msn(ph, v_thinking);
}
