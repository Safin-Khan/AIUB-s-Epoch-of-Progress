/*
1. Safin Khan 21-45715-3
2. Tanvir Shaad 21-45716-3
3. Mushfequr Rahman 21-45721-3
4. Sk. Md. Asif Newaz 21-45732-3

*/

#include <windows.h>
#include <mmsystem.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>



void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}
/// Sky

GLfloat position = 0.0f;
GLfloat speed = 0.0005f;
GLfloat RocketAlt = 0.0f;
GLfloat rocketSpeed = 0.00017f;
GLfloat MetroPos = 0.0f;
GLfloat MetroSpeed = 0.00001f;

void updateNight(int value)
{
    if(position <= -1)
        return;
    position -= speed;

	glutPostRedisplay();
	glutTimerFunc(2, updateNight, 0);
}

void updateDay(int value)
{
    if(position >= 1)
        return;
    position += speed;

	glutPostRedisplay();
	glutTimerFunc(2, updateDay, 0);
}

void updateRocket(int value)
{
    if(RocketAlt >= 1)
        return;
    RocketAlt += rocketSpeed;

	glutPostRedisplay();
	glutTimerFunc(2, updateRocket, 0);
}

void updateMetro(int value)
{
    if(MetroPos >= 1)
        return;
    MetroPos += MetroSpeed;
    //MetroSpeed = MetroSpeed - 0.00007;

	glutPostRedisplay();
	glutTimerFunc(2, updateMetro, 0);
}

void sky()
{
    glBegin(GL_POLYGON); // sky

    if(position > 0.6)
    {
        glColor3f(0.741, 0.867, 1); // noon p 0.6
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.231, 0.608, 1);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }
    else if(position <= 0.6 && position > 0.4)
    {
        glColor3f(0.941, 0.867, 1); // afternoon p < 0.6 to 0.4
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.431, 0.608, 1);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }
    else if(position <= 0.4 && position > 0.2)
    {
        glColor3f(1.0, 0.767, 0.6); //  p < 0.4 to 0.2
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.631, 0.48, 0.8);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }
    else if(position <= 0.2 && position > -0.1)
    {
        glColor3f(0.6, 0.4, 0.3); //  p < 0.2 to -0.1
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.531, 0.38, 0.7);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }
    else if(position <= -0.1 && position > -0.3)
    {
        glColor3f(0.3, 0.3, 0.2); //  p < -0.1 to -0.3
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.431, 0.38, 0.6);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }
    else if(position <= -0.3 && position > -0.6)
    {
        glColor3f(0.1, 0.1, 0.1); //  p < -0.3 to -0.6
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.231, 0.18, 0.4);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }
    else if(position <= -0.6)
    {
        glColor3f(0.0, 0.0, 0.0); //  p < -0.6 to -1
        glVertex2f(1, 0.20f);
        glVertex2f(-1, 0.20f);

        glColor3f(0.25, 0.25, 0.25);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);
    }

    glEnd();

    // SUN

    glPushMatrix();
    glScaled(0.6, 1, 1);
    glTranslated(0, position, 0);
    circle(0.1, 0.3, 0.4, 1, 1, 0); // Sun
    glPopMatrix();
}
/// sky end
void initGL()
{
 glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
//--------------------------------------------SKY-------------------------------------------------
//void sky()
//{
// glBegin(GL_POLYGON);
// glColor3f(42, 156,239);
// glVertex2f(-1.0f, 0.1f);
// glVertex2f(1.0f, 0.1f);
// glVertex2f(1.0f, 1.0f);
// glVertex2f(-1.0f, 1.0f);
// glEnd();
//}
//-----------------------------------------------------------------------------------------------
// green background
void backgroundgrass()
{
 glBegin(GL_POLYGON);
 glColor3f(0.0f, 0.9f, 0.0f);
 glVertex2f(-2.0f, -2.0f);
 glColor3f(0.0f, 0.9f, 0.0f);
 glVertex2f(2.0f, -2.0f);
  glColor3f(0.0f, 0.4f, 0.0f);
 glVertex2f(2.0f, 0.1f);
  glColor3f(0.0f, 0.4f, 0.0f);
 glVertex2f(-2.0f, 0.1f);
 glEnd();
}
// green background

//background buildings

 void backgrndbuildings()
 {
     glBegin(GL_QUADS);
     glColor3f(0.4f, 0.4f, 0.4f);// grey
     glVertex2f(-1.0f, 0.5f);
     glVertex2f(-0.9f, 0.5f);
     glVertex2f(-0.9f, 0.7f);
     glVertex2f(-1.0f, 0.7f);
     glEnd();
     //windows
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.985f, 0.52f);
     glVertex2f(-0.965f, 0.52f);
     glVertex2f(-0.965f, 0.545f);
     glVertex2f(-0.985f, 0.545f);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.935f, 0.52f);
     glVertex2f(-0.915f, 0.52f);
     glVertex2f(-0.915f, 0.545f);
     glVertex2f(-0.935f, 0.545f);
     glEnd();
     //----------
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.985f, 0.58f);
     glVertex2f(-0.965f, 0.58f);
     glVertex2f(-0.965f, 0.605f);
     glVertex2f(-0.985f, 0.605f);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.935f, 0.58f);
     glVertex2f(-0.915f, 0.58f);
     glVertex2f(-0.915f, 0.605f);
     glVertex2f(-0.935f, 0.605f);
     glEnd();
     //----------
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.985f, 0.64f);
     glVertex2f(-0.965f, 0.64f);
     glVertex2f(-0.965f, 0.665f);
     glVertex2f(-0.985f, 0.665f);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.935f, 0.64f);
     glVertex2f(-0.915f, 0.64f);
     glVertex2f(-0.915f, 0.665f);
     glVertex2f(-0.935f, 0.665f);
     glEnd();


//small one


     glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-0.9f, 0.5f);
     glVertex2f(-0.84f, 0.5f);
     glVertex2f(-0.84f, 0.6f);
     glVertex2f(-0.9f, 0.6f);
     glEnd();

    //-----window
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.89f, 0.51f);
     glVertex2f(-0.875f, 0.51f);
     glVertex2f(-0.875f, 0.53f);
     glVertex2f(-0.89f, 0.53f);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.865f, 0.51f);
     glVertex2f(-0.85f, 0.51f);
     glVertex2f(-0.85f, 0.53f);
     glVertex2f(-0.865f, 0.53f);
     glEnd();
     //----
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.89f, 0.55f);
     glVertex2f(-0.875f, 0.55f);
     glVertex2f(-0.875f, 0.57f);
     glVertex2f(-0.89f, 0.57f);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);// black
     glVertex2f(-0.865f, 0.55f);
     glVertex2f(-0.85f, 0.55f);
     glVertex2f(-0.85f, 0.57f);
     glVertex2f(-0.865f, 0.57f);
     glEnd();


 }
 void backgroundbuildings()
 {
     //backgrndbuildings() ;

    glPushMatrix();
    glTranslated(0.0, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.16,-0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.32,-0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.48, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.64, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.8,-0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.96, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.12, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.28, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.44, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.6,-0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.76, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.92, -0.4, 0.0);
    backgrndbuildings();
    glPopMatrix();
 }


 //circle func

 void Circle1(float radius, float xc, float yc, float a, float b, float c)
{
 glBegin(GL_POLYGON);
for(int i = 0; i< 200; i++)
 {
 glColor3f(a, b, c);
 float pi= 3.141;
 float A = (i*2*pi)/200;
 float r = radius;
 float x = r * cos(A);
 float y = r * sin(A);
 glVertex2f(x+xc,y+yc);
 }
 glEnd();
}


//void circle(float radius, float xc, float yc, float r, float g, float b)
//{
//    glBegin(GL_POLYGON);
//	for(int i=0;i<200;i++)
//        {
//            glColor3f(r,g,b);
//            float pi=3.1416;
//            float A=(i*2*pi)/200;
//            float r=radius;
//            float x = r * cos(A);
//            float y = r * sin(A);
//            glVertex2f(x+xc,y+yc);
//        }
//	glEnd();
//}

void circleLine(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void C_building()
{
    glBegin(GL_POLYGON);    // Stand

    glColor3f(0.518, 0.518, 0.51);

    glVertex2f(-0.48f, -0.4f);
    glVertex2f(0.48f, -0.4f);

    glColor3f(0.8, 0.8, 0.8);

    glVertex2f(0.48f, -0.86f);
    glVertex2f(-0.48f, -0.86f);

    glEnd();

    glBegin(GL_POLYGON);    // stand glass


    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(-0.48f, -0.67f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.48f, -0.67f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.48f, -0.77f);

     glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(-0.48f, -0.77f);

    glEnd();

    glLineWidth(2.5);

    glBegin(GL_LINES);  // stand outer lines

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-0.48f, -0.44f);
    glVertex2f(0.48f, -0.44f);

    glVertex2f(0.48f, -0.44f);
    glVertex2f(0.48f, -0.86f);

    glVertex2f(0.48f, -0.86f);
    glVertex2f(-0.48f, -0.86f);

    glVertex2f(-0.48f, -0.86f);
    glVertex2f(-0.48f, -0.44f);

    glEnd();

    glLineWidth(0.5);

    glBegin(GL_LINES);  // stand inner lines

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-0.48f, -0.67f);
    glVertex2f(0.48f, -0.67f);

    glVertex2f(0.48f, -0.77f);
    glVertex2f(-0.48f, -0.77f);

    glVertex2f(-0.48f, -0.6f);
    glVertex2f(0.48f, -0.6f);

    glVertex2f(-0.48f, -0.5f);
    glVertex2f(0.48f, -0.5f);

    glEnd();

    circle(0.8, 0, 0.2, 0.8, 0.8, 0.8);

    glBegin(GL_POLYGON);    // first floor glass

    glColor3f(0.5f, 0.9f, 1.0f);//cyan

    glVertex2f(-0.39f, -0.5f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(-0.5345f, -0.4f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.5345f, -0.4f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.39f, -0.5f);

    glEnd();

    glBegin(GL_POLYGON);    // second floor glass

    glColor3f(0.5f, 0.9f, 1.0f);//cyan

    glVertex2f(0.625f, -0.3f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.693f, -0.2f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(-0.693f, -0.2f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(-0.625f, -0.3f);

    glEnd();

    glBegin(GL_POLYGON);    // third floor glass

    glColor3f(0.5f, 0.9f, 1.0f);//cyan

    glVertex2f(0.741f, -0.1f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.774f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(-0.774f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(-0.741f, -0.1f);

    glEnd();

    glBegin(GL_POLYGON);    // fourth floor glass

    glColor3f(1.0f, 1.0f, 1.0f);//cyan

    glVertex2f(0.793f, 0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.8f, 0.2f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(-0.8f, 0.2f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(-0.793f, 0.1f);

    glEnd();

    glBegin(GL_POLYGON);    // fifth floor glass

    glColor3f(1.0f, 1.0f, 1.0f);//cyan

    glVertex2f(0.793f, 0.3f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.774f, 0.4f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(-0.774f, 0.4f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(-0.793f, 0.3f);

    glEnd();




    glLineWidth(0.1);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-0.529f, -0.4f); // horizontal lines
    glVertex2f(0.529f, -0.4f);

    glVertex2f(0.387f, -0.5f);
    glVertex2f(-0.387f, -0.5f);

    glVertex2f(0.692f, -0.2f);
    glVertex2f(-0.692f, -0.2f);

    glVertex2f(-0.624f, -0.3f);
    glVertex2f(0.624f, -0.3f);

    glVertex2f(0.774f, 0.0f);
    glVertex2f(-0.774f, 0.0f);

    glVertex2f(-0.741f, -0.1f);
    glVertex2f(0.741f, -0.1f);

    glVertex2f(0.8f, 0.2f);
    glVertex2f(-0.8f, 0.2f);

    glVertex2f(-0.793f, 0.1f);
    glVertex2f(0.793f, 0.1f);

    glVertex2f(0.774f, 0.4f);
    glVertex2f(-0.774f, 0.4f);

    glVertex2f(-0.793f, 0.3f);
    glVertex2f(0.793f, 0.3f);

    glVertex2f(-0.741f, 0.5f);
    glVertex2f(0.741f, 0.5f);

    glVertex2f(0.692f, 0.6f);
    glVertex2f(-0.692f, 0.6f);

    glVertex2f(-0.624f, 0.7f);
    glVertex2f(0.624f, 0.7f);

    glVertex2f(-0.529f, 0.8f);
    glVertex2f(0.529f, 0.8f);

    glVertex2f(0.387f, 0.9f);
    glVertex2f(-0.387f, 0.9f);  // horizontal lines end

    /*glVertex2f(-0.7f, -0.187f);  // vertical lines
    glVertex2f(-0.7f, 0.587f);

    glVertex2f(-0.6f, -0.329f);
    glVertex2f(-0.6f, 0.729f);

    glVertex2f(-0.5f, 0.824f);
    glVertex2f(-0.5f, -0.424f);

    glVertex2f(-0.4f, -0.86f);
    glVertex2f(-0.4f, 0.893f);

    glVertex2f(-0.3f, -0.86f);
    glVertex2f(-0.3f, 0.942f);

    glVertex2f(-0.2f, -0.86f);
    glVertex2f(-0.2f, 0.975f);

    glVertex2f(-0.1f, -0.86f);
    glVertex2f(-0.1f, 0.994f);

    glVertex2f(0.0f, -0.86f);
    glVertex2f(0.0f, 1.0f);*/

   // glVertex2f(0.7f, -0.187f);
   // glVertex2f(0.7f, 0.587f);
//
   // glVertex2f(0.6f, -0.329f);
   // glVertex2f(0.6f, 0.729f);

   // glVertex2f(0.5f, 0.824f);
  //  glVertex2f(0.5f, -0.424f);

   // glVertex2f(0.4f, -0.86f);
   // glVertex2f(0.4f, 0.893f);

    //glVertex2f(0.3f, -0.86f);
    //glVertex2f(0.3f, 0.942f);

    //glVertex2f(0.2f, -0.86f);
    //glVertex2f(0.2f, 0.975f);

    //glVertex2f(0.1f, -0.86f);
    //glVertex2f(0.1f, 0.994f);   // vertical lines end

    glVertex2f(0.0f, 1.0f); // antena
    glVertex2f(0.0f, 1.15f);

    glEnd();
    glLineWidth(2.5);
    circleLine(0.8, 0, 0.2, 0, 0, 0);
}

//end C----------------------------------------



void treeDbuilding()
{
    glBegin(GL_POLYGON); // top

    glColor3f(0.102f, 0.592f, 0.224f);

    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.2f, 0.0f);

    glEnd();

    glBegin(GL_POLYGON); // mid

    glColor3f(0.102f, 0.592f, 0.224f);

    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.16f, 0.0f);
    glVertex2f(-0.16f, 0.0f);
    glVertex2f(-0.3f, -0.3f);

    glEnd();

    glBegin(GL_POLYGON);  // bottom

    glColor3f(0.102f, 0.592f, 0.224f);

    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.4f, -0.6f);

    glEnd();

    glBegin(GL_POLYGON); // stem

    glColor3f(0.6f, 0.404f, 0.204f);

    glVertex2f(0.07f, -0.6f);
    glVertex2f(-0.07f, -0.6f);
    glVertex2f(-0.07f, -1.0f);
    glVertex2f(0.07f, -1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.2f, 0.0f); // top
    glVertex2f(0.0f, 0.5f);

    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.2f, 0.0f);

    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f); // top end

    glVertex2f(0.3f, -0.3f); // mid
    glVertex2f(0.16f, 0.0f);

    glVertex2f(0.16f, 0.0f);
    glVertex2f(-0.16f, 0.0f);

    glVertex2f(-0.16f, 0.0f);
    glVertex2f(-0.3f, -0.3f);

    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f); // mid end

    glVertex2f(0.4f, -0.6f); // bottom
    glVertex2f(0.25f, -0.3f);

    glVertex2f(0.25f, -0.3f);
    glVertex2f(-0.25f, -0.3f);

    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.4f, -0.6f);

    glVertex2f(-0.4f, -0.6f);
    glVertex2f(0.4f, -0.6f); // bottom end

    glVertex2f(0.07f, -0.6f); // stem
    glVertex2f(-0.07f, -0.6f);

    glVertex2f(-0.07f, -0.6f);
    glVertex2f(-0.07f, -1.0f);

    glVertex2f(-0.07f, -1.0f);
    glVertex2f(0.07f, -1.0f);

    glVertex2f(0.07f, -1.0f);
    glVertex2f(0.07f, -0.6f); // stem end

    glEnd();
}



//D_Building---
void dbuilding()
{
    //======
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);// grey
    glVertex2f(0.65f, -0.33f);
    glColor3f(0.6f, 0.6f, 0.6f);// grey
    glVertex2f(0.75f, -0.29f);
     glColor3f(0.6f, 0.6f, 0.6f);// grey
    glVertex2f(0.75f, 0.52f);
    glVertex2f(0.72f, 0.52f);
    glVertex2f(0.75f, 0.3f);
    glVertex2f(0.68f, 0.3f);
    glVertex2f(0.72f, 0.1f);
    glVertex2f(0.65f, 0.1f);
    glEnd();
    //----

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);// grey
    glVertex2f(0.75f, -0.29f);
    glVertex2f(0.78f, -0.35f);
    glVertex2f(0.78f, 0.6f);
    glVertex2f(0.75f, 0.6f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.75f, -0.29f);
    glVertex2f(0.78f, -0.35f);
    glVertex2f(0.78f, -0.35f);
    glVertex2f(0.78f, 0.6f);
    glVertex2f(0.78f, 0.6f);
    glVertex2f(0.75f, 0.6f);
    glVertex2f(0.75f, 0.6f);
    glVertex2f(0.75f, -0.29f);
     glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);// grey
    glVertex2f(0.78f, -0.35f);
    glColor3f(0.7f, 0.7f, 0.7f);// grey
    glVertex2f(0.85f, -0.29f);
    glColor3f(0.7f, 0.7f, 0.7f);// grey
    glVertex2f(0.85f, 0.58f);
    glColor3f(0.4f, 0.4f, 0.4f);// grey
    glVertex2f(0.78f, 0.6f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.78f, -0.35f);
    glVertex2f(0.85f, -0.29f);
    glVertex2f(0.85f, -0.29f);
    glVertex2f(0.85f, 0.58f);
    glVertex2f(0.85f, 0.58f);
    glVertex2f(0.78f, 0.6f);
    glVertex2f(0.78f, 0.6f);
    glVertex2f(0.78f, -0.35f);
     glEnd();


    //---------
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);//gray
    glVertex2f(0.28f, 0.0f);
    glVertex2f(0.65f, -0.33f);
    glVertex2f(0.65f, 0.1f);
    glVertex2f(0.68f, 0.1f);
    glVertex2f(0.68f, 0.3f);
    glVertex2f(0.72f, 0.3f);
    glVertex2f(0.72f, 0.52f);
    glVertex2f(0.33f, 0.52f);
    glVertex2f(0.35f, 0.4f);
    glVertex2f(0.3f, 0.38f);
    glVertex2f(0.32f, 0.288f);
    glVertex2f(0.28f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.0f);
    glVertex2f(0.65f, -0.33f);
    glVertex2f(0.65f, -0.33f);
    glVertex2f(0.65f, 0.09f);
    glVertex2f(0.65f, 0.09f);
    glVertex2f(0.68f, 0.1f);
    glVertex2f(0.68f, 0.1f);
    glVertex2f(0.68f, 0.27f);
    glVertex2f(0.68f, 0.27f);
    glVertex2f(0.72f, 0.3f);
    glVertex2f(0.72f, 0.3f);
    glVertex2f(0.72f, 0.52f);
    glVertex2f(0.72f, 0.52f);
    glVertex2f(0.33f, 0.52f);
    glEnd();


    //broder
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.29f, 0.01f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.64f, -0.305f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.64f, 0.1f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.67f, 0.1f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.67f, 0.3f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.71f, 0.3f);
    glColor3f(0.5f, 0.9f, 1.0f);//cyan
    glVertex2f(0.71f, 0.45f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.335f, 0.47f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.35f, 0.4f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.31f, 0.37f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.32f, 0.28f);
    glColor3f(1.0f, 1.0f, 1.0f);//cyan
    glVertex2f(0.29f, 0.27f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.29f, 0.01f);
    glVertex2f(0.64f, -0.305f);

    glVertex2f(0.64f, -0.305f);
    glVertex2f(0.64f, 0.1f);

    glVertex2f(0.64f, 0.1f);
    glVertex2f(0.67f, 0.1f);

    glVertex2f(0.67f, 0.1f);
    glVertex2f(0.67f, 0.3f);

    glVertex2f(0.67f, 0.3f);
    glVertex2f(0.71f, 0.3f);

    glVertex2f(0.71f, 0.3f);
    glVertex2f(0.71f, 0.45f);

    glVertex2f(0.71f, 0.45f);
    glVertex2f(0.335f, 0.47f);

    glVertex2f(0.335f, 0.47f);
    glVertex2f(0.327f, 0.37f);

    glVertex2f(0.327f, 0.37f);
    glVertex2f(0.31f, 0.37f);

    glVertex2f(0.31f, 0.37f);
    glVertex2f(0.305f, 0.28f);

    glVertex2f(0.305f, 0.28f);
    glVertex2f(0.29f, 0.27f);

    glVertex2f(0.29f, 0.27f);
     glVertex2f(0.29f, 0.01f);
     glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.5f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(0.27f, 0.02f);
    glVertex2f(0.36f, -0.06f);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.3f, 0.03f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.5f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(0.275f, 0.02f);
    glVertex2f(0.275f, -0.02f);

    glVertex2f(0.36f, -0.06f);
    glVertex2f(0.36f, -0.1f);

    glVertex2f(0.3175f, -0.02f);
    glVertex2f(0.3175f, -0.06f);

    glEnd();

//belcony---
    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.443, 0.365);
    glVertex2f(0.29f, 0.27f);
    glColor3f(0.42, 0.302, 0.208);//Blck
    glVertex2f(0.64f, 0.09f);
    glVertex2f(0.67f, 0.1f);
    glColor3f(0.537, 0.443, 0.365);
    glVertex2f(0.305f, 0.28f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.537, 0.443, 0.365);
    glVertex2f(0.31f, 0.37f);
    glColor3f(0.42, 0.302, 0.208);//Blck
    glVertex2f(0.67f, 0.27f);
    glVertex2f(0.71f, 0.3f);
    glColor3f(0.537, 0.443, 0.365);
    glVertex2f(0.3215f, 0.382f);
    glEnd();
    //------
    //glass  gray
    //1st
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);//gry
    glVertex2f(0.29f, 0.215f);
    glVertex2f(0.64f, 0.02f);
    glVertex2f(0.64f, 0.09f);
    glVertex2f(0.29f, 0.27f);
    glEnd();
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.29f, 0.215f);
     glVertex2f(0.64f, 0.02f);
     glVertex2f(0.64f, 0.02f);
     glVertex2f(0.64f, 0.09f);
     glVertex2f(0.64f, 0.09f);
     glVertex2f(0.29f, 0.27f);
     glVertex2f(0.29f, 0.27f);
     glVertex2f(0.29f, 0.215f);
     glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);//gry
    glVertex2f(0.29f, 0.14f);
    glVertex2f(0.64f, -0.08f);
    glVertex2f(0.64f,-0.04f);
    glVertex2f(0.29f,0.16f);
    glEnd();
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.29f, 0.14f);
     glVertex2f(0.64f, -0.08f);
     glVertex2f(0.64f, -0.08f);
     glVertex2f(0.64f,-0.04f);
     glVertex2f(0.64f,-0.04f);
     glVertex2f(0.29f,0.16f);
     glVertex2f(0.29f,0.16f);
     glVertex2f(0.29f, 0.14f);
     glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);//gry
    glVertex2f(0.29f,0.07f);
    glVertex2f(0.64f,-0.2f);
    glVertex2f(0.64f,-0.15f);
    glVertex2f(0.29f,0.1f);
    glEnd();
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.29f,0.07f);
     glVertex2f(0.64f,-0.2f);
     glVertex2f(0.64f,-0.2f);
     glVertex2f(0.64f,-0.15f);
     glVertex2f(0.64f,-0.15f);
     glVertex2f(0.29f,0.1f);
     glVertex2f(0.29f,0.1f);
     glVertex2f(0.29f,0.07f);
     glEnd();


    //2nd
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);//gry
    glVertex2f(0.306f, 0.31f);
    glVertex2f(0.67f, 0.15f);
    glVertex2f(0.67f, 0.18f);
    glVertex2f(0.306f, 0.32f);
    glEnd();
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.306f, 0.31f);
    glVertex2f(0.67f, 0.15f);
    glVertex2f(0.67f, 0.15f);
    glVertex2f(0.67f, 0.18f);
    glVertex2f(0.67f, 0.18f);
    glVertex2f(0.306f, 0.32f);
    glVertex2f(0.306f, 0.32f);
    glVertex2f(0.306f, 0.31f);
     glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);//gry
    glVertex2f(0.309f, 0.35f);
    glVertex2f(0.67f, 0.22f);
    glVertex2f(0.67f, 0.27f);
    glVertex2f(0.31f, 0.372f);
    glEnd();
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.309f, 0.35f);
    glVertex2f(0.67f, 0.22f);
    glVertex2f(0.67f, 0.22f);
    glVertex2f(0.67f, 0.27f);
    glVertex2f(0.67f, 0.27f);
    glVertex2f(0.31f, 0.372f);
    glVertex2f(0.31f, 0.372f);
    glVertex2f(0.309f, 0.35f);
     glEnd();


    //3rd
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);//gry
    glVertex2f(0.329f, 0.41f);
    glVertex2f(0.71f, 0.34f);
    glVertex2f(0.71f, 0.39f);
    glVertex2f(0.33f, 0.43f);
    glEnd();
    glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(0.329f, 0.41f);
    glVertex2f(0.71f, 0.34f);
    glVertex2f(0.71f, 0.34f);
    glVertex2f(0.71f, 0.39f);
    glVertex2f(0.71f, 0.39f);
    glVertex2f(0.33f, 0.43f);
    glVertex2f(0.33f, 0.43f);
    glVertex2f(0.329f, 0.41f);
     glEnd();

    /// D building trees
    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(16, 7.4, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(17.3, 7.1, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(18.6, 6.8, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(19.9, 6.4, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(21.2, 6.1, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(22.5, 5.8, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(23.8, 5.4, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(25.1, 5.1, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(26.4, 4.8, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(27.7, 4.4, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(29, 4.1, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(30.3, 3.8, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(31.6, 3.4, 0);
    treeDbuilding();
    glPopMatrix();

    // upper floor trees

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(32.9, 7.9, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(17.3, 10.1, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(18.6, 9.9, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(19.9, 9.7, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(21.2, 9.5, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(22.5, 9.3, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(23.8, 9.1, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(25.1, 8.9, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(26.4, 8.8, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(27.7, 8.6, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(29, 8.4, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(30.3, 8.2, 0);
    treeDbuilding();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.02, 0.04, 1);
    glTranslated(31.6, 8, 0);
    treeDbuilding();
    glPopMatrix();
    /// D building tree end
}

void maindbuilding()
{
    glPushMatrix();
    glScaled(1.2, 1.1, 0);
    glTranslated(0.0, 0.0, 0);
    dbuilding();
    glPopMatrix();
}
//D_Building---

//Annex------------------------
void annex()
{
   glBegin(GL_QUADS);
    glColor4f(0.7f, 0.2f, 0.0f, 0.0f);//orange/brown
    glVertex2f(-0.98f, -0.3f);
    glVertex2f(0.15f, -0.3f);
    glVertex2f(0.15f, -0.23f);
    glVertex2f(-0.98f, -0.23f);
    glEnd();


    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex2f(-0.98f, -0.3f);
    glVertex2f(0.15f, -0.3f);

    glVertex2f(0.15f, -0.3f);
    glVertex2f(0.15f, -0.23f);

    glVertex2f(0.15f, -0.23f);
    glVertex2f(-0.98f, -0.23f);

    glVertex2f(-0.98f, -0.23f);
    glVertex2f(-0.98f, -0.3f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.7f, 0.2f, 0.0f, 0.0f);//orange/brown
    glVertex2f(-0.98f, -0.3f);
    glVertex2f(-0.99f, -0.21f);
    glVertex2f(-0.99f, -0.13f);
    glVertex2f(-0.989f, -0.15f);
    glVertex2f(-0.984f, -0.23f);
    glVertex2f(-0.98f, -0.23f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.643, 0.745, 0.275);//Forest Green ROOF
    glVertex2f(-0.984f, -0.23f);
    glVertex2f(0.16f, -0.23f);
    glColor3f(0.455, 0.569, 0.235);
    glVertex2f(0.153f, -0.15f);
    glVertex2f(-0.989f, -0.15f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex2f(-0.984f, -0.23f);
    glVertex2f(0.16f, -0.23f);
    glVertex2f(0.16f, -0.23f);
    glVertex2f(0.153f, -0.15f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex2f(-0.989f, -0.15f);
    glVertex2f(0.153f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.627, 0.247);//Forest Green ROOF
    glVertex2f(-0.989f, -0.15f);
    glVertex2f(0.153f, -0.15f);
    glVertex2f(0.12f, -0.1f);
    glVertex2f(-0.995f, -0.1f);

    glEnd();
//window-----
     glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);//cyan Window1
    glVertex2f(-0.9f, -0.285f);
    glVertex2f(-0.85f, -0.285f);
    glVertex2f(-0.85f, -0.252f);
    glVertex2f(-0.9f, -0.252f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.285f);
    glVertex2f(-0.85f, -0.285f);

    glVertex2f(-0.85f, -0.285f);
    glVertex2f(-0.85f, -0.252f);

    glVertex2f(-0.85f, -0.252f);
    glVertex2f(-0.9f, -0.252f);

    glVertex2f(-0.9f, -0.252f);
    glVertex2f(-0.9f, -0.285f);

    glVertex2f(-0.875f, -0.285f);
    glVertex2f(-0.875f, -0.252f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);//cyan Window2
    glVertex2f(-0.7f, -0.285f);
    glVertex2f(-0.65f, -0.285f);
    glVertex2f(-0.65f, -0.252f);
    glVertex2f(-0.7f, -0.252f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.285f);
    glVertex2f(-0.65f, -0.285f);

    glVertex2f(-0.65f, -0.285f);
    glVertex2f(-0.65f, -0.252f);

    glVertex2f(-0.65f, -0.252f);
    glVertex2f(-0.7f, -0.252f);

    glVertex2f(-0.7f, -0.252f);
    glVertex2f(-0.7f, -0.285f);

    glVertex2f(-0.675f, -0.285f);
    glVertex2f(-0.675f, -0.252f);

    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);//cyan Window3
    glVertex2f(-0.5f, -0.285f);
    glVertex2f(-0.45f, -0.285f);
    glVertex2f(-0.45f, -0.252f);
    glVertex2f(-0.5f, -0.252f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);

    glVertex2f(-0.5f, -0.285f);
    glVertex2f(-0.45f, -0.285f);

    glVertex2f(-0.45f, -0.285f);
    glVertex2f(-0.45f, -0.252f);

    glVertex2f(-0.45f, -0.252f);
    glVertex2f(-0.5f, -0.252f);

    glVertex2f(-0.5f, -0.252f);
    glVertex2f(-0.5f, -0.285f);

    glVertex2f(-0.475f, -0.285f);
    glVertex2f(-0.475f, -0.252f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);//cyan Window4
    glVertex2f(-0.3f, -0.285f);
    glVertex2f(-0.25f, -0.285f);
    glVertex2f(-0.25f, -0.252f);
    glVertex2f(-0.3f, -0.252f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);

    glVertex2f(-0.3f, -0.285f);
    glVertex2f(-0.25f, -0.285f);

    glVertex2f(-0.25f, -0.285f);
    glVertex2f(-0.25f, -0.252f);

    glVertex2f(-0.25f, -0.252f);
    glVertex2f(-0.3f, -0.252f);

    glVertex2f(-0.3f, -0.252f);
    glVertex2f(-0.3f, -0.285f);

    glVertex2f(-0.275f, -0.285f);
    glVertex2f(-0.275f, -0.252f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);//cyan Window5
    glVertex2f(-0.1f, -0.285f);
    glVertex2f(-0.05f, -0.285f);
    glVertex2f(-0.05f, -0.252f);
    glVertex2f(-0.1f, -0.252f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);

    glVertex2f(-0.1f, -0.285f);
    glVertex2f(-0.05f, -0.285f);

    glVertex2f(-0.05f, -0.285f);
    glVertex2f(-0.05f, -0.252f);

    glVertex2f(-0.05f, -0.252f);
    glVertex2f(-0.1f, -0.252f);

    glVertex2f(-0.1f, -0.252f);
    glVertex2f(-0.1f, -0.285f);

    glVertex2f(-0.075f, -0.285f);
    glVertex2f(-0.075f, -0.252f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);//cyan Window6
    glVertex2f(0.05f, -0.285f);
    glVertex2f(0.1f, -0.285f);
    glVertex2f(0.1f, -0.252f);
    glVertex2f(0.05f, -0.252f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);

    glVertex2f(0.05f, -0.285f);
    glVertex2f(0.1f, -0.285f);

    glVertex2f(0.1f, -0.285f);
    glVertex2f(0.1f, -0.252f);

    glVertex2f(0.1f, -0.252f);
    glVertex2f(0.05f, -0.252f);

    glVertex2f(0.05f, -0.252f);
    glVertex2f(0.05f, -0.285f);

    glVertex2f(0.075f, -0.285f);
    glVertex2f(0.075f, -0.252f);
    glEnd();


}

//-------------------

//FOOTBALLL Ground--------------

 void footballgorund()
 {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.0f);//Forest Green
    glVertex2f(-0.85f, -0.8);
    glVertex2f(0.2f, -0.8f);
    glVertex2f(0.0f, -0.31f);
    glVertex2f(-0.95f, -0.31f);
    glEnd();

    Circle1(0.07, -0.395,-0.558, 1.0f, 1.0f, 1.0f);
    Circle1(0.065, -0.395,-0.558, 0.0f, 0.4f, 0.0f);

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.5);
    glVertex2f(-0.85f, -0.8);
    glVertex2f(0.2f, -0.8f);

    glVertex2f(0.2f, -0.8f);
    glVertex2f(0.0f, -0.31f);

    glVertex2f(0.0f, -0.31f);
    glVertex2f(-0.95f, -0.31f);

    glVertex2f(-0.95f, -0.31f);
    glVertex2f(-0.85f, -0.8);

    glVertex2f(-0.32f, -0.8);
    glVertex2f(-0.475f, -0.31f);
//bar
    glVertex2f(-0.88f, -0.65);
    glVertex2f(-0.88f, -0.58f);


    glVertex2f(-0.88f, -0.58f);
    glVertex2f(-0.9f, -0.47);

    glVertex2f(-0.9f, -0.47);
    glVertex2f(-0.9f, -0.55);
//---
    glVertex2f(0.125f, -0.615);
    glVertex2f(0.125f, -0.55f);


    glVertex2f(0.125f, -0.55f);
    glVertex2f(0.09f, -0.458f);

    glVertex2f(0.09f, -0.458f);
    glVertex2f(0.09f, -0.53f);

    glEnd();



 }
//-------------
//Road--------------------------------
void road1()
    {
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.8);
    glVertex2f(-1.0f, -0.8f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.8);
    glVertex2f(1.0f, -0.8);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
    glVertex2f(-1.0f, -0.9f);
    glVertex2f(-0.8f, -0.9f);
    glVertex2f(-0.75f, -0.9f);
    glVertex2f(-0.5f, -0.9f);
    glVertex2f(-0.4f, -0.9f);
    glVertex2f(-0.2f, -0.9f);
    glVertex2f(-0.15f, -0.9f);
    glVertex2f(0.05f, -0.9f);
    glVertex2f(0.1f, -0.9f);
    glVertex2f(0.3f, -0.9f);
    glVertex2f(0.35f, -0.9f);
    glVertex2f(0.55f, -0.9f);
    glVertex2f(0.6f, -0.9f);
    glVertex2f(0.8f, -0.9f);
    glVertex2f(0.85f, -0.9f);
    glVertex2f(1.0f, -0.9f);


    glEnd();

    }
void road2()
{
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(0.296f,0.03f);
    glVertex2f(0.296f,-0.1f);
    glVertex2f(-1.0f,-0.1f);
   // glVertex2f(1.0f, -0.545);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(0.296f,0.03f);
    glVertex2f(0.296f,0.03f);
    glVertex2f(0.296f,-0.1f);
    glVertex2f(0.296f,-0.1f);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-1.0f, 0.03f);
    glEnd();


}

void road3()
{
   glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.296f,0.03f);
    glVertex2f(1.0f, -0.545);
    glVertex2f(1.0f, -0.9);
    glVertex2f(0.95f, -0.9);
    glVertex2f(0.275f,-0.1f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(0.296f,0.03f);
    glVertex2f(1.0f, -0.545);
    glVertex2f(0.95f, -0.9);
    glVertex2f(0.275f,-0.1f);

    glEnd();


}

void Sidewalk()
{

   glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.22f,-0.1f);
    glVertex2f(0.273f, -0.1f);
    glVertex2f(0.865f, -0.8);
    glVertex2f(0.77f, -0.8);
    glEnd();

}

void Pond()
{
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.0f,-0.314f);
    glVertex2f(0.385f, -0.314f);
    glVertex2f(0.77f, -0.8);
    glVertex2f(0.2f, -0.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.02f,-0.324f);
    glVertex2f(0.38f, -0.324f);
    glVertex2f(0.747f, -0.79);
    glVertex2f(0.22f, -0.79);
    glEnd();

    Circle1(0.09, 0.330,-0.430, 0.7f, 0.7f, 0.7f);
    Circle1(0.09, 0.280,-0.570, 0.7f, 0.7f, 0.7f);
    Circle1(0.09, 0.420,-0.650, 0.7f, 0.7f, 0.7f);
    Circle1(0.085, 0.330,-0.430, 0.0f, 0.5f, 0.7f);
    Circle1(0.085, 0.280,-0.570, 0.0f, 0.5f, 0.7f);
    Circle1(0.085, 0.420,-0.650, 0.0f, 0.5f, 0.7f);


}


void Parking()
{

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.005f,0.085f);
    glVertex2f(0.330f, 0.085f);
    glVertex2f(0.336f, 0.032);
    glVertex2f(-0.002f, 0.032);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.008f,0.07f);
    glVertex2f(0.325f, 0.07f);
    glVertex2f(0.331f, 0.032);
    glVertex2f(0.003f, 0.032);
    glEnd();


}

//----------------------------------------

//MetroRail----------------------------

 void metrorail()
 {
     glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.5f);//Dark grey upper bar
     glVertex2f(-1.0f, -0.82);
     glVertex2f(1.0f, -0.82);
     glVertex2f(1.0f, -0.8);
     glVertex2f(-1.0f, -0.8);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.7f, 0.7f, 0.7f);//Dark grey  middle bar
     glVertex2f(-1.0f, -0.88);
     glVertex2f(1.0f, -0.88);
     glVertex2f(1.0f, -0.82);
     glVertex2f(-1.0f, -0.82);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.5f);//Dark grey  down bar
     glVertex2f(-1.0f, -0.9);
     glVertex2f(1.0f, -0.9);
     glVertex2f(1.0f, -0.88);
     glVertex2f(-1.0f, -0.88);
     glEnd();
     glBegin(GL_LINES);
     glColor3f(0.2f, 0.2f, 0.2);//Dark grey Rail Line
     glVertex2f(-1.0f, -0.9);
     glVertex2f(1.0f, -0.9);
     glEnd();



     glBegin(GL_LINES);
     glColor3f(0.2f, 0.2f, 0.2);//Dark grey Rail Line
     glVertex2f(1.0f, -0.835);
     glVertex2f(-1.0f, -0.835);

     glVertex2f(1.0f, -0.865);
     glVertex2f(-1.0f, -0.865);

     glEnd();

 }

 void metro()
 {


     glBegin(GL_QUADS);
     glColor3f(0.8f, 0.8f, 0.8f);//Dark grey Rail
     glVertex2f(-0.98f, -0.85);
     glColor3f(0.5f, 0.5f, 0.5f);//Dark grey Rail
     glVertex2f(-0.81f, -0.85);
     glVertex2f(-0.81f, -0.76);
     glVertex2f(-0.98f, -0.76);
     glEnd();

      glLineWidth(4);
     glBegin(GL_LINES);
     glColor3f(0.0f, 0.4f, 0.0f);//Forest Green rail box line
     glVertex2f(-0.98f, -0.832);
     glVertex2f(-0.81f, -0.832);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(-0.98f, -0.85);
     glVertex2f(-0.81f, -0.85);
     glVertex2f(-0.81f, -0.85);
     glVertex2f(-0.81f, -0.76);
     glVertex2f(-0.81f, -0.76);
     glVertex2f(-0.98f, -0.76);
     glVertex2f(-0.98f, -0.76);
     glVertex2f(-0.98f, -0.85);
     glEnd();


     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);//cyan Rail window
     glVertex2f(-0.975f, -0.825);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-0.815f, -0.825);
     glColor3f(0.5f, 1.0f, 1.0f);//cyan Rail window
     glVertex2f(-0.815f, -0.766);
     glColor3f(0.5f, 1.0f, 1.0f);//cyan Rail window
     glVertex2f(-0.975f, -0.766);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(-0.975f, -0.825);
     glVertex2f(-0.815f, -0.825);
     glVertex2f(-0.815f, -0.825);
     glVertex2f(-0.815f, -0.766);
     glVertex2f(-0.815f, -0.766);
     glVertex2f(-0.975f, -0.766);
     glVertex2f(-0.975f, -0.766);
     glVertex2f(-0.975f, -0.825);
     glEnd();



  //main rail--------------



  //-------------------------------
     glPushMatrix();//wheel
     glTranslated(-0.84, -0.865, 0.0);
     circle(0.007, 0, 0.01,0, 0,0);
     glPopMatrix();

     glPushMatrix();//wheel
     glTranslated(-0.95, -0.865, 0.0);
     circle(0.007, 0, 0.01,0, 0,0);
     glPopMatrix();



 }

void metro1()
{
    metro();
    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0);
    metro();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.17, 0.0, 0.0);
    metro();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.34, 0.0, 0.0);
    metro();
    glPopMatrix();


       //main engine---------


     glBegin(GL_POLYGON);
     glColor3f(0.8f, 0.8f, 0.8f);//Dark grey Rail
     glVertex2f(-0.465f, -0.85);
     glVertex2f(-0.3f, -0.85);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-0.29f, -0.848);
     glColor3f(0.5f, 0.5f, 0.5f);
     glVertex2f(-0.29f, -0.768);
     glVertex2f(-0.3f, -0.76);
     glVertex2f(-0.465f, -0.76);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(-0.465f, -0.85);
     glVertex2f(-0.3f, -0.85);
     glVertex2f(-0.3f, -0.85);
     glVertex2f(-0.29f, -0.848);
     glVertex2f(-0.29f, -0.848);
     glVertex2f(-0.29f, -0.768);
     glVertex2f(-0.29f, -0.768);
     glVertex2f(-0.3f, -0.76);
     glVertex2f(-0.3f, -0.76);
     glVertex2f(-0.465f, -0.76);
     glVertex2f(-0.465f, -0.76);
     glVertex2f(-0.465f, -0.85);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-0.458f, -0.83);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-0.35f, -0.83);
      glColor3f(0.5f, 1.0f, 1.0f);//cyan Rail window
     glVertex2f(-0.35f, -0.769);
      glColor3f(0.5f, 1.0f, 1.0f);//cyan Rail window
     glVertex2f(-0.458f, -0.769);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.0f, 0.4f, 0.0f);//Forest Green rail box line
     glVertex2f(-0.458f, -0.83);
     glVertex2f(-0.35f, -0.83);
     glVertex2f(-0.35f, -0.83);
     glVertex2f(-0.35f, -0.769);
     glVertex2f(-0.35f, -0.769);
     glVertex2f(-0.458f, -0.769);
     glVertex2f(-0.458f, -0.769);
     glVertex2f(-0.458f, -0.83);
     glEnd();

     glPushMatrix();//wheel
     glTranslated(-0.45, -0.865, 0.0);
     circle(0.007, 0, 0.01,0, 0,0);
     glPopMatrix();
     glPushMatrix();//wheel
     glTranslated(-0.425, -0.865, 0.0);
     circle(0.007, 0, 0.01,0, 0,0);
     glPopMatrix();
     glPushMatrix();//wheel
     glTranslated(-0.35, -0.865, 0.0);
     circle(0.007, 0, 0.01,0, 0,0);
     glPopMatrix();
     glPushMatrix();//wheel
     glTranslated(-0.325, -0.865, 0.0);
     circle(0.007, 0, 0.01,0, 0,0);
     glPopMatrix();

       //-------------

}

void singlepillar()
{
     glBegin(GL_QUADS);
     glColor3f(0.5f, 0.5f, 0.5f);//Dark grey  middle bar
     glVertex2f(-0.9f, -1.0);
     glColor3f(0.7f, 0.7f, 0.7f);//Dark grey  middle bar
     glVertex2f(-0.88f, -1.0);
     glColor3f(0.7f, 0.7f, 0.7f);//Dark grey  middle bar
     glVertex2f(-0.88f, -0.9);
     glColor3f(0.5f, 0.5f, 0.5f);//Dark grey  middle bar
     glVertex2f(-0.9f, -0.9);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.2f, 0.2f, 0.2);//Dark grey Rail Line
     glVertex2f(-0.9f, -1.0);
     glVertex2f(-0.88f, -1.0);
     glVertex2f(-0.88f, -1.0);
     glVertex2f(-0.88f, -0.9);
     glVertex2f(-0.88f, -0.9);
     glVertex2f(-0.9f, -0.9);
     glVertex2f(-0.9f, -0.9);
     glVertex2f(-0.9f, -1.0);
     glEnd();
}

void multipillar()
{
    singlepillar();
    glPushMatrix();
    glTranslated(0.15, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.30, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.45, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.60, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.75, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.90, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.05, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.20, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.35, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.50, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.65, 0.0, 0);
    singlepillar();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.80, 0.0, 0);
    singlepillar();
    glPopMatrix();


}

void holemetro()
{
    metrorail();
    multipillar();
}
void MetroControl()
{

    glPushMatrix();
    glTranslated(MetroPos,0, 0);
    metro1();
    glPopMatrix();
}
void metrostation()
{
     glLineWidth(10);//2nd line
     glBegin(GL_LINES);
     glColor4f(0.9f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.557f, -0.746);
     glVertex2f(0.893f, -0.746);
     glEnd();


    glBegin(GL_QUADS);
    glColor4f(0.6f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.55f, -1.0);
     glVertex2f(0.9f, -1.0);
     glVertex2f(0.9f, -0.75);
     glVertex2f(0.55f, -0.75);
     glEnd();

     glLineWidth(9);//3rd Line
     glBegin(GL_LINES);
     glColor4f(1.0f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.54f, -0.79);
     glVertex2f(0.91f, -0.79);
     glEnd();
     glLineWidth(9);//5th Line
     glBegin(GL_LINES);
     glColor4f(1.0f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.54f, -0.88);
     glVertex2f(0.91f, -0.88);
     glEnd();

     glBegin(GL_QUADS);
     glColor4f(0.8f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.64f, -1.0);
     glColor4f(0.8f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.81f, -1.0);
     glColor4f(0.6f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.81f, -0.7);
     glColor4f(0.6f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.64f, -0.7);
     glEnd();

     glBegin(GL_QUADS);
     glColor4f(0.8f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.64f, -1.0);
     glColor4f(0.8f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.81f, -1.0);
     glColor4f(0.5, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.81f, -0.81);
     glColor4f(0.5f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.64f, -0.81);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor4f(0.8f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.62f, -0.698);
     glVertex2f(0.83f, -0.698);
     glVertex2f(0.725f, -0.6);
     glEnd();

     glLineWidth(20);//1stLine
     glBegin(GL_LINES);
     glColor4f(1.0f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.62f, -0.698);
     glVertex2f(0.83f, -0.698);
     glEnd();

     glLineWidth(9);//1stLine
     glBegin(GL_LINES);
     glColor4f(1.0f, 0.2f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.64f, -0.81);
     glVertex2f(0.81f, -0.81);
     glEnd();


     glBegin(GL_QUADS);
     glColor3f(0.5f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.66f, -1.0);
     glColor3f(1.0f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.79f, -1.0);
     glColor3f(0.5f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.79f, -0.85);
     glColor3f(0.5f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.66f, -0.85);
     glEnd();

     glLineWidth(2);//1stLine
     glBegin(GL_LINES);
     glColor4f(0.0f, 0.0f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.66f, -1.0);
     glVertex2f(0.79f, -1.0);
     glVertex2f(0.79f, -1.0);
     glVertex2f(0.79f, -0.85);
     glVertex2f(0.79f, -0.85);
     glVertex2f(0.66f, -0.85);
     glVertex2f(0.66f, -0.85);
     glVertex2f(0.66f, -1.0);
     glEnd();



    /*glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex2f(0.55f, -1.0);
    glVertex2f(0.9f, -1.0);
    glVertex2f(0.9f, -1.0);
    glVertex2f(0.9f, -0.75);
    glVertex2f(0.9f, -0.75);
    glVertex2f(0.55f, -0.75);
    glVertex2f(0.55f, -0.75);
    glVertex2f(0.55f, -1.0);
    glEnd();*/
}

void stationname()
{
    glColor3f(0.0, 0.0, 0.0);  // Set text color (white)
    glRasterPos2f(300, 250);  // Set text position (x, y)

    const char* text = "AIUB";
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);   // Render each character in the text
    }

    glFlush();
}

void stationname1()
{
    glColor3f(0.0, 0.0, 0.0);  // Set text color (white)
    glRasterPos2f(300, 250);  // Set text position (x, y)

    const char* text = "METRO STATION";
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);   // Render each character in the text
    }

    glFlush();
}

void stationwindow()
{
    glBegin(GL_QUADS);
     glColor3f(0.3f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.66f, -1.0);
     glColor3f(1.0f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.79f, -1.0);
     glColor3f(0.3f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.79f, -0.85);
     glColor3f(0.3f, 1.0f, 1.0f);//cyan Window1
     glVertex2f(0.66f, -0.85);
     glEnd();
     glLineWidth(2);//1stLine
     glBegin(GL_LINES);
     glColor4f(0.0f, 0.0f, 0.0f, 0.0f);//orange/brown
     glVertex2f(0.66f, -1.0);
     glVertex2f(0.79f, -1.0);
     glVertex2f(0.79f, -1.0);
     glVertex2f(0.79f, -0.85);
     glVertex2f(0.79f, -0.85);
     glVertex2f(0.66f, -0.85);
     glVertex2f(0.66f, -0.85);
     glVertex2f(0.66f, -1.0);
     glEnd();
}

void stationwindows()
{
    stationwindow();
    glPushMatrix();
    glTranslated(0.235, -0.26, 0.0);
    glScalef(0.5, 0.75, 0.0);
    stationwindow();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.49, -0.26, 0.0);
    glScalef(0.5, 0.75, 0.0);
    stationwindow();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.49, -0.26, 0.0);
    glScalef(0.5, 0.75, 0.0);
    stationwindow();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.43, -0.427, 0.0);
    glScalef(0.2, 0.442, 0.0);
    stationwindow();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.47, -0.427, 0.0);
    glScalef(0.2, 0.442, 0.0);
    stationwindow();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.69, -0.427, 0.0);
    glScalef(0.2, 0.442, 0.0);
    stationwindow();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.73, -0.427, 0.0);
    glScalef(0.2, 0.442, 0.0);
    stationwindow();
    glPopMatrix();


    //name--------------------------------------------

    glPushMatrix();
    glTranslated(0.76, -0.75, 0.0);
    glScalef(-0.0002, -0.000001, 0.0);
    stationname();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.714, -0.78, 0.0);
    glScalef(-0.00025, -0.000001, 0.0);
    stationname1();
    glPopMatrix();




    //------------------------------


}

void aiubstation()
{
    metrostation();
    stationwindows();
}

void tree()
{
glBegin(GL_POLYGON);
glColor3f(0.1f, 0.0f, 0.0f);//Brown
glVertex2f(0.8f, -0.8f);
glVertex2f(0.85f, -0.8f);
glVertex2f(0.85f, -0.5f);
glVertex2f(0.8f, -0.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.2f, 0.0f);//Green
glVertex2f(0.65f,-0.5f);
glVertex2f(1.f,-0.5f);
glVertex2f(0.825f,-0.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.2f, 0.0f);
glVertex2f(0.68f,-0.43f);
glVertex2f(0.97f,-0.43f);
glVertex2f(0.825f,-0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.2f, 0.0f);
glVertex2f(0.72f,-0.36f);
glVertex2f(0.93f,-0.36f);
glVertex2f(0.825f,-0.1f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.2f, 0.0f);
glVertex2f(0.73f,-0.29f);
glVertex2f(0.92f,-0.29f);
glVertex2f(0.825f,-0.05f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.2f, 0.0f);
glVertex2f(0.74f,-0.22f);
glVertex2f(0.91f,-0.22f);
glVertex2f(0.825f,0.05f);
glEnd();



}
void mainTree()
{
    //1st
     glPushMatrix();
    glScaled(0.1, 0.15, 0);
    glTranslated(-10.7, -1.5, 0);
    tree();
    glPopMatrix();

     glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.5, -1.0, 0);
    tree();
    glPopMatrix();

    //2nd
     glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.6, -1.5, 0);
    tree();
    glPopMatrix();

     glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.3, -1.5, 0);
    tree();
    glPopMatrix();

    //3rd
    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.7, -2.0, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.5, -2.0, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.2, -2.0, 0);
    tree();
    glPopMatrix();

    //4th
     glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.8, -2.5, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.6, -2.5, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.1, -2.5, 0);
    tree();
    glPopMatrix();

    //5th

     glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.7, -3.0, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.5, -3.0, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1, 0.2, 0);
    glTranslated(-10.1, -3.0, 0);
    tree();
    glPopMatrix();
}
//-------------------------------ROCKET----------------------------------
void rocketFire1()
{

    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();

}

void rocketFire1Alt()
{
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.38f , 0.20f );
    glVertex2f(0.35f , 0.13f );
    glVertex2f(0.378f , 0.16f);
    glVertex2f(0.4f , 0.10f );
    glVertex2f(0.43f , 0.16f );
    glVertex2f(0.45f , 0.13f );
    glVertex2f(0.43f , 0.20f );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.382f, 0.20f );
    glVertex2f(0.37f , 0.158f );
    glVertex2f(0.385f , 0.18f );
    glVertex2f(0.40f , 0.12f );
    glVertex2f(0.42f , 0.18f );
    glVertex2f(0.44f , 0.16f );
    glVertex2f(0.427f , 0.20f);
    glEnd();
}

void rocketFire2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
}


void rocket()
{
    glBegin(GL_QUADS);

    ///_________3 Mid body________///
    glColor3f(0.2, 0.9, 0.9);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.2, 0.9, 0.9);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(1.0, 0.1, 0.1);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(1.0, 0.1, 0.1);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________5 Upper body________///
    glColor3f(1.0, 0.4, 0.4);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(1.0, 0.4, 0.4);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);

    ///_________6 Top cap________///
    glColor3f(0.2, 0.7, 0.9);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.2, 0.7, 0.9);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________10 Lower body________///
    glColor3f(1.0, 0.4, 0.4);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(1.0, 0.4, 0.4);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);

    glEnd();

    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.2, 0.9, 0.9);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.2, 0.9, 0.9);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.2, 0.9, 0.9);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glEnd();



    circle(0.015, 0.405, 0.45, 0.976, 0.482, 0.125);



    circle(.010f, 0.405f, 0.45f, 0.314, 0.863, 0.98);


    circle(.005f, 0.385f, 0.52f, 0.808, 0.839, 0.847);


    circle(.005f, 0.405f, 0.52f, 0.808, 0.839, 0.847);


    circle(.005f, 0.425f, 0.52f, 0.808, 0.839, 0.847);
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();




    circleLine(.015f, 0.405f, 0.45f, 0.0,0.0,0.0);

circleLine(.010f, 0.405f, 0.45f, 0.0,0.0,0.0);


    circleLine(.005f, 0.385f, 0.52f, 0.0,0.0,0.0);


    circleLine(.005f, 0.405f, 0.52f, 0.0,0.0,0.0);


    circleLine(.005f, 0.425f, 0.52f, 0.0,0.0,0.0);



    if(RocketAlt > 0.6)
    {
        rocketFire2();
        rocketFire1();
        rocketFire1Alt();
    }
    else if(RocketAlt <= 0.6 && RocketAlt > 0.55)
    {
        rocketFire2();
        rocketFire1Alt();

    }
    else if(RocketAlt <= 0.55 && RocketAlt > 0.5)
    {
        rocketFire2();
        rocketFire1();

    }
    else if(RocketAlt <= 0.5 && RocketAlt > 0.45)
    {
        rocketFire2();

    }
    else if(RocketAlt <= 0.45 && RocketAlt > 0.4)
    {
        rocketFire2();
        rocketFire1Alt();
    }
    else if(RocketAlt <= 0.4 && RocketAlt > 0.35)
    {
        rocketFire2();
        rocketFire1();
    }
    else if(RocketAlt <= 0.35 && RocketAlt > 0.3)
    {

        rocketFire2();

    }
    else if(RocketAlt <= 0.3 && RocketAlt > 0.25)
    {
        rocketFire2();
        rocketFire1Alt();
    }
        else if(RocketAlt <= 0.25 && RocketAlt > 0.2)
    {
        rocketFire2();
        rocketFire1();
    }
        else if(RocketAlt <= 0.2 && RocketAlt > 0.15)
    {
        rocketFire2();

    }
        else if(RocketAlt <= 0.15 && RocketAlt > 0.1)
    {
        rocketFire2();
        rocketFire1Alt();
    }
        else if(RocketAlt <= 0.1 && RocketAlt > 0.05)
    {
        rocketFire2();
        rocketFire1();

    }
    else if(RocketAlt <= 0.05 && RocketAlt > 0.0)
    {
        rocketFire2();

    }


}
void rocketGround()
{
        glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(-0.8f,0.028f);
        glVertex2f(-0.6f, 0.028f);
        glVertex2f(-0.68f,0.17f);
        glVertex2f(-0.71f, 0.17f);
        glEnd();

}

void rocketStand()
{glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-0.55f, 0.028f);
    glVertex2f(-0.45f, 0.028f);
    glVertex2f(-0.45f, 0.6f);
    glVertex2f(-0.55f, 0.6f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.028f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.028f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.06725f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.06725f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.1065f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.14575f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.1065f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.14575f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.185f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.22425f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.185f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.22425f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.2635f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.30275f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.2635f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.30275f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.342f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.38125f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.342f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.38125f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.4205f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.45975f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.4205f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);//baby Blue
    glVertex2f(-0.5f, 0.45975f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.499f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.55f, 0.499f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.66f, 0.4205f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.45f, 0.4205f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.45f, 0.499f);
    glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glVertex2f(-0.66f, 0.499f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.0f, 0.0f);//Brown
    glVertex2f(-0.85f,0.028f);
    glVertex2f(-0.45f, 0.028f);

    glVertex2f(-0.45f, 0.028f);
    glVertex2f(-0.45f, 0.6f);

    glVertex2f(-0.45f, 0.6f);
    glVertex2f(-0.55f, 0.6f);

    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.55f, 0.17f);

    glVertex2f(-0.55f, 0.17f);
    glVertex2f(-0.85f,0.17f);

    glVertex2f(-0.85f,0.17f);
    glVertex2f(-0.85f,0.028f);

    //midbar down

    glVertex2f(-0.55f,0.17f);
    glVertex2f(-0.55f,0.028f);

    glVertex2f(-0.61f,0.17f);
    glVertex2f(-0.61f,0.028f);

    glVertex2f(-0.67f,0.17f);
    glVertex2f(-0.67f,0.028f);

    glVertex2f(-0.73f,0.17f);
    glVertex2f(-0.73f,0.028f);

    glVertex2f(-0.79f,0.17f);
    glVertex2f(-0.79f,0.028f);

    glVertex2f(-0.55f,0.17f);
    glVertex2f(-0.61f,0.028f);

    glVertex2f(-0.55f,0.028f);
    glVertex2f(-0.61f,0.17f);

    glVertex2f(-0.61f,0.17f);
    glVertex2f(-0.67f,0.028f);

    glVertex2f(-0.61f,0.028f);
    glVertex2f(-0.67f,0.17f);

    glVertex2f(-0.67f,0.17f);
    glVertex2f(-0.73f,0.028f);

    glVertex2f(-0.67f,0.028f);
    glVertex2f(-0.73f,0.17f);

    glVertex2f(-0.73f,0.17f);
    glVertex2f(-0.79f,0.028f);

    glVertex2f(-0.73f,0.028f);
    glVertex2f(-0.79f,0.17f);

    glVertex2f(-0.79f,0.17f);
    glVertex2f(-0.85f,0.028f);

    glVertex2f(-0.85f,0.17f);
    glVertex2f(-0.79f,0.028f);

    //middlebar up
    glVertex2f(-0.45f, 0.1065f);
    glVertex2f(-0.55f, 0.1065f);

    glVertex2f(-0.45f, 0.185f);
    glVertex2f(-0.55f, 0.185f);

    glVertex2f(-0.45f, 0.2635f);
    glVertex2f(-0.55f, 0.2635f);

    glVertex2f(-0.45f, 0.342f);
    glVertex2f(-0.55f, 0.342f);

    glVertex2f(-0.45f, 0.4205f);
    glVertex2f(-0.55f, 0.4205f);

    glVertex2f(-0.45f, 0.499f);
    glVertex2f(-0.55f, 0.499f);


    glVertex2f(-0.55f, 0.028f);
    glVertex2f(-0.45f, 0.1065f);

    glVertex2f(-0.45f, 0.028f);
    glVertex2f(-0.55f, 0.1065f);

    glVertex2f(-0.45f, 0.1065f);
    glVertex2f(-0.55f, 0.185f);

    glVertex2f(-0.55f, 0.1065f);
    glVertex2f(-0.45f, 0.185f);

    glVertex2f(-0.45f, 0.185f);
    glVertex2f(-0.55f, 0.2635f);

    glVertex2f(-0.55f, 0.185f);
    glVertex2f(-0.45f, 0.2635f);

    glVertex2f(-0.45f, 0.2635f);
    glVertex2f(-0.55f, 0.342f);

    glVertex2f(-0.55f, 0.2635f);
    glVertex2f(-0.45f, 0.342f);


    glVertex2f(-0.45f, 0.342f);
    glVertex2f(-0.55f, 0.4205f);

    glVertex2f(-0.55f, 0.342f);
    glVertex2f(-0.45f, 0.4205f);

    glVertex2f(-0.45f, 0.4205f);
    glVertex2f(-0.55f, 0.499f);

    glVertex2f(-0.55f, 0.4205f);
    glVertex2f(-0.45f, 0.499f);


    glVertex2f(-0.45f, 0.4205f);
    glVertex2f(-0.66f, 0.4205f);


    glVertex2f(-0.45f, 0.499f);
    glVertex2f(-0.66f, 0.499f);

    glVertex2f(-0.66f, 0.4205f);
    glVertex2f(-0.66f, 0.499f);

    glVertex2f(-0.55f, 0.499f);
    glVertex2f(-0.66f, 0.4205f);

    glVertex2f(-0.66f, 0.499f);
    glVertex2f(-0.55f, 0.4205f);

    glEnd();


}
//----------------------------------------------------------------------------------------------------------------
void flightControl()
{

    glPushMatrix();
    glTranslated(0, RocketAlt, 0);
    rocket(); // ROCKET
    glPopMatrix();


}

/// Car Back
void carBack()
{
    glBegin(GL_POLYGON); // top

    glColor3f(1, 0, 0);

    glVertex2f(0.2f, 0.6f);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(1, 0, 0);

    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.3f, 0.23f);
    glVertex2f(-0.3f, 0.23f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 1);

    glVertex2f(0.17f, 0.57f);
    glVertex2f(-0.17f, 0.57f);
    glVertex2f(-0.24f, 0.43f);
    glVertex2f(0.24f, 0.43f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(1, 1, 0);

    glVertex2f(-0.2f, 0.34f);
    glVertex2f(-0.3f, 0.34f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.2f, 0.3f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(1, 1, 0);

    glVertex2f(0.2f, 0.34f);
    glVertex2f(0.3f, 0.34f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.2f, 0.3f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 0);

    glVertex2f(-0.22f, 0.23f);
    glVertex2f(-0.27f, 0.23f);
    glVertex2f(-0.27f, 0.14f);
    glVertex2f(-0.22f, 0.14f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 0);

    glVertex2f(0.22f, 0.23f);
    glVertex2f(0.27f, 0.23f);
    glVertex2f(0.27f, 0.14f);
    glVertex2f(0.22f, 0.14f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.2f, 0.6f);
    glVertex2f(-0.2f, 0.6f);

    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.3f, 0.4f);

    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.2f, 0.6f); //

    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.3f, 0.23f);

    glVertex2f(0.3f, 0.23f);
    glVertex2f(-0.3f, 0.23f);

    glVertex2f(-0.3f, 0.23f);
    glVertex2f(-0.3f, 0.4f); //

    glVertex2f(0.17f, 0.57f);
    glVertex2f(-0.17f, 0.57f);

    glVertex2f(-0.17f, 0.57f);
    glVertex2f(-0.24f, 0.43f);

    glVertex2f(-0.24f, 0.43f);
    glVertex2f(0.24f, 0.43f);

    glVertex2f(0.24f, 0.43f);
    glVertex2f(0.17f, 0.57f); //

    glVertex2f(-0.2f, 0.34f);
    glVertex2f(-0.3f, 0.34f);

    glVertex2f(-0.3f, 0.34f);
    glVertex2f(-0.3f, 0.3f);

    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.2f, 0.3f);

    glVertex2f(-0.2f, 0.3f);
    glVertex2f(-0.2f, 0.34f); //

    glVertex2f(0.2f, 0.34f);
    glVertex2f(0.3f, 0.34f);

    glVertex2f(0.3f, 0.34f);
    glVertex2f(0.3f, 0.3f);

    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.2f, 0.3f);

    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, 0.34f);

    glEnd();
}

/// Car back end


/// Car Back 2
void carBack2()
{
    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 1);

    glVertex2f(0.2f, 0.6f);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 1);

    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.3f, 0.23f);
    glVertex2f(-0.3f, 0.23f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 1);

    glVertex2f(0.17f, 0.57f);
    glVertex2f(-0.17f, 0.57f);
    glVertex2f(-0.24f, 0.43f);
    glVertex2f(0.24f, 0.43f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(1, 1, 0);

    glVertex2f(-0.2f, 0.34f);
    glVertex2f(-0.3f, 0.34f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.2f, 0.3f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(1, 1, 0);

    glVertex2f(0.2f, 0.34f);
    glVertex2f(0.3f, 0.34f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.2f, 0.3f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 0);

    glVertex2f(-0.22f, 0.23f);
    glVertex2f(-0.27f, 0.23f);
    glVertex2f(-0.27f, 0.14f);
    glVertex2f(-0.22f, 0.14f);

    glEnd();

    glBegin(GL_POLYGON); // top

    glColor3f(0, 0, 0);

    glVertex2f(0.22f, 0.23f);
    glVertex2f(0.27f, 0.23f);
    glVertex2f(0.27f, 0.14f);
    glVertex2f(0.22f, 0.14f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.2f, 0.6f);
    glVertex2f(-0.2f, 0.6f);

    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.3f, 0.4f);

    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.2f, 0.6f); //

    glVertex2f(-0.3f, 0.4f);
    glVertex2f(0.3f, 0.4f);

    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.3f, 0.23f);

    glVertex2f(0.3f, 0.23f);
    glVertex2f(-0.3f, 0.23f);

    glVertex2f(-0.3f, 0.23f);
    glVertex2f(-0.3f, 0.4f); //

    glVertex2f(0.17f, 0.57f);
    glVertex2f(-0.17f, 0.57f);

    glVertex2f(-0.17f, 0.57f);
    glVertex2f(-0.24f, 0.43f);

    glVertex2f(-0.24f, 0.43f);
    glVertex2f(0.24f, 0.43f);

    glVertex2f(0.24f, 0.43f);
    glVertex2f(0.17f, 0.57f); //

    glVertex2f(-0.2f, 0.34f);
    glVertex2f(-0.3f, 0.34f);

    glVertex2f(-0.3f, 0.34f);
    glVertex2f(-0.3f, 0.3f);

    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.2f, 0.3f);

    glVertex2f(-0.2f, 0.3f);
    glVertex2f(-0.2f, 0.34f); //

    glVertex2f(0.2f, 0.34f);
    glVertex2f(0.3f, 0.34f);

    glVertex2f(0.3f, 0.34f);
    glVertex2f(0.3f, 0.3f);

    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.2f, 0.3f);

    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, 0.34f);

    glEnd();
}

/// Car back 2 end



/// Car

GLfloat iCar = 0.0f;

GLfloat positionCar = -11;
GLfloat speedCar = 0.1f;

void updateCar(int value)
{
    if(positionCar >= 1)
    {
        positionCar = -12;
    }
    if(positionCar == -12)
    {
        return;
    }
    positionCar += speedCar;

	glutPostRedisplay();
	glutTimerFunc(100, updateCar, 0);
}

void rim()
{
    glBegin(GL_POLYGON);

    glColor3f(1, 1, 1);

    glVertex2f(0.43f, 0.13f);
    glVertex2f(0.41f, 0.13f);
    glVertex2f(0.41f, 0.11f);
    glVertex2f(0.43f, 0.11f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(0.43f, 0.13f);
    glVertex2f(0.41f, 0.13f);

    glVertex2f(0.41f, 0.13f);
    glVertex2f(0.41f, 0.11f);

    glVertex2f(0.41f, 0.11f);
    glVertex2f(0.43f, 0.11f);

    glVertex2f(0.43f, 0.11f);
    glVertex2f(0.43f, 0.13f);

    glEnd();
}

void rotatePart()
{
    circle(0.08, 0.4, 0.1, 0, 0, 0);
    circle(0.05, 0.4, 0.1, 0.416, 0.427, 0.427);
    circle(0.01, 0.4, 0.1, 1, 1, 1);

    rim();

    glPushMatrix();
    glTranslated(-0.04, 0, 0);
    rim();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.04, -0.04, 0);
    rim();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, -0.04, 0);
    rim();
    glPopMatrix();
}

void car()
{
    glBegin(GL_POLYGON); // body

    glColor3f(0.878, 0.196, 0.149);

    glVertex2f(-0.6f, 0.28f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.56f, 0.1f);
    glVertex2f(-0.6f, 0.13f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.878, 0.196, 0.149);

    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.39f, 0.42f);
    glVertex2f(0.09f, 0.42f);
    glVertex2f(0.34f, 0.28f);
    glVertex2f(0.46f, 0.28f);
    glVertex2f(0.64f, 0.24f);
    glVertex2f(0.64f, 0.1f);
    glVertex2f(-0.56f, 0.1f);

    glEnd();    // body end

    glBegin(GL_POLYGON);    // window

    glColor3f(0.745, 0.902, 0.992);

    glVertex2f(-0.43f, 0.3f);
    glVertex2f(-0.31f, 0.39f);

    glColor3f(0.871, 0.953, 1);

    glVertex2f(0.07f, 0.39f);

    glColor3f(0.745, 0.902, 0.992);

    glVertex2f(0.26f, 0.28f);
    glVertex2f(-0.41f, 0.28f);

    glEnd();

    glBegin(GL_POLYGON);    // handle

    glColor3f(0.898, 0.898, 0.898);

    glVertex2f(-0.35f, 0.24f);
    glVertex2f(-0.27f, 0.24f);
    glVertex2f(-0.29f, 0.23f);
    glVertex2f(-0.34f, 0.23f);

    glEnd();    // handle end

    glBegin(GL_POLYGON);    // head light

    glColor3f(1, 0.996, 0.478);

    glVertex2f(0.58f, 0.22f);
    glVertex2f(0.64f, 0.24f);
    glVertex2f(0.64f, 0.2f);
    glVertex2f(0.58f, 0.2f);

    glEnd();    // head light end

    glBegin(GL_LINES);

    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(-0.56f, 0.28f);   // body
    glVertex2f(-0.39f, 0.42f);

    glVertex2f(-0.39f, 0.42f);
    glVertex2f(0.09f, 0.42f);

    glVertex2f(0.09f, 0.42f);
    glVertex2f(0.34f, 0.28f);

    glVertex2f(0.34f, 0.28f);
    glVertex2f(0.46f, 0.28f);

    glVertex2f(0.46f, 0.28f);
    glVertex2f(0.64f, 0.24f);

    glVertex2f(0.64f, 0.24f);
    glVertex2f(0.64f, 0.1f);

    glVertex2f(0.64f, 0.1f);
    glVertex2f(-0.56f, 0.1f);

    glVertex2f(-0.6f, 0.28f);
    glVertex2f(-0.56f, 0.28f);

    glVertex2f(-0.56f, 0.1f);
    glVertex2f(-0.6f, 0.13f);

    glVertex2f(-0.6f, 0.13f);
    glVertex2f(-0.6f, 0.28f);    // body end

    glVertex2f(-0.43f, 0.3f);    // window
    glVertex2f(-0.31f, 0.39f);

    glVertex2f(-0.31f, 0.39f);
    glVertex2f(0.07f, 0.39f);

    glVertex2f(0.07f, 0.39f);
    glVertex2f(0.26f, 0.28f);

    glVertex2f(0.26f, 0.28f);
    glVertex2f(-0.41f, 0.28f);

    glVertex2f(-0.41f, 0.28f);
    glVertex2f(-0.43f, 0.3f);    // window end

    glVertex2f(-0.35f, 0.24f);   // handle
    glVertex2f(-0.27f, 0.24f);

    glVertex2f(-0.27f, 0.24f);
    glVertex2f(-0.29f, 0.23f);

    glVertex2f(-0.29f, 0.23f);
    glVertex2f(-0.34f, 0.23f);

    glVertex2f(-0.34f, 0.23f);
    glVertex2f(-0.35f, 0.24f);   // handle end

    glEnd();
}

void displayCar()
{
    glPushMatrix();
    glScaled(0.1, 0.2, 1);
    glTranslatef(positionCar,0.0f, 0.0f);

    car();

    glPushMatrix();
    glTranslated(0.4, 0.1, 0);
    glRotatef(-iCar, 0, 0, 1);
    glTranslated(-0.4, -0.1, 0);

    rotatePart();

    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.46, 0.1, 0);
    glRotatef(-iCar, 0, 0, 1);
    glTranslated(0.46, -0.1, 0);
    glTranslated(-0.86, 0, 0);
    rotatePart();

    glPopMatrix();
    glPopMatrix();

    iCar+=0.02f;
}


/// Car end




/// Car 2

GLfloat iCar2 = 0.0f;

GLfloat positionCar2 = -11;
GLfloat speedCar2 = 0.1f;

void updateCar2(int value)
{
    if(positionCar2 >= 2.4)
    {
        positionCar2 = -12;
    }
    if(positionCar2 == -12)
    {
        return;
    }
    positionCar2 += speedCar2;

	glutPostRedisplay();
	glutTimerFunc(100, updateCar2, 0);
}

void rim2()
{
    glBegin(GL_POLYGON);

    glColor3f(1, 1, 1);

    glVertex2f(0.43f, 0.13f);
    glVertex2f(0.41f, 0.13f);
    glVertex2f(0.41f, 0.11f);
    glVertex2f(0.43f, 0.11f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(0.43f, 0.13f);
    glVertex2f(0.41f, 0.13f);

    glVertex2f(0.41f, 0.13f);
    glVertex2f(0.41f, 0.11f);

    glVertex2f(0.41f, 0.11f);
    glVertex2f(0.43f, 0.11f);

    glVertex2f(0.43f, 0.11f);
    glVertex2f(0.43f, 0.13f);

    glEnd();
}

void rotatePart2()
{
    circle(0.08, 0.4, 0.1, 0, 0, 0);
    circle(0.05, 0.4, 0.1, 0.416, 0.427, 0.427);
    circle(0.01, 0.4, 0.1, 1, 1, 1);

    rim2();

    glPushMatrix();
    glTranslated(-0.04, 0, 0);
    rim2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.04, -0.04, 0);
    rim2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, -0.04, 0);
    rim2();
    glPopMatrix();
}

void car2()
{
    glBegin(GL_POLYGON); // body

    glColor3f(0.178, 0.196, 1.149);

    glVertex2f(-0.6f, 0.28f);
    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.56f, 0.1f);
    glVertex2f(-0.6f, 0.13f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.178, 0.196, 1.149);

    glVertex2f(-0.56f, 0.28f);
    glVertex2f(-0.39f, 0.42f);
    glVertex2f(0.09f, 0.42f);
    glVertex2f(0.34f, 0.28f);
    glVertex2f(0.46f, 0.28f);
    glVertex2f(0.64f, 0.24f);
    glVertex2f(0.64f, 0.1f);
    glVertex2f(-0.56f, 0.1f);

    glEnd();    // body end

    glBegin(GL_POLYGON);    // window

    glColor3f(0.745, 0.902, 0.992);

    glVertex2f(-0.43f, 0.3f);
    glVertex2f(-0.31f, 0.39f);

    glColor3f(0.871, 0.953, 1);

    glVertex2f(0.07f, 0.39f);

    glColor3f(0.745, 0.902, 0.992);

    glVertex2f(0.26f, 0.28f);
    glVertex2f(-0.41f, 0.28f);

    glEnd();

    glBegin(GL_POLYGON);    // handle

    glColor3f(0.898, 0.898, 0.898);

    glVertex2f(-0.35f, 0.24f);
    glVertex2f(-0.27f, 0.24f);
    glVertex2f(-0.29f, 0.23f);
    glVertex2f(-0.34f, 0.23f);

    glEnd();    // handle end

    glBegin(GL_POLYGON);    // head light

    glColor3f(1, 0.996, 0.478);

    glVertex2f(0.58f, 0.22f);
    glVertex2f(0.64f, 0.24f);
    glVertex2f(0.64f, 0.2f);
    glVertex2f(0.58f, 0.2f);

    glEnd();    // head light end

    glBegin(GL_LINES);

    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(-0.56f, 0.28f);   // body
    glVertex2f(-0.39f, 0.42f);

    glVertex2f(-0.39f, 0.42f);
    glVertex2f(0.09f, 0.42f);

    glVertex2f(0.09f, 0.42f);
    glVertex2f(0.34f, 0.28f);

    glVertex2f(0.34f, 0.28f);
    glVertex2f(0.46f, 0.28f);

    glVertex2f(0.46f, 0.28f);
    glVertex2f(0.64f, 0.24f);

    glVertex2f(0.64f, 0.24f);
    glVertex2f(0.64f, 0.1f);

    glVertex2f(0.64f, 0.1f);
    glVertex2f(-0.56f, 0.1f);

    glVertex2f(-0.6f, 0.28f);
    glVertex2f(-0.56f, 0.28f);

    glVertex2f(-0.56f, 0.1f);
    glVertex2f(-0.6f, 0.13f);

    glVertex2f(-0.6f, 0.13f);
    glVertex2f(-0.6f, 0.28f);    // body end

    glVertex2f(-0.43f, 0.3f);    // window
    glVertex2f(-0.31f, 0.39f);

    glVertex2f(-0.31f, 0.39f);
    glVertex2f(0.07f, 0.39f);

    glVertex2f(0.07f, 0.39f);
    glVertex2f(0.26f, 0.28f);

    glVertex2f(0.26f, 0.28f);
    glVertex2f(-0.41f, 0.28f);

    glVertex2f(-0.41f, 0.28f);
    glVertex2f(-0.43f, 0.3f);    // window end

    glVertex2f(-0.35f, 0.24f);   // handle
    glVertex2f(-0.27f, 0.24f);

    glVertex2f(-0.27f, 0.24f);
    glVertex2f(-0.29f, 0.23f);

    glVertex2f(-0.29f, 0.23f);
    glVertex2f(-0.34f, 0.23f);

    glVertex2f(-0.34f, 0.23f);
    glVertex2f(-0.35f, 0.24f);   // handle end

    glEnd();
}

void displayCar2()
{
    glPushMatrix();
    glScaled(0.1, 0.2, 1);
    glTranslatef(positionCar2,-0.28f, 0.0f);

    car2();

    glPushMatrix();
    glTranslated(0.4, 0.1, 0);
    glRotatef(-iCar2, 0, 0, 1);
    glTranslated(-0.4, -0.1, 0);

    rotatePart2();

    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.46, 0.1, 0);
    glRotatef(-iCar2, 0, 0, 1);
    glTranslated(0.46, -0.1, 0);
    glTranslated(-0.86, 0, 0);
    rotatePart2();

    glPopMatrix();
    glPopMatrix();

    iCar2+=0.02f;
}


/// Car 2 end


/// Stop sign
void drawStopSign() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 8; ++i) {
        float theta = 2.0f * M_PI * i / 8;
        float x = 2.0f * cos(theta);
        float y = 2.0f * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);


    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(-0.6, 0.2);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -5.5);
    glVertex2f(0.1, -5.5);
    glVertex2f(0.1, -1.9);
    glVertex2f(-0.1, -1.9);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.6, -0.1, 0);



    glPopMatrix();
}

/// Stop sign end



void display()
{
 glClear(GL_COLOR_BUFFER_BIT);

 //---------SKY__________

   sky();

 //-------------------
 //background buildings

 //background buildings

 // green background

    backgroundgrass() ;

    backgroundbuildings();

    ///rocket
    glPushMatrix();
    glScaled(1.0,1.3,0);
    glTranslated(-1.1,-0.1,0);
    flightControl();
    glPopMatrix();

    rocketGround();
    rocketStand();
    ///parking
    Parking();
 // green background

 //------------------------------------------------------------Road--------------------------------------------------
    road1();
    road2();
    road3();
    Sidewalk();
    Pond();
//----------------------------------------------------------------------------------------------------------------------

 // ------------------------------------D-Building----------
    maindbuilding();
 //----------
 //---------------------------------------C-Building---------------------
    glPushMatrix();
    glScaled(0.2, 0.33, 0);
    glTranslated(-0.5, 0.9, 0);
    C_building();
    glPopMatrix();
//--------------

//----------------------------------------------------------- annex---------------

    glPushMatrix();
    glScaled(1.2, 1.2, 0);
    glTranslated(0.05, 0.044, 0);
    annex();
    glPopMatrix();

//-------------------
//---football
    footballgorund();
//-----------------

    displayCar();
    displayCar2();
    if(positionCar==-12)
    {
        glPushMatrix();
        glScaled(0.1,0.2,1);
        glTranslated(0.5,0,0);
        carBack();
        glPopMatrix();
    }
    if(positionCar2 == -12)
    {
        glPushMatrix();
        glScaled(0.1,0.2,1);
        glTranslated(2,0,0);
        carBack2();
        glPopMatrix();
    }


// --------------------  Tree ------------------------------
    mainTree();
    glPushMatrix();
    glScaled(0.008,0.01,1);
    glTranslated(33,-6,0);
    drawStopSign();
    glPopMatrix();


//-------------------------------------------------------------

//----Metrorail------
    glPushMatrix();
    glScaled(1.4, 1.5, 0);
    glTranslated(0, 0.3, 0);
     holemetro();
     MetroControl();
    glPopMatrix();
//-----------------
//metro station-------

    glPushMatrix();
    glScaled(1.4, 1.6, 0);
    glTranslated(-0.25, 0.35, 0);
    aiubstation();
    glPopMatrix();
//--------------------------------

//--------------------------------
 glFlush();
}
/// ====================================== SCENE 2============================================================================================

GLfloat position2S2 = 0.0f;
GLfloat speed2S2 = 0.00007f;
GLfloat cloudSpeedS2 =0.00017f;
GLfloat cloudPositionS2 = -0.5f;
void updateSkyS2(int value)
{
    if(position2S2 >= 1)
        return;
    position2S2 += speed2S2;

	glutPostRedisplay();
	glutTimerFunc(2, updateSkyS2, 0);
}

void updateRocketS2(int value)
{
    if(position2S2 >= 2.5)
        return;
    position2S2 += cloudSpeedS2;

	glutPostRedisplay();
	glutTimerFunc(2, updateRocketS2, 0);
}

void updateCloudS2(int value)
{
    if(cloudPositionS2 <= -1.5)
        return;
    cloudPositionS2 -= speed2S2;

	glutPostRedisplay();
	glutTimerFunc(2, updateCloudS2, 0);
}


void circleS2(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void circleLineS2(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}


void cloud3S2()
{
    circleS2(.04f, 0.05f, 0.24f, 0.388f, 0.463f, 0.733f);
    circleS2(.05f, 0.10f, 0.28f, 0.388f, 0.463f, 0.733f);
    circleS2(.03f, 0.15f, 0.25f, 0.388f, 0.463f, 0.733f);
    circleS2(.03f, 0.18f, 0.21f, 0.388f, 0.463f, 0.733f);
    circleS2(.04f, 0.24f, 0.22f, 0.388f, 0.463f, 0.733f);
    circleS2(.04f, 0.30f, 0.19f, 0.388f, 0.463f, 0.733f);
    circleS2(.05f, 0.36f, 0.145f, 0.388f, 0.463f, 0.733f);    //7
    circleS2(.05f, 0.52f, 0.17f, 0.388f, 0.463f, 0.733f);
    circleS2(.05f, 0.57f, 0.245f, 0.388f, 0.463f, 0.733f);
    circleS2(.04f, 0.64f, 0.21f, 0.388f, 0.463f, 0.733f);
    circleS2(.05f, 0.66f, 0.16f, 0.388f, 0.463f, 0.733f);
    circleS2(.06f, 0.95f, 0.33f, 0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.388f, 0.463f, 0.733f);
    glVertex2f(0.05f,0.235f);
    glVertex2f(0.19f,0.235f);
    glVertex2f(0.05f,0.00f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.388f, 0.463f, 0.733f);
    glVertex2f(0.52f,0.21f);
    glVertex2f(0.52f,0.00f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.64f,0.21f);

    glVertex2f(0.05f,0.193f);
    glVertex2f(0.05f,0.00f);
    glVertex2f(0.34f,0.0f);
    glVertex2f(0.34f,0.193);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0.388f, 0.463f, 0.733f);
    glVertex2f(0.208f,0.197f);
    glEnd();
}

void cloud2S2()
{
    circleS2(.04f, 0.07f, 0.12f, 0.298f, 0.38f, 0.69f);
    circleS2(.065f, 0.15f, 0.17, 0.298f, 0.38f, 0.69f);
    circleS2(.10f, 0.15f, 0.04f, 0.298f, 0.38f, 0.69f);
    circleS2(.045f, 0.23f, 0.125f, 0.298f, 0.38f, 0.69f);
    circleS2(.07f, 0.26, 0.07f, 0.298f, 0.38f, 0.69f);
    circleS2(.05f, 0.35f, 0.07f, 0.298f, 0.38f, 0.69f);
    circleS2(.05f, 0.60f, 0.09f, 0.298f, 0.38f, 0.69f);
    circleS2(.05f, 0.69f, 0.09f, 0.298f, 0.38f, 0.69f);
    circleS2(.07f, 0.75f, 0.16f, 0.298f, 0.38f, 0.69f);
}

void cloud1S2()
{
    circleS2(.07f, 0.0f, 0.178f, 0.231f, 0.255f, 0.545f);
    circleS2(.05f, 0.05f, 0.09f, 0.231f, 0.255f, 0.545f);
    circleS2(.03f, 0.105f, 0.047, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.153f, 0.05f, 0.231f, 0.255f, 0.545f);
    circleS2(.03f, 0.19f, 0.02f, 0.231f, 0.255f, 0.545f);
    circleS2(.03f, 0.24, 0.029f, 0.231f, 0.255f, 0.545f);
    circleS2(.025f, 0.28f, 0.010f, 0.231f, 0.255f, 0.545f);   //7
    circleS2(.04f, 0.30f, 0.023f, 0.231f, 0.255f, 0.545f);
    circleS2(.035f, 0.35f, 0.07f, 0.231f, 0.255f, 0.545f);
    circleS2(.035f, 0.40f, 0.10f, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.445f, 0.14f, 0.231f, 0.255f, 0.545f);
    circleS2(.045f, 0.49f, 0.10f, 0.231f, 0.255f, 0.545f);    //12
    circleS2(.03f, 0.54f, 0.06f, 0.231f, 0.255f, 0.545f);
    circleS2(.105f, 0.45f, 0.00f, 0.231f, 0.255f, 0.545f);
    circleS2(.05f, 0.595f, 0.01f, 0.231f, 0.255f, 0.545f);
    circleS2(.05f, 0.67f, 0.03f, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.72f, 0.07f, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.76f, 0.10f,0.231f, 0.255f, 0.545f);
    circleS2(.055f, 0.81f, 0.17f, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.87, 0.20f, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.90f, 0.26f, 0.231f, 0.255f, 0.545f);
    circleS2(.04f, 0.95f, 0.31f, 0.231f, 0.255f, 0.545f);
    circleS2(.05f, 1.0f, 0.37f, 0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.231f, 0.255f, 0.545f);
    glVertex2f(0.65f,0.0f);
    glVertex2f(1.0f,0.35f);
    glVertex2f(1.0f,0.0f);

    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.10f);
    glVertex2f(0.20f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.231f, 0.255f, 0.545f);
    glVertex2f(0.20f,0.05f);
    glVertex2f(0.20f,0.00f);
    glVertex2f(0.35f,0.0f);
    glVertex2f(0.35f,0.05f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0.231f, 0.255f, 0.545f);
    glVertex2f(0.0f, 0.105f);
    glEnd();
}

void moonS2()
{
    circleS2(0.2, -1.2, 0.7, 1,1,1);
    //circleS2(0.2, -1.07, 0.75, 0.03, 0.03, 0.03);
}

void starS2()
{
    glPushMatrix();
    glScaled(0.6,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
}

void starsS2()
{
    glPushMatrix();
    glScaled(0.2,0.1,1);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(2,0,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(0.7,6,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-2,3,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-3,5,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-2,7,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(0,9,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(2,9,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(4,5,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-4,2,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-2,-2,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-4.7,8.3,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-0.3,-5,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(3.3,-4,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(3,0,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(-2,2.6,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(-0.7,1,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(2.7,2.8,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(-3,-0.6,0);
    starS2();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(1,-1.5,0);
    starS2();
    glPopMatrix();
}

void scene2skyS2()
{
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(2.1, -1.2, 0.7, 0.0025, 0.0025, 0.0025);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(2, -1.2, 0.7, 0.005, 0.005, 0.005);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.9, -1.2, 0.7, 0.0075, 0.0075, 0.0075);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.8, -1.2, 0.7, 0.01, 0.01, 0.01);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.7, -1.2, 0.7, 0.0125, 0.0125, 0.0125);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.6, -1.2, 0.7, 0.015, 0.015, 0.015);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.5, -1.2, 0.7, 0.0175, 0.0175, 0.0175);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.4, -1.2, 0.7, 0.02, 0.02, 0.02);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.3, -1.2, 0.7, 0.0225, 0.0225, 0.0225);
    glPopMatrix();

    glEnd();
    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.2, -1.2, 0.7, 0.025, 0.025, 0.025);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1.1, -1.2, 0.7, 0.0275, 0.0275, 0.0275);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.6, 1,1);
    circleS2(1, -1.2, 0.7, 0.03, 0.03, 0.03);
    glPopMatrix();
}

void rocketFire1S2()
{

    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f - 0.7, 0.20f - 1.2);
    glVertex2f(0.36f - 0.7, 0.14f - 1.2);
    glVertex2f(0.388f - 0.7, 0.17f - 1.2);
    glVertex2f(0.4f - 0.7, 0.12f - 1.2);
    glVertex2f(0.42f - 0.7, 0.18f - 1.2);
    glVertex2f(0.45f - 0.7, 0.14f - 1.2);
    glVertex2f(0.42f - 0.7, 0.20f - 1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f -0.7, 0.20f - 1.2);
    glVertex2f(0.38f - 0.7, 0.168f - 1.2);
    glVertex2f(0.395f - 0.7, 0.19f - 1.2);
    glVertex2f(0.40f - 0.7, 0.14f - 1.2);
    glVertex2f(0.41f - 0.7, 0.19f - 1.2);
    glVertex2f(0.43f - 0.7, 0.17f - 1.2);
    glVertex2f(0.417f - 0.7, 0.20f - 1.2);
    glEnd();


}

void rocketFire1AltS2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.38f - 0.7, 0.20f - 1.2);
    glVertex2f(0.35f - 0.7, 0.13f - 1.2);
    glVertex2f(0.378f - 0.7, 0.16f - 1.2);
    glVertex2f(0.4f - 0.7, 0.10f - 1.2);
    glVertex2f(0.43f - 0.7, 0.16f - 1.2);
    glVertex2f(0.45f - 0.7, 0.13f - 1.2);
    glVertex2f(0.43f -0.7, 0.20f - 1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.382f - 0.7, 0.20f - 1.2);
    glVertex2f(0.37f - 0.7, 0.158f - 1.2);
    glVertex2f(0.385f - 0.7, 0.18f - 1.2);
    glVertex2f(0.40f - 0.7, 0.12f - 1.2);
    glVertex2f(0.42f - 0.7, 0.18f - 1.2);
    glVertex2f(0.44f - 0.7, 0.16f - 1.2);
    glVertex2f(0.427f - 0.7, 0.20f - 1.2);
    glEnd();

}

void rocketFire2S2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f - 0.7, 0.23f - 1.2);
    glVertex2f(0.36f - 0.7, 0.17f - 1.2);
    glVertex2f(0.388f - 0.7, 0.2f - 1.2);
    glVertex2f(0.4f - 0.7, 0.15f - 1.2);
    glVertex2f(0.42f - 0.7, 0.21f - 1.2);
    glVertex2f(0.45f - 0.7, 0.17f - 1.2);
    glVertex2f(0.42f - 0.7, 0.23f - 1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f - 0.7, 0.23f - 1.2);
    glVertex2f(0.38f - 0.7, 0.198f - 1.2);
    glVertex2f(0.395f - 0.7, 0.22f - 1.2);
    glVertex2f(0.40f - 0.7, 0.19f - 1.2);
    glVertex2f(0.41f - 0.7, 0.22f - 1.2);
    glVertex2f(0.43f - 0.7, 0.2f - 1.2);
    glVertex2f(0.417f - 0.7, 0.23f - 1.2);
    glEnd();

}


void rocketS2()
{
glBegin(GL_QUADS);

///_________3 Mid body________///
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
///_________ 4________///
glColor3f(1.0, 0.1, 0.1);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glColor3f(1.0, 0.1, 0.1);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
///_________5 Upper body________///
glColor3f(1.0, 0.4, 0.4);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glColor3f(1.0, 0.4, 0.4);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);

///_________6 Top cap________///
glColor3f(0.2, 0.7, 0.9);
glVertex2f(0.403f - 0.7, 0.59f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glColor3f(0.2, 0.7, 0.9);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.407f - 0.7, 0.59f - 1.2);

///_________ 9________///
glColor3f(1.0, 0.0, 0.0);
glVertex2f(0.376f - 0.7, 0.35f - 1.2);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.35f - 1.2);
///_________10 Lower body________///
glColor3f(1.0, 0.4, 0.4);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glColor3f(1.0, 0.4, 0.4);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
///_________ Upper and Lower border________///
///_______Lower L_____///
glColor3f(0.0, 0.0, 0.0);
glVertex2f(0.39f - 0.7, 0.34f - 1.2);
glVertex2f(0.39f - 0.7, 0.25f - 1.2);
glVertex2f(0.392f - 0.7, 0.25f - 1.2);
glVertex2f(0.392f - 0.7, 0.34f - 1.2);
///_______Lower R_____///
glVertex2f(0.4185f - 0.7, 0.34f - 1.2);
glVertex2f(0.4185f - 0.7, 0.25f - 1.2);
glVertex2f(0.42f - 0.7, 0.25f - 1.2);
glVertex2f(0.42f - 0.7, 0.34f - 1.2);
///_______upper_____///
glVertex2f(0.372f - 0.7, 0.452f - 1.2);
glVertex2f(0.372f - 0.7, 0.449f - 1.2);
glVertex2f(0.438f - 0.7, 0.449f - 1.2);
glVertex2f(0.438f - 0.7, 0.452f - 1.2);

glEnd();

glBegin(GL_QUADS);
///_________ 7(Wing 1)________///
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.376f - 0.7, 0.36f - 1.2);
glVertex2f(0.33f - 0.7, 0.24f - 1.2);
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.32f - 0.7, 0.23f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
///_________ 8(Wing 2)________///
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.434f - 0.7, 0.36f - 1.2);
glVertex2f(0.48f - 0.7, 0.24f - 1.2);
glVertex2f(0.49f - 0.7, 0.23f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.455, 0.525, 0.553);
glVertex2f(0.387f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.24f - 1.2);
///_________ 2________///
glColor3f(0.345, 0.416, 0.424);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.24f - 1.2);
glColor3f(0.349, 0.42, 0.435);
glVertex2f(0.43f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glEnd();





    circleS2(0.015, -0.295, -0.75, 0.976, 0.482, 0.125);

    circleS2(.010f, -0.295f, -0.75f, 0.314, 0.863, 0.98);

    circleS2(.005f, -0.270f, -0.68f, 0.808, 0.839, 0.847);

    circleS2(.005f, -0.295f, -0.68f, 0.808, 0.839, 0.847);
     ///_________ 16________///

    circleS2(.005f, -0.320f, -0.68f, 0.808, 0.839, 0.847);
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
glLineWidth(1.4);
glBegin(GL_LINES);
glColor3f(0.0, 0.0, 0.0);
///_________ 1________///
glVertex2f(0.387f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.24f - 1.2);
glVertex2f(0.423f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.23f - 1.2);
///_________ 2________///
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.24f - 1.2);
///_________ 3________///
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
///_________ 4________///
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
///_________ 5________///
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
///_________ 6________///
glVertex2f(0.403f - 0.7, 0.59f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.407f - 0.7, 0.59f - 1.2);
glVertex2f(0.403f - 0.7, 0.59f - 1.2);
glVertex2f(0.407f - 0.7, 0.59f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
///_________ 7(Wing 1)________///
glVertex2f(0.376f - 0.7, 0.36f - 1.2);
glVertex2f(0.33f - 0.7, 0.24f - 1.2);
glVertex2f(0.32f - 0.7, 0.23f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.376f - 0.7, 0.36f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.33f - 0.7, 0.24f - 1.2);
glVertex2f(0.32f - 0.7, 0.23f - 1.2);
///_________ 8(Wing 2)________///
glVertex2f(0.434f - 0.7, 0.36f - 1.2);
glVertex2f(0.48f - 0.7, 0.24f - 1.2);
glVertex2f(0.49f - 0.7, 0.23f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.434f - 0.7, 0.36f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.48f - 0.7, 0.24f - 1.2);
glVertex2f(0.49f - 0.7, 0.23f - 1.2);
///_________ 9________///
glVertex2f(0.376f - 0.7, 0.35f - 1.2);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.35f - 1.2);
///_________ 10________///
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glEnd();


    circleLineS2(0.015, -0.295, -0.75, 0.976, 0.482, 0.125);

    circleLineS2(.010f, -0.295f, -0.75f, 0.314, 0.863, 0.98);

    circleLineS2(.005f, -0.270f, -0.68f, 0.808, 0.839, 0.847);

    circleLineS2(.005f, -0.295f, -0.68f, 0.808, 0.839, 0.847);

    circleLineS2(.005f, -0.320f, -0.68f, 0.808, 0.839, 0.847);
    if(position2S2 > 1.5)
    {
        rocketFire2S2();
        rocketFire1S2();
        rocketFire1AltS2();
    }
    else if(position2S2 <= 1.5 && position2S2 > 1.45)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 1.45 && position2S2 > 1.4)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 1.4 && position2S2 > 1.35)
    {
        rocketFire2S2();


    }
    else if(position2S2 <= 1.35 && position2S2 > 1.3)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 1.3 && position2S2 > 1.25)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 1.25 && position2S2 > 1.2)
    {
        rocketFire2S2();


    }
    else if(position2S2 <= 1.2 && position2S2 > 1.15)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 1.15 && position2S2 > 1.1)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 1.1 && position2S2 > 1.05)
    {
        rocketFire2S2();


    }
    else if(position2S2 <= 1.05 && position2S2 > 1.0)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 1.0 && position2S2 > 0.95)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 0.95 && position2S2 > 0.9)
    {
        rocketFire2S2();


    }
    else if(position2S2 <= 0.9 && position2S2 > 0.85)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 0.85 && position2S2 > 0.8)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 0.8 && position2S2 > 0.75)
    {
        rocketFire2S2();


    }
    else if(position2S2 <= 0.75 && position2S2 > 0.7)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 0.7 && position2S2 > 0.65)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 0.65 && position2S2 > 0.6)
    {
        rocketFire2S2();


    }
    else if(position2S2 <= 0.6 && position2S2 > 0.55)
    {
        rocketFire2S2();
        rocketFire1AltS2();

    }
    else if(position2S2 <= 0.55 && position2S2 > 0.5)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 0.5 && position2S2 > 0.45)
    {
        rocketFire2S2();

    }
    else if(position2S2 <= 0.45 && position2S2 > 0.4)
    {
        rocketFire2S2();
        rocketFire1AltS2();
    }
    else if(position2S2 <= 0.4 && position2S2 > 0.35)
    {
        rocketFire2S2();
        rocketFire1S2();
    }
    else if(position2S2 <= 0.35 && position2S2 > 0.3)
    {

        rocketFire2S2();

    }
    else if(position2S2 <= 0.3 && position2S2 > 0.25)
    {
        rocketFire2S2();
        rocketFire1AltS2();
    }
        else if(position2S2 <= 0.25 && position2S2 > 0.2)
    {
        rocketFire2S2();
        rocketFire1S2();
    }
        else if(position2S2 <= 0.2 && position2S2 > 0.15)
    {
        rocketFire2S2();

    }
        else if(position2S2 <= 0.15 && position2S2 > 0.1)
    {
        rocketFire2S2();
        rocketFire1AltS2();
    }
        else if(position2S2 <= 0.1 && position2S2 > 0.05)
    {
        rocketFire2S2();
        rocketFire1S2();

    }
    else if(position2S2 <= 0.05 && position2S2 > 0.0)
    {
        rocketFire2S2();

    }


}
void flightControlS2()
{
        glBegin(GL_POLYGON);
        if(position2S2 > 1.0)
        {
        glColor3f(0.0, 0.0, 0.0); //  p < -0.6 to -1
        glVertex2f(1, -1.20f);
        glVertex2f(-1, -1.20f);
        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);

        }
        else if(position2S2 > 0.7)
        {
        glColor3f(0.0, 0.0, 0.0); //  p < -0.6 to -1
        glVertex2f(1, -1.20f);
        glVertex2f(-1, -1.20f);

        glColor3f(0.25, 0.25, 0.25);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);

        }
        else if(position2S2 <= 0.8 && position2S2 > 0.5)
        {
        glColor3f(0.3, 0.3, 0.2); //  p < -0.1 to -0.3
        glVertex2f(1, -1.20f);
        glVertex2f(-1, -1.20f);

        glColor3f(0.431, 0.38, 0.6);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);

        }
        else if(position2S2 <= 0.5 && position2S2 > 0.3)
        {
        glColor3f(0.3, 0.3, 0.2); //  p < -0.1 to -0.3
        glVertex2f(1, -1.20f);
        glVertex2f(-1, -1.20f);

        glColor3f(0.431, 0.38, 0.6);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);


        }
        else if(position2S2 <= 0.3 && position2S2 > 0.1)
        {
        glColor3f(0.5, 0.3, 0.25); //  p < 0.2 to -0.1
        glVertex2f(1, -1.20f);
        glVertex2f(-1, -1.20f);

        glColor3f(0.431, 0.33, 0.6);

        glVertex2f(-1, 1.0f);
        glVertex2f(1, 1.0f);

        }
        else if(position2S2 <= 0.1)
        {
            glColor3f(0.8, 0.6, 0.42); //  p < 0.4 to 0.2
            glVertex2f(1, -1.20f);
            glVertex2f(-1, -1.20f);

            glColor3f(0.531, 0.42, 0.7);

            glVertex2f(-1, 1.0f);
            glVertex2f(1, 1.0f);
        }
        glEnd();

        glPushMatrix();
        glTranslated(0, position2S2, 0);
        rocketS2(); // rocketS2
        glPopMatrix();

        glPushMatrix();
        glScaled(2,2,1);
        glTranslated(-0.5,cloudPositionS2,0);
        cloud2S2();
        cloud3S2();
        cloud1S2();
        glPopMatrix();

}

void displayS2()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

//    glLineWidth(3.0);

    scene2skyS2();

    flightControlS2();
    glPushMatrix();
    glScaled(0.6, 1,1);
    moonS2();
    glPopMatrix();

    starsS2();

    glFlush();  // Render now
}

/// ==================================== SCENE 2 END==========================================================================================


/// =======================================SCENE 3 ============================================================================================



#define PI 3.14159265358979323846;
GLfloat position2S3 = -0.3f;
GLfloat speed2S3 = 0.0001f;
GLfloat moonSpeedS3 =0.00007f;
GLfloat moonPositionS3 = 1.0f;
GLfloat RocketHeadposS3 = 0.0;

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void updateRocketHeadS3(int value)
{
    if(RocketHeadposS3 >= 1)
        return;
    RocketHeadposS3 += speed2S3;

	glutPostRedisplay();
	glutTimerFunc(2, updateRocketHeadS3, 0);
}


void updateRocketS3(int value)
{
    if(position2S3 >= 1)
    {
        return;
    }


    position2S3 += speed2S3;

	glutPostRedisplay();
	glutTimerFunc(2, updateRocketS3, 0);
}



void updateMoonS3(int value)
{
    if(moonPositionS3 <= -0.2)
        return;
    moonPositionS3 -= moonSpeedS3;

	glutPostRedisplay();
	glutTimerFunc(2, updateMoonS3, 0);
}

void circleS3(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void circleLineS3(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}



void starS3()
{
    glPushMatrix();
    glScaled(0.6,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
}

void starsS3()
{
    glPushMatrix();
    glScaled(0.2,0.1,1);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(2,0,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(0.7,6,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-2,3,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-3,5,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-2,7,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(0,9,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(2,9,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(4,5,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-4,2,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-2,-2,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-4.7,8.3,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(-0.3,-5,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.2,0.1,1);
    glTranslated(3.3,-4,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(3,0,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(-2,2.6,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(-0.7,1,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(2.7,2.8,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(-3,-0.6,0);
    starS3();
    glPopMatrix();

    glPushMatrix();
    glScaled(0.3,0.3,1);
    glTranslated(1,-1.5,0);
    starS3();
    glPopMatrix();
}

void rocketFire1S3()
{

    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f - 0.7, 0.20f - 1.2);
    glVertex2f(0.36f - 0.7, 0.14f - 1.2);
    glVertex2f(0.388f - 0.7, 0.17f - 1.2);
    glVertex2f(0.4f - 0.7, 0.12f - 1.2);
    glVertex2f(0.42f - 0.7, 0.18f - 1.2);
    glVertex2f(0.45f - 0.7, 0.14f - 1.2);
    glVertex2f(0.42f - 0.7, 0.20f - 1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f -0.7, 0.20f - 1.2);
    glVertex2f(0.38f - 0.7, 0.168f - 1.2);
    glVertex2f(0.395f - 0.7, 0.19f - 1.2);
    glVertex2f(0.40f - 0.7, 0.14f - 1.2);
    glVertex2f(0.41f - 0.7, 0.19f - 1.2);
    glVertex2f(0.43f - 0.7, 0.17f - 1.2);
    glVertex2f(0.417f - 0.7, 0.20f - 1.2);
    glEnd();


}

void rocketFire1AltS3()
{
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.38f - 0.7, 0.20f - 1.2);
    glVertex2f(0.35f - 0.7, 0.13f - 1.2);
    glVertex2f(0.378f - 0.7, 0.16f - 1.2);
    glVertex2f(0.4f - 0.7, 0.10f - 1.2);
    glVertex2f(0.43f - 0.7, 0.16f - 1.2);
    glVertex2f(0.45f - 0.7, 0.13f - 1.2);
    glVertex2f(0.43f -0.7, 0.20f - 1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.382f - 0.7, 0.20f - 1.2);
    glVertex2f(0.37f - 0.7, 0.158f - 1.2);
    glVertex2f(0.385f - 0.7, 0.18f - 1.2);
    glVertex2f(0.40f - 0.7, 0.12f - 1.2);
    glVertex2f(0.42f - 0.7, 0.18f - 1.2);
    glVertex2f(0.44f - 0.7, 0.16f - 1.2);
    glVertex2f(0.427f - 0.7, 0.20f - 1.2);
    glEnd();

}

void rocketFire2S3()
{
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f - 0.7, 0.23f - 1.2);
    glVertex2f(0.36f - 0.7, 0.17f - 1.2);
    glVertex2f(0.388f - 0.7, 0.2f - 1.2);
    glVertex2f(0.4f - 0.7, 0.15f - 1.2);
    glVertex2f(0.42f - 0.7, 0.21f - 1.2);
    glVertex2f(0.45f - 0.7, 0.17f - 1.2);
    glVertex2f(0.42f - 0.7, 0.23f - 1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f - 0.7, 0.23f - 1.2);
    glVertex2f(0.38f - 0.7, 0.198f - 1.2);
    glVertex2f(0.395f - 0.7, 0.22f - 1.2);
    glVertex2f(0.40f - 0.7, 0.19f - 1.2);
    glVertex2f(0.41f - 0.7, 0.22f - 1.2);
    glVertex2f(0.43f - 0.7, 0.2f - 1.2);
    glVertex2f(0.417f - 0.7, 0.23f - 1.2);
    glEnd();

}

void rocketHeadS3()
{
    glBegin(GL_QUADS);
    ///_________5 Upper body________///
    glColor3f(1.0, 0.4, 0.4);
    glVertex2f(0.38f - 0.7, 0.56f - 1.2);
    glVertex2f(0.37f - 0.7, 0.51f - 1.2);
    glColor3f(1.0, 0.4, 0.4);
    glVertex2f(0.44f - 0.7, 0.51f - 1.2);
    glVertex2f(0.43f - 0.7, 0.56f - 1.2);

/////_________6 Top cap________///
    glColor3f(0.2, 0.7, 0.9);
    glVertex2f(0.403f - 0.7, 0.59f - 1.2);
    glVertex2f(0.38f - 0.7, 0.56f - 1.2);
    glColor3f(0.2, 0.7, 0.9);
    glVertex2f(0.43f - 0.7, 0.56f - 1.2);
    glVertex2f(0.407f - 0.7, 0.59f - 1.2);

    glEnd();

    circleS3(.005f, -0.270f, -0.68f, 0.808, 0.839, 0.847);

    circleS3(.005f, -0.295f, -0.68f, 0.808, 0.839, 0.847);
     ///_________ 16________///

    circleS3(.005f, -0.320f, -0.68f, 0.808, 0.839, 0.847);

    circleLineS3(.005f, -0.270f, -0.68f, 0.808, 0.839, 0.847);

    circleLineS3(.005f, -0.295f, -0.68f, 0.808, 0.839, 0.847);

    circleLineS3(.005f, -0.320f, -0.68f, 0.808, 0.839, 0.847);
}

void rocketS3()
{
glBegin(GL_QUADS);

///_________3 Mid body________///
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
///_________ 4________///
glColor3f(1.0, 0.1, 0.1);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glColor3f(1.0, 0.1, 0.1);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);

//rocketS3 head
//rocketHeadS3();
///_________ 9________///
glColor3f(1.0, 0.0, 0.0);
glVertex2f(0.376f - 0.7, 0.35f - 1.2);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.35f - 1.2);
///_________10 Lower body________///
glColor3f(1.0, 0.4, 0.4);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glColor3f(1.0, 0.4, 0.4);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
///_________ Upper and Lower border________///
///_______Lower L_____///
glColor3f(0.0, 0.0, 0.0);
glVertex2f(0.39f - 0.7, 0.34f - 1.2);
glVertex2f(0.39f - 0.7, 0.25f - 1.2);
glVertex2f(0.392f - 0.7, 0.25f - 1.2);
glVertex2f(0.392f - 0.7, 0.34f - 1.2);
///_______Lower R_____///
glVertex2f(0.4185f - 0.7, 0.34f - 1.2);
glVertex2f(0.4185f - 0.7, 0.25f - 1.2);
glVertex2f(0.42f - 0.7, 0.25f - 1.2);
glVertex2f(0.42f - 0.7, 0.34f - 1.2);
///_______upper_____///
glVertex2f(0.372f - 0.7, 0.452f - 1.2);
glVertex2f(0.372f - 0.7, 0.449f - 1.2);
glVertex2f(0.438f - 0.7, 0.449f - 1.2);
glVertex2f(0.438f - 0.7, 0.452f - 1.2);

glEnd();

glBegin(GL_QUADS);
///_________ 7(Wing 1)________///
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.376f - 0.7, 0.36f - 1.2);
glVertex2f(0.33f - 0.7, 0.24f - 1.2);
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.32f - 0.7, 0.23f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
///_________ 8(Wing 2)________///
glColor3f(0.2, 0.9, 0.9);
glVertex2f(0.434f - 0.7, 0.36f - 1.2);
glVertex2f(0.48f - 0.7, 0.24f - 1.2);
glVertex2f(0.49f - 0.7, 0.23f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.455, 0.525, 0.553);
glVertex2f(0.387f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.24f - 1.2);
///_________ 2________///
glColor3f(0.345, 0.416, 0.424);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.24f - 1.2);
glColor3f(0.349, 0.42, 0.435);
glVertex2f(0.43f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glEnd();


    circleS3(0.015, -0.295, -0.75, 0.976, 0.482, 0.125);

    circleS3(.010f, -0.295f, -0.75f, 0.314, 0.863, 0.98);


    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
glLineWidth(1.4);
glBegin(GL_LINES);
glColor3f(0.0, 0.0, 0.0);
///_________ 1________///
glVertex2f(0.387f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.24f - 1.2);
glVertex2f(0.423f - 0.7, 0.24f - 1.2);
glVertex2f(0.387f - 0.7, 0.23f - 1.2);
glVertex2f(0.423f - 0.7, 0.23f - 1.2);
///_________ 2________///
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.38f - 0.7, 0.24f - 1.2);
glVertex2f(0.43f - 0.7, 0.24f - 1.2);
///_________ 3________///
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
///_________ 4________///
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.37f - 0.7, 0.50f - 1.2);
glVertex2f(0.44f - 0.7, 0.50f - 1.2);
///_________ 5________///
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.37f - 0.7, 0.51f - 1.2);
glVertex2f(0.44f - 0.7, 0.51f - 1.2);
///_________ 6________///
glVertex2f(0.403f - 0.7, 0.59f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
glVertex2f(0.407f - 0.7, 0.59f - 1.2);
glVertex2f(0.403f - 0.7, 0.59f - 1.2);
glVertex2f(0.407f - 0.7, 0.59f - 1.2);
glVertex2f(0.38f - 0.7, 0.56f - 1.2);
glVertex2f(0.43f - 0.7, 0.56f - 1.2);
///_________ 7(Wing 1)________///
glVertex2f(0.376f - 0.7, 0.36f - 1.2);
glVertex2f(0.33f - 0.7, 0.24f - 1.2);
glVertex2f(0.32f - 0.7, 0.23f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.376f - 0.7, 0.36f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.33f - 0.7, 0.24f - 1.2);
glVertex2f(0.32f - 0.7, 0.23f - 1.2);
///_________ 8(Wing 2)________///
glVertex2f(0.434f - 0.7, 0.36f - 1.2);
glVertex2f(0.48f - 0.7, 0.24f - 1.2);
glVertex2f(0.49f - 0.7, 0.23f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.434f - 0.7, 0.36f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.48f - 0.7, 0.24f - 1.2);
glVertex2f(0.49f - 0.7, 0.23f - 1.2);
///_________ 9________///
glVertex2f(0.376f - 0.7, 0.35f - 1.2);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.35f - 1.2);
///_________ 10________///
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.376f - 0.7, 0.34f - 1.2);
glVertex2f(0.434f - 0.7, 0.34f - 1.2);
glVertex2f(0.38f - 0.7, 0.25f - 1.2);
glVertex2f(0.43f - 0.7, 0.25f - 1.2);
glEnd();


    circleLineS3(0.015, -0.295, -0.75, 0.976, 0.482, 0.125);

    circleLineS3(.010f, -0.295f, -0.75f, 0.314, 0.863, 0.98);


    if(position2S3 > 1)
    {
        glPushMatrix();
        glTranslated(0, RocketHeadposS3, 0);
        //rocketS3(); // rocketS3
        rocketHeadS3();
        glPopMatrix();
    }
    else if(position2S3 <= 1.0 && position2S3 > 0.95)
    {
        rocketFire2S3();
        rocketFire1S3();

    }
    else if(position2S3 <= 0.95 && position2S3 > 0.9)
    {
        rocketHeadS3();
        rocketFire2S3();


    }
    else if(position2S3 <= 0.9 && position2S3 > 0.85)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1AltS3();

    }
    else if(position2S3 <= 0.85 && position2S3 > 0.8)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1S3();

    }
    else if(position2S3 <= 0.8 && position2S3 > 0.75)
    {
        rocketHeadS3();
        rocketFire2S3();


    }
    else if(position2S3 <= 0.75 && position2S3 > 0.7)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1AltS3();

    }
    else if(position2S3 <= 0.7 && position2S3 > 0.65)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1S3();

    }
    else if(position2S3 <= 0.65 && position2S3 > 0.6)
    {
        rocketHeadS3();
        rocketFire2S3();


    }
    else if(position2S3 <= 0.6 && position2S3 > 0.55)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1AltS3();

    }
    else if(position2S3 <= 0.55 && position2S3 > 0.5)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1S3();

    }
    else if(position2S3 <= 0.5 && position2S3 > 0.45)
    {
        rocketHeadS3();
        rocketFire2S3();

    }
    else if(position2S3 <= 0.45 && position2S3 > 0.4)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1AltS3();
    }
    else if(position2S3 <= 0.4 && position2S3 > 0.35)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1S3();
    }
    else if(position2S3 <= 0.35 && position2S3 > 0.3)
    {
        rocketHeadS3();
        rocketFire2S3();

    }
    else if(position2S3 <= 0.3 && position2S3 > 0.25)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1AltS3();
    }
        else if(position2S3 <= 0.25 && position2S3 > 0.2)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1S3();
    }
        else if(position2S3 <= 0.2 && position2S3 > 0.15)
    {
        rocketHeadS3();
        rocketFire2S3();

    }
        else if(position2S3 <= 0.15 && position2S3 > 0.1)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1AltS3();
    }
        else if(position2S3 <= 0.1 && position2S3 > 0.05)
    {
        rocketHeadS3();
        rocketFire2S3();
        rocketFire1S3();

    }
    else if(position2S3 <= 0.05 && position2S3 > 0.0)
    {
        rocketHeadS3();
        rocketFire2S3();

    }
        else if(position2S3 <= 0.0)
    {
        rocketHeadS3();
        rocketFire2S3();

    }

}

/// satelliteS3

int triangleAmount1S3 = 100;
void satelliteS3()
{
    glBegin(GL_QUADS);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.65f);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.65f);
///RIGHT WINGS
    glColor3f(0.255, 0.42, 0.565);
    glVertex2f(0.125f,0.605f);
    glColor3f(0.337, 0.6, 0.776);
    glVertex2f(0.175f,0.605f);
    glColor3f(0.337, 0.6, 0.776);
    glVertex2f(0.175f,0.645f);
    glColor3f(0.255, 0.42, 0.565);
    glVertex2f(0.125f,0.645f);
///LEFT WINGS
    glColor3f(0.255, 0.42, 0.565);
    glVertex2f(0.095f,0.605f);
    glColor3f(0.337, 0.6, 0.776);
    glVertex2f(0.045f,0.605f);
    glColor3f(0.337, 0.6, 0.776);
    glVertex2f(0.045f,0.645f);
    glColor3f(0.255, 0.42, 0.565);
    glVertex2f(0.095,0.645f);
    glEnd();

///LINES
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///BETWEEN BODY
    glVertex2f(0.11f,0.635f);
    glVertex2f(0.12f,0.635f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///right
    glVertex2f(0.12f,0.625f);
    glVertex2f(0.125f,0.625f);
    ///left
    glVertex2f(0.10f,0.625f);
    glVertex2f(0.095f,0.625f);
    ///upper
    glVertex2f(0.105f,0.65f);
    glVertex2f(0.105f,0.66f);
    glVertex2f(0.115f,0.65f);
    glVertex2f(0.115f,0.66f);
    ///with mini circleS3
    glVertex2f(0.11f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.12f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.10f,0.68f);
    glVertex2f(0.11f,0.69);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    ///MIDDLE IN RIGHT WINGS
    glVertex2f(0.125f,0.615f);
    glVertex2f(0.175f,0.615f);
    glVertex2f(0.125f,0.625f);
    glVertex2f(0.175f,0.625f);
    glVertex2f(0.125f,0.635f);
    glVertex2f(0.175f,0.635f);
    glVertex2f(0.135f,0.605f);
    glVertex2f(0.135f,0.645f);
    glVertex2f(0.145f,0.605f);
    glVertex2f(0.145f,0.645f);
    glVertex2f(0.155f,0.605f);
    glVertex2f(0.155f,0.645f);
    glVertex2f(0.165f,0.605f);
    glVertex2f(0.165f,0.645f);

    ///MIDDLE LINE IN LEFT WINGS
    glVertex2f(0.095f,0.615f);
    glVertex2f(0.045f,0.615f);
    glVertex2f(0.095f,0.625f);
    glVertex2f(0.045f,0.625f);
    glVertex2f(0.095f,0.635f);
    glVertex2f(0.045f,0.635f);
    glVertex2f(0.055f,0.605f);
    glVertex2f(0.055f,0.645f);
    glVertex2f(0.065f,0.605f);
    glVertex2f(0.065f,0.645f);
    glVertex2f(0.075f,0.605f);
    glVertex2f(0.075f,0.645f);
    glVertex2f(0.085f,0.605f);
    glVertex2f(0.085f,0.645f);
    glEnd();

///mini circleS3
    GLfloat p=0.11f, k=0.70f, ra=.005;
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p, k); // center of circleS3
    for(int i = 0; i <= triangleAmount1S3; i++)
    {
        glVertex2f( p + (ra * cos(i *  twicePi / triangleAmount1S3)),
                    k + (ra * sin(i * twicePi / triangleAmount1S3)) );
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();

    ///HALF circleS3
    GLfloat p1=0.11f, k1=0.68f, ra1=.025;
    twicePi= -1.0f *PI;

    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p1, k1); // center of circleS3
    for(int i = 0; i <= triangleAmount1S3; i++)
    {
        glVertex2f( p1 + (ra1 * cos(i *  twicePi / triangleAmount1S3)),
                    k1 + (ra1 * sin(i * twicePi / triangleAmount1S3)) );
        glColor3f(0.514, 0.514, 0.514);
    }
    glEnd();
}

/// satelliteS3 end


void moonS3()
{

    int triangleAmount = 100000;
    GLfloat twicePi = 2.0f * PI;
    GLfloat p1= 0.11f, k1=0.68f, ra1=.125;
    //twicePi= -1.0f PI;



    GLfloat p=0.1f, k=0.0f, ra=.5;
    //GLfloat twicePi = 2.0f PI;

    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p, k); // center of circleS3
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p + (ra * cos(i *  twicePi / triangleAmount)),
                    k + (ra * sin(i * twicePi / triangleAmount)) );
        glColor3f(0.8f, 0.8f, 0.8f);
    }
    glEnd();
}

void flightControlS3()
{

        glPushMatrix();
        glScaled(0.58,1,1);
        glTranslated(-0.7, moonPositionS3, 0);
        moonS3();
        glPopMatrix();

        glPushMatrix();
        glTranslated(0, position2S3, 0);
        rocketS3(); // rocketS3
        //rocketHeadS3();
        glPopMatrix();

}


void handleKeypressS3(unsigned char key, int x, int y) {
	switch (key) {
case 'R':
    glutTimerFunc(100, updateRocketS3, 0);
    glutTimerFunc(100, updateMoonS3, 0);
    break;
case 'r':
    glutTimerFunc(100, updateRocketS3, 0);
    glutTimerFunc(100, updateMoonS3 , 0);
    break;
case 'B':
    glutTimerFunc(100, updateRocketHeadS3, 0);
    break;
case 'b':
    glutTimerFunc(100, updateRocketHeadS3, 0);
    break;
	}
}
GLfloat i = 0.0f;

void displayS3()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


    flightControlS3();

    if(RocketHeadposS3>=0.5)
    {
        glPushMatrix();
        glTranslated(-0.4,-0.3,0);
        glRotatef(i, 0, 0, -1);
        satelliteS3();

        glPopMatrix();
        i+=0.2f;
    }

    //satelliteS3();
    starsS3();

    glFlush();
}


/// ============================================ SCENE 3 END ==============================================================================


void handleKeypress(unsigned char key, int x, int y)
{
    switch(key)
    {
    /// scene 1
    case 'd':
    glutTimerFunc(100, updateDay, 0);
    break;
    case 'D':
    glutTimerFunc(100, updateDay, 0);
    break;
    case 'n':
    glutTimerFunc(100, updateNight, 0);
    break;
    case 'N':
    glutTimerFunc(100, updateNight, 0);
    break;
    case 'c':
    glutTimerFunc(100, updateCar, 0);
    glutTimerFunc(900, updateCar2, 0);
    break;
    case 'C':
    glutTimerFunc(100, updateCar, 0);
    glutTimerFunc(900, updateCar2, 0);
    break;
    case 'r':
    sndPlaySound("mixkit-rocket-engine-ignition-rumble-1715.wav", SND_ASYNC);
    glutTimerFunc(100, updateRocket, 0);
    break;
    case 'R':
    sndPlaySound("mixkit-rocket-engine-ignition-rumble-1715.wav", SND_ASYNC);
    glutTimerFunc(100, updateRocket, 0);
    break;
    case 'm':
    glutTimerFunc(100, updateMetro, 0);
    break;
    case 'M':
    glutTimerFunc(100, updateMetro, 0);
    break;
    glutPostRedisplay();
    /// scene 2
    case 'T':
    glutTimerFunc(100, updateRocketS2, 0);
    glutTimerFunc(100, updateCloudS2, 0);
    break;
    case 't':
    glutTimerFunc(100, updateRocketS2, 0);
    glutTimerFunc(100, updateCloudS2, 0);
    break;
    /// scene 3
    case 'Y':
    glutTimerFunc(100, updateRocketS3, 0);
    glutTimerFunc(100, updateMoonS3, 0);
    break;
    case 'y':
    glutTimerFunc(100, updateRocketS3, 0);
    glutTimerFunc(100, updateMoonS3 , 0);
    break;
    case 'B':
    glutTimerFunc(100, updateRocketHeadS3, 0);
    break;
    case 'b':
    glutTimerFunc(100, updateRocketHeadS3, 0);
    break;


    case '1':
    glutDisplayFunc(display);
    glutPostRedisplay();
    break;
    case '2':
    glutDisplayFunc(displayS2);
    glutPostRedisplay();
    break;
    case '3':
    glutDisplayFunc(displayS3);
    glutPostRedisplay();
    break;
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("task");
    glutIdleFunc(Idle);
    glutDisplayFunc(display);

    glutFullScreen();
    initGL();
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return 0;
}
