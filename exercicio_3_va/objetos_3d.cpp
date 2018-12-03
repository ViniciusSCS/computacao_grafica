// Alunos: Vinicius Sarmento

#include <GL/glut.h>

GLfloat angle, fAspect, tx, ty, tz, ang, rotx, roty, rotz;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(12,14,21);
	glRotatef(ang, rotx, roty, rotz);
	glutSolidCube(60);

	glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-60, 41, 36);
    glRotatef(ang, rotx, roty, rotz);
	glutSolidSphere(25,256, 30);		
		
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(-85, -20, -60);
	glRotatef(-25, 1, 0, 0);
	glutSolidCone(25,45,3,3);
	
	// Executa os comandos OpenGL
	glutSwapBuffers();
	
 }
 

// Inicializa par�metros de rendering
void Inicializa (void)
{ 
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    angle=45;
    tx = ty = tz = 0;
    ang = 15;
    rotx = 1;
    roty = 0;
    rotz = 0;
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
    gluPerspective(angle,fAspect,0.5,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posi��o do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Fun��o callback chamada para gerenciar eventos de teclado 
void GerenciaTeclado(unsigned char key, int x, int y) { 
     tx = 0;
     ty = 0;
     tz = 0;
	switch (key) { 
		case 'x': // diminui a transla��o em x
			tx -= 2;
			break; 
		case 'X': // aumenta a transla��o em x
			tx += 2;
			break; 
		case 'y': // diminui a transla��o em y
			ty -= 2;
			break; 
		case 'Y': // aumenta a transla��o em y
			ty += 2;
			break; 
		case 'z': // diminui a transla��o em z
			tz -= 2;
			break;  
		case 'Z': // aumenta a transla��o em z
			tz += 2;
			break; 
	} 
	glutPostRedisplay(); 
} 

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(350,300);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	// glutMouseFunc(GerenciaMouse);
	// glutKeyboardFunc(GerenciaTeclado);
	Inicializa();
	glutMainLoop();
}
