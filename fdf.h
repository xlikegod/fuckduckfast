/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:08:50 by amorefor          #+#    #+#             */
/*   Updated: 2021/12/05 16:27:16 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct s_fdf
{
	int		x;
	int		y;
	int		**z;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

// fdf.c
void	ft_error(void);
void	ft_check_file(char *filename);

// read_file.c
void	ft_read_file(char *filename, t_fdf *data);
int		get_x(char *filename);
int		get_y(char *filename);

// draw.c
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

#endif
//open, read, write, close, malloc, free, perror, strerror, exit