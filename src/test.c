/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:45 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/12 21:38:52 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"
#include <string.h>

int					garbage_collector(void);

int	main(void)
{
	t_gc	*gc;
	char	*str;
	int		*tab;

	gc = gc_init(); // Initialize the garbage collector
	if (!gc)
		return (1);

	str = strdup("Hello, 42 !");
	if (!str)
	{
		gc_clean(gc);
		return (1);
	}
	gc_add(gc, (void *)str); // Add ptr to the garbage collector

	tab = (int *)malloc(10 * sizeof(int));
	if (!tab)
	{
		gc_clean(gc);
		return (1);
	}
	gc_add(gc, tab); // Add ptr to the garbage collector

	gc_print_debug(gc); // Print all allocations in the garbage collector

	gc_remove_one(gc, (void *)str); // Remove and free one ptr from the garbage collector

	gc_clean(gc); // Clean all allocations in the garbage collector

	return (0);
}
