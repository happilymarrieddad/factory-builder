class Textures {
protected:
	SDL_Texture* _loadTextureFromFile(const String path,GLint &w,GLint &h) {
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		if( loadedSurface == NULL )
		{
			cout << "Unable to load image. SDL_image Error: " << IMG_GetError() << endl;
			return newTexture;
		}

		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
	    newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			cout << "Unable to create texture from. SDL Error: " << SDL_GetError() << endl;
			return newTexture;
		}

		//Get image dimensions
		w = loadedSurface->w;
		h = loadedSurface->h;

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
		loadedSurface = NULL;

		return newTexture;
	}

};