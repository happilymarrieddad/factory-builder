class OpenGL {
public:
	
	static bool init() {


		return GL_TRUE;
	}

	static bool test() {
		GLenum error = GL_NO_ERROR;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		error = glGetError();
		if (error != GL_NO_ERROR) {
			cout << "OpenGL could not initialize projection! OpenGL Error" << endl;
			return GL_FALSE;
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		error = glGetError();
		if (error != GL_NO_ERROR) {
			cout << "OpenGL could not initialize model view! OpenGL Error" << endl;
			return GL_FALSE;
		}

		glClearColor(0.0f,0.0f,0.0f,1.0f);

		error = glGetError();
		if (error != GL_NO_ERROR) {
			cout << "OpenGL could not initialize color! OpenGL Error" << endl;
			return GL_FALSE;
		}

		return GL_TRUE;
	}

	static void cleanup() {
		
	}

};