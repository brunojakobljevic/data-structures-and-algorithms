#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trokut.h"

void main()
{
	//prvi zdk
	FILE* pz = fopen("primjerbin.stl", "rb");
	Objekt3D* obj = readStlBin(pz);
	
	//drugi zdk
	FILE* dz = fopen("drugizadatak.stl", "wb");
	writeStlBin(obj, dz);

	//treci zdk
	FILE* tz = fopen("trecizadatak.stl", "w");
	writeStlTxt(obj, tz);

	//cetvrti
	delObj(obj);

	//zatvaranje
	fclose(pz);
	fclose(dz);
	fclose(tz);
}