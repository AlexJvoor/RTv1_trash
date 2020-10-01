//
// Created by Hugor Chau on 10/1/20.
//

#include "../includes/rtv1.h"

/*
**		filling renderer with color
*/

void	draw_color(t_data *data, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderTarget(data->sdl->rend, data->sdl->target_texture);
	safe_call_int(SDL_SetRenderDrawColor(data->sdl->rend, r,
										 g, b, a),
				  "Can't clear render.", data);
	safe_call_int(SDL_RenderClear(data->sdl->rend), "Can't clear render.", data);
	SDL_SetRenderTarget(data->sdl->rend, NULL);
	safe_call_int(SDL_RenderCopy(data->sdl->rend,
								 data->sdl->target_texture, NULL, NULL),
				  "Can't render texture.", data);
}

/*
**		example of keycode management - press R, G, B or it's combinations:
**		bitmap will combine those colors because of target_texture
*/

void	test_colors(t_data *data)
{
	SDL_SetRenderTarget(data->sdl->rend, data->sdl->target_texture);
	if (data->sdl->key_pressed['R'])
		draw_color(data, 255, 0, 0, 60);
	if (data->sdl->key_pressed['G'])
		draw_color(data, 0, 255, 0, 60);
	if (data->sdl->key_pressed['B'])
		draw_color(data, 0, 0, 255, 60);
	if (data->sdl->key_pressed[LEFT_ARROW])
		draw_color(data, 255, 255, 255, 255);
	if (data->sdl->key_pressed[RIGHT_ARROW])
		draw_color(data, 0, 0, 0, 255);
}
