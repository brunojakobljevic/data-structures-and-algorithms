#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trokut.h"

//funkcija koja cita binarnu STL datoteku i vraca ispunjenu Objekt3D struct

Objekt3D* readStlBin(FILE* fp)
{	
	Objekt3D* obj = (Objekt3D*)malloc(sizeof(Objekt3D));
	//priskocit zaglavlje
	fseek(fp, 80, SEEK_SET);
	//procitat broj trokuta
	fread(&obj->brojTrokuta, sizeof(unsigned int), 1, fp);

	obj->nizTrokuta = (Trokut*)malloc(sizeof(Trokut) * obj->brojTrokuta);

	for (unsigned int i = 0; i < obj->brojTrokuta; i++)
		fread(&obj->nizTrokuta[i], 50, 1, fp);

	return obj;
}

void writeStlBin(Objekt3D* obj, FILE* fp)
{
	char head[80] = { 0 };
	
	fwrite(head, sizeof(char), 80, fp);

	fwrite(&obj->brojTrokuta, sizeof(unsigned int), 1, fp);

	for (unsigned int i = 0; i < obj->brojTrokuta; i++)
		fwrite(&obj->nizTrokuta[i], 50, 1, fp);
}

void writeStlTxt(Objekt3D* obj, FILE* fp)
{
	fprintf(fp, "solid OpenSCAD_Model\n");

	for (unsigned int i = 0; i < obj->brojTrokuta; i++)
	{
		fprintf(fp, "\tfacet normal %f %f %f\n", obj->nizTrokuta[i].ni, obj->nizTrokuta[i].nj, obj->nizTrokuta[i].nk);
		fprintf(fp, "\t\touter loop\n");
		fprintf(fp, "\t\t\tvertex %f %f %f\n", obj->nizTrokuta[i].x1, obj->nizTrokuta[i].y1, obj->nizTrokuta[i].z1);
		fprintf(fp, "\t\t\tvertex %f %f %f\n", obj->nizTrokuta[i].x2, obj->nizTrokuta[i].y2, obj->nizTrokuta[i].z2);
		fprintf(fp, "\t\t\tvertex %f %f %f\n", obj->nizTrokuta[i].x3, obj->nizTrokuta[i].y3, obj->nizTrokuta[i].z3);
		fprintf(fp, "\t\tendloop\n");
		fprintf(fp, "\tendfacet\n");
	}

	fprintf(fp, "endsolid OpenSCAD_Model\n");
}

void delObj(Objekt3D* obj)
{
	free(obj->nizTrokuta);
	free(obj);
}