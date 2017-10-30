#include "TextBox.hpp"

TextBox::TextBox() {
	_setDefaults();

	setWidth(100);
	setHeight(50);
	setPosition(0,0);
	setFont(TTF_OpenFont(DEFAULT_FONT_PATH.c_str(),28));
	setColor(BLACK);
	setFontColor(RED);
	setText("TEST");

	_init();
}

TextBox::TextBox(const String text,const GLint x,const GLint y,const GLint w,const GLint h,const SDL_Color color,const SDL_Color fontColor,const String fontPath) {
	_setDefaults();

	setWidth(w);
	setHeight(h);
	setPosition(x,y);
	setFont(TTF_OpenFont(fontPath.c_str(),28));
	setColor(color);
	setFontColor(fontColor);
	setText(text);

	_init();
}

TextBox::~TextBox() {
	_free();
}

void TextBox::_setDefaults() {
	_font = TTF_OpenFont(DEFAULT_FONT_PATH.c_str(),28);
}

void TextBox::_free() {
	if (_surface != NULL) {
		SDL_FreeSurface( _surface );
		_surface = NULL;
	}
	if (_font != NULL) {
		TTF_CloseFont( _font );
    	_font = NULL;
	}
}

void TextBox::_init() {
	_surface = TTF_RenderText_Solid( _font, _text.c_str(), _fontColor );
}

void TextBox::draw() {
	_render(NULL,0.0f,NULL,SDL_FLIP_NONE);
}

void TextBox::_render( SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE ) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { _x, _y, _w, _h };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( renderer, SDL_CreateTextureFromSurface( renderer, _surface ), clip, &renderQuad, angle, center, flip );
}