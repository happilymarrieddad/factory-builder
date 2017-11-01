class Window {
public:
	Window();
	Window(GLint env);
	Window(GLint width,GLint height);
	Window(GLint env,GLint width,GLint height);

	bool start();

private:
	// Members
	void _init(GLint _width,GLint _height);
	void _setDevelopment();
	void _setProduction();
	void _run();
	void _clear();
	void _render();
	void _update();
	void _close();
	void _eventHandler();

	// Variables
	SDL_Event _sdlEvent;
	SDL_GLContext _glContext;

	GLint _width;
	GLint _height;

	GLint _desiredFps;
	GLint _tickPerFrame;
	GLint _countedFrames;

	GLint _env;

	Timer _fpsTimer;
	Timer _capTimer;


	// Flags
	bool _showConsoleFps;



	// Status'
	MainMenu _mainMenu;
	NewGameMenu _newGameMenu;
};