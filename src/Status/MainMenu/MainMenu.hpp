class MainMenu : public Textures {
public:
	MainMenu();
	MainMenu(GLint screenWidth,GLint screenHeight);
	~MainMenu();

	void run();
	void handleEvent( SDL_Event* event );

private:
	void _setDefaults(const GLint width,const GLint height);
	void _load();
	void _draw();

	SDL_Texture* _background;
	TextBox _title;

	Button _startButton;
	Button _loadButton;
	Button _exitButton;

	GLint _width;
	GLint _height;
};