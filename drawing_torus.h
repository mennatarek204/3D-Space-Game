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

void torus()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
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

