class TextBox {
public:
	TextBox();
	TextBox(const String text,const GLint x,const GLint y);
	~TextBox();

	// Methods
	void init();
	void draw();

	// Setters
	void setText(String text) { _txt = text; }
	void setPosX(GLint x) { _x = x; }
	void setPosY(GLint y) { _y = y; }
	void setWidth(GLint w) { _w = w; }
	void setHeight(GLint h) { _h = h; }
	void setColor(SDL_Color color) { _color = color; }
	void setFontColor(SDL_Color color) { _fontColor = color; }

private:
	void _setDefaults();
	void _free();
	void _init();
	void _render();

	String _txt;
	GLint _x;
	GLint _y;
	GLint _w;
	GLint _h;
	String _text;
	SDL_Color _color;
	SDL_Color _fontColor;
};