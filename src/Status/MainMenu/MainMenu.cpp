#include "MainMenu.hpp"

MainMenu::MainMenu() {
	_setDefaults();
}

MainMenu::MainMenu(GLint screenWidth,GLint screenHeight) {
	_setDefaults();
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

	switch(event->type) {

        case SDL_MOUSEBUTTONDOWN:
            break;

        case SDL_MOUSEBUTTONUP:
            break;

	}

}

void MainMenu::_setDefaults() {
	_background = NULL;

	// _title = TextBox("TEST",20,20);
	// _title.setFontColor(RED);
	// _title.init();
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

	//_title.draw();
}