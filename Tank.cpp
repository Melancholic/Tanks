#include"Tank.h"
tank::tank(){
	koord.resize(tsize);
	up(150,200);
};
tank::tank(int a, int b){
	koord.resize(tsize);
	up(a,b);
        koord[0].x=a;
        koord[0].y=b;
        koord[1].x=a;
        koord[1].y=b-point;
        koord[2].x=a+point;
        koord[2].y=b-point;
        koord[3].x=a-point;
        koord[3].y=b-point;
        koord[4].x=a-point;
        koord[4].y=b-2*point;
        koord[5].x=a+point;
        koord[5].y=b-2*point;
};

void tank::up(int a, int b){
        koord[0].x=a;
        koord[0].y=b+point;
        koord[1].x=a;
        koord[1].y=b;
        koord[2].x=a+point;
        koord[2].y=b;
        koord[3].x=a-point;
        koord[3].y=b;
        koord[4].x=a-point;
        koord[4].y=b-point;
        koord[5].x=a+point;
        koord[5].y=b-point;
}


void tank::down(int a, int b){
        koord[0].x=a;
        koord[0].y=b-point;
        koord[1].x=a;
        koord[1].y=b;
        koord[2].x=a-point;
        koord[2].y=b;
        koord[3].x=a+point;
        koord[3].y=b;
        koord[4].x=a+point;
        koord[4].y=b+point;
        koord[5].x=a-point;
        koord[5].y=b+point;
}
int tank::get_x(){
	return koord[1].x;
}
int tank::get_y(){
	return koord[1].y;
}

void tank::left(int a, int b){
	koord[0].x=a-point;
        koord[0].y=b;
        koord[1].x=a;
        koord[1].y=b;
        koord[2].x=a;
        koord[2].y=b-point;
        koord[3].x=a;
        koord[3].y=b+point;
        koord[4].x=a+point;
        koord[4].y=b+point;
        koord[5].x=a+point;
        koord[5].y=b-point;

}
void tank::right(int a, int b){
 	koord[0].x=a+point;
        koord[0].y=b;
        koord[1].x=a;
        koord[1].y=b;
        koord[2].x=a;
        koord[2].y=b+point;
        koord[3].x=a;
        koord[3].y=b-point;
        koord[4].x=a-point;
        koord[4].y=b-point;
        koord[5].x=a-point;
        koord[5].y=b+point;
}

void tank::sed_xy(int a,int b){
	koord[1].x+=a;
	koord[1].y+=b;
}

void tank::display(){
	glPointSize(10);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

		glColor3f(.1, .1, 0);
		for (int i = 20; i < 380; i++) glVertex2f(i, 20);
		for (int i = 20; i < 280; i++) glVertex2f(20, i);
		for (int i = 20; i < 380; i++) glVertex2f(i, 280);
		for (int i = 20; i < 280; i++) glVertex2f(380, i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
		glColor3f(0, 1, 0);

		for (int i = 0; i < tsize; ++i)
		{
			glVertex2f(koord[i].x, koord[i].y);
		}

		glColor3f(1, 0.3, 0);


	glClear(GL_COLOR_BUFFER_BIT);

	glEnd();
	glFlush();
	glutSwapBuffers();
	
}

void tank::SpecialKeyboard(int key,int x, int y){
	if(key==GLUT_KEY_LEFT){
      sed_xy(-point,0);
	  left(get_x(), get_y());

	}
	if(key== GLUT_KEY_RIGHT){
          sed_xy(point,0);
          right(get_x(), get_y());

	}	
	if(key==GLUT_KEY_DOWN){
      sed_xy(0,-point);
	  down(get_x(),get_y());
	}

	if (key==GLUT_KEY_UP){
            sed_xy(0,point);
            up(get_x(), get_y());
	}
}

void tank::timer(int){
	display();
 	glutSpecialFunc(&tank::SpecialKeyboard);

	glutTimerFunc(10, &tank::timer, 0);
}

void tank::init(){
    
	timer(0);
}
