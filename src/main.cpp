#include <iostream>
#include <string>

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

#include "Colors.hpp"
#include "Globals.hpp"
#include "Utils.hpp"

#include "SDL.hpp"
#include "OpenGL.hpp"
#include "Textures.hpp"
#include "Media/Media.cpp"
#include "Timer/Timer.cpp"
#include "TextBox/TextBox.cpp"

#include "Window/Window.cpp"


int main(int argc, char* args[]) {

	if (!SDL::init()) {
		return ERROR_EXIT;
	}
	
	if (!OpenGL::init()) {
		return ERROR_EXIT;
	}

	Window window = Window(DEVELOPMENT,DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);

	if (!window.start()) {
		return ERROR_EXIT;
	}

	OpenGL::cleanup();
	SDL::cleanup();

	return SUCCESSFUL_EXIT;
}