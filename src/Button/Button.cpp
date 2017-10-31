#include "Button.hpp"

Button::Button() {

}

Button::Button(String text,SDL_Color color,SDL_Color fontColor,SDL_Color borderColor,GLint fontSize) {
	_init();

	setButtonColor(color);
	setFontColor(fontColor);
	setBorderColor(borderColor);

	_text = TextBox(text,fontColor,fontSize);
	setSize(_text.getWidth(),_text.getHeight());
}

void Button::_init() {
	setPosition(0,0);
	setSize(100,50);
	_borderOffset = 5;
	_isMouseHovering = GL_FALSE;
}

bool Button::checkHovering(const GLint mouseX, const GLint mouseY) {

	if (
		mouseX >= _x && mouseY >= _y &&
		mouseX <= ( _x + _w ) && mouseY <= ( _y + _h ) &&
		mouseX > 1 && 
		mouseY > 1
	) {
		_isMouseHovering = GL_TRUE;
	} else {
		_isMouseHovering = GL_FALSE;
	}

	return _isMouseHovering;
}

void Button::draw(const GLint SCREEN_WIDTH,const GLint SCREEN_HEIGHT) {

	_text.draw(_x,_y);
	_w = _text.getWidth();
	_h = _text.getHeight();

	if (_isMouseHovering) {
		_drawBorder(SCREEN_WIDTH,SCREEN_HEIGHT);
	}
}

void Button::_drawBorder(const GLint SCREEN_WIDTH,const GLint SCREEN_HEIGHT) {

    SDL_Rect borderRect = {
    	_x - _borderOffset > 0 ? _x - _borderOffset : 0,
    	_y - _borderOffset > 0 ? _y - _borderOffset : 0,
    	_w + _borderOffset < SCREEN_WIDTH ? _w + _borderOffset : SCREEN_WIDTH,
    	_h + _borderOffset < SCREEN_HEIGHT ? _h + _borderOffset : SCREEN_HEIGHT
    };
    SDL_SetRenderDrawColor( renderer, _borderColor.r,_borderColor.g,_borderColor.b,0 );
    SDL_RenderDrawRect( renderer, &borderRect );
}