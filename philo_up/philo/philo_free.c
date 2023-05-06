/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:24:51 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 11:27:25 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free(t_hall *hall)
{
	int	i;

	i = 0;
	while (i < hall->n_philo)
	{
		pthread_mutex_destroy(&hall->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&hall->m_print);
	pthread_mutex_destroy(&hall->m_last_eat);
	free(hall->ph);
	free(hall->fork);
}
