/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:13:31 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 11:25:41 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_hall *hall)
{
	int	i;

	i = 0;
	hall->ph = malloc(sizeof(t_philo) * hall->n_philo);
	if (hall->ph == NULL)
	{
		prompt_error();
		return (2);
	}
	while (i < hall->n_philo)
	{
		hall->ph[i].id = (i + 1);
		hall->ph[i].index = i;
		hall->ph[i].r_fork = i;
		if (i == (hall->n_philo - 1))
			hall->ph[i].l_fork = 0;
		else
			hall->ph[i].l_fork = (i + 1);
		hall->ph[i].last_eat = 0;
		hall->ph[i].my_dinner_number = hall->dinner_number;
		hall->ph[i].hl = hall;
		i++;
	}
	return (0);
}

static int	init_mutex(t_hall *hall)
{
	int	i;

	i = 0;
	hall->fork = malloc(sizeof(t_mutex) * hall->n_philo);
	if (hall->fork == NULL)
	{
		printf("Malloc Error");
		return (2);
	}
	while (i < hall->n_philo)
	{
		pthread_mutex_init(&hall->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&hall->m_print, NULL);
	pthread_mutex_init(&hall->m_last_eat, NULL);
	return (0);
}

static int	initializing_var(int argc, char **argv, t_hall *hall)
{
	hall->start_time = marking_time();
	hall->n_philo = ft_atol(argv[1]);
	hall->time_to_die = ft_atol(argv[2]);
	hall->time_to_eat = ft_atol(argv[3]);
	hall->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		hall->dinner_number = ft_atol(argv[5]);
	else
		hall->dinner_number = -1;
	if (hall->n_philo < 1)
	{
		prompt_error();
		return (1);
	}
	hall->dead = 1;
	return (0);
}

static int	validation_arg(int argc, char **argv)
{
	int	p_argv;
	int	i;

	p_argv = 1;
	while (p_argv < argc)
	{
		i = 0;
		while (argv[p_argv][i] != '\0')
		{
			if (argv[p_argv][i] == '+')
				i++;
			if (ft_isdigit(argv[p_argv][i]) == 1)
				return (1);
			i++;
		}
		p_argv++;
	}
	return (0);
}

int	init_hall(int argc, char **argv, t_hall *hall)
{
	if (validation_arg(argc, argv) == 1 || (argc != 5 && argc != 6))
	{
		prompt_error();
		return (1);
	}
	if (initializing_var(argc, argv, hall))
		return (1);
	if (init_mutex(hall) == 2)
		return (2);
	if (init_philo(hall))
		return (2);
	return (0);
}
