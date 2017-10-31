#include "TextBox.hpp"

TextBox::TextBox() {
	_setDefaults();
}

TextBox::TextBox(const String text,const GLint x,const GLint y) {
	_setDefaults();

	setText(text);
	setPosX(x);
	setPosY(y);
}

TextBox::~TextBox() {
	_free();
}

void TextBox::_free() {

}

void TextBox::_setDefaults() {
	setText("");
	setPosX(0);
	setPosY(0);
	setWidth(0);
	setHeight(0);
	setColor(BLACK);
	setFontColor(WHITE);
}

void TextBox::init() {

}

void TextBox::draw() {
	_render();
}

void TextBox::_render() {

	cout << "Getting font" << endl;
	TTF_Font* font = TTF_OpenFont(DEFAULT_FONT_PATH.c_str(),16);
	if (font == NULL) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit(0);
	}
	cout << "Got font" << endl

		<< "Getting surface" << endl;
	SDL_Surface* surface = TTF_RenderText_Solid( font , _txt.c_str(), RED );
	if (surface == NULL) {
		cout << "TTF_Font Error: " << TTF_GetError() << endl;
		exit(0);
	}
	cout << "Got surface" << endl;

	if (surface->w < 1 || surface->h < 1) {
		cout << "TTF_Font Surface: " << " Error: " << TTF_GetError() << endl;
		exit(0);
	}

	setPosX(surface->w);
	setPosY(surface->h);

	//Set rendering space and render to screen
    SDL_Rect renderQuad = { _x, _y, _w, _h };

	cout << "X: " << renderQuad.x << " Y: " << renderQuad.y << " W: " << renderQuad.w << " H: " << renderQuad.h << endl;
	exit(0);

    //Render to screen
    SDL_RenderCopyEx( renderer, SDL_CreateTextureFromSurface( renderer, surface ), NULL, &renderQuad, 0.0f, NULL, SDL_FLIP_NONE );

	if (surface != NULL) {
		SDL_FreeSurface( surface );
		surface = NULL;
	}

	if (font != NULL) {
		TTF_CloseFont( font );
    	font = NULL;
	}

}