#include "MainMenu.hpp"

MainMenu::MainMenu() {

}

MainMenu::MainMenu(GLint screenWidth,GLint screenHeight) {
	_setDefaults(screenWidth,screenHeight);

	_width = screenWidth;
	_height = screenHeight;
}

MainMenu::~MainMenu() {
	if (_background != NULL) {
		SDL_DestroyTexture(_background);
		_background = NULL;
	}
}

void MainMenu::run() {
	if (IS_LOADING) {
		_load();
		IS_LOADING = GL_FALSE;
	}

	_draw();

}

void MainMenu::handleEvent( SDL_Event* event ) {
	GLint x = 0,y = 0;
	SDL_GetMouseState(&x,&y);

	bool isStartButtonHovered = _startButton.checkHovering(x,y);
	bool isLoadButtonHovered = _loadButton.checkHovering(x,y);
	bool isExitButtonHovered = _exitButton.checkHovering(x,y);

	switch(event->type) {

        case SDL_MOUSEBUTTONDOWN:
            break;

        case SDL_MOUSEBUTTONUP:

        	if ( isStartButtonHovered ) {
        		// Go to start new game menu
        		CURRENT_STATUS = NEW_GAME_MENU;
        	}

        	if ( isLoadButtonHovered ) {
        		// Go to load screen
        	}

			if ( isExitButtonHovered ) {
				RUNNING = GL_FALSE;
			}

            break;

	}

}

void MainMenu::_setDefaults(const GLint width,const GLint height) {
	_background = NULL;

	_title = TextBox("Welcome to Factory Builder",RED,30);

	_startButton = Button("Start Game",BLACK,RED,GREEN,24);
	_startButton.setPosition(( width / 2 ) - (_startButton.getWidth() / 2) ,200);
	_loadButton = Button("Load Game",BLACK,RED,GREEN,24);
	_loadButton.setPosition(( width / 2 ) - (_loadButton.getWidth() / 2) ,250);
	_exitButton = Button("Exit",BLACK,RED,GREEN,24);
	_exitButton.setPosition(( width / 2 ) - (_exitButton.getWidth() / 2) ,400);

}

void MainMenu::_load() {
	if (_background == NULL) {
		GLint x,y;
		_background = _loadTextureFromFile("./include/images/main_menu_background.jpg",x,y);
		if (_background == NULL) {
			cout << "Failed to load texture" << endl;
			RUNNING = GL_FALSE;
		}
	}
}

void MainMenu::_draw() {
	SDL_RenderCopy(renderer,_background,NULL,NULL);

	_title.draw(( _width / 2 ) - (_title.getWidth() / 2) ,100);
	
	_startButton.draw(_width,_height);
	_loadButton.draw(_width,_height);
	_exitButton.draw(_width,_height);

}