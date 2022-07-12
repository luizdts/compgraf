#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int year = 0, day = 0;
static int yearEarth = 0, dayEarth = 0;
static int yearMercurio = 0, dayMercurio = 0;
static int yearVenus = 0, dayVenus = 0;
static int yearMarte = 0, dayMarte = 0;
static int yearMoon = 0;
static int yearJupiter = 0, dayJupiter = 0, yearSaturno = 0, daySaturno = 0;
static int yearUrano = 0, dayUrano = 0, yearNetuno = 0, dayNetuno = 0;
static int yearPluto = 0, dayPluto = 0;

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
   glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
   glutWireSphere(5.0, 50, 16);   /* draw sun */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearMercurio, 0.0, 1.0, 0.0);
   glTranslatef (6.5, 0.0, 0.0);
   glRotatef ((GLfloat) dayMercurio, 0.0, 1.0, 0.0);
   glColor3f(1.0, 0.0, 0.0);
   glutWireSphere(0.07, 10, 8);    /* mercurio */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearVenus, 0.0, 1.0, 0.0);
   glTranslatef (7.5, 0.0, 0.0);
   glRotatef ((GLfloat) dayVenus, 0.0, 1.0, 0.0);
   glColor3f(0.0, 1.0, 0.0);
   glutWireSphere(0.1, 10, 8);    /* venus */
   glPopMatrix();
   
   glPushMatrix();
   glRotatef ((GLfloat) yearEarth, 0.0, 1.0, 0.0);
   glTranslatef (9.0, 0.0, 0.0);
   glRotatef ((GLfloat) dayEarth, 0.0, 1.0, 0.0);
   glColor3f(0.0, 0.0, 1.0);
   glutWireSphere(0.2, 10, 8); /* terra */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearMoon, 0.0, 1.0, 0.0);
   glTranslatef (9.5, 0.0, 0.0);
   glRotatef ((GLfloat) dayEarth, 0.0, 1.0, 0.0);
   glColor3f(1.0, 1.0, 1.0);
   glutWireSphere(0.05, 10, 8);    /* lua  */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearMarte, 0.0, 1.0, 0.0);
   glTranslatef (11.0, 0.0, 0.0);
   glRotatef ((GLfloat) dayMarte, 0.0, 1.0, 0.0);
   glColor3f(1.0, 0.5, 0.0);
   glutWireSphere(0.27, 10, 8);    /* marte */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearJupiter, 0.0, 1.0, 0.0);
   glTranslatef (20.0, 0.0, 0.0);
   glRotatef ((GLfloat) dayJupiter, 0.0, 1.0, 0.0);
   glColor3f(1.0, 0.5, 1.0);
   glutWireSphere(2.0, 10, 8);    /* jupiter */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearSaturno, 0.0, 1.0, 0.0);
   glTranslatef (30.0, 0.0, 0.0);
   glRotatef ((GLfloat) daySaturno, 0.0, 1.0, 0.0);
   glColor3f(1.0, 0.8, 0.0);
   glutWireSphere(1.8, 10, 8);    /* saturno */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearUrano, 0.0, 1.0, 0.0);
   glTranslatef (45.0, 0.0, 0.0);
   glRotatef ((GLfloat) dayUrano, 0.0, 1.0, 0.0);
   glColor3f(1.0, 1.0, 0.7);
   glutWireSphere(1.3, 10, 8);    /* urano */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearNetuno, 0.0, 1.0, 0.0);
   glTranslatef (55.0, 0.0, 0.0);
   glRotatef ((GLfloat) dayNetuno, 0.0, 1.0, 0.0);
   glColor3f(0.0, 0.0, 1.0);
   glutWireSphere(1.2, 10, 8);    /* netuno */
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) yearPluto, 0.0, 1.0, 0.0);
   glTranslatef (65.0, 0.0, 0.0);
   glRotatef ((GLfloat) dayPluto, 0.0, 1.0, 0.0);
   glColor3f(1.0, 1.0, 1.0);
   glutWireSphere(0.5, 10, 8);    /* pluto */
   glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 200.0); //angulo
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 30.0, 30.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0); // visao da camera
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd': /*d */
         day = (day + 10) % 360;
         dayMercurio = (dayMercurio + 25) % 360;
         dayVenus = (dayVenus + 15) % 360;
         dayMarte = (dayMarte + 9) % 360;
         dayEarth = (dayEarth + 10) % 360;
         dayJupiter = (dayJupiter + 5) % 360;
         daySaturno = (daySaturno + 4) % 360;
         dayUrano = (dayUrano + 3) % 360;
         dayNetuno = (dayNetuno + 2) % 360;
         dayPluto = (dayPluto + 1) % 360;
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
         //year = (year + 5) % 360;
         dayMercurio = (dayMercurio + 25) % 360;
         yearMercurio = (yearMercurio + 25) % 360;
         dayVenus = (dayVenus + 15) % 360;
         yearVenus = (yearVenus + 15) % 360;
         dayMarte = (dayMarte + 9) % 360;
         yearMarte = (yearMarte + 9) % 360;
         dayEarth = (dayEarth + 10) % 360;
         yearEarth = (yearEarth + 10) % 360;
         yearMoon = (yearEarth) % 360;
         // planetas gasosos são mais lentos
         yearJupiter = (yearJupiter + 5) % 360;
         dayJupiter = (dayJupiter + 5) % 360;
         yearSaturno = (yearSaturno + 4) % 360;
         daySaturno = (daySaturno + 4) % 360;
         yearUrano = (yearUrano + 3) % 360;
         dayUrano = (dayUrano + 3) % 360;
         yearNetuno = (yearNetuno + 2) % 360;
         dayNetuno = (dayNetuno + 2) % 360;
         yearPluto = (yearPluto + 1) % 360;
         dayPluto = (dayPluto + 1) % 360;
         glutPostRedisplay();
         break;
      default:
         while(1){
            yearMercurio = (yearMercurio + 25) % 360;
            yearVenus = (yearVenus + 15) % 360;
            yearMarte = (yearMarte + 9) % 360;
            yearEarth = (yearEarth + 10) % 360;
            yearMoon = (yearEarth) % 360;
            yearJupiter = (yearJupiter + 5) % 360;
            yearSaturno = (yearSaturno + 4) % 360;
            yearUrano = (yearUrano + 3) % 360;
            yearNetuno = (yearNetuno + 2) % 360;
            yearPluto = (yearPluto + 1) % 360;
         }

         
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (1280, 720); 
   glutInitWindowPosition (500, 500);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
