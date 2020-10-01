//
// Created by Hugor Chau on 10/1/20.
//

#include "../includes/rtv1.h"

/*
**		example of keycode saving event
*/

void	collect_key_data(t_data *data, SDL_Event *event, t_event_type curr_condition)
{
	if (event->key.keysym.sym == SDLK_r)
		data->sdl->key_pressed['R'] = curr_condition;
	else if (event->key.keysym.sym == SDLK_g)
		data->sdl->key_pressed['G'] = curr_condition;
	else if (event->key.keysym.sym == SDLK_b)
		data->sdl->key_pressed['B'] = curr_condition;
	else if (event->key.keysym.sym == SDLK_LEFT)
		data->sdl->key_pressed[LEFT_ARROW] = curr_condition;
	else if (event->key.keysym.sym == SDLK_RIGHT)
		data->sdl->key_pressed[RIGHT_ARROW] = curr_condition;
	else if (event->key.keysym.sym == SDLK_UP)
		data->sdl->key_pressed[TOP_ARROW] = curr_condition;
	else if (event->key.keysym.sym == SDLK_DOWN)
		data->sdl->key_pressed[DOWN_ARROW] = curr_condition;
}

void	main_loop(t_data *data)
{
	int quit = 0;
	SDL_Event event;

	while(!quit)
	{
		data->test->condition(data);
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				quit=1;
			if (quit == 1)
			{
				quit_program(data);
			}
			if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			{
				if (event.type == SDL_KEYDOWN)
					collect_key_data(data, &event, KEY_DOWN);
				else
					collect_key_data(data, &event, KEY_UP);
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
			}
		}
		SDL_RenderPresent(data->sdl->rend);
	}
	quit_program(data);
}
