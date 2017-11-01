class NewGameMenu : public Textures {
public:
	NewGameMenu();
	NewGameMenu(GLint screenWidth,GLint screenHeight);
	~NewGameMenu();

	void run();
	void handleEvent( SDL_Event* event );

private:
	void _setDefaults(const GLint width,const GLint height);
	void _load();
	void _draw();

	SDL_Texture* _background;
	TextBox _title;

	GLint _width;
	GLint _height;
};