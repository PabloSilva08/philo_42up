/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:23:37 by pvieira-          #+#    #+#             */
/*   Updated: 2023/05/06 11:24:48 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
typedef struct s_hall	t_hall;
typedef pthread_mutex_t	t_mutex;

typedef enum e_print
{
	v_fork = 80,
	v_eating,
	v_thinking,
	v_sleeping
}	t_print;

typedef struct s_philo
{
	int			id;
	int			index;
	int			r_fork;
	int			l_fork;
	long		last_eat;
	long		my_dinner_number;
	pthread_t	th;
	t_hall		*hl;
}	t_philo;

typedef struct s_hall
{
	long		start_time;
	long		n_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		dinner_number;
	int			dead;
	t_philo		*ph;
	t_mutex		*fork;
	t_mutex		m_print;
	t_mutex		m_last_eat;
}	t_hall;

// init.c
int		init_hall(int argc, char **argv, t_hall *hall);

// util_philo.c
long	ft_atol(const char *nptr);
int		ft_isdigit(int n);
void	print_msn(t_philo *ph, int action);
void	monitoring_philo(t_hall *hall);

// routine.c
void	thread_init(t_hall *hall);
void	thread_finish(t_hall *hall);
// action.c
void	take_fork(t_philo *ph);
void	eating(t_philo *ph);
void	sleeping(t_philo *ph);
void	thinking(t_philo *ph);

// error.c
void	prompt_error(void);

// current_time.c
long	marking_time(void);
long	current_time(t_hall *hall);

// philo_free.c
void	philo_free(t_hall *hall);
#endif
