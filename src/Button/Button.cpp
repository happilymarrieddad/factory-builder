#include "Button.hpp"

Button::Button() {
	_setDefaults();
}

Button::Button(GLint x,GLint y) {
	_setDefaults();

	setPosition(x,y);
}

Button::Button(GLint x,GLint y,GLint length,GLint height) {
	_setDefaults();

	setPosition(x,y);
	setHeight(length,height);
}

void Button::_setDefaults() {
	setPosition(0,0);
	setHeight(20,10);

	_isMouseHovering = false;

	color = BLACK;
	textColor = WHITE;
	borderColor = BLACK;
}

void Button::_draw() {

}