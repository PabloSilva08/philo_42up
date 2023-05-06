/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:56:32 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 09:49:20 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt_error(void)
{
	printf("\e[36;1m I think therefore I am\e[0m\n");
	printf("\e[36;1mTo use this program we must use.\e[0m\n\n");
	printf("\e[35;1m$ ./philo ph t_death t_eat t_sleep n_meals\e[0m\n");
	printf("\e[33;1m-----------------------------------------\e[0m\n");
	printf("\e[35;1mph \t→ \tnumber of philosophers\e[0m\n");
	printf("\e[35;1mt_eat \t→ \ttime to eat\e[0m\n");
	printf("\e[35;1mt_sleep → \tsleep time\e[0m\n");
	printf("\e[35;1mn_meals → \tnumber of meals (optional)\e[0m\n");
	printf("\e[33;1m-----------------------------------------\e[0m\n");
	printf("\e[33;1mExample\e[0m\n");
	printf("\e[33;1m$ ./philo 5 800 300 300 4\e[0m\n\n");
	printf("\e[31;1mP.S. Philosopher number must be greater than one.\e[0m\n");
}
