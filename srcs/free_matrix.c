/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:41:23 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/18 17:55:51 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
free the matrix 3-3 mat.
*/

void	free_matrix(double **mat)
{
	free(mat[0]);
	free(mat[1]);
	free(mat[2]);
	free(mat);
}
