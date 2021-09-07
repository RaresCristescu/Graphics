#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include<iostream>
using namespace std;
const double TWO_PI = 6.2831853;

GLsizei winWidth = 600, winHeight = 800;
GLuint masina1,masina2,banda,benzi_continue,asfalt,copac;
GLubyte lista_banda[13],lista_masina1[2], lista_masina2[2],lista_benziContinue[2];
static GLfloat rotTheta = 0.0;

double i = 0.0, i1 = 0.0001, j = 0.0,k=0.0,l=0.0,k1=0.0,l1=0.0,unghi1=0.0,numar=0.0,scadere=0.0,cont_copac=500;
double alpha = 1.0,beta=0.2,gamma=4,unghi=0.0001;
double xg = 0.0, yg = 0.0, r=0.6,g=0.0,b=0.0;
int p = 1,semn=1, test =0,copac_parte=1;

class scrPt
{
public:
	GLint x, y;
};

static void init(void)
{
	glClearColor(0.134, 0.54, 0.134, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-300.0, 300.0, -400.0, 400.0, -1.0, 1.0);
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(0.134, 0.54, 0.134, 1.0);
	masina1 = glGenLists(3);
	glNewList(masina1, GL_COMPILE);//////////////////////////////////////////////////////////Conturu masinii
	glColor3f(r, g, b);//0.6, 0.0, 0.0
	glBegin(GL_POLYGON);
	hexVertex.x = -60;
	hexVertex.y = -72;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -60;
	hexVertex.y = 48;
	glVertex2i(hexVertex.x, hexVertex.y);
	int n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI/4 * k / n;
		hexVertex.x = -36 -24 * cos(hexTheta);
		hexVertex.y = 48+ 48 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
		
	}
	hexVertex.x = 36;
	hexVertex.y = 95;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = 36 + 24 * cos(hexTheta);
		hexVertex.y = 48 + 48 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	
	hexVertex.x = 60;
	hexVertex.y = 48;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 60;
	hexVertex.y = -72;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = 36 + 24 * cos(hexTheta);
		hexVertex.y = -72 - 24 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = 36;
	hexVertex.y = -95;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -36;
	hexVertex.y = -95;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = -36 - 24 * cos(hexTheta);
		hexVertex.y = -72 - 24 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = -60;
	hexVertex.y = -72;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	glEndList();
	///////////////////////////////////////////////////////////////Geamuri masina
	n = 200;
	glNewList(masina1+1, GL_COMPILE);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);// parbriz masina
	for (k = 1; k < n; k++)
	{
		hexTheta = TWO_PI/4* k / n+TWO_PI/5.4;
		hexVertex.x = 0 + 199.2 * cos(hexTheta);
		hexVertex.y = -153.2 + 199.2 * sin(hexTheta);
		if (hexVertex.x < -48) {
			break;
		}
		if (hexVertex.x > 48) {
			continue;
		}
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	hexVertex.x = 48 ;
	hexVertex.y = 40;
	glVertex2i(hexVertex.x, hexVertex.y);
	for (k = 1; k <n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n + TWO_PI / 5.4;
		hexVertex.x = 0 + 158.4 * cos(hexTheta);
		hexVertex.y = -153.2 + 158.4 * sin(hexTheta);
		if (hexVertex.x < -37) {
			break;
		}
		if (hexVertex.x > 37) {
			continue;
		}
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = -48;
	hexVertex.y = 40;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	//geamuri stanga
	glBegin(GL_POLYGON);
	hexVertex.x = -54;
	hexVertex.y = 27;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -41;
	hexVertex.y = -5;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -41;
	hexVertex.y = -29;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -54;
	hexVertex.y = -29;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	glBegin(GL_POLYGON);
	hexVertex.x = -54;
	hexVertex.y = -34;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -41;
	hexVertex.y = -34;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -41;
	hexVertex.y = -62;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -54;
	hexVertex.y = -58;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	/////////////////////////////////////////////////////////////////LUNETA
	n = 500;
	glBegin(GL_POLYGON);
	hexVertex.x = -43;
	hexVertex.y = -69;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 44;
	hexVertex.y = -69;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 44;
	hexVertex.y = -75;
	glVertex2i(hexVertex.x, hexVertex.y);
	
	for (k = 1; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = 32 + 12 * cos(hexTheta);
		hexVertex.y = -75 - 12 * sin(hexTheta);
		if (hexVertex.x < -44) {
			break;
		}
		if (hexVertex.x > 44) {
			continue;
		}
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = -31;
	hexVertex.y = -86;
	glVertex2i(hexVertex.x, hexVertex.y);
	for (k = 1; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = -32 - 12 * cos(hexTheta);
		hexVertex.y = -75 - 12 * sin(hexTheta);
		if (hexVertex.x < -44) {
			break;
		}
		if (hexVertex.x > 44) {
			continue;
		}
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = -43;
	hexVertex.y = -75;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	/////////////////////////////////////////////////////////geamuri dreapta
	glBegin(GL_POLYGON);
	hexVertex.x = 54;
	hexVertex.y = 27;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 41;
	hexVertex.y = -5;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 41;
	hexVertex.y = -29;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 54;
	hexVertex.y = -29;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	glBegin(GL_POLYGON);
	hexVertex.x = 54;
	hexVertex.y = -34;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 41;
	hexVertex.y = -34;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 41;
	hexVertex.y = -62;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 54;
	hexVertex.y = -58;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	glEndList();
	
	r = 0.0;
	b = 0.5;
	glNewList(masina1+2, GL_COMPILE);//////////////////////////////////////////////////////////Conturu masina 2
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	hexVertex.x = -60;
	hexVertex.y = -72;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -60;
	hexVertex.y = 48;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = -36 - 24 * cos(hexTheta);
		hexVertex.y = 48 + 48 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = 36;
	hexVertex.y = 95;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = 36 + 24 * cos(hexTheta);
		hexVertex.y = 48 + 48 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}

	hexVertex.x = 60;
	hexVertex.y = 48;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 60;
	hexVertex.y = -72;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = 36 + 24 * cos(hexTheta);
		hexVertex.y = -72 - 24 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = 36;
	hexVertex.y = -95;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -36;
	hexVertex.y = -95;
	glVertex2i(hexVertex.x, hexVertex.y);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI / 4 * k / n;
		hexVertex.x = -36 - 24 * cos(hexTheta);
		hexVertex.y = -72 - 24 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	hexVertex.x = -60;
	hexVertex.y = -72;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();
	glEndList();
	//// //////////////////////////////////////////////////////////////////////////////////// COPAC
	
	glClearColor(0.134, 0.54, 0.134, 1.0);
	copac = glGenLists(2);//2 benzi pe lateral
	glNewList(copac, GL_COMPILE);
	glColor3f(0.54, 0.27, 0.07);
	glBegin(GL_POLYGON);
	hexVertex.x = -17.5;
	hexVertex.y = -10;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 17.5;
	hexVertex.y = -10;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 12.5;
	hexVertex.y = 0;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = 12.5;
	hexVertex.y = 90;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -12.5;
	hexVertex.y = 90;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -12.5;
	hexVertex.y = 0;
	glVertex2i(hexVertex.x, hexVertex.y);
	hexVertex.x = -30.5;
	hexVertex.y = -10;
	glVertex2i(hexVertex.x, hexVertex.y);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	n = 300;
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI  * k / n;
		hexVertex.x =  30* cos(hexTheta);
		hexVertex.y = 100+ 30* sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glBegin(GL_POLYGON);
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI * k / n;
		hexVertex.x = 12.5 + 25 * cos(hexTheta);
		hexVertex.y = 112.5+ 25 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glBegin(GL_POLYGON);
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI * k / n;
		hexVertex.x = 12.5+ 25 * cos(hexTheta);
		hexVertex.y = 100-12.5 + 25 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glBegin(GL_POLYGON);
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI * k / n;
		hexVertex.x = -12.5 + 25 * cos(hexTheta);
		hexVertex.y = 112.5+ 25 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glBegin(GL_POLYGON);
	for (k = 0; k < n; k++)
	{
		hexTheta = TWO_PI * k / n;
		hexVertex.x = -12.5+ 25 * cos(hexTheta);
		hexVertex.y = 100-12.5 + 25 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glEndList();



	/// /////////////////////////////////////////////////////////////////////////////////////BENZI
	
	glClearColor(0.134, 0.54, 0.134, 1.0);
	banda = glGenLists(13);//13 benzi, 11 pe ecran //
	float dist=400.0,miscare = 72;
	int contor = 0;
	for (int i = 0; i < 13; i++) {
		glNewList(banda+i, GL_COMPILE);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		hexVertex.x = -15.0;
		hexVertex.y = dist - 50 - miscare*i;
		glVertex2i(hexVertex.x, hexVertex.y);
		hexVertex.x = -15.0;
		hexVertex.y = dist - miscare * i;
		glVertex2i(hexVertex.x, hexVertex.y);
		hexVertex.x = 15.0;
		hexVertex.y = dist - miscare * i;
		glVertex2i(hexVertex.x, hexVertex.y);
		hexVertex.x = 15.0;
		hexVertex.y = dist -50- miscare * i;
		glVertex2i(hexVertex.x, hexVertex.y);
		contor++;
		glEnd();
		glEndList();
	}
	
	/// /////////////////////////////////////////////////////////////////////////////////////Benzi Continue
	
	glClearColor(0.134, 0.54, 0.134, 1.0);
	benzi_continue = glGenLists(1);//2 benzi pe lateral
	glNewList(benzi_continue , GL_COMPILE);
	glColor3f(1, 1, 1);
	glLineWidth(10.0);
	glBegin(GL_LINES);
	glVertex2i(-142.0, -400.0);
	glVertex2i(-142.0, 400.0);
	glEnd();
	glEndList();
	glNewList(benzi_continue+1, GL_COMPILE);
	glColor3f(1, 1, 1);
	glLineWidth(10.0);
	glBegin(GL_LINES);
	glVertex2i(142.0, -400.0);
	glVertex2i(142.0, 400.0);
	glEnd();
	glEndList();
	///////////////////////////////////////////////////////////////////////ASFALT
	glClearColor(0.134, 0.54, 0.134, 1.0);
	asfalt = glGenLists(1);//2 benzi pe lateral
	glNewList(asfalt, GL_COMPILE);
	glColor3f(0.50, 0.50, 0.50);
	glBegin(GL_POLYGON);
	glVertex2i(-142.0, -400.0);
	glVertex2i(-142.0, 400.0);
	glVertex2i(142.0, 400.0);
	glVertex2i(142.0, -400.0);
	glEnd();
	glEndList();
	
}


void display(void)
{


	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glCallList(asfalt);
	glTranslated(0.0,i,0.0);
	for (int i = 0; i < 13; i++)
	{
		lista_banda[i] = i;
	}
	glListBase(banda);
	glCallLists(13,GL_UNSIGNED_BYTE,lista_banda);
	glPopMatrix();
	lista_benziContinue[0] = 0;
	lista_benziContinue[1] = 1;
	glListBase(benzi_continue);
	glCallLists(2, GL_UNSIGNED_BYTE, lista_benziContinue);

	glPushMatrix();
	glTranslated(-200*copac_parte, cont_copac, 0);
	glListBase(copac);
	glCallLists(1, GL_UNSIGNED_BYTE, lista_banda);
	glPopMatrix();
	
	for (int i = 0; i < 2; i++)
	{
		lista_masina1[i] = i;
	}
	lista_masina2[0] = 2;
	lista_masina2[1] = 1;

	if (test == 1){
		glPushMatrix();
		glScaled(0.7, 0.9, 0.9);
		glTranslated(0.0, 40+k-j-numar , 0);
		glRotated(unghi, 0, 0, 1);
		glTranslated(0.0, -40-k+j+numar , 0);
		glTranslated((k<16)?112.0 - l:112.0- l-k, -j+k-numar , 0);
		glListBase(masina1);
		glCallLists(2, GL_UNSIGNED_BYTE, lista_masina2);
		glPopMatrix();


		glPushMatrix();
		glScaled(0.7, 0.9, 0.9);
		if (l > 10) { 
			if(i1>0)glTranslated(-112.0, j - i1, 0.0);
			else if (i1 < 0) { glTranslated(112.0, j - i1, 0.0); 
			}
			else {
				glTranslated(+112.0, j , 0.0);
				//test = 0;
			}
		}
		else glTranslated(-112.0, j , 0.0);
		glListBase(masina1);
		glCallLists(2, GL_UNSIGNED_BYTE, lista_masina1);
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glScaled(0.7, 0.9, 0.9);
		glTranslated(-112.0, j, 0.0);
		glListBase(masina1);
		glCallLists(2, GL_UNSIGNED_BYTE, lista_masina1);
		glPopMatrix();
		glPushMatrix();
		glScaled(0.7, 0.9, 0.9);
		glTranslated(112.0, -j, 0);
		glListBase(masina1);
		glCallLists(2, GL_UNSIGNED_BYTE, lista_masina2);
		glPopMatrix();

	}

	


	glutSwapBuffers();
	glFlush();

}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300.0, 300.0, -400.0, 400.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
}

void depasire(void)
{
	if (test == 1) {
		if (unghi > 0.00) {
			k = k + gamma;
			if (k > 8)
			{

				l = l + gamma;
				unghi += 2;
			}
			if (l >= 54) {
				unghi -= 4;
			}
		}
		else {
			unghi = 0;
			if(numar<k)numar=numar + gamma;

		}
	}
	test =1;
	i = i + alpha;/////benzi
	if (l > 10) if(i1!=0)i1 = i1 - alpha;//alpha e negativ in declarare
	if (i1 > 496)i1 = -500;
	if (i <80 )
		i=i+72;
	if (j > 5)
		p = -1;
	if (j < -5)
		p = +1;
	if ((j > 3) || (j < -3))
		beta = 0.05;
	else beta = 0.2;
	if ((j > 1.5) || (j < -1.5))
		beta = 0.13;
	else beta = 0.2;
	j = j + beta * p;//////fata spate masina
	cont_copac += alpha;
	if (cont_copac < -1000) {
		cont_copac = 500;
		copac_parte *= -1;
	}

	
	glutPostRedisplay();
}

void start(void)
{
	i = i + alpha;
	if (i <82)
		i = i + 72;
	if (j > 5)
		p=-1;
	if (j < -5)
		p = +1;
	if ((j > 3) || (j < -3))
		beta = 0.05;
	else beta = 0.2;
	if ((j > 1.5) || (j < -1.5))
		beta = 0.13;
	else beta = 0.2;
	j = j + beta * p;
	cont_copac += alpha;
	if (cont_copac < -1000) {
		cont_copac = 500;
		copac_parte *= -1;
	}

	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			alpha = -10;
		}
		glutIdleFunc(start);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			alpha = -10; 
		glutIdleFunc(depasire);
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			alpha = -15;
		glutIdleFunc(start);
		break;
	default:
		break;
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Hexagon - utilizarea listelor de display");
	
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouse);
	glutMainLoop();
}


