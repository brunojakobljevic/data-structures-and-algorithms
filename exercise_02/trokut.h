#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	float ni, nj, nk;
	float x1, y1, z1;
	float x2, y2, z2;
	float x3, y3, z3;
	unsigned short boja;
}Trokut;

typedef struct
{
	Trokut* nizTrokuta;
	unsigned int brojTrokuta;
}Objekt3D;

Objekt3D* readStlBin(FILE* fp);
void writeStlBin(Objekt3D* obj);
void writeStlTxt(Objekt3D* obj, FILE* fp);
void delObj(Objekt3D* obj);