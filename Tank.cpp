#include"Tank.h"
tank Tank;

void bang(){
	if(Tank.zaryd.koord.x<20 ||Tank.zaryd.koord.x>380){
		Tank.zaryd.koord.x=Tank.zaryd.koord.y=-100;
		Tank.zaryd.fspeed=firespeed;
	}
       if(Tank.zaryd.koord.y<20 || Tank.zaryd.koord.y>280 ){
                Tank.zaryd.koord.x=-100;Tank.zaryd.koord.y=-100;
		Tank.zaryd.fspeed=firespeed;
        }   

	
}

void display(){
	glPointSize(10);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	bang();
	if(Tank.zaryd.koord.x !=-100 && Tank.zaryd.koord.y !=-100){
		glColor3f(.2,.5,.5);
		glVertex2f(Tank.zaryd.koord.x, Tank.zaryd.koord.y);
		Tank.ffly();
		}
                


		glColor3f(.1, .1, 0);
		for (int i = 20; i < 380; i++) glVertex2f(i, 20);
		for (int i = 20; i < 280; i++) glVertex2f(20, i);
		for (int i = 20; i < 380; i++) glVertex2f(i, 280);
		for (int i = 20; i < 280; i++) glVertex2f(380, i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
		glColor3f(0, 1, 0);

		for (int i = 0; i < tsize; ++i)
		{
			glVertex2f(Tank.koord[i].x, Tank.koord[i].y);
		}

		glColor3f(1, 0.3, 0);


	glClear(GL_COLOR_BUFFER_BIT);

	glEnd();
	glFlush();
	glutSwapBuffers();
	
}

void SpecialKeyboard(int key,int x, int y){
   
    if(key==GLUT_KEY_LEFT){
        if(Tank.get_x()-2*point>20){
       Tank.sed_xy(-point/2,0);
       Tank.left(Tank.get_x(),  Tank.get_y());
       }    
	}
	if(key== GLUT_KEY_RIGHT){
       if(Tank.get_x()+2*point<380){
           Tank.sed_xy(point/2,0);
           Tank.right(Tank.get_x(),  Tank.get_y());
        }   
    
	}	
	if(key==GLUT_KEY_DOWN){
        if(Tank.get_y()-2*point>20){
           Tank.sed_xy(0,-point/2);
    	   Tank.down(Tank.get_x(), Tank.get_y());
        }
	}
    
	if (key==GLUT_KEY_UP){
        if(Tank.get_y()+2*point<280){
           Tank.sed_xy(0,point/2);
            Tank.up(Tank.get_x(),  Tank.get_y());
        }
	}
	if(key==GLUT_KEY_PAGE_DOWN &&Tank.zaryd.koord.x==-100 && Tank.zaryd.koord.y==-100){
	Tank.fprocessing=Tank.finit();
	}
    
}

void timer(int){
	display();
 	glutSpecialFunc(SpecialKeyboard);

	glutTimerFunc(10, timer, 0);
}

void init(){
    
	timer(0);
}

tank::tank(){
	koord.resize(tsize);
	up(150,200);
	zaryd.koord.x=zaryd.koord.y=-100;
};
tank::tank(int a, int b){
	koord.resize(tsize);
	up(a,b);
	zaryd.koord.x=zaryd.koord.y=-100;
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
int tank::finit(){
	switch(koord[0].x-koord[1].x){
		case point:{
		  zaryd.koord.x=koord[0].x+point;
		  zaryd.koord.y=koord[0].y;
		  return 1;};break;
		case -point:{
                  zaryd.koord.x=koord[0].x-point;
                  zaryd.koord.y=koord[0].y;
		zaryd.fspeed*=-1;
		return 1;
		};
	}
	switch(koord[0].y-koord[1].y){
		case point:{
                  zaryd.koord.x=koord[0].x;
                  zaryd.koord.y=koord[0].y-point;
			return 2;};break;
		case -point:{
                  zaryd.koord.x=koord[0].x;
                  zaryd.koord.y=koord[0].y+point;
			zaryd.fspeed*=-1;
			return 2;
		}
	
}
return 0;
}
fire::fire(){
	fspeed=firespeed;
	koord.x=koord.y=-100;
}
void fire::reset(){

	koord.x=koord.y=-100;
        fspeed=firespeed;
}
void tank::ffly(){
	if (fprocessing ==1){
		zaryd.koord.x+=zaryd.fspeed;
	}
	if(fprocessing ==2){
		zaryd.koord.y+=zaryd.fspeed;
	}
}
