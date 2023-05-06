/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:19:35 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 14:24:15 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_hall	hall;

	if (init_hall(argc, argv, &hall) == 1)
		return (1);
	thread_init(&hall);
	thread_finish(&hall);
	philo_free(&hall);
	return (0);
}
