#ifndef TANK_H
#define TANK_H
#include <GL/glut.h>
#include<time.h>
#include<stdio.h>
#include <termios.h>
#include <unistd.h>
#include<iostream>
#include<vector>
#include<functional>
#define point 10
#define tsize 6
#define firespeed 7
struct p{
	int x;
	int y;
};

struct fire{
	int fspeed;
	p koord;
	fire();
	void reset();
};
struct tank{
	std::vector<p> koord;
	fire zaryd;
	int fprocessing;
	tank();
	tank(int a, int b);
	void up(int a, int b);
	void down(int a, int b);
	void right(int , int b);
	void left(int b, int a);
	int get_x();
	int get_y();
	void sed_xy(int a, int b);
	int finit();
	void ffly();
};
void display();
void SpecialKeyboard(int key,int x, int y);
void timer(int = 0);
void init();
void bang();
#endif
