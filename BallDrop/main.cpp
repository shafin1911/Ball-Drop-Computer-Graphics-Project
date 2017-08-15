//Name: Karim, Shafin Al ID: 14-27769-3

#include<windows.h>
#include<gl/glut.h>
#include<stdio.h>
#include <iostream>
#include<time.h>

using namespace std;

static int score = 0;
int x1 = 600;
int y1 = 780;
int flag = 0;
int j = 0;
int k = 0;
int l = 0;
int m = 0;
int n = 0;
int o = 0;
int p = 0;
int q = 11;
int giveLife = 0;
int Life = 5;
int velocity = 10;

int globalr = 200;
int globalg = 0;
int globalb = 100;

float move_unit = 50;
int ballposition = 0;

int arr [12][4] = {1000, 0, 1080, 60, // 8  9
                  900, 0, 980, 60,   //  6  7
                  800, 0, 880, 60,   //  4  5
                  700, 0, 780, 60,   //  2  3
                  600, 0, 680, 60,   //  0  1
                500, 0, 580, 60,     // -2 -1
                  400, 0, 480, 60,   // -4 -3
                  300, 0, 380, 60,   // -6 -5
                  200, 0, 280, 60,   // -8 -7
                  100, 0, 180, 60,   // -10 -9
                  0, 0, 80, 60,      // -11 -12
                  1100, 0, 1180, 60};     // life

void drawText (void * font, char *s, float x, float y){
     glRasterPos2f(x, y);
	 glColor3f(255, 0, 0);
     for (int i = 0; i < strlen (s); i++)
     glutBitmapCharacter (font, s[i]);
}

void drawNumber (void * font, int s,int spc, float x, float y){
     glRasterPos2f(x, y);
	 glColor3f(255, 0, 0);
     int k=0,j=0;
     while(s>9)
     {
        k=s%10;
        glRasterPos2f((x-(j*spc)), y);
        glutBitmapCharacter (font, 48+k);
        j++;glPushMatrix();
        glPopMatrix();
        s=s/10;
     }
    glRasterPos2f((x-(j*spc)), y);
    glutBitmapCharacter (font, 48+s);
}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
        case GLUT_KEY_RIGHT:
        if(ballposition < 9)
           {
            x1 += move_unit;
            glutPostRedisplay();
            ballposition++;
            break;
           }else{break;}

        case GLUT_KEY_LEFT:
        if(ballposition > -12){
           x1 -= move_unit;
           glutPostRedisplay();
           ballposition--;
           break;
        }else{break;}

        default:
            break;
	}
}

void drawBall()
{
    glBegin(GL_QUADS);
    glColor3ub(100, 255, 100);
    glVertex2i(x1, y1);
    glVertex2i(x1+30,y1);
    glVertex2i(x1+30,y1-60);
    glVertex2i(x1,y1-60);
    glEnd();
    glFlush();
}

void RandQuad()
{
    j = rand()%11;
    k = rand()%11;
    l = rand()%11;
    m = rand()%11;
    n = rand()%11;
    o = rand()%11;
    p = rand()%11;
    if(giveLife == 1)
        q = rand()%11;
    else
        q = 11;
}

void drawObject1()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[j][0],arr[j][1]);
    glVertex2i(arr[j][2],arr[j][1]);
    glVertex2i(arr[j][2],arr[j][3]);
    glVertex2i(arr[j][0],arr[j][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawObject2()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[k][0],arr[k][1]);
    glVertex2i(arr[k][2],arr[k][1]);
    glVertex2i(arr[k][2],arr[k][3]);
    glVertex2i(arr[k][0],arr[k][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawObject3()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[l][0],arr[l][1]);
    glVertex2i(arr[l][2],arr[l][1]);
    glVertex2i(arr[l][2],arr[l][3]);
    glVertex2i(arr[l][0],arr[l][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawObject4()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[m][0],arr[m][1]);
    glVertex2i(arr[m][2],arr[m][1]);
    glVertex2i(arr[m][2],arr[m][3]);
    glVertex2i(arr[m][0],arr[m][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawObject5()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[n][0],arr[n][1]);
    glVertex2i(arr[n][2],arr[n][1]);
    glVertex2i(arr[n][2],arr[n][3]);
    glVertex2i(arr[n][0],arr[n][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawObject6()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[o][0],arr[o][1]);
    glVertex2i(arr[o][2],arr[o][1]);
    glVertex2i(arr[o][2],arr[o][3]);
    glVertex2i(arr[o][0],arr[o][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawObject7()
{
    glBegin(GL_QUADS);
    glColor3ub (globalr,globalg,globalb);
    glVertex2i(arr[p][0],arr[p][1]);
    glVertex2i(arr[p][2],arr[p][1]);
    glVertex2i(arr[p][2],arr[p][3]);
    glVertex2i(arr[p][0],arr[p][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawLife()
{
    glBegin(GL_QUADS);
    glColor3ub (0,255,255);
    glVertex2i(arr[q][0],arr[q][1]);
    glVertex2i(arr[q][2],arr[q][1]);
    glVertex2i(arr[q][2],arr[q][3]);
    glVertex2i(arr[q][0],arr[q][3]);
    glFlush();
    glEnd();
    glFlush();
}

void drawScence()
{
    glPushMatrix();
    drawBall();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject5();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject6();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawObject7();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, flag ,0);
    drawLife();
    glPopMatrix();
}

int militime = 0;
void update(int value)
{
    if(flag < 680)
    {
        if(militime % 500 == 0)
        {
            giveLife = 1;
        }
        flag += velocity;
    }
    else
    {
        RandQuad();
        flag = 0;
        giveLife = 0;
    }

	glutPostRedisplay();
	glutTimerFunc(1, update, militime++);
}

bool collision()
{
    if((ballposition == 8 || ballposition == 9) && ( j == 0 || k == 0 || l == 0 || m == 0 || n == 0 || o == 0 || p == 0 || q == 0) && flag > 679)
    {
        if(q != 0)
            return true;
        else if(q == 0)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == 6 || ballposition == 7) && ( j == 1 || k == 1 || l == 1 || m == 1 || n == 1 || o == 1 || p == 1 || q == 1) && flag > 679)
    {
        if(q != 1)
            return true;
        else if(q == 1)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == 4 || ballposition == 5) && ( j == 2 || k == 2 || l == 2 || m == 2 || n == 2 || o == 2 || p == 2 || q == 2) && flag > 679)
    {
        if(q != 2)
            return true;
        else if(q == 2)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == 2 || ballposition == 3) && ( j == 3 || k == 3 || l == 3 || m == 3 || n == 3 || o == 3 || p == 3 || q == 3) && flag > 679)
    {
        if(q != 3)
            return true;
        else if(q == 3)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == 0 || ballposition == 1) && ( j == 4 || k == 4 || l == 4 || m == 4 || n == 4 || o == 4 || p == 4 || q == 4) && flag > 679)
    {
        if(q != 4)
            return true;
        else if(q == 4)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == -1 || ballposition == -2) && ( j == 5 || k == 5 || l == 5 || m == 5 || n == 5 || o == 5 || p == 5 || q == 5) && flag > 679)
    {
        if(q != 5)
            return true;
        else if(q == 5)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == -3 || ballposition == -4) && ( j == 6 || k == 6 || l == 6 || m == 6 || n == 6 || o == 6 || p == 6 || q == 6) && flag > 679)
    {
        if(q != 6)
            return true;
        else if(q == 6)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == -5 || ballposition == -6) && ( j == 7 || k == 7 || l == 7 || m == 7 || n == 7 || o == 7 || p == 7 || q == 7) && flag > 679)
    {
        if(q != 7)
            return true;
        else if(q == 7)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == -7 || ballposition == -8) && ( j == 8 || k == 8 || l == 8 || m == 8 || n == 8 || o == 8 || p == 8 || q == 8) && flag > 679)
    {
        if(q != 8)
            return true;
        else if(q == 8)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == -9 || ballposition == -10) && ( j == 9 || k == 9 || l == 9 || m == 9 || n == 9 || o == 9 || p == 9 || q == 9) && flag > 679)
    {
        if(q != 9)
            return true;
        else if(q == 9)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else if((ballposition == -11 || ballposition == -12) && ( j == 10 || k == 10 || l == 10 || m == 10 || n == 10 || o == 10 || p == 10 || q == 10) && flag > 679)
    {
        if(q != 10)
            return true;
        else if(q == 10)
        {
            if(Life < 5)
            {
                Life++;
            }
            return false;
        }
    }

    else
    {
        return false;
    }
}

void myInit(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1090, 800, 0.0);
}

void GameOver()
{
    myInit();
    drawText(GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER",500,400);
    drawText(GLUT_BITMAP_TIMES_ROMAN_24,"Your Score:",500,500);
    drawNumber(GLUT_BITMAP_TIMES_ROMAN_24,score,10,625,500);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    if(collision())
    {
        Life--;
    }

    else if(Life > 0)
    {
        if(flag > 679)
        {
            score++;
        }
        drawNumber(GLUT_BITMAP_TIMES_ROMAN_24,score,10,190,100);
        drawText(GLUT_BITMAP_TIMES_ROMAN_24,"Score :",100,100);
        drawText(GLUT_BITMAP_TIMES_ROMAN_24,"Life :",950,100);
        drawNumber(GLUT_BITMAP_TIMES_ROMAN_24,Life,10,1000,100);
        drawScence();
    }

    else
    {
        GameOver();
    }

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1190, 800);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Ball Drop");
	glutDisplayFunc(myDisplay);
	myInit();
	glutTimerFunc(100, update, 0);
	glutSpecialFunc(keyboard);
	glutMainLoop();
	return 0;
}
