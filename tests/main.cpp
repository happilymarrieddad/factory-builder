#include <iostream>
#include <string>
#include <intrin.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <GL/glew.h>
#ifndef LOPENGL_H
#define LOPENGL_H
#include <GL/glu.h>
#include <GL/gl.h>
#endif

using std::cout;
using std::endl;
using String = std::string;

SDL_Renderer* renderer;
SDL_Window* window;
SDL_Event sdlEvent;

bool RUNNING = true;
SDL_Color RED = { 255,0,0 };
SDL_Color WHITE = { 0,0,0 };
SDL_Color BLACK = { 255,255,255 };

int main(int argc, char* args[]) {

	//Use OpenGL 3.1 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize. SDL Error: " << SDL_GetError() << endl;
		return GL_FALSE;
	}

	if (TTF_Init() == -1) {
		cout << "SDL_ttf could not initialize! SDL_ttf Error: " << IMG_GetError() << endl;
		return GL_FALSE;
	}

	TTF_Font* font = TTF_OpenFont("../include/fonts/OpenSans-Bold.ttf",28);
	if (font == NULL) {
		cout << "TTF_OpenFont ERROR: " << TTF_GetError() << endl;
		return 0;
	}

	window = SDL_CreateWindow(
		"Application",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		// Flags
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		cout << "Window could not be created. SDL Error: " << SDL_GetError() << endl;
		return 0;
	}

	// This is a global renderering object
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	if (renderer == NULL) {
		cout << "Renderer could not be created. SDL Error: " << SDL_GetError() << endl;
		return 0;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == NULL) {
		cout << "OpenGL context could not be created! OpenGL Error: " << SDL_GetError() << endl;
		return 0;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font,"TEST",RED);
	if (surface == NULL) {
		cout << "TTF Font Surface Error: " << TTF_GetError() << endl;
		return 0;
	}

	cout << "W: " << surface->w << "H: " << surface->h << endl;
	SDL_Rect renderQuad = { 10,10,surface->w,surface->h };

	while (RUNNING) {
		while( SDL_PollEvent( &sdlEvent ) != 0 ) {
			switch(sdlEvent.type) {		
				case SDL_QUIT:
					RUNNING = GL_FALSE;
					break;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Draw
		SDL_RenderCopyEx( renderer,SDL_CreateTextureFromSurface( renderer,surface ), NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE );
		

		SDL_GL_SwapWindow(window);
		SDL_RenderClear(renderer);

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	TTF_Quit();
	SDL_Quit();

	return 0;
}