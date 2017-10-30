class Button {
public:
	Button();
	Button(GLint x,GLint y);
	Button(GLint x,GLint y,GLint length,GLint height);

	void setPosition(GLint x,GLint y) { _x = x; _y = y; }
	void setHeight(GLint length,GLint height) { _length = length; _height = height; }
	void setHovering(bool hovering) { _isMouseHovering = hovering; }

private:
	void _setDefaults();
	void _draw();
	void _drawBorder();

	GLint _x;
	GLint _y;
	GLint _length;
	GLint _height;

	SDL_Color color;
	SDL_Color textColor;
	SDL_Color borderColor;

	bool _isMouseHovering;
};