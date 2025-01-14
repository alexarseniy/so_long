/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarseniy <oleksandr.arseniy@student.madri  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:00:16 by oarseniy          #+#    #+#             */
/*   Updated: 2025/01/05 14:25:45 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

int	main(void)
{
	void *mlx;
	void *window;
	t_img *img_bg;
	t_img *img_pj;
	int	bg_width;
	int bg_height;
	int pj_width;
	int pj_height;

	bg_width = 1000;
	bg_height = 1000;
	pj_width = 32;
	pj_height = 32;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Mi ventana");
	img_bg = mlx_xpm_file_to_image(mlx, "bg.xpm", &bg_width, &bg_height);
	img_pj = mlx_xpm_file_to_image(mlx, "pj.png", &pj_width, &pj_height);
	mlx_put_image_to_window(mlx, window, img_bg, 0, 0);
	mlx_put_image_to_window(mlx, window, img_pj, 100, 100);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	return (0);
}
