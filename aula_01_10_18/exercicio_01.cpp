#include <GL/glut.h>

void display(void)
{
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Quadrado */
   glBegin(GL_POLYGON);
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
   glEnd();

   /* Triangulo */
    glBegin(GL_TRIANGLES);
        glColor3f (0.0, 1.0, 0.0);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.25f, 0.50f);
        glVertex2f(0.50f, 0.0f);
        glVertex2f(0.75f,0.50f);
        glVertex2f(0.25f,0.0f);
    glEnd();

    /* Retangulo */
    glBegin(GL_QUAD_STRIP);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 0.25f);
        glVertex2f(0.25f, 0.0f);
        glVertex2f(0.25f,0.25f);
        glVertex2f(0.5f,0.0f);
        glVertex2f(0.5f,0.25f);
    glEnd();

    /* Circulo */
    glBegin(GL_POLYGON);
        glColor3f (1.0, 1.0, 0.0);
        glVertex2f(0.0f, 0.0f);

    glEnd();

	glFlush ();
}

int calculaCircunferencia()
{
        int raio = 2;
        int x = 1;
        int y = 1;
        int pi = 3.14;
        int centro = ();


}


void init (void) 
{
  /* selecionar cor de fundo (branco) */
  glClearColor (1.0, 1.0, 1.0, 0.0);

  /* inicializar sistema de viz. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (300, 300);
   glutCreateWindow ("Ecercicio 1");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();

   return 0;
}
