class MainMenu : public Textures {
public:
	MainMenu();
	MainMenu(GLint screenWidth,GLint screenHeight);
	~MainMenu();

	void run();
	void handleEvent( SDL_Event* event );

private:
	void _setDefaults();
	void _load();
	void _draw();

	SDL_Texture* _background;
	TextBox _title;
};