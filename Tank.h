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
struct p{
	int x;
	int y;
};

struct tank{
	std::vector<p> koord;
	tank();
	tank(int a, int b);
	void up(int a, int b);
	void down(int a, int b);
	void right(int , int b);
	void left(int b, int a);
	int get_x();
	int get_y();
	void sed_xy(int a, int b);
    void SpecialKeyboard(int key,int x, int y);
     void display();
    void timer(int = 0);
    void init();
};
//void display();
#endif
