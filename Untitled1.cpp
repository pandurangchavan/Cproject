#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ch1,m;
struct Supplier{
	int id;
	char suppName[50];
	int mobNo[11];
	char city[50];
	char name[100];

};
//---------------------------------------------------------------------------------------------------------------
struct Supplier  *med=(struct Supplier*)malloc(sizeof(Supplier)*m);
FILE *sptr;
//-----------------------------------------------------------------------------------------------------------

