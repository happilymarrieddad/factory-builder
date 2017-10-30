#include <iostream>
#include <String>

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
using std::String;


int main(int argc, char* args[]) {

	SDL_Color test = { 240 , 0 , 0 };

	cout << (int) test.r << endl;

	return 0;
}