#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int myStrLen(char* word)
{
	int strLen = 0;

	while (*word != '\0')
	{
		word++;
		strLen += 1;
	}

	return strLen;
}

char* myStrCpy(char* str1, char* str2)
{
	if (str1 == NULL)
		return NULL;

	char* noviPtr = str1;

	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	//dodat null terminator
	*str1 = '\0';

	return noviPtr;
}

int myStrCmp(char* str1, char* str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

char* myStrCat(char* str1, char* str2)
{
	char* ptr = str1;

	while (*ptr != '\0')
		ptr++;

	while (*str2 != '\0')
		*ptr++ = *str2++;

	//dodat null terminator
	*ptr = '\0';

	return str1;
}

char* myStrStr(char* str1, char* str2)
{
	char* ptr1;
	char* ptr2;

	while (*str1)
	{
		ptr1 = str1;
		ptr2 = str2;
		while (*ptr2 == *ptr1)
		{
			ptr1++;
			ptr2++;
		}
		if (*ptr2 == '\0')
			return str1;
		str1++;
	}

	return NULL;
}

char* reverse(char* str1, char* str2)
{	
	char* ptr1 = str1;
	int counter = myStrLen(str2);
	int i;

	while (*ptr1 != '\0')
		ptr1++;

	while (*str2 != '\0')
		str2++;

	for (i = 1; i != counter + 1; i++)
		*ptr1++ = *(str2 - i);

	//dodat null terminator
	*ptr1 = '\0';

	return str1;
}

int main(void)
{
	char str[50] = "SPA";
	char strr[50] = "BRACO";
	char a[50] = "abaaaaabaa";
	char b[50] = "aaab";

	int length = myStrLen(str);

	//printf("%d\n", length);

	//myStrCpy(str, strr);

	//printf("%s\n", str);

	printf("%d\n", myStrCmp(str, strr));

	//printf("%s", myStrCat(str, strr));

	//printf("%s", myStrStr(a, b));

	printf("%s", reverse(strr, str));

	return 0;
}