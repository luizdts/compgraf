#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int year = 0, day = 0;

void init(void) 
{
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);

}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 0.0);

   glPushMatrix();
   glutWireSphere(1.0, 20, 16);   /* draw sun */
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (1.5, 0.0, 0.0);
  
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glColor3f(1.0, 0.0, 0.0);
 

   glutWireSphere(0.07, 10, 8);    /* mercurio */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (2.5, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glColor3f(0.0, 1.0, 0.0);
   glutWireSphere(0.1, 10, 8);    /* venus */
   glPopMatrix();
   
   glPushMatrix();
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (4.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glColor3f(0.0, 0.0, 1.0);
   glutWireSphere(0.2, 10, 8); /* terra */
  
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (4.5, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glColor3f(1.0, 1.0, 1.0);
   glutWireSphere(0.05, 10, 8);    /* lua  */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (6.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glColor3f(1.0, 0.5, 0.0);
   glutWireSphere(0.27, 10, 8);    /* marte */
   glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); //angulo
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 5.0, 8.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0); // visao da camera
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd': /*d */
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 'y': /*y*/
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 5) % 360;
         glutPostRedisplay();
         break;
      case 'a':
	
         day = (day + 10) % 360;
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 600); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
