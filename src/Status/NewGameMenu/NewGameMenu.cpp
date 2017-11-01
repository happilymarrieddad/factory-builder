#include "NewGameMenu.hpp"

NewGameMenu::NewGameMenu() {

}

NewGameMenu::NewGameMenu(GLint screenWidth,GLint screenHeight) {
	_setDefaults(screenWidth,screenHeight);

	_width = screenWidth;
	_height = screenHeight;
}

NewGameMenu::~NewGameMenu() {
	if (_background != NULL) {
		SDL_DestroyTexture(_background);
		_background = NULL;
	}
}

void NewGameMenu::run() {
	if (IS_LOADING) {
		_load();
		IS_LOADING = GL_FALSE;
	}

	_draw();

}

void NewGameMenu::handleEvent( SDL_Event* event ) {
	GLint x = 0,y = 0;
	SDL_GetMouseState(&x,&y);

	// bool isStartButtonHovered = _startButton.checkHovering(x,y);

	switch(event->type) {

        case SDL_MOUSEBUTTONDOWN:
            break;

        case SDL_MOUSEBUTTONUP:

        	// if ( isStartButtonHovered ) {
        	// 	// Go to start new game menu
        	// 	CURRENT_STATUS = NEW_GAME_MENU;
        	// }

            break;

	}

}

void NewGameMenu::_setDefaults(const GLint width,const GLint height) {
	_background = NULL;

	_title = TextBox("Start New Game",RED,30);

	// _startButton = Button("Start Game",BLACK,RED,GREEN,24);
	// _startButton.setPosition(( width / 2 ) - (_startButton.getWidth() / 2) ,200);

}

void NewGameMenu::_load() {
	if (_background == NULL) {
		GLint x,y;
		_background = _loadTextureFromFile("./include/images/main_menu_background.jpg",x,y);
		if (_background == NULL) {
			cout << "Failed to load texture" << endl;
			RUNNING = GL_FALSE;
		}
	}
}

void NewGameMenu::_draw() {
	SDL_RenderCopy(renderer,_background,NULL,NULL);

	_title.draw(( _width / 2 ) - (_title.getWidth() / 2) ,100);
	
	// _startButton.draw(_width,_height);

}