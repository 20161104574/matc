#pragma once
#ifndef _STUDENT
#define _STUDENT

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
struct Teacher
{
	char name[10];
	char sex[5];
	long num;
};
struct Teacher t[100];
struct Student
{
	int snum;
	char name[10];
	char sex[5];
	char showname[30];
	char type[3];
	char showtype[5];
	char stuclass[10];
	long num;
	float grade;
};
struct Student s[100];
extern int a;
extern int menu_select();
extern void t_output();
extern void s_output();
extern void mark();
extern void show();
extern void ranking();
extern void save();
#endif