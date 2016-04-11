/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_equ_thrd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 17:33:03 by rnicolas          #+#    #+#             */
/*   Updated: 2014/03/27 16:44:57 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>
#include <stdlib.h>

static double	*al_tb(double t0, double t1, double t2)
{
	double	*t;

	t = malloc(sizeof(double) * 3);
	t[0] = t0;
	t[1] = t1;
	t[2] = t2;
	return (t);
}

static double	*res_equ_thrd_help(double p, double q)
{
	double	*tab;
	double	v[2];

	v[0] = pow(q / 2, 2) + pow(p / 3, 3);
	if (p == 0)
		tab = al_tb(pow(-q, 1 / 3), pow(-q, 1 / 3), pow(-q, 1 / 3));
	else if (q == 0 && p > 0)
		tab = al_tb(0, 0, 0);
	else if (q == 0)
		tab = al_tb(0, sqrt(-q), -sqrt(-q));
	else if (v[0] == 0)
		tab = al_tb(3 * q / p, -3 * q / (2 * p), -3 * q / (2 * p));
	else if (v[0] > 0)
	{
		v[1] = pow(sqrt(v[0]) - q / 2, 1 / 3) + pow(-q / 2 - sqrt(v[0]), 1 / 3);
		tab = al_tb(v[1], v[1], v[1]);
	}
	else
	{
		v[1] = acos((3 * q / (2 * p)) * sqrt(-3 / p));
		tab = al_tb(sqrt(-p / 3) * cos(v[1] / 3), sqrt(-p / 3)
			* cos((v[1] + 2 * M_PI) / 3), sqrt(-p / 3) * cos((v[1] + 4
			* M_PI) / 3));
	}
	return (tab);
}

static double	*res_third_scnd(double a, double b, double c)
{
	double	delta;
	double	*tab;

	delta = b * b - 4 * a * c;
	if (a == 0 && b == 0 && c == 0)
		tab = al_tb(0, 0, 0);
	else if (a == 0 && b == 0)
		tab = NULL;
	else if (a == 0)
		tab = al_tb(-c / b, -c / b, 0);
	else if (delta < 0)
		tab = al_tb(0, 0, 0);
	else
	{
		tab = al_tb((-b - sqrt(delta)) / (2 * a),
			(-b + sqrt(delta)) / (2 * a), 0);
	}
	return (tab);
}

double			*res_equ_thrd(double a, double b, double c, double d)
{
	double	*tab;
	double	v[2];

	if (b == 0 && c == 0)
		tab = al_tb(pow(-d / a, 1 / 3), pow(-d / a, 1 / 3), pow(-d / a, 1 / 3));
	else if (b == 0 && d == 0 && (a * c > 0))
		tab = al_tb(0, 0, 0);
	else if (b == 0 && d == 0)
		tab = al_tb(0, sqrt(-c / a), -sqrt(-c / a));
	else if (b == 0)
		tab = res_equ_thrd_help(c / a, d / a);
	else if (d == 0 && c == 0)
		tab = al_tb(0, 0, -b / a);
	else if (d == 0)
		tab = res_third_scnd(a, b, c);
	else
	{
		v[0] = c / a - b * b / (3 * a * a);
		v[1] = d / a - b * c / (3 * a * a) + 2 * pow(b / (3 * a), 3);
		tab = res_equ_thrd_help(v[0], v[1]);
		tab[0] = tab[0] - b / (3 * a);
		tab[1] = tab[1] - b / (3 * a);
		tab[2] = tab[2] - b / (3 * a);
	}
	return (tab);
}
