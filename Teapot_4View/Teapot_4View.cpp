#include<gl/glut.h>

int width, hight;

void Light()
{
	GLfloat m_diffuse[] = { 0.6,0.5,0.6,0.5 };
	GLfloat m_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat m_ambient[] = { 0.5,0.4,0.3,1.0 };
	GLfloat m_shin[] = { 15.0 };
	GLfloat l_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat l_diffuse[] = { 0.5,0.8,0.9,1.0 };
	GLfloat l_ambient[] = { 0.3,0.3,0.3,1.0 };
	GLfloat l_position[] = { -3,6,3.0,0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, l_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, m_shin);
}
void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene()
{
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glEnd();
	glPopMatrix();
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);
	glPopMatrix();
}

void DrawSolid()
{
	Light();
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutSolidTeapot(1.0);
	glPopMatrix();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, width / 2, hight / 2);
	glPushMatrix();											//3
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glViewport(width / 2, 0, width / 2, hight / 2);
	glPushMatrix();											//4
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glViewport(0, hight / 2, width / 2, hight / 2);
	glPushMatrix();											//1
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();
	glViewport(width / 2, hight / 2, width / 2, hight / 2);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(30, 1.0, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(10.0, 9.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawSolid();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glFlush();
}


void Resh(int w, int h)
{
	width = w;
	hight = h;
}

int main(int argc, char** argv)
{
	width = 600;
	hight = 600;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, hight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Open_GL");
	Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(Resh);
	glutMainLoop();
}