#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

GLfloat positionWitch = 0.0f;
GLfloat speedWitch = 0.015f;
GLfloat positionGhost = 0.0f;
GLfloat positionShip = 0.0f;
GLfloat positionPumpkin = 0.0f;
GLfloat positionBatsH = 0.0f;
GLfloat positionBatsM = 0.0f;
GLfloat positionRain = 0.0f;
GLfloat pumpkinRotate = 0.0f;
GLfloat ghandRotate = 0.0f;

bool Ship_moveCondition = false;
bool Pumpkin_moveCondition = false;
bool Ghost_moveCondition = false;
bool GhostMove = false;
bool rainStatus = false;
bool houseLight = true;
bool redMoon = false;
bool redEyePumpkin = false;
bool gHand_moveCondition = false;

void update(int value)
{
///witch move

    positionWitch -= speedWitch;

    if (positionWitch < -1.3f)
    {
        positionWitch = 0.95f ;
    }

///bats fly

    positionBatsH += 0.01f;

    if (positionBatsH > 1.0f)
    {
        positionBatsH = 0.05f ;
    }

    positionBatsM += 0.016f;

    if (positionBatsM > 1.0f)
    {
        positionBatsM = 0.0f ;
    }

/// ship move

    if (!Ship_moveCondition)
   {
       positionShip += 0.01f;

    if (positionShip > 0.7f)
    {
        Ship_moveCondition = true;
    }
   }

    if (Ship_moveCondition)
    {
        positionShip -= 0.02f ;

     if  (positionShip < -0.15f )
     {
        Ship_moveCondition = false;
     }
    }

/// pumpkin dance

    if (!Pumpkin_moveCondition)
    {
        positionPumpkin -= 0.028f;

      if (positionPumpkin < -0.12f )
      {
          Pumpkin_moveCondition = true;
      }
    }

    if (Pumpkin_moveCondition)
    {
        positionPumpkin +=0.028f;

        if (positionPumpkin > 0.0f )
        {
            Pumpkin_moveCondition = false;
        }
    }

/// ghost move

  if (GhostMove == true)
  {
    if (!Ghost_moveCondition)
    {
        positionGhost += 0.01f;

      if (positionGhost > 0.25f )
      {
            Ghost_moveCondition = true;
      }
    }

    if (Ghost_moveCondition)
    {
        positionGhost -= 0.012f;

        if (positionGhost < 0.0f )
        {
            Ghost_moveCondition = false;
        }
    }
   }


///rain drops

     positionRain += 0.018f ;

   if(positionRain >0.02f)
   {
        positionRain = -0.01f;
   }

    glutPostRedisplay();

    glutTimerFunc(50, update, 0);
}

void sky()
{
    glBegin(GL_POLYGON);
       glColor3f(0.39f, 0.58f, 0.93f);
       glVertex2f(-1.0f, 0.305f);
       glVertex2f(-1.0f, 1.0f);
       glColor3f(0.0f, 0.0f, 0.5f);
       glVertex2f(0.5f, 1.0f);
       glVertex2f(1.0f, 1.0f);
       glVertex2f(1.0f, 0.305f);
    glEnd();
}

void stars()
{
   glPointSize(2.5);
   glBegin(GL_POINTS);
       glColor3f(0.85f, 1.0f, 1.0f);
       glVertex2f(-0.96f, 0.95f);
       glVertex2f(-0.88f, 0.95f);
       glVertex2f(-0.8f, 0.95f);
       glVertex2f(-0.72f, 0.95f);
       glVertex2f(-0.64f, 0.95f);
       glVertex2f(-0.56f, 0.95f);
       glVertex2f(-0.48f, 0.95f);
       glVertex2f(-0.4f, 0.95f);
       glVertex2f(-0.32f, 0.95f);
       glVertex2f(-0.24f, 0.95f);
       glVertex2f(-0.16f, 0.95f);
       glVertex2f(-0.08f, 0.95f);
       glVertex2f(0.0f, 0.95f);
       glVertex2f(0.08f, 0.95f);
       glVertex2f(0.16f, 0.95f);
       glVertex2f(0.24f, 0.95f);
       glVertex2f(0.32f, 0.95f);
       glVertex2f(0.4f, 0.95f);
       glVertex2f(0.48f, 0.95f);
       glVertex2f(0.56f, 0.95f);
       glVertex2f(0.64f, 0.95f);
       glVertex2f(0.72f, 0.95f);
       glVertex2f(0.8f, 0.95f);
       glVertex2f(0.88f, 0.95f);
       glVertex2f(0.96f, 0.95f);

       glVertex2f(-0.98f, 0.9f);
       glVertex2f(-0.94f, 0.9f);
       glVertex2f(-0.89f, 0.9f);
       glVertex2f(-0.82f, 0.9f);
       glVertex2f(-0.75f, 0.9f);
       glVertex2f(-0.68f, 0.9f);
       glVertex2f(-0.62f, 0.9f);
       glVertex2f(-0.54f, 0.9f);
       glVertex2f(-0.48f, 0.9f);
       glVertex2f(-0.41f, 0.9f);
       glVertex2f(-0.34f, 0.9f);
       glVertex2f(-0.27f, 0.9f);
       glVertex2f(-0.2f, 0.9f);
       glVertex2f(-0.12f, 0.9f);
       glVertex2f(-0.05f, 0.9f);
       glVertex2f(0.0f, 0.9f);
       glVertex2f(0.05f, 0.9f);
       glVertex2f(0.12f, 0.9f);
       glVertex2f(0.19f, 0.9f);
       glVertex2f(0.26f, 0.9f);
       glVertex2f(0.34f, 0.9f);
       glVertex2f(0.4f, 0.9f);
       glVertex2f(0.46f, 0.9f);
       glVertex2f(0.53f, 0.9f);
       glVertex2f(0.6f, 0.9f);
       glVertex2f(0.67f, 0.9f);
       glVertex2f(0.75f, 0.9f);
       glVertex2f(0.82f, 0.9f);
       glVertex2f(0.89f, 0.9f);
       glVertex2f(0.96f, 0.9f);

       glVertex2f(-0.96f, 0.85f);
       glVertex2f(-0.88f, 0.85f);
       glVertex2f(-0.8f, 0.85f);
       glVertex2f(-0.72f, 0.85f);
       glVertex2f(-0.64f, 0.85f);
       glVertex2f(-0.56f, 0.85f);
       glVertex2f(-0.48f, 0.85f);
       glVertex2f(-0.4f, 0.85f);
       glVertex2f(-0.32f, 0.85f);
       glVertex2f(-0.24f, 0.85f);
       glVertex2f(-0.16f, 0.85f);
       glVertex2f(-0.08f, 0.85f);
       glVertex2f(0.0f, 0.85f);
       glVertex2f(0.08f, 0.85f);
       glVertex2f(0.16f, 0.85f);
       glVertex2f(0.24f, 0.85f);
       glVertex2f(0.32f, 0.85f);
       glVertex2f(0.4f, 0.85f);
       glVertex2f(0.48f, 0.85f);
       glVertex2f(0.56f, 0.85f);
       glVertex2f(0.64f, 0.85f);
       glVertex2f(0.72f, 0.85f);
       glVertex2f(0.8f, 0.85f);
       glVertex2f(0.88f, 0.85f);
       glVertex2f(0.96f, 0.85f);

       glVertex2f(-0.96f, 0.8f);
       glVertex2f(-0.89f, 0.8f);
       glVertex2f(-0.82f, 0.8f);
       glVertex2f(-0.75f, 0.8f);
       glVertex2f(-0.68f, 0.8f);
       glVertex2f(-0.62f, 0.8f);
       glVertex2f(-0.54f, 0.8f);
       glVertex2f(-0.48f, 0.8f);
       glVertex2f(-0.41f, 0.8f);
       glVertex2f(-0.34f, 0.8f);
       glVertex2f(-0.27f, 0.8f);
       glVertex2f(-0.2f, 0.8f);
       glVertex2f(-0.12f, 0.8f);
       glVertex2f(-0.05f, 0.8f);
       glVertex2f(0.0f, 0.8f);
       glVertex2f(0.05f, 0.8f);
       glVertex2f(0.12f, 0.8f);
       glVertex2f(0.19f, 0.8f);
       glVertex2f(0.26f, 0.8f);
       glVertex2f(0.34f, 0.8f);
       glVertex2f(0.4f, 0.8f);
       glVertex2f(0.46f, 0.8f);
       glVertex2f(0.53f, 0.8f);
       glVertex2f(0.6f, 0.8f);
       glVertex2f(0.67f, 0.8f);
       glVertex2f(0.75f, 0.8f);
       glVertex2f(0.82f, 0.8f);
       glVertex2f(0.89f, 0.8f);
       glVertex2f(0.96f, 0.8f);

       glVertex2f(-0.98f, 0.75f);
       glVertex2f(-0.94f, 0.75f);
       glVertex2f(-0.88f, 0.75f);
       glVertex2f(-0.82f, 0.75f);
       glVertex2f(-0.76f, 0.75f);
       glVertex2f(-0.7f, 0.75f);
       glVertex2f(-0.64f, 0.75f);
       glVertex2f(-0.58f, 0.75f);
       glVertex2f(-0.52f, 0.75f);
       glVertex2f(-0.46f, 0.75f);
       glVertex2f(-0.4f, 0.75f);
       glVertex2f(-0.34f, 0.75f);
       glVertex2f(-0.28f, 0.75f);
       glVertex2f(-0.22f, 0.75f);
       glVertex2f(-0.16f, 0.75f);
       glVertex2f(-0.1f, 0.75f);
       glVertex2f(-0.04f, 0.75f);
       glVertex2f(0.02f, 0.75f);
       glVertex2f(0.08f, 0.75f);
       glVertex2f(0.14f, 0.75f);
       glVertex2f(0.2f, 0.75f);
       glVertex2f(0.26f, 0.75f);
       glVertex2f(0.32f, 0.75f);
       glVertex2f(0.38f, 0.75f);
       glVertex2f(0.44f, 0.75f);
       glVertex2f(0.5f, 0.75f);
       glVertex2f(0.56f, 0.75f);
       glVertex2f(0.62f, 0.75f);
       glVertex2f(0.68f, 0.75f);
       glVertex2f(0.74f, 0.75f);
       glVertex2f(0.8f, 0.75f);
       glVertex2f(0.86f, 0.75f);
       glVertex2f(0.93f, 0.75f);
       glVertex2f(0.98f, 0.75f);

       glVertex2f(-0.96f, 0.7f);
       glVertex2f(-0.89f, 0.7f);
       glVertex2f(-0.82f, 0.7f);
       glVertex2f(-0.75f, 0.7f);
       glVertex2f(-0.68f, 0.7f);
       glVertex2f(-0.62f, 0.7f);
       glVertex2f(-0.54f, 0.7f);
       glVertex2f(-0.48f, 0.7f);
       glVertex2f(-0.41f, 0.7f);
       glVertex2f(-0.34f, 0.7f);
       glVertex2f(-0.27f, 0.7f);
       glVertex2f(-0.2f, 0.7f);
       glVertex2f(-0.12f, 0.7f);
       glVertex2f(-0.05f, 0.7f);
       glVertex2f(0.0f, 0.7f);
       glVertex2f(0.05f, 0.7f);
       glVertex2f(0.12f, 0.7f);
       glVertex2f(0.19f, 0.7f);
       glVertex2f(0.26f, 0.7f);
       glVertex2f(0.34f, 0.7f);
       glVertex2f(0.4f, 0.7f);
       glVertex2f(0.46f, 0.7f);
       glVertex2f(0.53f, 0.7f);
       glVertex2f(0.6f, 0.7f);
       glVertex2f(0.67f, 0.7f);
       glVertex2f(0.75f, 0.7f);
       glVertex2f(0.82f, 0.7f);
       glVertex2f(0.89f, 0.7f);
       glVertex2f(0.96f, 0.7f);

       glVertex2f(-0.96f, 0.65f);
       glVertex2f(-0.88f, 0.65f);
       glVertex2f(-0.8f, 0.65f);
       glVertex2f(-0.72f, 0.65f);
       glVertex2f(-0.64f, 0.65f);
       glVertex2f(-0.56f, 0.65f);
       glVertex2f(-0.48f, 0.65f);
       glVertex2f(-0.4f, 0.65f);
       glVertex2f(-0.32f, 0.65f);
       glVertex2f(-0.24f, 0.65f);
       glVertex2f(-0.16f, 0.65f);
       glVertex2f(-0.08f, 0.65f);
       glVertex2f(0.0f, 0.65f);
       glVertex2f(0.08f, 0.65f);
       glVertex2f(0.16f, 0.65f);
       glVertex2f(0.24f, 0.65f);
       glVertex2f(0.32f, 0.65f);
       glVertex2f(0.4f, 0.65f);
       glVertex2f(0.48f, 0.65f);
       glVertex2f(0.56f, 0.65f);
       glVertex2f(0.64f, 0.65f);
       glVertex2f(0.72f, 0.65f);
       glVertex2f(0.8f, 0.65f);
       glVertex2f(0.88f, 0.65f);
       glVertex2f(0.96f, 0.65f);
   glEnd();
}

void moon()
{
    glBegin(GL_TRIANGLE_FAN);
       glColor3f(0.99f, 0.95f, 0.84f);
       glVertex2f(0.65f, 0.55f);
       for(int i = 0; i <= 250 ; i++)
       {
            glVertex2f( 0.65 + (0.25*cos(i*((2*3.1416)/250))),
                        0.55 + (0.25*sin(i*((2*3.1416)/250)))
                       );
        }
    glEnd();
}

void red_moon()
{
    glBegin(GL_TRIANGLE_FAN);
       glColor3f(0.99f, 0.0f, 0.0f);
       glVertex2f(0.65f, 0.55f);
       glColor3f(0.99f, 0.95f, 0.84f);
       for(int i = 0; i <= 250 ; i++)
       {
            glVertex2f( 0.65 + (0.25*cos(i*((2*3.1416)/250))),
                        0.55 + (0.25*sin(i*((2*3.1416)/250)))
                       );
        }
    glEnd();
}

void Rain(int value)
{
    if(rainStatus)
    {
        positionRain += 0.01f;

        glBegin(GL_POINTS);
        for(int i=1; i<=1200; i++)
        {
          int x=rand(),y=rand();
          x%=1280; y%=840;
          glBegin(GL_LINES);
          glColor3f(1.0, 1.0, 1.0);
          glVertex2f(x,y);
          glVertex2f(x+.05,y+.05);
          glEnd();
        }

    glutPostRedisplay();
	glutTimerFunc(25, Rain, 0);

      glFlush();
    }
}

void rain()
{
    glLineWidth(0.8);
    glBegin(GL_LINES);
       glColor3f(0.5f, 1.0f, 1.0f);
       glVertex2f(1.0f,1.0f);
       glVertex2f(0.995f,0.98f);

       glVertex2f(0.98f,1.0f);
       glVertex2f(0.975f,0.98f);

       glVertex2f(0.96f,1.0f);
       glVertex2f(0.955f,0.98f);

       glVertex2f(0.94f,1.0f);
       glVertex2f(0.935f,0.98f);

       glVertex2f(0.92f,1.0f);
       glVertex2f(0.915f,0.98f);

       glVertex2f(0.9f,1.0f);
       glVertex2f(0.895f,0.98f);

       glVertex2f(0.88f,1.0f);
       glVertex2f(0.875f,0.98f);

       glVertex2f(0.86f,1.0f);
       glVertex2f(0.855f,0.98f);

       glVertex2f(0.84f,1.0f);
       glVertex2f(0.835f,0.98f);

       glVertex2f(0.82f,1.0f);
       glVertex2f(0.815f,0.98f);

       glVertex2f(0.8f,1.0f);
       glVertex2f(0.795f,0.98f);

       glVertex2f(0.78f,1.0f);
       glVertex2f(0.775f,0.98f);

       glVertex2f(0.76f,1.0f);
       glVertex2f(0.755f,0.98f);

       glVertex2f(0.74f,1.0f);
       glVertex2f(0.735f,0.98f);

       glVertex2f(0.72f,1.0f);
       glVertex2f(0.715f,0.98f);

       glVertex2f(0.7f,1.0f);
       glVertex2f(0.695f,0.98f);

       glVertex2f(0.68f,1.0f);
       glVertex2f(0.675f,0.98f);

       glVertex2f(0.66f,1.0f);
       glVertex2f(0.655f,0.98f);

       glVertex2f(0.64f,1.0f);
       glVertex2f(0.635f,0.98f);

       glVertex2f(0.62f,1.0f);
       glVertex2f(0.615f,0.98f);

       glVertex2f(0.6f,1.0f);
       glVertex2f(0.595f,0.98f);

       glVertex2f(0.58f,1.0f);
       glVertex2f(0.575f,0.98f);

       glVertex2f(0.56f,1.0f);
       glVertex2f(0.555f,0.98f);

       glVertex2f(0.54f,1.0f);
       glVertex2f(0.535f,0.98f);

       glVertex2f(0.52f,1.0f);
       glVertex2f(0.515f,0.98f);

       glVertex2f(0.5f,1.0f);
       glVertex2f(0.495f,0.98f);

       glVertex2f(0.48f,1.0f);
       glVertex2f(0.475f,0.98f);

       glVertex2f(0.46f,1.0f);
       glVertex2f(0.455f,0.98f);

       glVertex2f(0.44f,1.0f);
       glVertex2f(0.435f,0.98f);

       glVertex2f(0.42f,1.0f);
       glVertex2f(0.415f,0.98f);

       glVertex2f(0.4f,1.0f);
       glVertex2f(0.395f,0.98f);

       glVertex2f(0.38f,1.0f);
       glVertex2f(0.375f,0.98f);

       glVertex2f(0.36f,1.0f);
       glVertex2f(0.355f,0.98f);

       glVertex2f(0.34f,1.0f);
       glVertex2f(0.335f,0.98f);

       glVertex2f(0.32f,1.0f);
       glVertex2f(0.315f,0.98f);

       glVertex2f(0.3f,1.0f);
       glVertex2f(0.295f,0.98f);

       glVertex2f(0.28f,1.0f);
       glVertex2f(0.275f,0.98f);

       glVertex2f(0.26f,1.0f);
       glVertex2f(0.255,0.98f);

       glVertex2f(0.24f,1.0f);
       glVertex2f(0.235f,0.98f);

       glVertex2f(0.22f,1.0f);
       glVertex2f(0.215f,0.98f);

       glVertex2f(0.2f,1.0f);
       glVertex2f(0.195f,0.98f);

       glVertex2f(0.18f,1.0f);
       glVertex2f(0.175f,0.98f);

       glVertex2f(0.16f,1.0f);
       glVertex2f(0.155f,0.98f);

       glVertex2f(0.14f,1.0f);
       glVertex2f(0.135f,0.98f);

       glVertex2f(0.12f,1.0f);
       glVertex2f(0.115f,0.98f);

       glVertex2f(0.1f,1.0f);
       glVertex2f(0.095f,0.98f);

       glVertex2f(0.08f,1.0f);
       glVertex2f(0.075f,0.98f);

       glVertex2f(0.06f,1.0f);
       glVertex2f(0.055f,0.98f);

       glVertex2f(0.04f,1.0f);
       glVertex2f(0.035f,0.98f);

       glVertex2f(0.02f,1.0f);
       glVertex2f(0.015f,0.98f);

       glVertex2f(0.0f,1.0f);
       glVertex2f(-0.005f,0.98f);

       glVertex2f(-0.02f,1.0f);
       glVertex2f(-0.025f,0.98f);

       glVertex2f(-0.04f,1.0f);
       glVertex2f(-0.045f,0.98f);

       glVertex2f(-0.06f,1.0f);
       glVertex2f(-0.065f,0.98f);

       glVertex2f(-0.08f,1.0f);
       glVertex2f(-0.085f,0.98f);

       glVertex2f(-0.1f,1.0f);
       glVertex2f(-0.105f,0.98f);

       glVertex2f(-0.12f,1.0f);
       glVertex2f(-0.125f,0.98f);

       glVertex2f(-0.14f,1.0f);
       glVertex2f(-0.145f,0.98f);

       glVertex2f(-0.16f,1.0f);
       glVertex2f(-0.165f,0.98f);

       glVertex2f(-0.18f,1.0f);
       glVertex2f(-0.185f,0.98f);

       glVertex2f(-0.2f,1.0f);
       glVertex2f(-0.205f,0.98f);

       glVertex2f(-0.22f,1.0f);
       glVertex2f(-0.225f,0.98f);

       glVertex2f(-0.24f,1.0f);
       glVertex2f(-0.245f,0.98f);

       glVertex2f(-0.26f,1.0f);
       glVertex2f(-0.265f,0.98f);

       glVertex2f(-0.28f,1.0f);
       glVertex2f(-0.285f,0.98f);

       glVertex2f(-0.3f,1.0f);
       glVertex2f(-0.305f,0.98f);

       glVertex2f(-0.32f,1.0f);
       glVertex2f(-0.325f,0.98f);

       glVertex2f(-0.34f,1.0f);
       glVertex2f(-0.345f,0.98f);

       glVertex2f(-0.36f,1.0f);
       glVertex2f(-0.365f,0.98f);

       glVertex2f(-0.38f,1.0f);
       glVertex2f(-0.385f,0.98f);

       glVertex2f(-0.4f,1.0f);
       glVertex2f(-0.405f,0.98f);

       glVertex2f(-0.42f,1.0f);
       glVertex2f(-0.425f,0.98f);

       glVertex2f(-0.44f,1.0f);
       glVertex2f(-0.445f,0.98f);

       glVertex2f(-0.46f,1.0f);
       glVertex2f(-0.465f,0.98f);

       glVertex2f(-0.48f,1.0f);
       glVertex2f(-0.485f,0.98f);

       glVertex2f(-0.5f,1.0f);
       glVertex2f(-0.505f,0.98f);

       glVertex2f(-0.52f,1.0f);
       glVertex2f(-0.525f,0.98f);

       glVertex2f(-0.54f,1.0f);
       glVertex2f(-0.545f,0.98f);

       glVertex2f(-0.56f,1.0f);
       glVertex2f(-0.565f,0.98f);

       glVertex2f(-0.58f,1.0f);
       glVertex2f(-0.585f,0.98f);

       glVertex2f(-0.6f,1.0f);
       glVertex2f(-0.605f,0.98f);

       glVertex2f(-0.62f,1.0f);
       glVertex2f(-0.625f,0.98f);

       glVertex2f(-0.64f,1.0f);
       glVertex2f(-0.645f,0.98f);

       glVertex2f(-0.66f,1.0f);
       glVertex2f(-0.665f,0.98f);

       glVertex2f(-0.68f,1.0f);
       glVertex2f(-0.685f,0.98f);

       glVertex2f(-0.7f,1.0f);
       glVertex2f(-0.705f,0.98f);

       glVertex2f(-0.72f,1.0f);
       glVertex2f(-0.725f,0.98f);

       glVertex2f(-0.74f,1.0f);
       glVertex2f(-0.745f,0.98f);

       glVertex2f(-0.76f,1.0f);
       glVertex2f(-0.765f,0.98f);

       glVertex2f(-0.78f,1.0f);
       glVertex2f(-0.785f,0.98f);

       glVertex2f(-0.8f,1.0f);
       glVertex2f(-0.805f,0.98f);

       glVertex2f(-0.82f,1.0f);
       glVertex2f(-0.825f,0.98f);

       glVertex2f(-0.84f,1.0f);
       glVertex2f(-0.845f,0.98f);

       glVertex2f(-0.86f,1.0f);
       glVertex2f(-0.865f,0.98f);

       glVertex2f(-0.88f,1.0f);
       glVertex2f(-0.885f,0.98f);

       glVertex2f(-0.9f,1.0f);
       glVertex2f(-0.905f,0.98f);

       glVertex2f(-0.92f,1.0f);
       glVertex2f(-0.925f,0.98f);

       glVertex2f(-0.94f,1.0f);
       glVertex2f(-0.945f,0.98f);

       glVertex2f(-0.96f,1.0f);
       glVertex2f(-0.965f,0.98f);

       glVertex2f(-0.98f,1.0f);
       glVertex2f(-0.985f,0.98f);

       glVertex2f(-0.995f,1.0f);
       glVertex2f(-1.0f,0.98f);
    glEnd();
}

void grass()
{
    glLineWidth(2.3);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.4f, 0.0f);
        glVertex2f(1.0f, 0.301f);
        glVertex2f(-1.0f, 0.301f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.35f, 0.0f);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f(-0.95f, 0.33f);
        glVertex2f(-0.9f, 0.3f);

        glVertex2f(-0.9f, 0.3f);
        glVertex2f(-0.85f, 0.33f);
        glVertex2f(-0.8f, 0.3f);

        glVertex2f(-0.8f, 0.3f);
        glVertex2f(-0.75f, 0.33f);
        glVertex2f(-0.7f, 0.3f);

        glVertex2f(-0.7f, 0.3f);
        glVertex2f(-0.65f, 0.33f);
        glVertex2f(-0.6f, 0.3f);

        glVertex2f(-0.6f, 0.3f);
        glVertex2f(-0.55f, 0.33f);
        glVertex2f(-0.5f, 0.3f);

        glVertex2f(-0.5f, 0.3f);
        glVertex2f(-0.45f, 0.33f);
        glVertex2f(-0.4f, 0.3f);

        glVertex2f(-0.4f, 0.3f);
        glVertex2f(-0.35f, 0.33f);
        glVertex2f(-0.3f, 0.3f);

        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.25f, 0.33f);
        glVertex2f(-0.2f, 0.3f);

        glVertex2f(-0.2f, 0.3f);
        glVertex2f(-0.15f, 0.33f);
        glVertex2f(-0.1f, 0.3f);

        glVertex2f(-0.1f, 0.3f);
        glVertex2f(-0.05f, 0.33f);
        glVertex2f(0.0f, 0.3f);

        glVertex2f(0.0f, 0.3f);
        glVertex2f(0.05f, 0.33f);
        glVertex2f(0.1f, 0.3f);

        glVertex2f(0.1f, 0.3f);
        glVertex2f(0.15f, 0.33f);
        glVertex2f(0.2f, 0.3f);

        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.25f, 0.33f);
        glVertex2f(0.3f, 0.3f);

        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.35f, 0.33f);
        glVertex2f(0.4f, 0.3f);

        glVertex2f(0.4f, 0.3f);
        glVertex2f(0.45f, 0.33f);
        glVertex2f(0.5f, 0.3f);

        glVertex2f(0.5f, 0.3f);
        glVertex2f(0.55f, 0.33f);
        glVertex2f(0.6f, 0.3f);

        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.65f, 0.33f);
        glVertex2f(0.7f, 0.3f);

        glVertex2f(0.7f, 0.3f);
        glVertex2f(0.75f, 0.33f);
        glVertex2f(0.8f, 0.3f);

        glVertex2f(0.8f, 0.3f);
        glVertex2f(0.85f, 0.33f);
        glVertex2f(0.9f, 0.3f);

        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.95f, 0.33f);
        glVertex2f(1.0f, 0.3f);
    glEnd();
}

void grass2()
{
    glBegin(GL_POLYGON);
       glColor3f(0.05f, 1.0f, 0.05f);
       glVertex2f(1.0f, 0.2967f);
       glVertex2f(-1.0f, 0.2967f);
       glColor3f(0.0f, 0.08f, 0.0f);
       glVertex2f(-1.0f, -1.0f);
       glVertex2f(1.0f, -1.0f);
    glEnd();
}

void river()
{
   glBegin(GL_POLYGON);
       glColor3f(0.65f, 0.92f, 0.98f);
       glVertex2f(1.0f, 0.296f);
       glVertex2f(0.34f, 0.296f);
       glVertex2f(0.26f, 0.17f);
       glVertex2f(0.2f,  0.0f);
       glVertex2f(0.16f, -0.16f);
       glVertex2f(0.16f, -0.24f);
       glVertex2f(0.22f, -0.42f);
       glVertex2f(0.34f, -0.58f);
       glVertex2f(0.51f, -0.73f);
       glVertex2f(0.7f, -0.79f);
       glVertex2f(1.0f, -0.8f);
    glEnd();
}

void tress()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.03f, 0.62f, 0.376f);
        glVertex2f(-0.905f, 0.00f);
        glVertex2f(-0.755f, 0.00f);
        glVertex2f(-0.83f, 0.4f);
    glEnd();

    glLineWidth(2.3f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.83f, 0.32f);
        glVertex2f(-0.83f, -0.04f);

        glVertex2f(-0.83f, 0.04f);
        glVertex2f(-0.87f, 0.1f);

        glVertex2f(-0.83f, 0.16f);
        glVertex2f(-0.858f, 0.22f);

        glVertex2f(-0.83f, 0.09f);
        glVertex2f(-0.792f, 0.15f);

        glVertex2f(-0.83f, 0.2f);
        glVertex2f(-0.81f, 0.26f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.03f, 0.62f, 0.376f);
        glVertex2f(-0.215f, 0.1f);
        glVertex2f(-0.365f, 0.1f);
        glVertex2f(-0.29f, 0.45f);
    glEnd();

    glLineWidth(2.3f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.29f, 0.048f);
        glVertex2f(-0.29f, 0.38f);

        glVertex2f(-0.29f, 0.15f);
        glVertex2f(-0.33f, 0.21f);

        glVertex2f(-0.29f, 0.24f);
        glVertex2f(-0.313f, 0.3f);

        glVertex2f(-0.29f, 0.2f);
        glVertex2f(-0.26f, 0.26f);

        glVertex2f(-0.29f, 0.29f);
        glVertex2f(-0.274f, 0.34f);

        glVertex2f(-0.29f, 0.12f);
        glVertex2f(-0.245f, 0.18f);
    glEnd();
}

void ghost_house()
{
    //ground floor
    glBegin(GL_POLYGON);
        glColor3f(0.25f, 0.0f, 0.29f);
        glVertex2f(-0.86f, 0.02f);
        glVertex2f(-0.8f, 0.2f);
        glVertex2f(-0.36f, 0.2f);
        glVertex2f(-0.3f, 0.02f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.67f, 0.19f, 0.67f);
        glVertex2f(-0.81f, 0.02f);
        glVertex2f(-0.78f, -0.17f);
        glVertex2f(-0.382f, -0.17f);
        glVertex2f(-0.35f, 0.02f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.25f, 0.0f, 0.29f);
        glVertex2f(-0.78f, -0.17f);
        glVertex2f(-0.382f, -0.17f);
        glVertex2f(-0.378f, -0.2f);
        glVertex2f(-0.784f, -0.2f);
    glEnd();

    //top floor
    glBegin(GL_POLYGON);
        glColor3f(0.2f, 0.0f, 0.2f);
        glVertex2f(-0.72f, 0.2f);
        glVertex2f(-0.723f, 0.25f);
        glVertex2f(-0.437f, 0.25f);
        glVertex2f(-0.44f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.25f, 0.0f, 0.29f);
        glVertex2f(-0.7f, 0.32f);
        glVertex2f(-0.67f, 0.4f);
        glVertex2f(-0.49f, 0.4f);
        glVertex2f(-0.46f, 0.32f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.7f, 0.2f, 0.7f);
        glVertex2f(-0.68f, 0.32f);
        glVertex2f(-0.67f, 0.25f);
        glVertex2f(-0.49f, 0.25f);
        glVertex2f(-0.48f, 0.32f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.7f, 0.2f, 0.7f);
        glVertex2f(-0.62f, 0.4f);
        glVertex2f(-0.62f, 0.46f);
        glVertex2f(-0.54f, 0.46f);
        glVertex2f(-0.54f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.0f, 0.2f);
        glVertex2f(-0.58f, 0.52f);
        glVertex2f(-0.635f, 0.46f);
        glVertex2f(-0.525f, 0.46f);
    glEnd();

    //side-tomb
    glBegin(GL_POLYGON);
        glColor3f(0.7f, 0.2f, 0.7f);
        glVertex2f(-0.73f, 0.2f);
        glVertex2f(-0.73f, 0.36f);
        glVertex2f(-0.79f, 0.36f);
        glVertex2f(-0.79f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.0f, 0.2f);
        glVertex2f(-0.76f, 0.44f);
        glVertex2f(-0.71f, 0.36f);
        glVertex2f(-0.81f, 0.36f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.6f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.775f, 0.31f);
        glVertex2f(-0.76f, 0.318f);
        glVertex2f(-0.745f, 0.31f);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.745f, 0.25f);
        glVertex2f(-0.775f, 0.25f);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.76f, 0.318f);
        glVertex2f(-0.76f, 0.249f);

        glVertex2f(-0.745f, 0.282f);
        glVertex2f(-0.775f, 0.282f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.7f, 0.2f, 0.7f);
        glVertex2f(-0.43f, 0.2f);
        glVertex2f(-0.43f, 0.405f);
        glVertex2f(-0.37f, 0.405f);
        glVertex2f(-0.37f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.0f, 0.2f);
        glVertex2f(-0.4f, 0.48f);
        glVertex2f(-0.45f, 0.405f);
        glVertex2f(-0.35f, 0.405f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.6f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.415f, 0.34f);
        glVertex2f(-0.4f, 0.35f);
        glVertex2f(-0.385f, 0.34f);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.385f, 0.27f);
        glVertex2f(-0.415f, 0.27f);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.4f, 0.35f);
        glVertex2f(-0.4f, 0.27f);

        glVertex2f(-0.385f, 0.307f);
        glVertex2f(-0.415f, 0.307f);
    glEnd();

    //doors & windows
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.568f, 0.415f);
        glVertex2f(-0.568f, 0.443f);
        glVertex2f(-0.592f, 0.443f);
        glVertex2f(-0.592f, 0.415f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.592f, 0.303f);
        glVertex2f(-0.568f, 0.303f);

        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.568f, 0.267f);
        glVertex2f(-0.592f, 0.267f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.628f, 0.267f);
        glVertex2f(-0.652f, 0.267f);

        if (houseLight == false)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.652f, 0.303f);
        glVertex2f(-0.628f, 0.303f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.508f, 0.267f);
        glVertex2f(-0.532f, 0.267f);

        if (houseLight == false)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.532f, 0.303f);
        glVertex2f(-0.508f, 0.303f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.6f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.54f, -0.015f);
        glVertex2f(-0.62f, -0.015f);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        glVertex2f(-0.62f, -0.17f);
        glVertex2f(-0.54f, -0.17f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.6f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.95f, 0.0f, 0.0f);
        }
        glVertex2f(-0.414f, -0.03f);
        glVertex2f(-0.47f, -0.03f);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.95f, 0.0f, 0.0f);
        }
        glVertex2f(-0.47f, -0.105f);
        glVertex2f(-0.414f, -0.105f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.6f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.95, 0.0f, 0.0f);
        }
        glVertex2f(-0.7f, -0.03f);
        glVertex2f(-0.756f, -0.03f);
        glColor3f(1.0f, 1.0f, 0.0f);
        if (houseLight == false)
        {
            glColor3f(0.95f, 0.0f, 0.0f);
        }
        glVertex2f(-0.756f, -0.105f);
        glVertex2f(-0.7f, -0.105f);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.7f, -0.0675f);
        glVertex2f(-0.756, -0.0675f);

        glVertex2f(-0.728f, -0.105f);
        glVertex2f(-0.728f, -0.03f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.47f, -0.0675f);
        glVertex2f(-0.414f, -0.0675f);

        glVertex2f(-0.442f, -0.105f);
        glVertex2f(-0.442f, -0.03f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.723f, 0.25f);
        glVertex2f(-0.437f, 0.25f);

        glVertex2f(-0.718f, 0.25f);
        glVertex2f(-0.718f, 0.28f);

        glVertex2f(-0.705f, 0.25f);
        glVertex2f(-0.705f, 0.28f);

        glVertex2f(-0.692f, 0.25f);
        glVertex2f(-0.692f, 0.28f);

        glVertex2f(-0.679f, 0.25f);
        glVertex2f(-0.679f, 0.28f);

        glVertex2f(-0.666f, 0.25f);
        glVertex2f(-0.666f, 0.28f);

        glVertex2f(-0.653f, 0.25f);
        glVertex2f(-0.653f, 0.28f);

        glVertex2f(-0.64f, 0.25f);
        glVertex2f(-0.64f, 0.28f);

        glVertex2f(-0.627f, 0.25f);
        glVertex2f(-0.627f, 0.28f);

        glVertex2f(-0.614f, 0.25f);
        glVertex2f(-0.614f, 0.28f);

        glVertex2f(-0.601f, 0.25f);
        glVertex2f(-0.601f, 0.28f);

        glVertex2f(-0.588f, 0.25f);
        glVertex2f(-0.588f, 0.28f);

        glVertex2f(-0.575f, 0.25f);
        glVertex2f(-0.575f, 0.28f);

        glVertex2f(-0.562f, 0.25f);
        glVertex2f(-0.562f, 0.28f);

        glVertex2f(-0.548f, 0.25f);
        glVertex2f(-0.548f, 0.28f);

        glVertex2f(-0.534f, 0.25f);
        glVertex2f(-0.534f, 0.28f);

        glVertex2f(-0.52f, 0.25f);
        glVertex2f(-0.52f, 0.28f);

        glVertex2f(-0.507f, 0.25f);
        glVertex2f(-0.507f, 0.28f);

        glVertex2f(-0.494f, 0.25f);
        glVertex2f(-0.494f, 0.28f);

        glVertex2f(-0.481f, 0.25f);
        glVertex2f(-0.481f, 0.28f);

        glVertex2f(-0.468f, 0.25f);
        glVertex2f(-0.468f, 0.28f);

        glVertex2f(-0.455f, 0.25f);
        glVertex2f(-0.455f, 0.28f);

        glVertex2f(-0.442f, 0.25f);
        glVertex2f(-0.442f, 0.28f);
    glEnd();
}

void ghost_ship()
{
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.65f, 0.0f);
        glVertex2f(0.34f, -0.26f);
        glVertex2f(0.94f, -0.26f);
        glColor3f(0.59f, 0.22f, 0.13f);
        glVertex2f(0.88f, -0.46f);
        glVertex2f(0.405f, -0.46f);
    glEnd();

     glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.7f, 0.0f);
        glVertex2f(0.92f, -0.26f);
        glVertex2f(0.72f, -0.26f);
        glVertex2f(0.72f, -0.14f);
        glVertex2f(0.92f, -0.14f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.7f, 0.0f);
        glVertex2f(0.39f, -0.26f);
        glVertex2f(0.52f, -0.26f);
        glVertex2f(0.52f, -0.19f);
        glVertex2f(0.39f, -0.19f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.41f, -0.245f);
        glVertex2f(0.44f, -0.245f);
        glVertex2f(0.44f, -0.21f);
        glVertex2f(0.41f, -0.21f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.47f, -0.245f);
        glVertex2f(0.5f, -0.245f);
        glVertex2f(0.5f, -0.21f);
        glVertex2f(0.47f, -0.21f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.74f, -0.245f);
        glVertex2f(0.77f, -0.245f);
        glVertex2f(0.77f, -0.215f);
        glVertex2f(0.74f, -0.215f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.805f, -0.245f);
        glVertex2f(0.835f, -0.245f);
        glVertex2f(0.835f, -0.215f);
        glVertex2f(0.805f, -0.215f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.87f, -0.245f);
        glVertex2f(0.9f, -0.245f);
        glVertex2f(0.9f, -0.215f);
        glVertex2f(0.87f, -0.215f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.74f, -0.155f);
        glVertex2f(0.77f, -0.155f);
        glVertex2f(0.77f, -0.185f);
        glVertex2f(0.74f, -0.185f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.805f, -0.155f);
        glVertex2f(0.835f, -0.155f);
        glVertex2f(0.835f, -0.185f);
        glVertex2f(0.805f, -0.185f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.87f, -0.155f);
        glVertex2f(0.9f, -0.155f);
        glVertex2f(0.9f, -0.185f);
        glVertex2f(0.87f, -0.185f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.4f, 0.22f, 0.13f);
        glVertex2f(0.34f, -0.26f);
        glVertex2f(0.94f, -0.26f);
        glVertex2f(0.52f, -0.19f);
        glVertex2f(0.39f, -0.19f);
        glVertex2f(0.72f, -0.14f);
        glVertex2f(0.92f, -0.14f);
        glVertex2f(0.72f, -0.203f);
        glVertex2f(0.92f, -0.203f);
        glVertex2f(0.72f, -0.196f);
        glVertex2f(0.92f, -0.196f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(0.58f, -0.31f);
        for(int i = 0; i <= 400 ; i++)
        {
            glVertex2f( 0.58 + (0.012*cos(i*((2*3.1416)/400))),
                        -0.31 + (0.012*sin(i*((2*3.1416)/400)))
                       );
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(0.68f, -0.31f);
        for(int i = 0; i <= 400 ; i++)
        {
            glVertex2f( 0.68 + (0.012*cos(i*((2*3.1416)/400))),
                        -0.31 + (0.012*sin(i*((2*3.1416)/400)))
                       );
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(0.78f, -0.31f);
        for(int i = 0; i <= 400 ; i++)
        {
            glVertex2f( 0.78 + (0.012*cos(i*((2*3.1416)/400))),
                        -0.31 + (0.012*sin(i*((2*3.1416)/400)))
                       );
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(0.432f, -0.294f);
        for(int i = 0; i <= 400 ; i++)
        {
            glVertex2f( 0.43 + (0.008*cos(i*((2*3.1416)/400))),
                        -0.29 + (0.008*sin(i*((2*3.1416)/400)))
                       );
        }
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.432f, -0.29f);
        glVertex2f(0.432f, -0.41f);

        glVertex2f(0.432f, -0.41f);
        glVertex2f(0.414f, -0.375f);

        glVertex2f(0.432f, -0.41f);
        glVertex2f(0.45f, -0.375f);

        glVertex2f(0.419f, -0.34f);
        glVertex2f(0.444f, -0.34f);

        glVertex2f(0.419f, -0.33f);
        glVertex2f(0.444f, -0.33f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.414f, -0.375f);
        for(int i = 0; i <= 100 ; i++)
        {
            glVertex2f( 0.414 + (0.005*cos(i*((2*3.1416)/100))),
                        -0.375 + (0.005*sin(i*((2*3.1416)/100)))
                       );
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.45f, -0.375f);
        for(int i = 0; i <= 100 ; i++)
        {
            glVertex2f( 0.45 + (0.005*cos(i*((2*3.1416)/100))),
                        -0.375 + (0.005*sin(i*((2*3.1416)/100)))
                       );
        }
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.675f, -0.43f);
        glVertex2f(0.725f, -0.46f);

        glVertex2f(0.725f, -0.43f);
        glVertex2f(0.675f, -0.46f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.7f, -0.4f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( 0.7 + (0.023*cos(i*((2*3.1416)/200))),
                        -0.4 + (0.023*sin(i*((2*3.1416)/200)))
                       );
        }
    glEnd();

    glPointSize(3);
    glBegin(GL_POINTS);
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex2f(0.69f, -0.4f);
       glVertex2f(0.71f, -0.4f);
    glEnd();
}

void ship_flag()
{
    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.22f, 0.13f);
        glVertex2f(0.37f, 0.022f);
        glVertex2f(0.37f, 0.01f);
        glVertex2f(0.56f, 0.01f);
        glVertex2f(0.56f, 0.022f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.22f, 0.13f);
        glVertex2f(0.46f, -0.19f);
        glVertex2f(0.46f, 0.14f);
        glVertex2f(0.47f, 0.14f);
        glVertex2f(0.47f, -0.19f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.22f, 0.13f);
        glVertex2f(0.681f, -0.26f);
        glVertex2f(0.681f, 0.18f);
        glVertex2f(0.67f, 0.18f);
        glVertex2f(0.67f, -0.26f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.22f, 0.13f);
        glVertex2f(0.58f, 0.098f);
        glVertex2f(0.58f, 0.086f);
        glVertex2f(0.77f, 0.086f);
        glVertex2f(0.77f, 0.098f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.22f, 0.13f);
        glVertex2f(0.6f, -0.08f);
        glVertex2f(0.61f, -0.092f);
        glVertex2f(0.755f, -0.092f);
        glVertex2f(0.755f, -0.08f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.91f, 0.86f, 0.68f);
        glVertex2f(0.385f, 0.012f);
        glVertex2f(0.385f, -0.1f);
        glVertex2f(0.41f, 0.012f);

        glVertex2f(0.48f, 0.012f);
        glVertex2f(0.5f, -0.07f);
        glVertex2f(0.52f, 0.012f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.91f, 0.86f, 0.68f);
        glVertex2f(0.418f, 0.012f);
        glVertex2f(0.426f, -0.02f);
        glVertex2f(0.436f, 0.00f);
        glVertex2f(0.446f, -0.04f);
        glVertex2f(0.452f, 0.012f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.91f, 0.86f, 0.68f);
        glVertex2f(0.6f, 0.088f);
        glVertex2f(0.62f, -0.05f);
        glVertex2f(0.65f, 0.088f);

        glVertex2f(0.672f, 0.088f);
        glVertex2f(0.687f, 0.00f);
        glVertex2f(0.71f, 0.088f);

        glVertex2f(0.717f, 0.088f);
        glVertex2f(0.764f, -0.06f);
        glVertex2f(0.761f, 0.088f);
    glEnd();
}

void grave1()
{
    glBegin(GL_POLYGON);
       glColor3f(0.1f, 0.1f, 0.1f);
       glVertex2f(0.66f, 0.55f);
       glVertex2f(0.64f, 0.51f);
       glVertex2f(0.68f, 0.3f);
       glVertex2f(0.72f, 0.3f);
       glVertex2f(0.76f, 0.51f);
       glVertex2f(0.74f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.665f, 0.475f);
        glVertex2f(0.665f, 0.46f);
        glVertex2f(0.735f, 0.46f);
        glVertex2f(0.735f, 0.475f);
    glEnd();

     glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.695f, 0.51f);
        glVertex2f(0.695f, 0.38f);
        glVertex2f(0.705f, 0.38f);
        glVertex2f(0.705f, 0.51f);
    glEnd();
}

void grave2()
{
    glBegin(GL_POLYGON);
       glColor3f(0.1f, 0.1f, 0.1f);
       glVertex2f(0.49f, 0.51f);
       glVertex2f(0.47f, 0.47f);
       glVertex2f(0.505f, 0.3f);
       glVertex2f(0.535f, 0.3f);
       glVertex2f(0.57f, 0.47f);
       glVertex2f(0.55f, 0.51f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.49f, 0.45f);
        glVertex2f(0.49f, 0.44f);
        glVertex2f(0.55f, 0.44f);
        glVertex2f(0.55f, 0.45f);
    glEnd();

     glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.515f, 0.48f);
        glVertex2f(0.515f, 0.37f);
        glVertex2f(0.525f, 0.37f);
        glVertex2f(0.525f, 0.48f);
    glEnd();
}

void grave3()
{
    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.36f, 0.44f);
        glVertex2f(0.36f, 0.42f);
        glVertex2f(0.43f, 0.43f);
        glVertex2f(0.43f, 0.45f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.388f, 0.475f);
        glVertex2f(0.391f, 0.3f);
        glVertex2f(0.399f, 0.3f);
        glVertex2f(0.402f, 0.475f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.585f, 0.38f);
        glVertex2f(0.585f, 0.364f);
        glVertex2f(0.63f, 0.364f);
        glVertex2f(0.63f, 0.38f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.602f, 0.4f);
        glVertex2f(0.602f, 0.3f);
        glVertex2f(0.613f, 0.3f);
        glVertex2f(0.613f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.78f, 0.44f);
        glVertex2f(0.78f, 0.422f);
        glVertex2f(0.86f, 0.422f);
        glVertex2f(0.86f, 0.44f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.812f, 0.475f);
        glVertex2f(0.8164f, 0.3f);
        glVertex2f(0.8236f, 0.3f);
        glVertex2f(0.828f, 0.475f);
    glEnd();
}

void grave4()
{
    glBegin(GL_POLYGON);
       glColor3f(0.07f, 0.07f, 0.07f);
       glVertex2f(0.9f, 0.3f);
       glVertex2f(0.9f, 0.35f);
       glVertex2f(0.917f, 0.375f);
       glVertex2f(0.933f, 0.375f);
       glVertex2f(0.95f, 0.35f);
       glVertex2f(0.95f, 0.3f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.07f, 0.07f, 0.07f);
        glVertex2f(0.918f, 0.375f);
        glVertex2f(0.918f, 0.45f);
        glVertex2f(0.932f, 0.45f);
        glVertex2f(0.932f, 0.375f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.07f, 0.07f, 0.07f);
        glVertex2f(0.904f, 0.405f);
        glVertex2f(0.904f, 0.417f);
        glVertex2f(0.946f, 0.417f);
        glVertex2f(0.946f, 0.405f);
    glEnd();
}

void grave5()
{
    glBegin(GL_POLYGON);
       glColor3f(0.05f, 0.05f, 0.05f);
       glVertex2f(-0.9f, -0.95f);
       glVertex2f(-0.9f, -0.84f);
       glVertex2f(-0.866f, -0.785f);
       glVertex2f(-0.834f, -0.785f);
       glVertex2f(-0.8f, -0.84f);
       glVertex2f(-0.8f, -0.95f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.05f, 0.05f, 0.05f);
        glVertex2f(-0.864f, -0.785f);
        glVertex2f(-0.864f, -0.62f);
        glVertex2f(-0.836f, -0.62f);
        glVertex2f(-0.836f, -0.785f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.05f, 0.05f, 0.05f);
        glVertex2f(-0.893f, -0.73f);
        glVertex2f(-0.893f, -0.693f);
        glVertex2f(-0.807f, -0.693f);
        glVertex2f(-0.807f, -0.73f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
       glVertex2f(-0.67f, -0.98f);
       for(int i = 0; i <= 100 ; i++)
       {
             glVertex2f( -0.67 + (0.12*cos(i*((2*3.1416)/100))),
                        -0.98 + (0.06*sin(i*((2*3.1416)/100)))
                       );
            if (i > 50)
            {
                    glColor3f(0.05f, 0.05f, 0.05f);
            }
            else     glColor3f(0.5f, 0.05f, 0.05f);
        }
    glEnd();
}

void pumpkin1()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(-0.63f, -0.225f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( -0.63 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.225 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.624f, -0.174f);
        glVertex2f(-0.624f, -0.14f);
        glVertex2f(-0.636f, -0.14f);
        glVertex2f(-0.636f, -0.174f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.65f, -0.194f);
        glVertex2f(-0.66f, -0.21f);
        glVertex2f(-0.64f, -0.21f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.61f, -0.194f);
        glVertex2f(-0.6f, -0.21f);
        glVertex2f(-0.62f, -0.21f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.63f, -0.205f);
        glVertex2f(-0.624f, -0.22f);
        glVertex2f(-0.636f, -0.22f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.658f, -0.252f);
        glVertex2f(-0.652f, -0.233f);

        glVertex2f(-0.652f, -0.233f);
        glVertex2f(-0.644f, -0.26f);

        glVertex2f(-0.644f, -0.26f);
        glVertex2f(-0.636f, -0.233f);

        glVertex2f(-0.636f, -0.233f);
        glVertex2f(-0.628f, -0.26f);

        glVertex2f(-0.628f, -0.26f);
        glVertex2f(-0.62f, -0.233f);

        glVertex2f(-0.62f, -0.233f);
        glVertex2f(-0.612f, -0.26f);

        glVertex2f(-0.612f, -0.26f);
        glVertex2f(-0.604f, -0.233f);

        glVertex2f(-0.604f, -0.233f);
        glVertex2f(-0.598f, -0.252f);
    glEnd();
}

void pumpkin2()
{
  glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f, 0.46f, 0.094f);
            glVertex2f(-0.0024f, -0.34305f);
            glVertex2f(0.01395f, -0.34305f);
            glVertex2f(0.03135f, -0.34305f);
            glVertex2f(0.0513f, -0.3318f);
            glVertex2f(0.06495f, -0.3111f);
            glVertex2f(0.07035f, -0.29505f);
            glVertex2f(0.0756f, -0.27135f);
            glVertex2f(0.0756f, -0.24405f);
            glVertex2f(0.075f, -0.2127f);
            glVertex2f(0.07035f, -0.19185f);
            glVertex2f(0.0606f, -0.16755f);
            glVertex2f(0.0453f, -0.14985f);
            glVertex2f(0.03405f, -0.14745f);
            glVertex2f(0.0207f, -0.14385f);
            glVertex2f(0.00195f, -0.1404f);
            glVertex2f(-0.0207f, -0.14385f);
            glVertex2f(-0.04005f, -0.15165f);
            glVertex2f(-0.04995f, -0.16995f);
            glVertex2f(-0.05805f, -0.19125f);
            glVertex2f(-0.06165f, -0.2085f);
            glVertex2f(-0.0633f, -0.22755f);
            glVertex2f(-0.06465f, -0.24885f);
            glVertex2f(-0.06195f, -0.2802f);
            glVertex2f(-0.0543f, -0.30285f);
            glVertex2f(-0.0444f, -0.32415f);
            glVertex2f(-0.03105f, -0.339f);
            glVertex2f(-0.01635f, -0.34305f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
            glColor3ub(10,199,48);
            glVertex2f(-0.00495f,  -0.13365f);
            glVertex2f(-0.006f,  -0.14085f);
            glVertex2f(-0.0087f,  -0.1533f);
            glVertex2f(-0.01095f,  -0.1551f);
            glVertex2f(-0.006f,  -0.1557f);
            glVertex2f(-0.00135f,  -0.1539f);
            glVertex2f(0.00195f,  -0.15675f);
            glVertex2f(0.0057f,  -0.15855f);
            glVertex2f(0.0117f,  -0.15855f);
            glVertex2f(0.01935f,  -0.1545f);
            glVertex2f(0.01395f,  -0.1497f);
            glVertex2f(0.01395f,  -0.13245f);
            glVertex2f(0.01005f,  -0.11475f);
            glVertex2f(0.00735f,  -0.11115f);
            glVertex2f(-0.0006f,  -0.11595f);
            glVertex2f(-0.006f,  -0.11775f);
            glVertex2f(-0.00705f,  -0.1218f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            if (redEyePumpkin == true)
            {
                glColor3f(0.8f, 0.0f, 0.0f);
            }
            glVertex2f(-0.0144f,  -0.22165f);
            glVertex2f(-0.01905f,  -0.15755f);
            glVertex2f(-0.0387f,  -0.21315f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            if (redEyePumpkin == true)
            {
                glColor3f(0.8f, 0.0f, 0.0f);
            }
            glVertex2f(0.0174f,  -0.21675f);
            glVertex2f(0.0267f,  -0.16575f);
            glVertex2f(0.0414f,  -0.21435f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(-0.00735f,  -0.23925f);
            glVertex2f(0.01005f,  -0.23925f);
            glVertex2f(0.00135f,  -0.20835f);
    glEnd();

   glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            if (redEyePumpkin == true)
            {
                glColor3f(1.0f, 0.0f, 0.0f);
            }
            glVertex2f(0.0057f, -0.26655f);
            glVertex2f(0.018f, -0.2655f);
            glVertex2f(0.0183f, -0.27735f);
            glVertex2f(0.0246f, -0.27435f);
            glVertex2f(0.02565f, -0.2631f);
            glVertex2f(0.0414f, -0.25125f);
            glVertex2f(0.0567f, -0.2316f);
            glVertex2f(0.0483f, -0.2649f);
            glVertex2f(0.0297f, -0.291f);
            glVertex2f(0.0096f, -0.29745f);
            glVertex2f(-0.00735f, -0.2886f);
            glVertex2f(-0.0057f, -0.279f);
            glVertex2f(-0.01665f, -0.27495f);
            glVertex2f(-0.01995f, -0.29205f);
            glVertex2f(-0.03405f, -0.279f);
            glVertex2f(-0.04305f, -0.2583f);
            glVertex2f(-0.04095f, -0.2358f);
            glVertex2f(-0.0336f, -0.2547f);
            glVertex2f(-0.01605f, -0.2661f);
    glEnd();
}

void pumpkin3()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(-0.5f, -0.525f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( -0.5 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.525 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.494f, -0.473f);
        glVertex2f(-0.494f, -0.44f);
        glVertex2f(-0.506f, -0.44f);
        glVertex2f(-0.506f, -0.473f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.52f, -0.494f);
        glVertex2f(-0.53f, -0.51f);
        glVertex2f(-0.51f, -0.51f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.48f, -0.494f);
        glVertex2f(-0.47f, -0.51f);
        glVertex2f(-0.49f, -0.51f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.5f, -0.505f);
        glVertex2f(-0.494f, -0.52f);
        glVertex2f(-0.506f, -0.52f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.528f, -0.552f);
        glVertex2f(-0.522f, -0.533f);

        glVertex2f(-0.522f, -0.533f);
        glVertex2f(-0.514f, -0.56f);

        glVertex2f(-0.514f, -0.56f);
        glVertex2f(-0.506f, -0.533f);

        glVertex2f(-0.506f, -0.533f);
        glVertex2f(-0.498f, -0.56f);

        glVertex2f(-0.498f, -0.56f);
        glVertex2f(-0.49f, -0.533f);

        glVertex2f(-0.49f, -0.533f);
        glVertex2f(-0.482f, -0.56f);

        glVertex2f(-0.482f, -0.56f);
        glVertex2f(-0.474f, -0.533f);

        glVertex2f(-0.474f, -0.533f);
        glVertex2f(-0.468f, -0.552f);
    glEnd();
}

void pumpkin4()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(-0.3f, -0.37f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( -0.3 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.37 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.294f, -0.318f);
        glVertex2f(-0.294f, -0.285f);
        glVertex2f(-0.306f, -0.285f);
        glVertex2f(-0.306f, -0.318f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.32f, -0.339f);
        glVertex2f(-0.33f, -0.355f);
        glVertex2f(-0.31f, -0.355f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.28f, -0.339f);
        glVertex2f(-0.27f, -0.355f);
        glVertex2f(-0.29f, -0.355f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.3f, -0.35f);
        glVertex2f(-0.294f, -0.365f);
        glVertex2f(-0.306f, -0.365f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.328f, -0.397f);
        glVertex2f(-0.322f, -0.378f);

        glVertex2f(-0.322f, -0.378f);
        glVertex2f(-0.314f, -0.405f);

        glVertex2f(-0.314f, -0.405f);
        glVertex2f(-0.306f, -0.378f);

        glVertex2f(-0.306f, -0.378f);
        glVertex2f(-0.298f, -0.405f);

        glVertex2f(-0.298f, -0.405f);
        glVertex2f(-0.29f, -0.378f);

        glVertex2f(-0.29f, -0.378f);
        glVertex2f(-0.282f, -0.405f);

        glVertex2f(-0.282f, -0.405f);
        glVertex2f(-0.274f, -0.378f);

        glVertex2f(-0.274f, -0.378f);
        glVertex2f(-0.268f, -0.397f);
    glEnd();
}

void pumpkin5()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(-0.12f, -0.525f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( -0.12 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.525 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.114f, -0.473f);
        glVertex2f(-0.114f, -0.44f);
        glVertex2f(-0.126f, -0.44f);
        glVertex2f(-0.126f, -0.473f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.14f, -0.494f);
        glVertex2f(-0.15f, -0.51f);
        glVertex2f(-0.13f, -0.51f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.1f, -0.494f);
        glVertex2f(-0.09f, -0.51f);
        glVertex2f(-0.11f, -0.51f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.12f, -0.505f);
        glVertex2f(-0.114f, -0.52f);
        glVertex2f(-0.126f, -0.52f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.148f, -0.552f);
        glVertex2f(-0.142f, -0.533f);

        glVertex2f(-0.142f, -0.533f);
        glVertex2f(-0.134f, -0.56f);

        glVertex2f(-0.134f, -0.56f);
        glVertex2f(-0.126f, -0.533f);

        glVertex2f(-0.126f, -0.533f);
        glVertex2f(-0.118f, -0.56f);

        glVertex2f(-0.118f, -0.56f);
        glVertex2f(-0.11f, -0.533f);

        glVertex2f(-0.11f, -0.533f);
        glVertex2f(-0.102f, -0.56f);

        glVertex2f(-0.102f, -0.56f);
        glVertex2f(-0.094f, -0.533f);

        glVertex2f(-0.094f, -0.533f);
        glVertex2f(-0.088f, -0.552f);
    glEnd();
}

void pumpkin6()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(-0.31f, -0.71f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( -0.31 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.71 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.304f, -0.658f);
        glVertex2f(-0.304f, -0.625f);
        glVertex2f(-0.316f, -0.625f);
        glVertex2f(-0.316f, -0.658f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.33f, -0.679f);
        glVertex2f(-0.34f, -0.695f);
        glVertex2f(-0.32f, -0.695f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(-0.29f, -0.679f);
        glVertex2f(-0.28f, -0.695f);
        glVertex2f(-0.30f, -0.695f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.31f, -0.69f);
        glVertex2f(-0.304f, -0.705f);
        glVertex2f(-0.316f, -0.705f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.338f, -0.737f);
        glVertex2f(-0.332f, -0.718f);

        glVertex2f(-0.332f, -0.718f);
        glVertex2f(-0.324f, -0.745f);

        glVertex2f(-0.324f, -0.745f);
        glVertex2f(-0.316f, -0.718f);

        glVertex2f(-0.316f, -0.718f);
        glVertex2f(-0.308f, -0.745f);

        glVertex2f(-0.308f, -0.745f);
        glVertex2f(-0.30f, -0.718f);

        glVertex2f(-0.30f, -0.718f);
        glVertex2f(-0.292f, -0.745f);

        glVertex2f(-0.292f, -0.745f);
        glVertex2f(-0.284f, -0.718f);

        glVertex2f(-0.284f, -0.718f);
        glVertex2f(-0.278f, -0.737f);
    glEnd();
}

void pumpkin7()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(0.07f, -0.71f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( 0.07 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.71 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(0.076f, -0.658f);
        glVertex2f(0.076f, -0.625f);
        glVertex2f(0.064f, -0.625f);
        glVertex2f(0.064f, -0.658f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(0.05f, -0.679f);
        glVertex2f(0.04f, -0.695f);
        glVertex2f(0.06f, -0.695f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(0.09f, -0.679f);
        glVertex2f(0.1f, -0.695f);
        glVertex2f(0.08f, -0.695f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(0.07f, -0.69f);
        glVertex2f(0.076f, -0.705f);
        glVertex2f(0.064f, -0.705f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(0.042f, -0.737f);
        glVertex2f(0.048f, -0.718f);

        glVertex2f(0.048f, -0.718f);
        glVertex2f(0.056f, -0.745f);

        glVertex2f(0.056f, -0.745f);
        glVertex2f(0.064f, -0.718f);

        glVertex2f(0.064f, -0.718f);
        glVertex2f(0.072f, -0.745f);

        glVertex2f(0.072f, -0.745f);
        glVertex2f(0.08f, -0.718f);

        glVertex2f(0.08f, -0.718f);
        glVertex2f(0.088f, -0.745f);

        glVertex2f(0.088f, -0.745f);
        glVertex2f(0.096f, -0.718f);

        glVertex2f(0.096f, -0.718f);
        glVertex2f(0.102f, -0.737f);
    glEnd();
}

void pumpkin8()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.46f, 0.094f);
        glVertex2f(0.28f, -0.83f);
        for(int i = 0; i <= 200 ; i++)
        {
            glVertex2f( 0.33 + (0.05*cos(i*((2*3.1416)/200))),
                        -0.83 + (0.055*sin(i*((2*3.1416)/200)))
                      );
        }
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(0.336f, -0.778f);
        glVertex2f(0.336f, -0.745f);
        glVertex2f(0.324f, -0.745f);
        glVertex2f(0.324f, -0.778f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(0.31f, -0.799f);
        glVertex2f(0.3f, -0.815f);
        glVertex2f(0.32f, -0.815f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        if (redEyePumpkin == true)
        {
            glColor3f(0.8f, 0.0f, 0.0f);
        }
        glVertex2f(0.35f, -0.799f);
        glVertex2f(0.36f, -0.815f);
        glVertex2f(0.34f, -0.815f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(0.33f, -0.81f);
        glVertex2f(0.336f, -0.825f);
        glVertex2f(0.324f, -0.825f);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(0.302f, -0.857f);
        glVertex2f(0.308f, -0.838f);

        glVertex2f(0.308f, -0.838f);
        glVertex2f(0.316f, -0.865f);

        glVertex2f(0.316f, -0.865f);
        glVertex2f(0.324f, -0.838f);

        glVertex2f(0.324f, -0.838f);
        glVertex2f(0.332f, -0.865f);

        glVertex2f(0.332f, -0.865f);
        glVertex2f(0.34f, -0.838f);

        glVertex2f(0.34f, -0.838f);
        glVertex2f(0.348f, -0.865f);

        glVertex2f(0.348f, -0.865f);
        glVertex2f(0.356f, -0.838f);

        glVertex2f(0.356f, -0.838f);
        glVertex2f(0.362f, -0.857f);
    glEnd();
}

void witch()
{

///boomstick
    glBegin(GL_TRIANGLES);      //wwitch's hand
        glColor3f(0.22f, 0.8f, 0.22f);
        glVertex2f(-0.067f, 0.55f);
        glVertex2f(-0.068f, 0.52f);
        glVertex2f(-0.16f, 0.46f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.3f, 0.2f, 0.2f);
        glVertex2f(-0.192f, 0.475f);
        glVertex2f(0.23f, 0.32f);
        glVertex2f(0.236f, 0.345f);
        glVertex2f(-0.19f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3f(0.2f, 0.2f, 0.2f);
       glVertex2f(0.252f, 0.3f);
       glVertex2f(0.227f, 0.3f);
       glVertex2f(0.232f, 0.364f);
       glVertex2f(0.252f, 0.364f);
    glEnd();

    glBegin(GL_POLYGON);
       glColor3f(0.9f, 0.9f, 0.15f);
       glVertex2f(0.252f, 0.3f);
       glVertex2f(0.33f, 0.26f);
       glVertex2f(0.33f, 0.364f);
       glVertex2f(0.252f, 0.364f);
    glEnd();

///witch
    glBegin(GL_POLYGON);
        glColor3f(0.18f, 0.18f, 0.18f);
        glVertex2f(-0.1f, 0.705f);
        glVertex2f(-0.06f, 0.73f);
        glVertex2f(0.0f, 0.73f);
        glVertex2f(0.04f, 0.705f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.18f, 0.18f, 0.18f);
        glVertex2f(-0.06f, 0.73f);
        glVertex2f(-0.03f, 0.91f);
        glVertex2f(0.0f, 0.89f);
        glVertex2f(0.0f, 0.73f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.18f, 0.18f, 0.18f);
        glVertex2f(-0.03f, 0.91f);
        glVertex2f(0.06f, 0.905f);
        glVertex2f(0.0f, 0.89f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.22f, 0.8f, 0.22f);
        glVertex2f(-0.08f, 0.705f);
        glVertex2f(-0.078f, 0.63f);
        glVertex2f(-0.03f, 0.63f);
        glVertex2f(-0.03f, 0.69f);
        glVertex2f(-0.04f, 0.705f);
    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.066f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.42f, 0.42f);
        glVertex2f(0.0f, 0.705f);
        glVertex2f(0.03f, 0.61f);
        glVertex2f(-0.03f, 0.61f);
        glVertex2f(-0.03f, 0.67f);
        glVertex2f(-0.04f, 0.705f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.22f, 0.8f, 0.22f);
        glVertex2f(-0.08f, 0.69f);
        glVertex2f(-0.125f, 0.682f);
        glVertex2f(-0.08f, 0.674f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.22f, 0.8f, 0.22f);
        glVertex2f(-0.078f, 0.63f);
        glVertex2f(-0.105f, 0.62f);
        glVertex2f(-0.103f, 0.61f);
        glVertex2f(-0.046f, 0.63f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.22f, 0.8f, 0.22f);
        glVertex2f(-0.046f, 0.63f);
        glVertex2f(-0.046f, 0.585f);
        glVertex2f(-0.03f, 0.585f);
        glVertex2f(-0.03f, 0.63f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.18f, 0.18f, 0.18f);
        glVertex2f(-0.03f, 0.585f);
        glVertex2f(-0.067f, 0.585f);
        glVertex2f(-0.068f, 0.47f);
        glVertex2f(-0.11f, 0.37f);
        glVertex2f(-0.11f, 0.3f);
        glVertex2f(-0.06f, 0.3f);
        glVertex2f(0.01f, 0.4f);
        glVertex2f(0.0f, 0.44f);
        glVertex2f(0.0f, 0.585f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(-0.11f, 0.273f);
        glVertex2f(-0.11f, 0.3f);
        glVertex2f(-0.095f, 0.3f);
        glVertex2f(-0.085f, 0.273f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(-0.075f, 0.273f);
        glVertex2f(-0.075f, 0.3f);
        glVertex2f(-0.06f, 0.3f);
        glVertex2f(-0.05f, 0.273f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(-0.02f, 0.585f);
        glVertex2f(0.25f, 0.565f);
        glVertex2f(0.225f, 0.54f);
        glVertex2f(0.25f, 0.514f);
        glVertex2f(0.225f, 0.488f);
        glVertex2f(0.25f, 0.462f);
        glVertex2f(0.225f, 0.436f);
        glVertex2f(0.25f, 0.42f);
        glVertex2f(0.2f, 0.44f);
        glVertex2f(0.15f, 0.45f);
        glVertex2f(0.1f, 0.44f);
        glVertex2f(0.05f, 0.455f);
        glVertex2f(-0.01f, 0.44f);
    glEnd();
}

void bat1()
{
    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(-0.699f, 0.5158f);
            glVertex2f(-0.7047f, 0.5126f);
            glVertex2f(-0.7062f, 0.5225f);
            glVertex2f(-0.7062f, 0.5296f);
            glVertex2f(-0.7084f, 0.519f);
            glVertex2f(-0.7071f, 0.5079f);
            glVertex2f(-0.7098f, 0.4964f);
            glVertex2f(-0.714f, 0.4984f);
            glVertex2f(-0.72f, 0.5111f);
            glVertex2f(-0.7273f, 0.5332f);
            glVertex2f(-0.7709f, 0.5502f);
            glVertex2f(-0.7616f, 0.53f);
            glVertex2f(-0.7602f, 0.5178f);
            glVertex2f(-0.7484f, 0.5051f);
            glVertex2f(-0.7438f, 0.4889f);
            glVertex2f(-0.7327f, 0.481f);
            glVertex2f(-0.7251f, 0.4676f);
            glVertex2f(-0.7089f, 0.4668f);
            glVertex2f(-0.7002f, 0.4468f);
            glVertex2f(-0.6902f, 0.468f);
            glVertex2f(-0.674f, 0.468f);
            glVertex2f(-0.6671f, 0.4814f);
            glVertex2f(-0.6547f, 0.4921f);
            glVertex2f(-0.6491f, 0.5095f);
            glVertex2f(-0.6387f, 0.5178f);
            glVertex2f(-0.6373f, 0.5328f);
            glVertex2f(-0.6287f, 0.5506f);
            glVertex2f(-0.6722f, 0.532f);
            glVertex2f(-0.68f, 0.5091f);
            glVertex2f(-0.6849f, 0.4996f);
            glVertex2f(-0.6902f, 0.4957f);
            glVertex2f(-0.692f, 0.5091f);
            glVertex2f(-0.6911f, 0.519f);
            glVertex2f(-0.6927f, 0.5269f);
            glVertex2f(-0.6951f, 0.5115f);
    glEnd();
}

void bat2()
{
    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.801f, 0.5958f);
            glVertex2f(0.7913f, 0.5926f);
            glVertex2f(0.7938f, 0.6025f);
            glVertex2f(0.7938f, 0.6096f);
            glVertex2f(0.7916f, 0.599f);
            glVertex2f(0.7929f, 0.5879f);
            glVertex2f(0.7902f, 0.5764f);
            glVertex2f(0.786f, 0.5784f);
            glVertex2f(0.78f, 0.5911f);
            glVertex2f(0.7727f, 0.6132f);
            glVertex2f(0.7291f, 0.6302f);
            glVertex2f(0.7384f, 0.61f);
            glVertex2f(0.7398f, 0.5978f);
            glVertex2f(0.7516f, 0.5851f);
            glVertex2f(0.7562f, 0.5689f);
            glVertex2f(0.7673f, 0.561f);
            glVertex2f(0.7749f, 0.5476f);
            glVertex2f(0.7911f, 0.5468f);
            glVertex2f(0.7998f, 0.5268f);
            glVertex2f(0.8098f, 0.548f);
            glVertex2f(0.826f, 0.548f);
            glVertex2f(0.8329f, 0.5614f);
            glVertex2f(0.8453f, 0.5721f);
            glVertex2f(0.8509f, 0.5895);
            glVertex2f(0.8613f, 0.5978f);
            glVertex2f(0.8627f, 0.6128f);
            glVertex2f(0.8713f, 0.6306f);
            glVertex2f(0.8278f, 0.612f);
            glVertex2f(0.82f, 0.5891f);
            glVertex2f(0.8151f, 0.5796f);
            glVertex2f(0.8098f, 0.5757f);
            glVertex2f(0.808f,0.5891f);
            glVertex2f(0.8089f, 0.599f);
            glVertex2f(0.8073f, 0.6069f);
            glVertex2f(0.8049f, 0.5915f);
    glEnd();
}

void bat3()
{
     glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.5515f, 0.59378f);
            glVertex2f(0.53695f, 0.5889f);
            glVertex2f(0.5407f, 0.60375f);
            glVertex2f(0.5407f, 0.6144f);
            glVertex2f(0.5374f, 0.5985f);
            glVertex2f(0.53935f, 0.58185f);
            glVertex2f(0.5353f, 0.5646f);
            glVertex2f(0.529f, 0.5676f);
            glVertex2f(0.52f, 0.58665f);
            glVertex2f(0.50905f, 0.6198f);
            glVertex2f(0.44365f, 0.6453f);
            glVertex2f(0.4576f, 0.615f);
            glVertex2f(0.4597f, 0.5967f);
            glVertex2f(0.4774f, 0.57765f);
            glVertex2f(0.4843f, 0.55335f);
            glVertex2f(0.50095f, 0.5415f);
            glVertex2f(0.51235f, 0.5214f);
            glVertex2f(0.53665f, 0.4968f);
            glVertex2f(0.5497f, 0.4902f);
            glVertex2f(0.5647f, 0.522f);
            glVertex2f(0.589f, 0.522f);
            glVertex2f(0.59935f, 0.5421f);
            glVertex2f(0.61795f, 0.55815f);
            glVertex2f(0.6263f, 0.58425);
            glVertex2f(0.64195f, 0.5967f);
            glVertex2f(0.64405f, 0.6192f);
            glVertex2f(0.65695f, 0.6459f);
            glVertex2f(0.5917f, 0.618f);
            glVertex2f(0.58f, 0.58365f);
            glVertex2f(0.57265f, 0.5694f);
            glVertex2f(0.5647f, 0.56355f);
            glVertex2f(0.562f, 0.58365f);
            glVertex2f(0.56335f, 0.59865f);
            glVertex2f(0.56095f, 0.61035f);
            glVertex2f(0.55735f, 0.58725f);
    glEnd();
}

void bat4()
{
     glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.701f, 0.6958f);
            glVertex2f(0.6913f, 0.6926f);
            glVertex2f(0.6938f, 0.7025f);
            glVertex2f(0.6938f, 0.7096f);
            glVertex2f(0.6916f, 0.699f);
            glVertex2f(0.6929f, 0.6879f);
            glVertex2f(0.6902f, 0.6764f);
            glVertex2f(0.686f, 0.6784f);
            glVertex2f(0.68f, 0.6911f);
            glVertex2f(0.6727f, 0.7132f);
            glVertex2f(0.6291f, 0.7302f);
            glVertex2f(0.6384f, 0.71f);
            glVertex2f(0.6398f, 0.6978f);
            glVertex2f(0.6516f, 0.6851f);
            glVertex2f(0.6562f, 0.6689f);
            glVertex2f(0.6673f, 0.661f);
            glVertex2f(0.6749f, 0.6476f);
            glVertex2f(0.6911f, 0.6468f);
            glVertex2f(0.6998f, 0.6268f);
            glVertex2f(0.7098f, 0.648f);
            glVertex2f(0.726f, 0.648f);
            glVertex2f(0.7329f, 0.6614f);
            glVertex2f(0.7453f, 0.6721f);
            glVertex2f(0.7509f, 0.6895);
            glVertex2f(0.7613f, 0.6978f);
            glVertex2f(0.7627f, 0.7128f);
            glVertex2f(0.7713f, 0.7306f);
            glVertex2f(0.7278f, 0.712f);
            glVertex2f(0.72f, 0.6891f);
            glVertex2f(0.7151f, 0.6796f);
            glVertex2f(0.7098f, 0.6757f);
            glVertex2f(0.708f,0.6891f);
            glVertex2f(0.7089f, 0.6991f);
            glVertex2f(0.7073f, 0.7069f);
            glVertex2f(0.7049f, 0.6915f);
    glEnd();
}

void bat5()
{
    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(-0.8193f, 0.48606f);
            glVertex2f(-0.8233f, 0.48382f);
            glVertex2f(-0.82434f, 0.49075f);
            glVertex2f(-0.82434f, 0.49572f);
            glVertex2f(-0.82588f, 0.4883f);
            glVertex2f(-0.82497f, 0.48053f);
            glVertex2f(-0.82686f, 0.47248f);
            glVertex2f(-0.8298f, 0.47388f);
            glVertex2f(-0.834f, 0.48277f);
            glVertex2f(-0.83911f, 0.49824f);
            glVertex2f(-0.86963f, 0.51014f);
            glVertex2f(-0.86312f, 0.496f);
            glVertex2f(-0.86214f, 0.48746f);
            glVertex2f(-0.85388f, 0.47857f);
            glVertex2f(-0.85066f, 0.46723f);
            glVertex2f(-0.84289f, 0.4617f);
            glVertex2f(-0.83757f, 0.45232f);
            glVertex2f(-0.82623f, 0.45176f);
            glVertex2f(-0.82014f, 0.43776f);
            glVertex2f(-0.81314f, 0.4526f);
            glVertex2f(-0.8018f, 0.4526f);
            glVertex2f(-0.79697f, 0.46198f);
            glVertex2f(-0.78829f, 0.46947f);
            glVertex2f(-0.78437f, 0.48165f);
            glVertex2f(-0.77709f, 0.48746f);
            glVertex2f(-0.77611f, 0.49796f);
            glVertex2f(-0.77009f, 0.51042f);
            glVertex2f(-0.80054f, 0.4974f);
            glVertex2f(-0.806f, 0.48137f);
            glVertex2f(-0.80943f, 0.47472f);
            glVertex2f(-0.81314f, 0.47199f);
            glVertex2f(-0.8144f, 0.48137f);
            glVertex2f(-0.81377f, 0.4883f);
            glVertex2f(-0.81489f, 0.49383f);
            glVertex2f(-0.81657f, 0.48305f);
        glEnd();
}

void bat6()
{
    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.6893f, 0.53606f);
            glVertex2f(0.6933f, 0.53382f);
            glVertex2f(0.69434f, 0.54075f);
            glVertex2f(0.69434f, 0.54572f);
            glVertex2f(0.69588f, 0.5383f);
            glVertex2f(0.69497f, 0.53053f);
            glVertex2f(0.69686f, 0.52248f);
            glVertex2f(0.6998f, 0.52388f);
            glVertex2f(0.704f, 0.53277f);
            glVertex2f(0.70911f, 0.54824f);
            glVertex2f(0.73963f, 0.56014f);
            glVertex2f(0.73312f, 0.546f);
            glVertex2f(0.73214f, 0.53746f);
            glVertex2f(0.72388f, 0.52857f);
            glVertex2f(0.72066f, 0.51723f);
            glVertex2f(0.71289f, 0.5117f);
            glVertex2f(0.70757f, 0.50232f);
            glVertex2f(0.69623f, 0.50176f);
            glVertex2f(0.69014f, 0.48776f);
            glVertex2f(0.68314f, 0.5026f);
            glVertex2f(0.6718f, 0.5026f);
            glVertex2f(0.66697f, 0.51198f);
            glVertex2f(0.65829f, 0.51947f);
            glVertex2f(0.65437f, 0.53165f);
            glVertex2f(0.64709f, 0.53746f);
            glVertex2f(0.64611f, 0.54796f);
            glVertex2f(0.64009f, 0.56042f);
            glVertex2f(0.67054f, 0.5474f);
            glVertex2f(0.676f, 0.53137f);
            glVertex2f(0.67943f, 0.52472f);
            glVertex2f(0.68314f, 0.522f);
            glVertex2f(0.6844f, 0.53137f);
            glVertex2f(0.68377f, 0.5383f);
            glVertex2f(0.68489f, 0.54383f);
            glVertex2f(0.68657f, 0.53305f);
        glEnd();
}

void bat7()
{
     glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.8809f, 0.70101f);
            glVertex2f(0.87217f, 0.69797f);
            glVertex2f(0.87442f, 0.707375f);
            glVertex2f(0.87442f, 0.71412f);
            glVertex2f(0.87244f, 0.70405f);
            glVertex2f(0.87361f, 0.693505f);
            glVertex2f(0.87118f, 0.68258f);
            glVertex2f(0.8674f, 0.68448f);
            glVertex2f(0.862f, 0.696545f);
            glVertex2f(0.85543f, 0.71754f);
            glVertex2f(0.8162f, 0.73369f);
            glVertex2f(0.82456f, 0.7145f);
            glVertex2f(0.82582f, 0.70291f);
            glVertex2f(0.83644f, 0.690845f);
            glVertex2f(0.84058f, 0.675455f);
            glVertex2f(0.85057f, 0.66795f);
            glVertex2f(0.85741f, 0.65522f);
            glVertex2f(0.87199f, 0.65446f);
            glVertex2f(0.87982f, 0.63546f);
            glVertex2f(0.88882f, 0.6556f);
            glVertex2f(0.9034f, 0.6556f);
            glVertex2f(0.90961f, 0.66833f);
            glVertex2f(0.92077f, 0.678494f);
            glVertex2f(0.92581f, 0.695025);
            glVertex2f(0.93517f, 0.70291f);
            glVertex2f(0.93643f, 0.71716f);
            glVertex2f(0.94417f, 0.73407f);
            glVertex2f(0.90502f, 0.7164f);
            glVertex2f(0.898f, 0.694645f);
            glVertex2f(0.89359f, 0.68562f);
            glVertex2f(0.88882f, 0.681915f);
            glVertex2f(0.8872f,0.694645f);
            glVertex2f(0.88801f, 0.704145f);
            glVertex2f(0.88657f, 0.71165f);
            glVertex2f(0.88441f, 0.69699f);
    glEnd();
}

void bat8()
{
    glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.8893f, 0.51606f);
            glVertex2f(0.8933f, 0.51382f);
            glVertex2f(0.89434f, 0.52075f);
            glVertex2f(0.89434f, 0.52572f);
            glVertex2f(0.89588f, 0.5183f);
            glVertex2f(0.89497f, 0.51053f);
            glVertex2f(0.89686f, 0.50248f);
            glVertex2f(0.8998f, 0.50388f);
            glVertex2f(0.904f, 0.51277f);
            glVertex2f(0.90911f, 0.52824f);
            glVertex2f(0.93963f, 0.54014f);
            glVertex2f(0.93312f, 0.526f);
            glVertex2f(0.93214f, 0.51746f);
            glVertex2f(0.92388f, 0.50857f);
            glVertex2f(0.92066f, 0.49723f);
            glVertex2f(0.91289f, 0.4917f);
            glVertex2f(0.90757f, 0.48232f);
            glVertex2f(0.89623f, 0.48176f);
            glVertex2f(0.89014f, 0.46776f);
            glVertex2f(0.88314f, 0.4826f);
            glVertex2f(0.8718f, 0.4826f);
            glVertex2f(0.86697f, 0.481198f);
            glVertex2f(0.85829f, 0.49947f);
            glVertex2f(0.85437f, 0.51165f);
            glVertex2f(0.84709f, 0.51746f);
            glVertex2f(0.84611f, 0.52796f);
            glVertex2f(0.84009f, 0.54042f);
            glVertex2f(0.87054f, 0.5274f);
            glVertex2f(0.876f, 0.51137f);
            glVertex2f(0.87943f, 0.50472f);
            glVertex2f(0.88314f, 0.502f);
            glVertex2f(0.8844f, 0.51137f);
            glVertex2f(0.88377f, 0.5183f);
            glVertex2f(0.88489f, 0.52383f);
            glVertex2f(0.88657f, 0.51305f);
        glEnd();
}

void ghost1()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.822029f, -0.18416f);
        glVertex2f(-0.808863f, -0.28751f);
        glVertex2f(-0.806913f, -0.31832f);
        glVertex2f(-0.817638f, -0.32729f);
        glVertex2f(-0.838113f, -0.32729f);
        glVertex2f(-0.856638f, -0.3152f);
        glVertex2f(-0.87175f, -0.32729f);
        glVertex2f(-0.887838f, -0.32885f);
        glVertex2f(-0.905388f, -0.31988f);
        glVertex2f(-0.925863f, -0.33353f);
        glVertex2f(-0.940975f, -0.33197f);
        glVertex2f(-0.9478f, -0.31832f);
        glVertex2f(-0.934638f, -0.21809f);
        glVertex2f(-0.91958f, -0.12722f);
        glVertex2f(-0.91075f, -0.09329f);
        glVertex2f(-0.895638f, -0.06677f);
        glVertex2f(-0.88345f, -0.05624f);
        glVertex2f(-0.870775f, -0.05624f);
        glVertex2f(-0.8542f, -0.06092f);
        glVertex2f(-0.839088f, -0.08393f);
        glVertex2f(-0.829338f, -0.12254f);
    glEnd();

    if (Ghost_moveCondition == true)
    {
         glTranslatef(0.0f, positionGhost/2, 0.0f);
    }
    glBegin(GL_TRIANGLE_FAN);
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex2f(-0.895f, -0.13f);
       for(int i = 0; i <= 100 ; i++)
       {
            glVertex2f( -0.895 + (0.01*cos(i*((2*3.1416)/100))),
                        -0.13 + (0.01*sin(i*((2*3.1416)/100)))
                       );
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex2f(-0.854f, -0.13f);
       for(int i = 0; i <= 100 ; i++)
       {
            glVertex2f( -0.854 + (0.01*cos(i*((2*3.1416)/100))),
                        -0.13 + (0.01*sin(i*((2*3.1416)/100)))
                       );
        }
    glEnd();
}

void ghost2()
{
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.04411f, -0.01836f);
        glVertex2f(-0.03817f, -0.0567f);
        glVertex2f(-0.02251f, -0.12285f);
        glVertex2f(-0.00631f, -0.17415f);
        glVertex2f(-0.00631f, -0.18684f);
        glVertex2f(-0.01549f, -0.1944f);
        glVertex2f(-0.02143f, -0.19116f);
        glVertex2f(-0.03331f, -0.18279f);
        glVertex2f(-0.04357f, -0.17307f);
        glVertex2f(-0.05086f, -0.16767f);
        glVertex2f(-0.05788f, -0.16659f);
        glVertex2f(-0.06652f, -0.16875f);
        glVertex2f(-0.08191f, -0.18171f);
        glVertex2f(-0.09568f, -0.19116f);
        glVertex2f(-0.10972f, -0.19116f);
        glVertex2f(-0.11863f, -0.18603f);
        glVertex2f(-0.13294f, -0.17415f);
        glVertex2f(-0.14752f, -0.17631f);
        glVertex2f(-0.154f, -0.18063f);
        glVertex2f(-0.16534f, -0.18684f);
        glVertex2f(-0.17317f, -0.18279f);
        glVertex2f(-0.17803f, -0.17847f);
        glVertex2f(-0.181f, -0.17091f);
        glVertex2f(-0.18451f, -0.15714f);
        glVertex2f(-0.18586f, -0.13257f);
        glVertex2f(-0.17992f, -0.09315f);
        glVertex2f(-0.17317f, -0.05778f);
        glVertex2f(-0.1648f, -0.02484f);
        glVertex2f(-0.16129f, -0.00567f);
        glVertex2f(-0.16912f, 0.0189f);
        glVertex2f(-0.18397f, 0.0351f);
        glVertex2f(-0.19531f, 0.0351f);
        glVertex2f(-0.1972f, 0.03915f);
        glVertex2f(-0.19531f, 0.04887f);
        glVertex2f(-0.19531f, 0.05643f);
        glVertex2f(-0.19963f, 0.06075f);
        glVertex2f(-0.20449f, 0.0648f);
        glVertex2f(-0.20503f, 0.07236f);
        glVertex2f(-0.20449f, 0.07776f);
        glVertex2f(-0.1972f, 0.07776f);
        glVertex2f(-0.19288f, 0.07884f);
        glVertex2f(-0.19369f, 0.08937f);
        glVertex2f(-0.19369f, 0.10017f);
        glVertex2f(-0.18937f, 0.10341f);
        glVertex2f(-0.18343f, 0.09585f);
        glVertex2f(-0.17911f, 0.08208f);
        glVertex2f(-0.17263f, 0.06696f);
        glVertex2f(-0.16426f, 0.06075f);
        glVertex2f(-0.14968f, 0.05103f);
        glVertex2f(-0.14077f, 0.05643f);
        glVertex2f(-0.13483f, 0.1107f);
        glVertex2f(-0.12646f, 0.15336f);
        glVertex2f(-0.11674f, 0.18009f);
        glVertex2f(-0.09892f, 0.19305f);
        glVertex2f(-0.08083f, 0.18441f);
        glVertex2f(-0.07192f, 0.17361f);
        glVertex2f(-0.06463f, 0.14499f);
        glVertex2f(-0.05788f, 0.10962f);
        glVertex2f(-0.05383f, 0.08208f);
        glVertex2f(-0.05329f, 0.06075f);
        glVertex2f(-0.05329f, 0.05427f);
        glVertex2f(-0.03871f, 0.05643f);
        glVertex2f(-0.02548f, 0.06588f);
        glVertex2f(-0.01792f, 0.081f);
        glVertex2f(-0.01306f, 0.09801f);
        glVertex2f(-0.00712f, 0.10125f);
        glVertex2f(-0.00388f, 0.09909f);
        glVertex2f(-0.00388f, 0.08937f);
        glVertex2f(-0.00523f, 0.08613f);
        glVertex2f(-0.00577f, 0.07992f);
        glVertex2f(-0.00334f, 0.07776f);
        glVertex2f(-0.00037f, 0.07344f);
        glVertex2f(0.00152f, 0.07128f);
        glVertex2f(0.0026f, 0.06156f);
        glVertex2f(0.00017f, 0.05535f);
        glVertex2f(-0.00172f, 0.05103f);
        glVertex2f(-0.00226f, 0.04779f);
        glVertex2f(-0.00334f, 0.0351f);
        glVertex2f(-0.0082f, 0.03186f);
        glVertex2f(-0.02008f, 0.03186f);
        glVertex2f(-0.02494f, 0.02646f);
        glVertex2f(-0.03331f, 0.01782f);
        glVertex2f(-0.04249f, -0.00351f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.1054f, 0.0351f);
        glVertex2f(-0.10729f, 0.05427f);
        glVertex2f(-0.10783f, 0.0702f);
        glVertex2f(-0.10432f, 0.07884f);
        glVertex2f(-0.09703f, 0.08316f);
        glVertex2f(-0.09217f, 0.08316f);
        glVertex2f(-0.08731f, 0.081f);
        glVertex2f(-0.08272f, 0.06912f);
        glVertex2f(-0.08137f, 0.05643f);
        glVertex2f(-0.08137f, 0.05211f);
        glVertex2f(-0.08326f, 0.03726f);
        glVertex2f(-0.08731f, 0.02538f);
        glVertex2f(-0.09163f, 0.01377f);
        glVertex2f(-0.10108f, 0.00837f);
        glVertex2f(-0.10297f, 0.01269f);
        glVertex2f(-0.10432f, 0.0189f);
        glVertex2f(-0.10432f, 0.02862f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.1054f, 0.1161f);
        glVertex2f(-0.10297f, 0.12042f);
        glVertex2f(-0.10108f, 0.12474f);
        glVertex2f(-0.10108f, 0.12987f);
        glVertex2f(-0.10648f, 0.13527f);
        glVertex2f(-0.11134f, 0.13527f);
        glVertex2f(-0.11431f, 0.13527f);
        glVertex2f(-0.11917f, 0.13203f);
        glVertex2f(-0.12214f, 0.12474f);
        glVertex2f(-0.11971f, 0.11178f);
        glVertex2f(-0.1162f, 0.10854f);
        glVertex2f(-0.11512f, 0.10557f);
        glVertex2f(-0.10972f, 0.10449f);
        glVertex2f(-0.10729f, 0.10638f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.08434f, 0.11286f);
        glVertex2f(-0.08434f, 0.10557f);
        glVertex2f(-0.08083f, 0.10557f);
        glVertex2f(-0.07543f, 0.10854f);
        glVertex2f(-0.06949f, 0.12042f);
        glVertex2f(-0.07003f, 0.13203f);
        glVertex2f(-0.073f, 0.13419f);
        glVertex2f(-0.07597f, 0.13635f);
        glVertex2f(-0.08272f, 0.13635f);
        glVertex2f(-0.08731f, 0.13311f);
        glVertex2f(-0.08974f, 0.13311f);
        glVertex2f(-0.09109f, 0.12798f);
        glVertex2f(-0.088f, 0.12042f);
    glEnd();
}

void ghost_hand()
{
    glBegin(GL_TRIANGLE_FAN);
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f(-0.68275f, -0.7345f);
       glColor3f(0.5f, 0.0f, 0.0f);
       glVertex2f(-0.6810f, -0.7065f);
       glVertex2f(-0.6855f, -0.6395f);
       glVertex2f(-0.6835f, -0.6235f);
       glVertex2f(-0.6765f, -0.6235f);
       glVertex2f(-0.6735f, -0.6595f);
       glVertex2f(-0.672f, -0.693f);
       glVertex2f(-0.6635f, -0.7085f);
       glVertex2f(-0.648f, -0.6355f);
       glVertex2f(-0.6210f, -0.6255f);
       glVertex2f(-0.6365f, -0.6355f);
       glVertex2f(-0.6435f, -0.663f);
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f(-0.6545f, -0.7105f);
       glVertex2f(-0.650f, -0.7185f);
       glVertex2f(-0.6410f, -0.7105f);
       glColor3f(0.5f, 0.0f, 0.0f);
       glVertex2f(-0.638f, -0.701f);
       glVertex2f(-0.6365f, -0.6850f);
       glVertex2f(-0.6290f, -0.6830f);
       glVertex2f(-0.6245f, -0.7030f);
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f(-0.642f, -0.7425f);
       glVertex2f(-0.628f, -0.7325f);
       glVertex2f(-0.6245f, -0.752f);
       glVertex2f(-0.6365f, -0.766f);
       glVertex2f(-0.6410f, -0.7915f);
       glVertex2f(-0.6490f, -0.8135f);
       glVertex2f(-0.652f, -0.8195f);
       glVertex2f(-0.652f, -0.839f);
       glVertex2f(-0.648f, -0.9125f);
       glVertex2f(-0.6455f, -0.9555f);
       glVertex2f(-0.6890f, -0.95f);
       glVertex2f(-0.688f, -0.94f);
       glVertex2f(-0.6865f, -0.8450f);
       glVertex2f(-0.688f, -0.8135f);
       glVertex2f(-0.6945f, -0.7915f);
       glVertex2f(-0.7065f, -0.774f);
       glVertex2f(-0.7145f, -0.748f);
       glVertex2f(-0.7245f, -0.7325f);
       glVertex2f(-0.73f, -0.7325f);
       glVertex2f(-0.73f, -0.7185f);
       glVertex2f(-0.722f, -0.7185f);
       glVertex2f(-0.712f, -0.7185f);
       glVertex2f(-0.7045f, -0.7285f);
       glVertex2f(-0.6968f, -0.7425f);
    glEnd();
}

void sound()
{
    PlaySound("HalloweenMusic.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void sound_2()
{

    PlaySound("WhatsApp_Horror_Audio.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void sound_Rain()
{

    PlaySound("rain-02.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}


void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
       case 'R':
       rainStatus = true;
       sound_Rain();
       break;

       case 'S':
       rainStatus = false;
       sound();
       break;

       case 'W':
          speedWitch += 0.0125f;
       break;

       case 'D':
          speedWitch -= 0.008f;
       break;

       case 'G':
       GhostMove = true;
       break;

       case 'H':
       GhostMove = false;
       break;

       case 'M':
       sound_2();
       redMoon = true;
       gHand_moveCondition = true;
       redEyePumpkin = true;
       break;

       case 'N':
       sound();
       redMoon = false;
       redEyePumpkin = false;
       gHand_moveCondition = false;
       break;

       case 'E':
       redEyePumpkin = true;
       break;

       case 'L':
       houseLight = true;
       break;

       case 'O':
       sound_2();
       houseLight = false;
       break;

       case 'T':
       sound();
       break;

       default:
            exit(0);
       break;
	}
}


void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

    grass2();
    sky();
    stars();
    moon();
       if (redMoon == true)
        {
            red_moon();
        }
    grass();
    river();

    glPushMatrix();
    glTranslatef((-positionBatsM)/2, positionBatsM, 0.0f);
    bat3();
    bat2();
    bat4();
    bat6();
    bat7();
    bat8();
    glPopMatrix();

    grave1();
    grave2();
    grave3();
    grave4();

    if (Ghost_moveCondition == false)
    {
        ghost1();
    }

    if (Ghost_moveCondition == true)
    {
        glPushMatrix();
        ghost1();
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(positionGhost, positionGhost, 0.0f);
    ghost2();
    glTranslatef(-positionGhost, positionGhost, 0.0f);
    ghost2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(positionWitch, 0.0f, 0.0f);
    witch();
    glPopMatrix();

    tress();
    ghost_house();

    glPushMatrix();
    glTranslatef(positionBatsH, positionBatsH, 0.0f);
    bat1();
    bat5();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, positionPumpkin, 0.0f);
    pumpkin1();
    pumpkin3();
    pumpkin4();
    pumpkin5();
    pumpkin6();
    pumpkin7();
    pumpkin8();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionShip, 0.0f, 0.0f);
    ghost_ship();
    ship_flag();
    glPopMatrix();

    glPushMatrix();
    glRotatef(pumpkinRotate,0.0f,0.5f,0.0f);
    pumpkin2();
    pumpkinRotate += 0.7f;
    glPopMatrix();

    grave5();
    glPushMatrix();
    glRotatef(ghandRotate,0.0f,1.0f,0.0f);
    ghost_hand();
    if (gHand_moveCondition == true)
    {
    ghandRotate += 0.5f;
    if(ghandRotate > 30.f )
    {
        ghandRotate -= 60.0f;
    }
    }
    glPopMatrix();

    if(rainStatus == true)
    {
        glPushMatrix();
        glTranslatef(positionRain, positionRain, 0.0f);

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();

        glTranslatef(0.0,-0.12f,0.0);
        rain();
        glEnd();
        glPopMatrix();
    }

	glFlush();
}

void reshape(int w,int h)
{
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(160, aspectRatio, 1.6, 100.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void controls()
{
    cout<<"               THE HALLOWEEN                "<<endl<<endl;

    cout<<"Please Press 'T' For Starting Tune"<<endl;

    cout<<"Press R : Start Raining"<<endl;
    cout<<"Press S : Stop Raining"<<endl;
    cout<<"Press W : Increase Witch's Speed"<<endl;
    cout<<"Press D : Decrease Witch's Speed"<<endl;
    cout<<"Press G : Start moving ghosts"<<endl;
    cout<<"Press H : Stop moving ghosts"<<endl;
    cout<<"Press M : Start Red moon Effect"<<endl;
    cout<<"Press N : Stop Red moon Effect"<<endl;
    cout<<"Press E : Change Pumpkin's Eye (Red)"<<endl;
    cout<<"Press O : House Lights OFF"<<endl;
    cout<<"Press L : House Lights ON"<<endl;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    controls();
	glutInitWindowSize (1280, 800);
	glutInitWindowPosition (10, 10);
	glutCreateWindow ("THE HALLOWEEN");
    //glutReshapeFunc(reshape);
	glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(50, update, 0);
	glutMainLoop();
	sound();
	sound_2();
	sound_Rain();
	return 0;
}
