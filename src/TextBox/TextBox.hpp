class TextBox {
public:
	TextBox();
	TextBox(const String text,const GLint x,const GLint y,const GLint w,const GLint h,const SDL_Color color,const SDL_Color fontColor,const String fontPath);
	~TextBox();

	void draw();

	// Setters
	void setFont(TTF_Font* font) { _font = font; }
	void setColor(SDL_Color color) { _color = color; }
	void setFontColor(SDL_Color color) { _fontColor = color; }
	void setPosX(GLint x) { _x = x; }
	void setPosY(GLint y) { _y = y; }
	void setWidth(GLint w) { _w = w; }
	void setHeight(GLint h) { _h = h; }
	void setPosition(GLint x, GLint y) { _x = x; _y = y; }
	void setText(String text) { _text = text; }

	// Getters
	// Need to find a way to return pos.x/pos.y  { x,y }

private:
	void _setDefaults();
	void _free();
	void _init();
	void _render( SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip );

	GLint _x;
	GLint _y;
	GLint _w;
	GLint _h;
	String _text;
	SDL_Color _color;
	SDL_Color _fontColor;
	SDL_Surface* _surface;
	TTF_Font* _font;
};