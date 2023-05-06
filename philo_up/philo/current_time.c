/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:00:23 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 09:50:23 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(t_hall *hall)
{
	return (marking_time() - hall->start_time);
}

long	marking_time(void)
{
	struct timeval	time;
	long			miliseconds;

	miliseconds = 0;
	gettimeofday(&time, NULL);
	miliseconds = time.tv_sec * 1000;
	miliseconds += time.tv_usec / 1000;
	return (miliseconds);
}
