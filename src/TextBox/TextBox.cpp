#include "TextBox.hpp"

TextBox::TextBox() {

}

TextBox::TextBox(const String text,const GLint x = 0,const GLint y = 0,const GLint w = 100,const GLint h = 50,const SDL_Color color = BLACK,const SDL_Color fontColor = WHITE,const String fontPath = DEFAULT_FONT_PATH) {
	setWidth(w);
	setHeight(h);
	setPosition(x,y);
	//setFont(TTF_OpenFont(fontPath.c_str(),28));
	setColor(color);
	setFontColor(fontColor);
	setText(text);

	_init();
}

TextBox::~TextBox() {
	_free();
}

void TextBox::_setDefaults() {
	_font = NULL;
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
	_surface = TTF_RenderText_Solid( NULL, _text.c_str(), _fontColor );
}

void TextBox::draw() {
	_render(NULL,0.0,NULL,SDL_FLIP_NONE);
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