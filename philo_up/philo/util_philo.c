/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:25:31 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 17:27:23 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *nptr)
{
	size_t		i;
	long		sign;
	long		result;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (0);
	return (1);
}

void	print_msn(t_philo *ph, int action)
{
	pthread_mutex_lock(&ph->hl->m_print);
	if (action == v_thinking)
		printf("%ld \t%d is thinking\n", current_time(ph->hl), ph->id);
	else if (action == v_sleeping)
		printf("%ld \t%d is sleeping\n", current_time(ph->hl), ph->id);
	else if (action == v_eating)
		printf("%ld \t%d is eating\n", current_time(ph->hl), ph->id);
	else if (action == v_fork)
		printf("%ld \t%d has taken a fork\n", current_time(ph->hl), ph->id);
	pthread_mutex_unlock(&ph->hl->m_print);
}

static void	sleep_and_print(t_hall *hall)
{
	hall->dead = 0;
	pthread_mutex_unlock(&hall->m_last_eat);
	usleep(7000);
}

void	monitoring_philo(t_hall *hall)
{
	long	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&hall->m_last_eat);
		if (current_time(hall) - hall->ph[i].last_eat >= hall->time_to_die)
		{
			sleep_and_print(hall);
			printf("%ld \t%d died\n", current_time(hall), hall->ph[i].id);
			break ;
		}
		if (hall->ph[i].my_dinner_number == 0)
		{
			hall->ph[i].my_dinner_number--;
			hall->dinner_number--;
			if (hall->dinner_number == 0)
			{
				pthread_mutex_unlock(&hall->m_last_eat);
				break ;
			}
		}
		pthread_mutex_unlock(&hall->m_last_eat);
		i++;
		if (i == hall->n_philo)
			i = 0;
		usleep(100);
	}
}
