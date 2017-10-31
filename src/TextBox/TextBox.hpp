class TextBox {
public:
	TextBox();
	TextBox(const String text,const SDL_Color color,GLint fontSize);
	~TextBox();

	// Methods
	void draw(const GLint x, const GLint y);

	// Setters
	void setText(String text) { _txt = text; }
	void setPosX(GLint x) { _x = x; }
	void setPosY(GLint y) { _y = y; }
	void setWidth(GLint w) { _w = w; }
	void setHeight(GLint h) { _h = h; }
	void setColor(SDL_Color color) { _color = color; }
	void setFontColor(SDL_Color color) { _fontColor = color; }
	void setFontSize(GLint size) { _fontSize = size; }

	// Getters
	GLint getWidth() { return _w; }
	GLint getHeight() { return _h; }
	GLint getPosX() { return _x; }
	GLint getPosY() { return _y; }

private:
	void _setDefaults();
	void _free();

	String _txt;
	GLint _x;
	GLint _y;
	GLint _w;
	GLint _h;
	String _text;
	SDL_Color _color;
	SDL_Color _fontColor;
	GLint _fontSize;

	SDL_Surface* _surface = NULL;
};