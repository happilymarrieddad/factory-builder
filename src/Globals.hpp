GLint DEFAULT_SCREEN_WIDTH = 1440;
GLint DEFAULT_SCREEN_HEIGHT = 900;
String DEFAULT_FONT_PATH = "../include/fonts/lazy.ttf";

SDL_Renderer* renderer;
SDL_Window* window;

enum EXIT_STATUS
{
	SUCCESSFUL_EXIT = 0,
	ERROR_EXIT = -1
};

enum STATUS
{
	MAIN_MENU = 0
};

enum ENVIRONMENTS
{
	DEVELOPMENT = 0,
	PRODUCTION = 1
};

GLint CURRENT_STATUS = MAIN_MENU;

bool IS_LOADING = GL_TRUE;
bool RUNNING = GL_TRUE;

