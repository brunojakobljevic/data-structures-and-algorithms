#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable* NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)

	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));

	if (newTable == NULL)
		return NULL;

	newTable->table = (Bin**)calloc(size,sizeof(Bin*));

	if (newTable->table == NULL)
		return NULL;

	newTable->size = size;
	newTable->load = 0;

	return newTable;
}

unsigned int hash(char* word)
{
	// od kljuca generira hash kod

	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable* ht, char* word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu

	Bin* newBin = (Bin*)malloc(sizeof(Bin));

	if (newBin == NULL) 
		return;

	unsigned int index = hash(word) % ht->size;

	newBin->word = word;
	newBin->next = ht->table[index];

	ht->table[index] = newBin;
	ht->load++;
}

int Get(HashTable* ht, char* word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici

	unsigned int index = hash(word) % ht->size;

	Bin* currentBin = ht->table[index];

	while (currentBin != NULL)
	{
		if (strcmp(word, currentBin->word) == 0) 
			return 1;

		currentBin = currentBin->next;
	}

	return 0;
}

void DeleteTable(HashTable* ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)

	for (int i = 0; i < ht->size; i++)
	{
		Bin* currentBin = ht->table[i];

		while (currentBin != NULL)
		{
			Bin* nextBin = currentBin->next;
			free(currentBin->word);
			free(currentBin);
			currentBin = nextBin;
		}
	}

	free(ht->table);
	free(ht);
}