#include "TextBox.hpp"

TextBox::TextBox() {

}

TextBox::TextBox(const String text,const SDL_Color color,GLint fontSize) {
	_setDefaults();

	setText(text);
	setFontColor(color);
	setFontSize(fontSize);

	// Need to find some way to do this on instantiation
	if (_surface == NULL) {
		_surface = TTF_RenderText_Solid( TTF_OpenFont(DEFAULT_FONT_PATH.c_str(), _fontSize ) , _txt.c_str(), _fontColor );
		if (_surface == NULL) {
			cout << "TTF_Font Error: " << TTF_GetError() << endl;
			exit(0);
		}

		if (_surface->w < 1 || _surface->h < 1) {
			cout << "TTF_Font Surface: " << " Error: " << TTF_GetError() << endl;
			exit(0);
		}

		setWidth(_surface->w);
		setHeight(_surface->h);

		_free();
	}
}

TextBox::~TextBox() {
	_free();
}

void TextBox::_free() {

	if (_surface != NULL) {
		SDL_FreeSurface( _surface );
		_surface = NULL;
	}

}

void TextBox::_setDefaults() {
	setText("");
	setWidth(0);
	setHeight(0);
	setFontSize(16);
	setColor(BLACK);
	setFontColor(WHITE);
}

void TextBox::draw(const GLint x, const GLint y) {

	// Need to find some way to do this on instantiation
	if (_surface == NULL) {
		_surface = TTF_RenderText_Solid( TTF_OpenFont(DEFAULT_FONT_PATH.c_str(), _fontSize ) , _txt.c_str(), _fontColor );
		if (_surface == NULL) {
			cout << "TTF_Font Error: " << TTF_GetError() << endl;
			exit(0);
		}

		if (_surface->w < 1 || _surface->h < 1) {
			cout << "TTF_Font Surface: " << " Error: " << TTF_GetError() << endl;
			exit(0);
		}

		setWidth(_surface->w);
		setHeight(_surface->h);
	}

	//Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, _w, _h };

    //Render to screen
    SDL_RenderCopyEx( renderer, SDL_CreateTextureFromSurface( renderer, _surface ), NULL, &renderQuad, 0.0f, NULL, SDL_FLIP_NONE );

}