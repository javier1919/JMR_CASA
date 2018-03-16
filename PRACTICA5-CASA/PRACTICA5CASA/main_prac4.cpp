//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Moran Rivas Javier         ******//
//*************	Visual Estudio 2015  					******//
//*************											******//
//*************	r- pulgar, t-dedo4, h-dedo3, y-dedo2, u-dedo1, i-mano, o-muñeca, p-brazo, l-hombro, k-bisep, j-codo ******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;
//angulos
float angcodo = 0.0f;
float angbisep = 0.0f;
float anghombro = 0.0f;
float angbrazo = 0.0f;
float angmuñeca = 0.0f;
float angmano = 0.0f;

float angdedo1 = 0.0f;
float angdedo2 = 0.0f;
float angdedo3 = 0.0f;
float angdedo4 = 0.0f;
float angpulgar = 0.0f;
float roty=0;
void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(0.0f, 0.0f, transZ);
		//Poner Código Aquí.
		glRotated(roty,0,1,0);
		

	
	//cabeza
	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(4,4,4);
	prisma();
	glPopMatrix();

	//cuello

    glTranslatef(0,-3,-0);
	glPushMatrix();

    glScalef(3,2,3);
	glColor3f(1,0,0);
	
	prisma();
	glPopMatrix();
glTranslated(0,-6,0);
	//torso
	glPushMatrix();
	
	 glScalef(10,10,3);
	 glColor3f(0,0,1);
	 prisma();
   glPopMatrix();

   glTranslated(2.5,-7.5,0);
   //pierna izquierda
   glPushMatrix();
      glScalef(2,5,3);
	  glColor3f(1,1,0);
	  prisma();
	  glPopMatrix();
  glTranslated(0,-3,0);
// rodilla izq
  glPushMatrix();
      glScalef(2,1,2);
	  glColor3f(1,0,1);
	  prisma();
	  glPopMatrix();
  glTranslated(0,-3,0);
  //espinilla izquierda
  glPushMatrix();
      glScalef(2,5,3);
	  glColor3f(1,0.5,0.5);
	  prisma();
	  glPopMatrix();

  glTranslated(0,-3,0);
  //tobillo izq
  glPushMatrix();
      glScalef(2,0,3);
	  glColor3f(1,1,0);
	  prisma();
	  glPopMatrix();
	  glTranslated(0, -.5, 0);
  //pie izq
	  glPushMatrix();
	  glScalef(2, 2, 3);
	  glColor3f(1, 0, 0);
	  prisma();
	  glPopMatrix();
  glTranslated(-5,0,0);
  
  //pie der
  glPushMatrix();
  glScalef(2, 2, 3);
  glColor3f(1, 0, 0);
  prisma();
  glPopMatrix();
  glTranslated(0, .5, 0);
  //dobillo der
  glPushMatrix();
      glScalef(2,0,3);
	  glColor3f(1,1,0);
	  prisma();
	  glPopMatrix();
  glTranslated(0,+3,0);
  //espinilla der
  glPushMatrix();
      glScalef(2,5,3);
	  glColor3f(1,0.5,0.5);
	  prisma();
	  glPopMatrix();
  glTranslated(0,3,0);

  //rodilla der
  glPushMatrix();
      glScalef(2,1,2);
	  glColor3f(1,0,1);
	  prisma();
	  glPopMatrix();
  glTranslated(0,3,0);
  //pierna der
  glPushMatrix();
      glScalef(2,5,3);
	  glColor3f(1, 1, 0);
	  prisma();
	  glPopMatrix();

	  //codo izq
  glTranslated(8,11.5,0);
  glRotatef(angcodo, 0.0, 0.0, 0.1);
  glPushMatrix();

  glScalef(1, 2, 2);
  glColor3f(1, 1, 1);

  prisma();
  glPopMatrix();
  
  //bicep
  glRotatef(angbisep, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(2, 0, 0);
  glScalef(3, 2, 2);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();

  //codo
  glRotatef(anghombro, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(3.75, 0, 0);
  glScalef(.5, 2, 2);
  glColor3f(1, 0, 0);
  prisma();
  glPopMatrix();

  //brazo
  glRotatef(angbrazo, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(6, 0, 0);
  glScalef(4, 2, 2);
  glColor3f(1, 1, 1);
  prisma();
  glPopMatrix();

  //Muñeca
  glRotatef(angmuñeca, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(8.25, 0, 0);
  glScalef(.5, 2, 2);
  glColor3f(1, 1, 0);
  prisma();
  glPopMatrix();

  //Mano
  glRotatef(angmano, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(9.5, 0, 0);
  glScalef(2, 2, 2);
  glColor3f(1, 1, 1);
  prisma();
  glPopMatrix();
  ///ded01
  //dedo1,1
  glRotatef(angdedo1, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, .75, .8);
  glScalef(.5, .4, .4);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo1, 0.0, 0.0, 0.1);
  //dedo1,2
  glRotatef(2 * angdedo1, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, .75, 0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo1, 0.0, 0.0, 0.1);
  //dedo1,3
  glRotatef(3 * angdedo1, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, .75, 0.8);
  glScalef(.5, .4, .4);
  glColor3f(1, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo1, 0.0, 0.0, 0.1);
  ///ded02
  //dedo2,1
  glRotatef(angdedo2, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, .75, .2);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo2, 0.0, 0.0, 0.1);
  //dedo2,2
  glRotatef(2 * angdedo2, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, .75, 0.2);
  glScalef(.5, .4, .4);
  glColor3f(0, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo2, 0.0, 0.0, 0.1);
  //dedo2,3
  glRotatef(3 * angdedo2, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, .75, 0.2);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo2, 0.0, 0.0, 0.1);
  ///ded03
  //dedo3,1
  glRotatef(angdedo3, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, .75, -0.3);
  glScalef(.5, .4, .4);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo3, 0.0, 0.0, 0.1);
  //dedo3,2
  glRotatef(2 * angdedo3, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, 0.75, -0.3);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo3, 0.0, 0.0, 0.1);
  //dedo3,3
  glRotatef(3 * angdedo3, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, 0.75, -0.3);
  glScalef(.5, .4, .4);
  glColor3f(1, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo3, 0.0, 0.0, 0.1);
  ///ded04
  //dedo4,1
  glRotatef(angdedo4, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, 0.75, -0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo4, 0.0, 0.0, 0.1);
  //dedo4,2
  glRotatef(2 * angdedo4, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, 0.75, -0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo4, 0.0, 0.0, 0.1);
  //dedo4,3
  glRotatef(3 * angdedo4, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, 0.75, -0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo4, 0.0, 0.0, 0.1);
  //pulgar 1
  glRotatef(angpulgar, 0.0, 0.1, 0.0);
  glPushMatrix();
  glTranslatef(10.25, 1.25, .75);
  glScalef(.4, .5, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angpulgar, 0.0, 0.1, 0.0);
  //pulgar 2
  glRotatef(2 * angpulgar, 0.0, 0.1, 0.0);
  glPushMatrix();
  glTranslatef(10.25, 1.75, .75);
  glScalef(.4, .5, .4);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angpulgar, 0.0, 0.1, 0.0);

  glRotatef(-angcodo, 0.0, 0.0, 0.1);
  glRotatef(-angbisep, 0.0, 0.0, 0.1);
  glRotatef(-anghombro, 0.0, 0.0, 0.1);
  glRotatef(-angbrazo, 0.0, 0.0, 0.1);
  glRotatef(-angmuñeca, 0.0, 0.0, 0.1);
  glRotatef(-angmano, 0.0, 0.0, 0.1);

  //TODO ESTO ES DEL BRAZO DERECHO
  glRotatef(180, 0.0,0.0,0.1);
  glRotatef(180, 1.0, 0.0, 0.0);
  glTranslatef(11, 0.0, 0.0);
 glRotatef(angcodo, 0.0, 0.0, 0.1); 
  glPushMatrix();

  glScalef(1, 2, 2);
  glColor3f(1, 1, 1);

  prisma();
  glPopMatrix();
  //bicep
  glRotatef(angbisep, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(2, 0, 0);
  glScalef(3, 2, 2);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();

  //codo
  glRotatef(anghombro, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(3.75, 0, 0);
  glScalef(.5, 2, 2);
  glColor3f(1, 0, 0);
  prisma();
  glPopMatrix();

  //brazo
  glRotatef(angbrazo, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(6, 0, 0);
  glScalef(4, 2, 2);
  glColor3f(1, 1, 1);
  prisma();
  glPopMatrix();

  //Muñeca
  glRotatef(angmuñeca, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(8.25, 0, 0);
  glScalef(.5, 2, 2);
  glColor3f(1, 1, 0);
  prisma();
  glPopMatrix();

  //Mano
  glRotatef(angmano, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(9.5, 0, 0);
  glScalef(2, 2, 2);
  glColor3f(1, 1, 1);
  prisma();
  glPopMatrix();
  ///ded01
  //dedo1,1
  glRotatef(angdedo1, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, .75, .8);
  glScalef(.5, .4, .4);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo1, 0.0, 0.0, 0.1);
  //dedo1,2
  glRotatef(2 * angdedo1, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, .75, 0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo1, 0.0, 0.0, 0.1);
  //dedo1,3
  glRotatef(3 * angdedo1, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, .75, 0.8);
  glScalef(.5, .4, .4);
  glColor3f(1, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo1, 0.0, 0.0, 0.1);
  ///ded02
  //dedo2,1
  glRotatef(angdedo2, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, .75, .2);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo2, 0.0, 0.0, 0.1);
  //dedo2,2
  glRotatef(2 * angdedo2, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, .75, 0.2);
  glScalef(.5, .4, .4);
  glColor3f(0, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo2, 0.0, 0.0, 0.1);
  //dedo2,3
  glRotatef(3 * angdedo2, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, .75, 0.2);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo2, 0.0, 0.0, 0.1);
  ///ded03
  //dedo3,1
  glRotatef(angdedo3, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, .75, -0.3);
  glScalef(.5, .4, .4);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo3, 0.0, 0.0, 0.1);
  //dedo3,2
  glRotatef(2 * angdedo3, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, 0.75, -0.3);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo3, 0.0, 0.0, 0.1);
  //dedo3,3
  glRotatef(3 * angdedo3, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, 0.75, -0.3);
  glScalef(.5, .4, .4);
  glColor3f(1, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo3, 0.0, 0.0, 0.1);
  ///ded04
  //dedo4,1
  glRotatef(angdedo4, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(10.75, 0.75, -0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angdedo4, 0.0, 0.0, 0.1);
  //dedo4,2
  glRotatef(2 * angdedo4, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.25, 0.75, -0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 1, 0);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angdedo4, 0.0, 0.0, 0.1);
  //dedo4,3
  glRotatef(3 * angdedo4, 0.0, 0.0, 0.1);
  glPushMatrix();
  glTranslatef(11.75, 0.75, -0.8);
  glScalef(.5, .4, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-3 * angdedo4, 0.0, 0.0, 0.1);
  //pulgar 1
  glRotatef(angpulgar, 0.0, 0.1, 0.0);
  glPushMatrix();
  glTranslatef(10.25, 1.25, .75);
  glScalef(.4, .5, .4);
  glColor3f(0, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-angpulgar, 0.0, 0.1, 0.0);
  //pulgar 2
  glRotatef(2 * angpulgar, 0.0, 0.1, 0.0);
  glPushMatrix();
  glTranslatef(10.25, 1.75, .75);
  glScalef(.4, .5, .4);
  glColor3f(1, 0, 1);
  prisma();
  glPopMatrix();
  glRotatef(-2 * angpulgar, 0.0, 0.1, 0.0);
	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	//glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
glutSwapBuffers ( );
  // Swap The Buffers
}
		
		


void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			
			break;
		case 'd':
		case 'D':
	
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;  
		case 'j':        // Cuando Esc es presionado...
			if (angcodo <= 80)
				angcodo += 1;   // Salimos del programa

			printf("%f \n", angcodo);// Salimos del programa
			break;

		case 'J':        // Cuando Esc es presionado...
			if (angcodo >= -80)
				angcodo = angcodo - 1;

			printf("%f \n", angcodo);// Salimos del programa
			break;

		case 'k':        // Cuando Esc es presionado...
			if (angbisep <= 15)
				angbisep += 1;   // Salimos del programa

			printf("%f \n", angbisep);// Salimos del programa
			break;

		case 'K':        // Cuando Esc es presionado...
			if (angbisep >= -15)
				angbisep = angbisep - 1;

			printf("%f \n", angbisep);// Salimos del programa
			break;

		case 'l':        // Cuando Esc es presionado...
			if (anghombro <= 2)
				anghombro += 1;   // Salimos del programa

			printf("%f \n", anghombro);// Salimos del programa
			break;

		case 'L':        // Cuando Esc es presionado...
			if (anghombro >= -2)
				anghombro = anghombro - 1;

			printf("%f \n", anghombro);// Salimos del programa
			break;

		case 'p':        // Cuando Esc es presionado...
			if (angbrazo <= 2)
				angbrazo += 1;   // Salimos del programa

			printf("%f \n", angbrazo);// Salimos del programa
			break;

		case 'P':        // Cuando Esc es presionado...
			if (angbrazo >= -2)
				angbrazo = angbrazo - 1;

			printf("%f \n", angbrazo);// Salimos del programa
			break;

		case 'o':        // Cuando Esc es presionado...
			if (angmuñeca <= 2)
				angmuñeca += 1;   // Salimos del programa

			printf("%f \n", angmuñeca);// Salimos del programa
			break;

		case 'O':        // Cuando Esc es presionado...
			if (angmuñeca >= -2)
				angmuñeca = angmuñeca - 1;

			printf("%f \n", angmuñeca);// Salimos del programa
			break;

		case 'i':        // Cuando Esc es presionado...
			if (angmano <= 2)
				angmano += 1;   // Salimos del programa

			printf("%f \n", angmano);// Salimos del programa
			break;

		case 'I':        // Cuando Esc es presionado...
			if (angmano >= -2)
				angmano = angmano - 1;

			printf("%f \n", angmano);// Salimos del programa
			break;

		case 'U':        // Cuando Esc es presionado...
			if (angdedo1 <= 1)
				angdedo1 += 1;   // Salimos del programa

			printf("%f \n", angdedo1);// Salimos del programa
			break;

		case 'u':        // Cuando Esc es presionado...
			if (angdedo1 >= -1)
				angdedo1 = angdedo1 - 1;

			printf("%f \n", angdedo1);// Salimos del programa
			break;

		case 'Y':        // Cuando Esc es presionado...
			if (angdedo2 <= 1)
				angdedo2 += 1;   // Salimos del programa

			printf("%f \n", angdedo2);// Salimos del programa
			break;

		case 'y':        // Cuando Esc es presionado...
			if (angdedo2 >= -1)
				angdedo2 = angdedo2 - 1;

			printf("%f \n", angdedo2);// Salimos del programa
			break;
		case 'H':        // Cuando Esc es presionado...
			if (angdedo3 <= 1)
				angdedo3 += 1;   // Salimos del programa

			printf("%f \n", angdedo3);// Salimos del programa
			break;

		case 'h':        // Cuando Esc es presionado...
			if (angdedo3 >= -1)
				angdedo3 = angdedo3 - 1;

			printf("%f \n", angdedo3);// Salimos del programa
			break;

		case 'T':        // Cuando Esc es presionado...
			if (angdedo4 <= 1)
				angdedo4 += 1;   // Salimos del programa

			printf("%f \n", angdedo4);// Salimos del programa
			break;

		case 't':        // Cuando Esc es presionado...
			if (angdedo4 >= -1)
				angdedo4 = angdedo4 - 1;

			printf("%f \n", angdedo4);// Salimos del programa
			break;

		case 'R':        // Cuando Esc es presionado...
			if (angpulgar <= 1)
				angpulgar += 1;   // Salimos del programa

			printf("%f \n", angpulgar);// Salimos del programa
			break;

		case 'r':        // Cuando Esc es presionado...
			if (angpulgar >= -1)
				angpulgar = angpulgar - 1;

			printf("%f \n", angpulgar);// Salimos del programa
			break;

		
		default:        // Cualquier otra
		break;

  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		roty= roty-0.2;
		break;
	case GLUT_KEY_RIGHT:
		roty=roty+0.2;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



