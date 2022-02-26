/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:10:13 by svirgil           #+#    #+#             */
/*   Updated: 2022/02/26 12:14:44 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	my_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	my_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
