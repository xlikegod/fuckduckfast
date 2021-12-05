/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:08:40 by amorefor          #+#    #+#             */
/*   Updated: 2021/12/05 16:46:12 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(void)
{
	perror("Error");
	exit (1);
}

void	ft_check_file(char *filename)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error();
	//i = read(fd, )
}

int	deal_key(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 64;
	if (key == 125)
		data->shift_y += 64;
	if (key == 124)
		data->shift_x += 64;
	if (key == 123)
		data->shift_x -= 64;
	if (key == 53)
		exit (EXIT_SUCCESS);
	if (key == 24)
		data->zoom += 64;
	if (key == 27)
		data->zoom /= 64;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		i;
	int		j;

	i = 0;
	if (argc != 2)
		ft_error();
	ft_check_file(argv[1]);
	data = (t_fdf *)malloc(sizeof(t_fdf)); // leak [16]
	ft_read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->zoom = 64;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free (data);
}
