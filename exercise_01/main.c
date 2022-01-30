#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;
}Tocka;

typedef struct
{	
	int n;
	Tocka* nizVrhova;
}Poligon;

Poligon* noviPoligon(float* nizX, float* nizY, int n)
{	
	Poligon* poligon = (Poligon*)malloc(sizeof(Poligon));
	Tocka* tocke = (Tocka*)malloc(sizeof(Tocka) * n);

	poligon->n = n;
	poligon->nizVrhova = tocke;

	for (int i = 0; i < n; i++)
	{
		tocke[i].x = nizX[i];
		tocke[i].y = nizY[i];
	}

	return poligon;
}

Tocka** pozitivni(Poligon* p, int* np)
{	
	*np = 0;
	for (int i = 0; i < p->n; i++)
		if ((p->nizVrhova[i].x > 0) && (p->nizVrhova[i].y > 0))
			*np += 1;

	Tocka** nizTocaka = (Tocka**)malloc(sizeof(Tocka*) * (*np));
		
	for (int i = 0, j = 0; i < (p->n); i++)
		if ((p->nizVrhova[i].x > 0) && (p->nizVrhova[i].y > 0))
			nizTocaka[j++] = p->nizVrhova + i;
						
	return nizTocaka;
}

void printArr(int* arr, int arrLen)
{	

	for (int i = 0; i < arrLen; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

int* podniz(int* niz, int start, int stop)
{
	int* noviNiz = (int*)malloc((stop - start) * sizeof(int));

	for (int i = 0; i < stop - start; i++)
		*(noviNiz + i) = *(niz + start + i);

	return noviNiz;
}

int* filtriraj(int* niz, int n, int th, int* nth)
{
	*nth = 0;

	for (int i = 0; i < n; i++)
		if (*(niz + i) < th)
			*nth += 1;

	int* noviNiz = (int*)malloc(*nth * sizeof(int));

	for (int i = 0; i < *nth; i++)
		if (*(niz + i) < th)
			*(noviNiz + i) = *(niz + i);

	return noviNiz;
}

int** podijeli(int* niz, int n)
{
	int** nizNizova = (int**)malloc(sizeof(int*) * 2);

	nizNizova[0] = (int*)malloc(sizeof(int) * n / 2);
	nizNizova[1] = (int*)malloc(sizeof(int) * (n - n / 2));

	int i, j;

	for (i = 0, j = 0; i < n; i++)
	{
		if (i < n / 2)
			*(nizNizova[0] + i) = *(niz + i);
		else
			*(nizNizova[1] + j++) = *(niz + i);
	}
	return nizNizova;
}


int main(void)
{
	//prvi
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	
	int* noviArr = podniz(arr, 3, 7);
	printArr(noviArr, 4);
	free(noviArr);

	//drugi
	int brojManjih; 
	int* filtrArr = filtriraj(arr, 9, 5, &brojManjih);
	printf("\nKolicina manjih brojeva je: %d\n", brojManjih);
	free(filtrArr);

	//treci
	int** ptr = podijeli(arr, 9);
	printArr(ptr[0], 4);
	free(ptr[0]);
	printArr(ptr[1], 5);
	free(ptr[1]);
	free(ptr);


	//cetvrti
	float x[5] = { 1.2, 3.6, 7.1, -1.2, 4.0 };
	float y[5] = { 2.1, 5.3, 5.6, 0.0, 3.3 };
	Poligon* poli = noviPoligon(x, y, 5);

	//peti
	int brojPoz = 0;
	Tocka** arrTocaka = pozitivni(poli, &brojPoz);
	printf("\nKolicina pozitivnih tocaka je: %d\n", brojPoz);
	free(arrTocaka);
	free(poli);
	

	return 0;
}