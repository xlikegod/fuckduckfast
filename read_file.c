/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:28:17 by amorefor          #+#    #+#             */
/*   Updated: 2021/12/05 15:47:30 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_y(char *filename)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(line); // leak length: 37  "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
		y++;
	}
	free(line);
	close (fd);
	return (y);
}

int	get_x(char *filename)
{
	char	*line;
	int		fd;
	int		x;
	char	**numbs;
	int		i;

	x = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	numbs = ft_split(line, ' ');
	while (numbs[i])
	{
		free(numbs[i]); // leak length: 1  "0"
		x++;
		i++;
	}
	free(numbs);
	free(line);
	close (fd);
	return (x);
}

static void	ft_create_matrix(int *z, char *line)
{
	int		i;
	char	**numbs;

	i = 0;
	numbs = ft_split(line, ' ');
	while (numbs[i])
	{
		z[i] = ft_atoi(numbs[i]);
		free(numbs[i]);
		i++;
	}
	free(numbs);
}

void	ft_read_file(char *filename, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	data->y = get_y(filename);
	data->x = get_x(filename);
	data->z = (int **)malloc(sizeof(int **) * (data->y + 1)); // leak [96]
	while (i < data->y)
	{
		data->z[i] = (int *)malloc(sizeof(int *) * (data->x + 1)); // leak [160]
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_create_matrix(data->z[i], line);
		free(line);
		i++;
	}
	free (line);
	close (fd);
}
