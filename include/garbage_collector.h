/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:50:57 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/12 21:38:43 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

/* #include "libft.h" */

# include <stdio.h>
# include <stdlib.h>

/*******************************/
/*       GARBAGE COLLECTOR     */
/*******************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_gc
{
	t_list			*head;
}					t_gc;

t_gc				*gc_init(void);
short				gc_add(t_gc *gc, void *ptr);
short				gc_remove_one(t_gc *gc, void *ptr);
void				gc_clean(t_gc *gc);
void				gc_print_debug(t_gc *gc);

#endif