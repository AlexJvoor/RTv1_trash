//
// Created by Hugor Chau on 10/1/20.
//

#include "../includes/rtv1.h"

/*
**		just in case if we would make some layers
**		with different alpha-channel
*/

void		init_single_layer(t_texture **layer, t_data *data)
{
	(*layer) = (t_texture *)safe_call_ptr(malloc(sizeof(t_texture)),
										  "Malloc crashed at \"./src/memory_management/init_window_layer.c\" "
										  "in \"init_single_layer\" function.", data);
	(*layer)->bit_map = (uint32_t *)safe_call_ptr(malloc(((SCREEN_HEIGHT) *
														  (SCREEN_WIDTH)) * sizeof(uint32_t)),
												  "Malloc crashed at \"./src/memory_management/init_window_layer.c\" "
												  "in \"init_layers\" function.", data);
	(*layer)->width = SCREEN_WIDTH;
	(*layer)->height = SCREEN_HEIGHT;
}

void		init_sdl_layers(t_data *data)
{
	data->sdl->layers = safe_call_ptr(ft_memalloc(sizeof(t_layers)),
									  "Malloc crashed at \"./src/memory_management/init_window_layer.c\" "
									  "in \"init_layers\" function.", data);
	init_single_layer(&data->sdl->layers->main_frame, data);
}

void		remove_layers(t_layers **layers)
{
	ft_memdel((void **) &(*layers)->main_frame->bit_map);
	ft_memdel((void **) &(*layers)->main_frame);
	ft_memdel((void **) layers);
}
