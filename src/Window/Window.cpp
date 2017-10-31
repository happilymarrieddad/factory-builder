#include "../Status/MainMenu/MainMenu.cpp"

#include "Window.hpp"

Window::Window() {
	_init(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);
}

Window::Window(GLint env) {
	_init(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);

	_env = env;
}

Window::Window(GLint width,GLint height) {
	_init(width,height);
}

Window::Window(GLint env,GLint width,GLint height) {
	_init(width,height);

	_env = env;
}

void Window::_init(GLint width = DEFAULT_SCREEN_WIDTH,GLint height = DEFAULT_SCREEN_HEIGHT) {
	window = NULL;
	renderer = NULL;

	_width = width;
	_height = height;
	_desiredFps = 60;
	_tickPerFrame = 1000 / _desiredFps;

	_fpsTimer = Timer();
	_capTimer = Timer();

	_mainMenu = MainMenu(width,height);

	_env = PRODUCTION;
}

void Window::_setDevelopment() {
	_showConsoleFps = true;
}

void Window::_setProduction() {
	_showConsoleFps = false;
}

/*-------------------------------------------------------------------------
|	Window::Init
|--------------------------------------------------------------------------
|
|	This function is used for initializing window.
|
*/
bool Window::start() {

	switch(_env) {

		case DEVELOPMENT:
			_setDevelopment();
			break;

		case PRODUCTION:
			_setProduction();
			break;
	
	}

	window = SDL_CreateWindow(
		"Application",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width,
		_height,
		// Flags
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		cout << "Window could not be created. SDL Error: " << SDL_GetError() << endl;
		return GL_FALSE;
	}

	// This is a global renderering object
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	if (renderer == NULL) {
		cout << "Renderer could not be created. SDL Error: " << SDL_GetError() << endl;
		return GL_FALSE;
	}

	_glContext = SDL_GL_CreateContext(window);
	if (_glContext == NULL) {
		cout << "OpenGL context could not be created! OpenGL Error: " << SDL_GetError() << endl;
		return GL_FALSE;
	}

	if (!OpenGL::test()) {
		return GL_FALSE;
	}

	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_StartTextInput();

	if (_showConsoleFps) {
		_countedFrames = 0;
		_fpsTimer.start();
	}

	while (RUNNING) {
		if (_showConsoleFps) {
			cout << endl;
			_capTimer.start();
			float avgFps = _countedFrames / (_fpsTimer.getTicks() / 1000.0f);
			if (avgFps > 2000000) avgFps = 0;
			cout << "Average FPS: " << avgFps << endl;
		}

		_run();

		if (_showConsoleFps) {
			++_countedFrames;
			GLint frameTicks = _capTimer.getTicks();
			if (frameTicks < _tickPerFrame) {
				GLint delayingTime = _tickPerFrame - frameTicks;
				cout << "Delaying for: " << delayingTime << endl;
				SDL_Delay(delayingTime);
			}
			cout << endl;
		}
	}

	_close();
	return GL_TRUE;
}

/*-------------------------------------------------------------------------
|	Window::Run
|--------------------------------------------------------------------------
|
|	This function is the event loop.
|
*/
void Window::_run() {
	// Clear the screen for drawing
	_clear();

	// Handle Events
	_eventHandler();
	
	// Draw objects
	_render();

	// Update the screen with drawn objects
	_update();
}

/*-------------------------------------------------------------------------
|	Window::Render
|--------------------------------------------------------------------------
|
|	This function is used for rendering all objects.
|
*/
void Window::_render() {

	switch(CURRENT_STATUS) {

		case MAIN_MENU:
			_mainMenu.run();
			break;

		
	}

}

/*-------------------------------------------------------------------------
|	Window::Clear
|--------------------------------------------------------------------------
|
|	This function is used for clearing anything you need to before drawing.
|
*/
void Window::_clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_SetRenderDrawColor( renderer,255,255,255,0 );
}

/*-------------------------------------------------------------------------
|	Window::Update
|--------------------------------------------------------------------------
|
|	This function is used for updating...
|
*/
void Window::_update() {
	SDL_GL_SwapWindow(window);
	SDL_RenderClear(renderer);
}

/*-------------------------------------------------------------------------
|	Window::Close
|--------------------------------------------------------------------------
|
|	Clean up the application
|
*/
void Window::_close() {
	SDL_GL_DeleteContext( _glContext );
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	renderer = NULL;
	window = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	SDL_StopTextInput();
}

/*-------------------------------------------------------------------------
|	Window::Event Handler
|--------------------------------------------------------------------------
|
|	Handle Events
|
*/
void Window::_eventHandler() {

	while( SDL_PollEvent( &_sdlEvent ) != 0 ) {

		// Window Events
		switch(_sdlEvent.window.event) {
			case SDL_WINDOWEVENT_SIZE_CHANGED: break;
			case SDL_WINDOWEVENT_EXPOSED: break;
			case SDL_WINDOWEVENT_ENTER: break;
			case SDL_WINDOWEVENT_LEAVE: break;
			case SDL_WINDOWEVENT_FOCUS_GAINED: break;
			case SDL_WINDOWEVENT_FOCUS_LOST: break;
			case SDL_WINDOWEVENT_MINIMIZED: break;
			case SDL_WINDOWEVENT_MAXIMIZED: break;
			case SDL_WINDOWEVENT_RESTORED: break;
		}

		// Status SDL Events
		switch(CURRENT_STATUS) {

			case MAIN_MENU:
				_mainMenu.handleEvent( &_sdlEvent );
				break;

		}

		// Global SDL Events
		switch(_sdlEvent.type) {
			
			case SDL_QUIT:
				RUNNING = GL_FALSE;
				break;

			case SDL_KEYDOWN:

				switch(_sdlEvent.key.keysym.sym) {

					case SDLK_ESCAPE:
						RUNNING = GL_FALSE;
						break;

				}
				break;

		}

	}

}