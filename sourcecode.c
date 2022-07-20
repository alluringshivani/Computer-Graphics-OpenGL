
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include <math.h>
#include <time.h>
#define M_PI 3.14
#define DEGREES_TO_RADIANS 3.14159/180.0

int disp=0;
void *currentfont;
int c=0,d=500,g=380,h=970,i=540,j=970,k=380,l=965,m=540,n=970,cc=0,dd=440;
GLfloat x=0.0;
int z=0,a;
int train1,train2,train3,basic;
int x11=0,y11=0,x12=0,y12=0,x21=0,y21=0,x22=0,y22=0;
int flag=0;
void mountains(int x,int y);

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,1.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void displaytext()
{
	
glClear(GL_COLOR_BUFFER_BIT);
setFont(GLUT_BITMAP_HELVETICA_10);
	glColor3f(1,1,0);


	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(450,650,0,"PROJECT ASSOCIATES");
	drawstring(220,550,0,"RAJAT R SHETTY");
	drawstring(220,500,0,"2GI15CS115");
	drawstring(720,550,0,"RAJESH KUMAR");
	drawstring(720,500,0,"2GI15CS116");

	glColor3f(1,1,0);
	drawstring(470,450,0,"UNDER THE GUIDANCE OF");
	drawstring(220,320,0,"Prof. VIDYADHEESH PANDURANGI");
	drawstring(240,280,0,"");
	drawstring(720,320,0,"Prof.PANKAJA B. PATIL");
	drawstring(750,280,0,"");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,1,0);
	drawstring(350,750,0,"COLLISION DETECTION OF TRAINS");
	glColor3f(1,0,0);
	drawstring(250,850,0,"COMPUTER GRAPHICS MINI PROJECT");
	drawstring(450,800,0,"");
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,1);
	drawstring(480,200,0,"CLICK TO START...");
	drawstring(400,120,0,"COMPUTER SCIENCE AND ENGINEERING");
	drawstring(400,60,0,"KLS GOGTE INSTITUTE TECHNOLOGY");
	glFlush();
}

void sun(GLfloat radius)
{
	int i;
	glBegin(GL_POLYGON);
	glColor3f(1.0f,1.f,1.0f);
	glVertex2f(0,0);

	for (i=0; i<361; i++)
	{
		glColor3f(.9f,0.8f,.0f);
		float degInRad = i * DEGREES_TO_RADIANS;
		glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
	}
	
	glEnd();
}



void menu()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	drawstring(250,800,0,"--------------------------------------------");
	glColor3f(0,1,0);
	drawstring(250,770,0,"1.COLLISION DETECTION REQUIRED ------- press 1");
	glColor3f(1,0,0);
	drawstring(250,740,0,"--------------------------------------------");
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1,1,0);
	drawstring(250,710,0,"This case deals about two trains on the same track running at high speeds.");
	glColor3f(1,1,0);
	drawstring(250,680,0,"This may be the case on a single line system or may be due to poor visibility.");
	glColor3f(1,1,0);
drawstring(250,650,0,"Hence Anti-Collisision Device with the help of GPS technology sends a warning");
	glColor3f(1,1,0);
	drawstring(250,620,0,"to approaching trains and an acknowledgement is sent by the trains in return.");
	glColor3f(1,1,0);
drawstring(250,590,0,"Automatic brakes are applied and the train stops before collision");
	glColor3f(1,0,0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(250,560,0,"--------------------------------------------");
	

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	drawstring(250,450,0,"--------------------------------------------");
	glColor3f(0,1,0);
	drawstring(250,420,0,"2.COLLISION DETECTION NOT REQUIRED ------- press 2");
	glColor3f(1,0,0);
	drawstring(250,390,0,"--------------------------------------------");
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1,1,0);
	drawstring(250,350,0,"In this case both the trains are on different tracks and there is no danger detected");
	glColor3f(1,1,0);
	drawstring(250,320,0,"The trains are though connected through the GPS but the brakes are not applied.");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	drawstring(250,290,0,"--------------------------------------------");
}


void sky()
{	
		glBegin(GL_QUADS);
		glColor3f(0,1,1);
		glVertex2f(0,730);
		glColor3f(0,1,1);
		glVertex2f(999,730);
		glColor3f(1,1,1);
		glVertex2f(999,999);
		glColor3f(1,1,1);
		glVertex2f(0,999);
		glEnd();
}

void circle( float x, float y )
{		
	float r=5.0,t=0;
	int n;
	
glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,0,0);
       glVertex2f( x, y );
for( n = 0;n <= 90;++n) // increment by a fraction of the maximum 
        {
            glVertex2f( x + sin( t * 2 * M_PI ) * r, y + cos( t * 2 * M_PI ) * r );
			t = (float)n/90;
        }
glEnd();
}

void tree( int x, int y)
{
	glColor3f(0,0.9,0);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y);
	glVertex2f(x-10,y-15);
	glVertex2f(x+10,y-15);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y-15);
	glVertex2f(x-20,y-30);
	glVertex2f(x+20,y-30);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x,y-30);
	glVertex2f(x-30,y-45);
	glVertex2f(x+30,y-45);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y-45);
	glVertex2f(x-40,y-60);
	glVertex2f(x+40,y-60);
	glEnd();
	
	glColor3f(0.7,0.3,0);
	glBegin(GL_POLYGON);
	glVertex2f(x-10,y-60);
	glVertex2f(x-5,y-65);
	glVertex2f(x+5,y-65);
	glVertex2f(x+10,y-60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x-5,y-65);
	glVertex2f(x-5,y-95);
	glVertex2f(x+5,y-95);
	glVertex2f(x+5,y-65);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x-5,y-95);
	glVertex2f(x-10,y-100);
	glVertex2f(x+10,y-100);
	glVertex2f(x+5,y-95);;
	
	glEnd();

	glFlush();
}

void sleep(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}


void TRAINS(int x1,int y1,int a,int b)
{		int i=0;
		
		glBegin(GL_QUADS);
		glColor3f(0,0.0,1.0);			 //ENGINE
		glVertex2f(x1,y1);				//lengh of engine=60;height of engine=30;
		glColor3f(0,0.0,1.0);
		glVertex2f(x1+60,y1);			
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x1+60,y1-30);
		glColor3f(0,0.0,0.0);
		glVertex2f(x1,y1-30);
		glEnd();
		circle(x1+10,y1-35);			//wheels
		circle(x1+50,y1-35);
		
		while(i<3)
		{	glBegin(GL_QUADS);			//BOGIES
			glColor3f(1.0,0.0,0.0);		//For right train a=795,b=510
			glVertex2f(a,b);
			glColor3f(1.0,0.0,0.0);
			glVertex2f(a+60,b);
			glColor3f(1.0,0.0,0.0);
			glVertex2f(a+60,b-20);
			glColor3f(1.0,0.0,0.0);
			glVertex2f(a,b-20);
			glEnd();
			a+=65;
			i++;
			circle(a-15,b-25);			//wheels
			circle(a-55,b-25);
		}
	
}

void Basics_func()
{	int x=80,y=650,ii,xx=70,yy=350;

		sky();

		//Sun
	glPushMatrix();
	glTranslatef(720,690,0.0);
	sun(70);
	glPopMatrix();



		mountains(0,300);

		for(ii=0;ii<9;ii++)
		{
			tree(x,y);
			tree(xx,yy);
			x+=110;
			xx+=110;
		}



		/** Track **/
		glBegin(GL_LINES);												
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,500);
		glVertex2f(1000,500);
		glVertex2f(0,499);
	        glVertex2f(1000,499);

		glVertex2f(0,480);
		glVertex2f(1000,480);
		

		while(c!=1000)
		{
			glVertex2f(c,d);
			glVertex2f(c,d-20);
			c+=10;
		}
		glEnd();
		
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,440);
		glVertex2f(1000,440);
		glVertex2f(0,420);
		glVertex2f(1000,420);
		while(cc!=1000)
		{
			glVertex2f(cc,dd);
			glVertex2f(cc,dd-20);
			cc+=10;
		}
		glEnd();
		
	/**	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(468,500);
		glVertex2f(520,440);
		glVertex2f(460,480);
		glVertex2f(512,420);

		glVertex2f(468,500);
		glVertex2f(460,480);

	glVertex2f(520,440);
	glVertex2f(512,420);
	glVertex2f(476,492);
	glVertex2f(467,471);
	glVertex2f(484,484);
	glVertex2f(474,462);
	glVertex2f(492,476);
	glVertex2f(481,453);
	glVertex2f(500,466);
	glVertex2f(488,444);
	glVertex2f(508,458);
	glVertex2f(495,435);
	glVertex2f(516,449);
	glVertex2f(504,425);
	glEnd();

	
		/**	satellite	**/
		glColor3f(0,0,0);
		setFont(GLUT_BITMAP_HELVETICA_18);
		drawstring(650,950,0,"satellite");



		glBegin(GL_POLYGON);					//middle part in yellow
		glColor3f(1.0,1.5,0.0);	
		glVertex2f(480,990);
		glVertex2f(510,990);
		glVertex2f(510,900);
		glVertex2f(480,900);
		glEnd();
		glBegin(GL_LINE_LOOP);					//black color surrounding middle part
		glColor3f(0.0,0.0,0.0);	
		glVertex2f(480,990);
		glVertex2f(510,990);
		glVertex2f(510,900);
		glVertex2f(480,900);
		glEnd();
					
		glBegin(GL_LINE_LOOP);					//left panel of satellite
		glColor3f(0.0,0.0,1.0);
		glVertex2f(380,970);
		glVertex2f(450,970);
		glVertex2f(450,950);
		glVertex2f(480,950);
		glVertex2f(480,940);
		glVertex2f(450,940);
		glVertex2f(450,920);
		glVertex2f(380,920);
		glEnd();
	while(g<=450)								//vertical lines in left panel
	{											//g=380;h=970
		glBegin(GL_LINES);
		glVertex2f(g,h);					
		glVertex2f(g,h-50);
		glEnd();
		g+=5;
	}	
	while(l>=920)								//horizontal lines in left panel		
	{											//k=380;l=970
		glBegin(GL_LINES);						
		glVertex2f(k,l);
		glVertex2f(k+70,l);
		glEnd();
		l-=7;
	
	}

	glBegin(GL_LINE_LOOP);						//right panel of satellite
		glColor3f(0.0,0.0,1.0);
		glVertex2f(610,970);
		glVertex2f(540,970);
		glVertex2f(540,950);
		glVertex2f(510,950);
		glVertex2f(510,940);
		glVertex2f(540,940);
		glVertex2f(540,920);
		glVertex2f(610,920);
	glEnd();
	while(i<=610)									//vertical lines in right panel
	{												//i=540;j=970
		glBegin(GL_LINES);
		glVertex2f(i,j);
		glVertex2f(i,j-50);
		glEnd();
		i+=5;
	}
	while(n>=920)								//horizontal lines in right panel		
	{											//m=540;n=970
		glBegin(GL_LINES);						
		glVertex2f(m,n);
		glVertex2f(m+70,n);
		glEnd();
		n-=7;
	}

	
}

void mountains(int x,int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.35, 0.05);
	glVertex2i(0+x,300+y);
	glVertex2i(100+x,450+y);
	glVertex2i(250+x,300+y);
	glVertex2i(500+x,450+y);
	glVertex2i(750+x,300+y);
	
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(700+x,300+y);


	glVertex2i(900+x,470+y);
	glVertex2i(1000+x,300+y);
	glEnd();

}

void myinit()
{	glClearColor(0.0,0.0,0.0,0.0);	//background color
	gluOrtho2D(0,999,0,999);
	glPointSize(2.0);
	glLineWidth(2.0);

	basic = glGenLists(1);
		glNewList(basic, GL_COMPILE);
		Basics_func();
	glEndList();
	
	train1 = glGenLists(1);
		glNewList(train1, GL_COMPILE);
		TRAINS(850,520,915,510);
	glEndList();
	
	train2 = glGenLists(1);
		glNewList(train2, GL_COMPILE);
		TRAINS(85,520,-110,510);
	glEndList();

	train3 = glGenLists(1);
		glNewList(train3, GL_COMPILE);
		TRAINS(280,460,85,450);
	glEndList();
	
}

void danger()
{
	x11+=16;
	y11-=20;
	glTranslatef(x11,y11,0);
		glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(495,900);
		glVertex2f(510,880);
		glVertex2f(520,880);
		glVertex2f(505,900);
		glEnd();
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(520,880,0,"WARNING");
	
	x21-=40;
	y21-=10;
	glTranslatef(x21,y21,0);
		glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(495,900);
		glVertex2f(505,900);
		glVertex2f(495,870);
		glVertex2f(485,870);
		glEnd();
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(410,870,0,"WARNING");
	
} 


void ack()
{
	glTranslatef(x12,y12,0);
		glBegin(GL_POLYGON);
		glColor3f(0,0.5,0);
		glVertex2f(815,540);
		glVertex2f(825,540);
		glVertex2f(840,520);
		glVertex2f(830,520);
		glEnd();
	x12-=20;
	y12+=20;
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(815,545,0,"Acknowledgement");
	
	glTranslatef(x22,y22,0);
		glBegin(GL_POLYGON);
		glColor3f(0,0.5,0);
		glVertex2f(90,540);
		glVertex2f(100,540);
		glVertex2f(95,520);
		glVertex2f(85,520);
		glEnd();
	x22+=50;
	y22+=10;
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(105,520,0,"Acknowledgement");
	

}


void draw(void)
{	
	int count=0;

if(disp==0)
	{ 
	glClearColor(0,0,0,0);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	displaytext();
	}
if(disp==1)
	{	
	glClearColor(0,0,0,0);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	menu();
	}
if(disp==3)
	{
	glClearColor(0.0,0.5,0,0);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();


	glPushMatrix();
		glCallList(basic);
	glPopMatrix();
		
	glPushMatrix();
		glTranslatef(x,0.0,0.0);
		glCallList(train1);
		glFlush();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-x,0.0,0.0);
		sleep(150);
		glCallList(train3);
		glFlush();
	glPopMatrix();


if(z<250)
	{	
	x=x-5.0;
	sleep(50);	
	z++;
	}
if(z>=250)
	{		
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(325,780,0,"!! DIFFERENT TRACKS, COLLISION NOT POSSIBLE !!");
	}
glFlush();
glutPostRedisplay();
glPopMatrix();
}

if(disp==2)
{
	
	glClearColor(0.0,0.5,0,0);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glPushMatrix();


	glPushMatrix();
		glCallList(basic);
	glPopMatrix();
		
	glPushMatrix();
		glTranslatef(x,0.0,0.0);
		glCallList(train1);
		glFlush();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-x,0.0,0.0);
		glCallList(train2);
		glFlush();
	glPopMatrix();
	
	if(x11<=340&&y11>=-340&&x21>=-470&&y21>=-470)
	{
	glPushMatrix();
		danger();
		glFlush();
	glPopMatrix();
	}
	
	else if(x12>=-320&&y12<=320&&x22<=600&&y22<=600) 
	{
	glPushMatrix();
		ack();
		glFlush();
	glPopMatrix();
	}

if(z<65)
	{	
	x=x-5.0;
	sleep(100);	
	z++;
	}
if(z>=65)
	{	
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(225,780,0,"!! DANGER DETECTED, TRAINS STOPPED BEFORE COLLISION !!");
	glColor3f(0,0,0);
	drawstring(700,100,0,"Left Click to go back to menus");
	}

glPopMatrix();
}
glutPostRedisplay();
glFlush();
glutSwapBuffers();
}

void mouse(int btn,int state,int x,int y)
{	
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)	
		disp=1;
		glutPostRedisplay();
 }

void mykey(unsigned char key,int x,int y)
{
	if(key=='1') disp=2;
	if(key=='2') disp=3;
}


int main(int argc, char **argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("MY RAIL");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1024,768);
	glutMouseFunc(mouse);
	glutKeyboardFunc(mykey);
	glutDisplayFunc(draw);	
	glDisable(GL_DEPTH_TEST);
	myinit();
	glutMainLoop ();
	return(0);
}




