class SDL {
public:

	static bool init() {
		//Use OpenGL 3.1 core
	    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	    // Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			cout << "SDL could not initialize. SDL Error: " << SDL_GetError() << endl;
			return GL_FALSE;
		}

		// Initialize PNG Loading
		int imgFlags = IMG_INIT_PNG;
		if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {
			cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
			return GL_FALSE;
		}

		if (TTF_Init() == -1) {
			cout << "SDL_ttf could not initialize! SDL_ttf Error: " << IMG_GetError() << endl;
			return GL_FALSE;
		}

		return GL_TRUE;
	}

	static void cleanup() {
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		SDL_StopTextInput();
	}

};