#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <mmsystem.h>
#include <conio.h>

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
double x = 0.0;
double y = 0.0;
double m = 0.0;
double n = 0.0;

int scr1 = 0;
int scr2 = 0;

double px = 0.0;
double py = 0.0;

float torus_x1= 0;
float torus_x2= 3;
float torus_x3= -3;
float torus_x4= -6;
float torus_x5= 6;

float torus_y1= 10;
float torus_y2= 25;
float torus_y3= 30;
float torus_y4= 40;
float torus_y5= 15;

float rocks_x1= 9;
float rocks_x2= 8;
float rocks_x3= 10;
float rocks_x4= 11;

float rocks_x5= -9;
float rocks_x6= -8;
float rocks_x7= -10;
float rocks_x8= -11;

float rocks_x9= -9;
float rocks_x10= -8;
float rocks_x11= -10;
float rocks_x12= -11;

float rocks_x13= -9;
float rocks_x14= -8;
float rocks_x15= -10;
float rocks_x16= -11;

float rocks_y1= 0;
float rocks_y2= 2;
float rocks_y3= 1;
float rocks_y4= -1;

float rocks_y5= 0;
float rocks_y6= 2;
float rocks_y7= 1;
float rocks_y8= -1;


float rocks_y9= 0;
float rocks_y10= 2;
float rocks_y11= 1;
float rocks_y12= -1;

float rocks_y13= 0;
float rocks_y14= 2;
float rocks_y15= 1;
float rocks_y16= -1;

void torusAnimation(int);
void rocksAnimation(int);

void torus();
void rocket();



//------------------------------  reshapeFunc  --------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  drawing_text  --------------------------------

void drawing_text(char *text,int length,float x,float y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 100, 0, 1100, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i =0; i<length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);

    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}


//--------------------------------  rocks animation  ----------------------------------

void rocksAnimation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,rocksAnimation,0);
    rocks_x1 = rocks_x1 - 0.03;
    rocks_x2 = rocks_x2 - 0.02;
    rocks_x3 = rocks_x3 - 0.03;
    rocks_x4 = rocks_x4 - 0.03;

    if(rocks_x1<-(-2)) rocks_x1=9;
    if(rocks_x2<-(-1)) rocks_x2=8;
    if(rocks_x3<-(-2)) rocks_x3=10;
    if(rocks_x4<-(-2)) rocks_x4=11;

    rocks_x5 = rocks_x5 + 0.01;
    rocks_x6 = rocks_x6 + 0.02;
    rocks_x7 = rocks_x7 + 0.04;
    rocks_x8 = rocks_x8 + 0.03;

    rocks_x9 = rocks_x9 + 0.01;
    rocks_x10 = rocks_x10 + 0.02;
    rocks_x11 = rocks_x11 + 0.04;
    rocks_x12 = rocks_x12 + 0.03;

    rocks_x13 = rocks_x13 + 0.01;
    rocks_x14 = rocks_x14 + 0.02;
    rocks_x15 = rocks_x15 + 0.04;
    rocks_x16 = rocks_x16 + 0.03;


    float torrance=0.9;
    float deviation=2.2;

    if((-4.0+py+m)>=rocks_y1+deviation-torrance && (-4.0+py+m)<=rocks_y1+deviation+torrance && (-4.3+px)>=rocks_x1-torrance && (-4.3+px)<=rocks_x1+torrance){
            rocks_x1=9;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y2+deviation-torrance && (-4.0+py+m)<=rocks_y2+deviation+torrance && (-4.3+px)>=rocks_x2-torrance && (-4.3+px)<=rocks_x2+torrance) {
            rocks_x2=8;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y3+deviation-torrance && (-4.0+py+m)<=rocks_y3+deviation+torrance && (-4.3+px)>=rocks_x3-torrance && (-4.3+px)<=rocks_x3+torrance) {
            rocks_x3=10;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y4+deviation-torrance && (-4.0+py+m)<=rocks_y4+deviation+torrance && (-4.3+px)>=rocks_x4-torrance && (-4.3+px)<=rocks_x4+torrance) {
            rocks_x4=11;
            scr1 += 2;
    }

    if((-4.0+py+m)>=rocks_y5+deviation-torrance && (-4.0+py+m)<=rocks_y5+deviation+torrance && (-4.3+px)>=rocks_x5-torrance && (-4.3+px)<=rocks_x5+torrance) {
            rocks_x5=-9;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y6+deviation-torrance && (-4.0+py+m)<=rocks_y6+deviation+torrance && (-4.3+px)>=rocks_x6-torrance && (-4.3+px)<=rocks_x6+torrance) {
            rocks_x6=-8;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y7+deviation-torrance && (-4.0+py+m)<=rocks_y7+deviation+torrance && (-4.3+px)>=rocks_x7-torrance && (-4.3+px)<=rocks_x7+torrance) {
            rocks_x7=-10;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y8+deviation-torrance && (-4.0+py+m)<=rocks_y8+deviation+torrance && (-4.3+px)>=rocks_x8-torrance && (-4.3+px)<=rocks_x8+torrance) {
            rocks_x8=-11;
            scr1 += 2;
    }

    if((-4.0+py+m)>=rocks_y9+deviation-torrance && (-4.0+py+m)<=rocks_y9+deviation+torrance && (-4.3+px)>=rocks_x9-torrance && (-4.3+px)<=rocks_x9+torrance) {
            rocks_x9=-9;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y10+deviation-torrance && (-4.0+py+m)<=rocks_y10+deviation+torrance && (-4.3+px)>=rocks_x10-torrance && (-4.3+px)<=rocks_x10+torrance) {
            rocks_x10=-8;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y11+deviation-torrance && (-4.0+py+m)<=rocks_y11+deviation+torrance && (-4.3+px)>=rocks_x11-torrance && (-4.3+px)<=rocks_x11+torrance) {
            rocks_x11=-10;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y12+deviation-torrance && (-4.0+py+m)<=rocks_y12+deviation+torrance && (-4.3+px)>=rocks_x12-torrance && (-4.3+px)<=rocks_x12+torrance) {
            rocks_x12=-11;
            scr1 += 2;
    }

    if((-4.0+py+m)>=rocks_y13+deviation-torrance && (-4.0+py+m)<=rocks_y13+deviation+torrance && (-4.3+px)>=rocks_x13-torrance && (-4.3+px)<=rocks_x13+torrance) {
            rocks_x13=-9;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y14+deviation-torrance && (-4.0+py+m)<=rocks_y14+deviation+torrance && (-4.3+px)>=rocks_x14-torrance && (-4.3+px)<=rocks_x14+torrance) {
            rocks_x14=-8;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y15+deviation-torrance && (-4.0+py+m)<=rocks_y15+deviation+torrance && (-4.3+px)>=rocks_x15-torrance && (-4.3+px)<=rocks_x15+torrance) {
            rocks_x15=-10;
            scr1 += 2;
    }
    if((-4.0+py+m)>=rocks_y16+deviation-torrance && (-4.0+py+m)<=rocks_y16+deviation+torrance && (-4.3+px)>=rocks_x16-torrance && (-4.3+px)<=rocks_x16+torrance) {
            rocks_x16=-11;
            scr1 += 2;
    }
    if((-4.0+y+n)>=rocks_y1+deviation-torrance && (-4.0+y+n)<=rocks_y1+deviation+torrance && (4.3+x)>=rocks_x1-torrance && (4.3+x)<=rocks_x1+torrance) {
            rocks_x1=9;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y2+deviation-torrance && (-4.0+y+n)<=rocks_y2+deviation+torrance && (4.3+x)>=rocks_x2-torrance && (4.3+x)<=rocks_x2+torrance) {
            rocks_x2=8;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y3+deviation-torrance && (-4.0+y+n)<=rocks_y3+deviation+torrance && (4.3+x)>=rocks_x3-torrance && (4.3+x)<=rocks_x3+torrance) {
            rocks_x3=10;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y4+deviation-torrance && (-4.0+y+n)<=rocks_y4+deviation+torrance && (4.3+x)>=rocks_x4-torrance && (4.3+x)<=rocks_x4+torrance) {
            rocks_x4=11;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y5+deviation-torrance && (-4.0+y+n)<=rocks_y5+deviation+torrance && (4.3+x)>=rocks_x5-torrance && (4.3+x)<=rocks_x5+torrance) {
            rocks_x5=-9;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y6+deviation-torrance && (-4.0+y+n)<=rocks_y6+deviation+torrance && (4.3+x)>=rocks_x6-torrance && (4.3+x)<=rocks_x6+torrance) {
            rocks_x6=-8;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y7+deviation-torrance && (-4.0+y+n)<=rocks_y7+deviation+torrance && (4.3+x)>=rocks_x7-torrance && (4.3+x)<=rocks_x7+torrance) {
            rocks_x7=-10;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y8+deviation-torrance && (-4.0+y+n)<=rocks_y8+deviation+torrance && (4.3+x)>=rocks_x8-torrance && (4.3+x)<=rocks_x8+torrance) {
            rocks_x8=-11;
            scr2 += 2;
    }

    if((-4.0+y+n)>=rocks_y9+deviation-torrance && (-4.0+y+n)<=rocks_y9+deviation+torrance && (4.3+x)>=rocks_x9-torrance && (4.3+x)<=rocks_x9+torrance) {
            rocks_x9=-9;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y10+deviation-torrance && (-4.0+y+n)<=rocks_y10+deviation+torrance && (4.3+x)>=rocks_x10-torrance && (4.3+x)<=rocks_x10+torrance) {
            rocks_x10=-8;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y11+deviation-torrance && (-4.0+y+n)<=rocks_y11+deviation+torrance && (4.3+x)>=rocks_x11-torrance && (4.3+x)<=rocks_x11+torrance) {
            rocks_x11=-10;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y12+deviation-torrance && (-4.0+y+n)<=rocks_y12+deviation+torrance && (4.3+x)>=rocks_x12-torrance && (4.3+x)<=rocks_x12+torrance) {
            rocks_x12=-11;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y13+deviation-torrance && (-4.0+y+n)<=rocks_y13+deviation+torrance && (4.3+x)>=rocks_x13-torrance && (4.3+x)<=rocks_x13+torrance) {
            rocks_x13=-9;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y14+deviation-torrance && (-4.0+y+n)<=rocks_y14+deviation+torrance && (4.3+x)>=rocks_x14-torrance && (4.3+x)<=rocks_x14+torrance) {
            rocks_x14=-8;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y15+deviation-torrance && (-4.0+y+n)<=rocks_y15+deviation+torrance && (4.3+x)>=rocks_x15-torrance && (4.3+x)<=rocks_x15+torrance) {
            rocks_x15=-10;
            scr2 += 2;
    }
    if((-4.0+y+n)>=rocks_y16+deviation-torrance && (-4.0+y+n)<=rocks_y16+deviation+torrance && (4.3+x)>=rocks_x16-torrance && (4.3+x)<=rocks_x16+torrance) {
            rocks_x16=-11;
            scr2 += 2;
    }
}

//--------------------------------  Player One   ----------------------------------

void playerOne()
{
    char score[64]="Player1: ";
    char num[50];

    sprintf(num, "%d", scr1); // changes datatype by adding to a char arrray

    strcat(score, num);//copy array num to score

    glColor3f(0,1,0); //text color
    glRasterPos3f(-7.0,5.1,-15.2); //xyz
    for(int i=0;i<strlen(score);i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,score[i]);

    } //for loop to print text
}


//--------------------------------  Player Two   ----------------------------------

void playerTwo()
{
    char score[64]="Player2: ";
    char num[50];

    sprintf(num, "%d", scr2); // changes datatype by adding to a char arrray

    strcat(score, num);//copy array num to score

    glColor3f(0,1,0); //text color
    glRasterPos3f(5.0,5.1,-15.2); //xyz
    for(int i=0;i<strlen(score);i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,score[i]);
    } //for loop to print text

}
//------------------------------  welcome display   ------------------------------

void welcomeDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,0);

    drawing_text("Press (x) To Start The Game", 28, 38, 520);
    glutSwapBuffers();

}

//------------------------------  earth  --------------------------------

void earth()
{
    glPushMatrix();
        glTranslatef(0,0,-15);
        glScalef(0.9,0.9,0.9);
        glColor4f(0.0/255.0,82/255.0,218.0/255.0, 255.0/255.0);
        gluSphere(gluNewQuadric(),2,100,100);
	glPopMatrix();
}

//------------------------------  poly  --------------------------------

void poly()
{

    glBegin(GL_POLYGON);
    // Front
    glColor4f(1,0,0,0);
    glVertex3f(-5.0 , 2.2 ,  -15);
    glVertex3f(-5.1 , 2.1 ,  -15);
    glVertex3f(-5 , 2 ,-15);
    glVertex3f(-4.9 , 2.1 ,-15);
    //right side
    glColor4f(178.0/255.0,34.0/255.0,34.0/255.0,0.0);
    glVertex3f(-5.0 , 2.2 ,  -15);
    glVertex3f(-4.9 , 2.1 ,-15);
    glVertex3f(-5 , 2 ,  -15);
    glVertex3f(-5 , 2 ,-15.2);
    glVertex3f(-4.9 , 2.1 ,-15.2);
    glVertex3f(-5.0 , 2.2 ,-15.2);
    //left side
    glColor4f(178.0/255.0,34.0/255.0,34.0/255.0,0.0);
    glVertex3f(-5.0 , 2.2 ,  -15);
    glVertex3f(-5.1 , 2.1 ,  -15);
    glVertex3f(-5 , 2 ,-15);
    glVertex3f(-5 , 2 ,-15.2);
    glVertex3f(-5.11 , 2.1 ,-15.2);
    glVertex3f(-5.0 , 2.2 ,-15.2);
    //back
    glColor4f(1,0,0,0);
    glVertex3f(-5 , 2 ,-15.2);
    glVertex3f(-4.9 , 2.1 ,-15.2);
    glVertex3f(-5.0 , 2.2 ,-15.2);
    glVertex3f(-5.11 , 2.1 ,-15.2);
    glEnd();


}

//------------------------------  rectangle  --------------------------------

void rectangle()
{

    //first rectangle
    glBegin(GL_POLYGON);
    // Front
    glColor4f(15/255.0, 42/255.0,156/255.0,1);
    glVertex3f(-7.0, 4.5,  -15.0);
    glVertex3f(-7.0, 4.0, -15.0);
    glVertex3f(-5.5, 4.0, -15.0);
    glVertex3f(-5.5, 4.5, -15.0);
    // Back
    glColor3f(25/255.0,25/255.0,122/255.0);
    glVertex3f(-7.0, 4.0,  -16.0);
    glVertex3f(-5.5, 4.0, -16.0);
    glVertex3f(-5.5, 4.5, -16.0);
    glVertex3f(-7.0, 4.5, -16.0);
    // left
    glColor3f(25/255.0,25/255.0,122/255.0);
    glVertex3f(-5.5, 4.0,  -15.0);
    glVertex3f(-5.5, 4.0, -15.0);
    glVertex3f(-5.5, 4.0, -16.0);
    glVertex3f(-5.5, 4.5, -16.0);
    // right
    glColor3f(25/255.0,25/255.0,122/255.0);
    glVertex3f(-7.0, 4.5,  -15.0);
    glVertex3f(-7.0, 4.0, -15.0);
    glVertex3f(-7.0, 4.0, -16.0);
    glVertex3f(-7.0, 4.5, -16.0);
    // top
    glColor3f(25/255.0,25/255.0,122/255.0);
    glVertex3f(-7.0, 4.5,  -15.0);
    glVertex3f(-7.0, 4.5, -16.0);
    glVertex3f(-5.5, 4.5, -16.0);
    glVertex3f(-5.5, 4.5, -15.0);
    // bottom
    glColor3f(25/255.0,25/255.0,122/255.0);
    glVertex3f(-7.0, 4.0,  -15.0);
    glVertex3f(-5.5, 4.0, -15.0);
    glVertex3f(-5.5, 4.0, -16.0);
    glVertex3f(-7.0, 4.0, -16.0);
    glEnd();



    //second rectangle
    glBegin(GL_POLYGON);
    // Front
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3.0, 4.5,  -15.0);
    glVertex3f(3.0, 4.0, -15.0);
    glVertex3f(4.5, 4.0, -15.0);
    glVertex3f(4.5, 4.5, -15.0);
    // Back
    glVertex3f(3.0, 4.0,  -16.0);
    glVertex3f(4.5, 4.0, -16.0);
    glVertex3f(4.5, 4.5, -16.0);
    glVertex3f(3.0, 4.5, -16.0);
//
    glVertex3f(3.0, 4.0,  -15.0);
    glVertex3f(3.0, 4.0, -15.0);
    glVertex3f(3.0, 4.0, -16.0);
    glVertex3f(3.0, 4.5, -16.0);
    // right
    glVertex3f(4.5, 4.5,  -15.0);
    glVertex3f(4.5, 4.0, -15.0);
    glVertex3f(4.5, 4.0, -16.0);
    glVertex3f(4.5, 4.5, -16.0);
//     top
    glVertex3f(3.0, 4.5,  -15.0);
    glVertex3f(3.0, 4.5, -16.0);
    glVertex3f(4.5, 4.5, -16.0);
    glVertex3f(4.5, 4.5, -15.0);
//     bottom
    glVertex3f(3.0, 4.0,  -15.0);
    glVertex3f(4.5, 4.0, -15.0);
    glVertex3f(4.5, 4.0, -16.0);
    glVertex3f(3.0, 4.0, -16.0);
    glEnd();
}

//------------------------------  bullets  --------------------------------

void bullets(){
    // LEFT bullets
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-4.3+px,-4.0+py+m, -13);
    glRotated(280.0,280.0,0.0,-15.0);
    glScaled(0.1, 0.1, 0.2);
    glutSolidCone(1.0, 2.0, 50.0, 50.0);
    glPopMatrix();

    // RIGHT bullets
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(4.3+x,-4.0+y+n, -13);
    glRotated(280.0,280.0,0.0,-15.0);
    glScaled(0.1, 0.1, 0.2);
    glutSolidCone(1.0, 2.0, 50.0, 50.0);
    glPopMatrix();
}

//------------------------------  rocket  --------------------------------

void rocket()
{
    //---------- right rocket -----------
    //oval
    glPushMatrix();
    glColor3f(230.0/255, 230.0/255, 250.0/255);
    glTranslatef(5.0+x, -4.5+y, -15.0);
    glScaled(0.2,0.5,0.2);
    glutSolidSphere(1,25,25);
    glPopMatrix();
    //right wing
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(5.3+x, -4.5+y, -15.0);
    glScaled(0.1, 0.3, 0.2);
    glutSolidSphere(1,25,25);
    glPopMatrix();
    //left wing
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(4.7+x, -4.5+y, -15.0);
    glScaled(0.1, 0.3, 0.2);
    glutSolidSphere(1,25,25);
    glPopMatrix();

    //---------- left rocket -----------
    //oval
    glPushMatrix();
    glColor3f(1.0,84.0/255.0,0.0);
    glTranslatef(-5.0+px, -4.5+py, -15.0);
    glScaled(0.2,0.5,0.2);
    glutSolidSphere(1,25,25);
    glPopMatrix();
    //left wing
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-5.3+px, -4.5+py, -15.0);
    glScaled(0.1, 0.3, 0.2);
    glutSolidSphere(1,25,25);
    glPopMatrix();
    //right wing
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-4.7+px, -4.5+py, -15.0);
    glScaled(0.1, 0.3, 0.2);
    glutSolidSphere(1,25,25);
    glPopMatrix();
}


//------------------------------  display  --------------------------------
void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3d(0,0,0);

    earth();
    torus();
    rocket();
    bullets();
    playerOne();
    playerTwo();
    rectangle();

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    glRotated(a,0,0,1);
    poly();

    glutSwapBuffers();
}

//------------------------------  keys  --------------------------------

void keys(unsigned char key, int xx, int yy)
{
    if(key =='x')
    {
        glutDisplayFunc(display);
    }
    if (key == 32)
    {
        m = 0;
    }
    else{
        m++;
    }
    if (key == 13)
    {
        n = 0;
    }
    else{
        n ++;
    }
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case '4':
        x--;
        break;

    case '6':
        x++;
        break;

    case '8':
        y++;
        break;

    case '5':
        y--;
        break;

    case 'a':
        px--;
        break;

    case 's':
        py--;
        break;

    case'd':
        px++;
        break;

    case'w':
        py++;
        break;
    }

    glutPostRedisplay();
}

//------------------------------  rocks  --------------------------------

void rocks()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    glColor3d(220.0/255.0,220/255.0,220/255.0);

    glPushMatrix();
        glTranslatef(rocks_x1,rocks_y1,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x2,rocks_y2,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x3,rocks_y3,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x4,rocks_y4,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x5,rocks_y5,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x6,rocks_y6,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x7,rocks_y7,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x8,rocks_y8,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x9,rocks_y9,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x10,rocks_y10,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x11,rocks_y11,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x12,rocks_y12,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x13,rocks_y13,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x14,rocks_y14,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glTranslatef(rocks_x15,rocks_y15,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();

	glPushMatrix();
        glColor3d(0,0,0);
        glTranslatef(rocks_x16,rocks_y16,-15);
        glScaled(0.25,0.25,0.25);
        glRotated(a,0,0,1);
        glutSolidIcosahedron();
	glPopMatrix();
}

//------------------------------  torus  --------------------------------

void torus()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    rocks();
    glColor3d(255.0/255.0,215.0/255.0,0.0/255.0);

    glPushMatrix();
        glTranslated(torus_x1,torus_y1,-20);
        glRotated(a,0,0,1);
        glutSolidTorus(0.15,0.4,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(torus_x2,torus_y2,-20);
        glRotated(a,0,0,1);
        glutSolidTorus(0.15,0.4,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(torus_x3,torus_y3,-20);
        glRotated(a,0,0,1);
        glutSolidTorus(0.15,0.4,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(torus_x4,torus_y4,-20);
        glRotated(a,0,0,1);
        glutSolidTorus(0.15,0.4,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(torus_x5,torus_y5,-20);
        glRotated(a,0,0,1);
        glutSolidTorus(0.15,0.4,16,16);
    glPopMatrix();

}

//------------------------------  torus animation  --------------------------------

void torusAnimation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,torusAnimation,0);

    torus_y1 = torus_y1 - 0.04;
    torus_y2 = torus_y2 - 0.03;
    torus_y3 = torus_y3 - 0.02;
    torus_y4 = torus_y4 - 0.01;
    torus_y5 = torus_y5 - 0.001;

    float torrance=0.9;
    float deviation=2.2;

    if((-4.5+y)>=torus_y1+deviation-torrance && (-4.5+y)<=torus_y1+deviation+torrance && (5.0+x)>=torus_x1-torrance && (5.0+x)<=torus_x1+torrance){
            torus_y1=10;
            scr2 += 5;
    }
    if((-4.5+y)>=torus_y2+deviation-torrance && (-4.5+y)<=torus_y2+deviation+torrance && (5.0+x)>=torus_x2-torrance && (5.0+x)<=torus_x2+torrance){
            torus_y2=25;
            scr2 += 5;
    }
    if((-4.5+y)>=torus_y3+deviation-torrance && (-4.5+y)<=torus_y3+deviation+torrance && (5.0+x)>=torus_x3-torrance && (5.0+x)<=torus_x3+torrance){
            torus_y3=30;
            scr2 += 5;
    }
    if((-4.5+y)>=torus_y4+deviation-torrance && (-4.5+y)<=torus_y4+deviation+torrance && (5.0+x)>=torus_x4-torrance && (5.0+x)<=torus_x4+torrance){
            torus_y4=40;
            scr2 += 5;
    }
    if((-4.5+y)>=torus_y5+deviation-torrance && (-4.5+y)<=torus_y5+deviation+torrance && (5.0+x)>=torus_x5-torrance && (5.0+x)<=torus_x5+torrance){
            torus_y5=15;
            scr2 += 5;
    }
    if((-4.5+py)>=torus_y1+deviation-torrance && (-4.5+y)<=torus_y1+deviation+torrance && (-5.0+px)>=torus_x1-torrance && (-5.0+px)<=torus_x1+torrance){
            torus_y1=10;
            scr1 += 5;
    }
    if((-4.5+py)>=torus_y2+deviation-torrance && (-4.5+y)<=torus_y2+deviation+torrance && (-5.0+px)>=torus_x2-torrance && (-5.0+px)<=torus_x2+torrance){
            torus_y2=25;
            scr1 += 5;
    }
    if((-4.5+py)>=torus_y3+deviation-torrance && (-4.5+y)<=torus_y3+deviation+torrance && (-5.0+px)>=torus_x3-torrance && (-5.0+px)<=torus_x3+torrance){
            torus_y3=30;
            scr1 += 5;
    }
    if((-4.5+py)>=torus_y4+deviation-torrance && (-4.5+y)<=torus_y4+deviation+torrance && (-5.0+px)>=torus_x4-torrance && (-5.0+px)<=torus_x4+torrance){
            torus_y4=40;
            scr1 += 5;
    }
    if((-4.5+py)>=torus_y5+deviation-torrance && (-4.5+y)<=torus_y5+deviation+torrance && (-5.0+px)>=torus_x5-torrance && (-5.0+px)<=torus_x5+torrance){
            torus_y5=15;
            scr1 += 5;
    }

}


//------------------------------  bullets animation  --------------------------------

void Animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,Animation,0);
    m+=0.05;
    n+=0.05;
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

//------------------------------  texture  --------------------------------

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

//----------------------------------  main  ------------------------------------

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("19101076 - 19102091 - 19102573");

    glClearColor(1.0, 1.0, 1.0, 0.0);

    glutDisplayFunc(welcomeDisplay);
    glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    glutKeyboardFunc(keys);
    glutTimerFunc(0,rocksAnimation,0);
    glutTimerFunc(0,torusAnimation,0);
    glutTimerFunc(0,Animation,0);

    PlaySound(TEXT("gamesong.wav"), NULL, SND_ASYNC|SND_FILENAME);

    glClearColor(1,1,1,1);
    texture(); // Lighting and textures

    glutMainLoop();
}

