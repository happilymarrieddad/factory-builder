class Button {
public:
	Button();
	Button(String text,SDL_Color color,SDL_Color fontColor,SDL_Color borderColor,GLint fontSize);

	void draw(const GLint SCREEN_WIDTH,const GLint SCREEN_HEIGHT);
	bool checkHovering(const GLint mouseX, const GLint mouseY);

	// Setters
	void setPosition(const GLint x,const GLint y) { _x = x;_y = y; }
	void setSize(const GLint w, const GLint h) { _w = w;_h = h; }
	void setButtonColor(const SDL_Color color) { _color = color; }
	void setFontColor(const SDL_Color color) { _textColor = color; }
	void setBorderColor(const SDL_Color color) { _borderColor = color; }
	void setIsMouseHovering(const bool isMouseHovering) { _isMouseHovering = isMouseHovering; }

	// Getters
	GLint getWidth() { return _w; }
	GLint getHeight() { return _h; }
	bool getHovering() { return _isMouseHovering; }

private:
	void _init();
	void _drawBorder(const GLint SCREEN_WIDTH,const GLint SCREEN_HEIGHT);

	GLint _x;
	GLint _y;
	GLint _w;
	GLint _h;
	GLint _borderOffset;

	SDL_Color _color;
	SDL_Color _textColor;
	SDL_Color _borderColor;

	bool _isMouseHovering;

	TextBox _text;
};