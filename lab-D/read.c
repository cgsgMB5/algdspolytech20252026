#include <stdio.h>
#include <stdlib.h>

#include "grc.h"

void SetMatr(int Size, t_matr* M)
{
	int i, j;

	M->Size = Size;
	if ((M->Table = malloc(sizeof(int*) * Size)) != NULL)
		for (i = 0; i < Size; i++)
			if ((M->Table[i] = malloc(sizeof(int) * Size)) != NULL)
				for (j = 0; j < Size; j++)
					M->Table[i][j] = 0;

}

void SetList(int Size, t_dlist* L)
{
	int i;

	L->Size = Size;
	if ((L->Dots = malloc(sizeof(t_dot) * Size)) != NULL)
		for (i = 0; i < Size; i++)
		{
			L->Dots[i].Color = 0;
			L->Dots[i].Number = i + 1;
			L->Dots[i].Power = 0;
		}

}

void PrintMatr(t_matr M)
{
	int i, j;

	for (i = 0; i < M.Size; i++)
	{
		for (j = 0; j < M.Size; j++)
			printf("%i ", M.Table[i][j]);
		printf("\n");
	}
	printf("\n");
}

void ReadFile(const char* FN, t_matr* A, t_dlist* G, int* CS)
{
	FILE* F = fopen(FN, "r");
	char Str[10];
	int i = 0;

	int Size = 0, Colors = 0;
	int d1 = 0, d2 = 0;

	if (F != NULL)
	{
		fgets(Str, 10, F);
		sscanf(Str, "%i %i", &Size, &Colors);

		SetMatr(Size, A);
		SetList(Size, G);
		*CS = Colors;

		while (fgets(Str, 10, F) != NULL)
		{
			sscanf(Str, "%i %i", &d1, &d2);
			A->Table[d1 - 1][d2 - 1] = A->Table[d2 - 1][d1 - 1] = 1;
			G->Dots[d1].Power++;
			G->Dots[d2].Power++;
		}
		PrintMatr(*A);

		fclose(F);
	}
}

void WriteFile(const char* FN, t_matr T, t_dlist* G, int ColorSize)
{
	FILE* F = fopen(FN, "w");
	int i;

	if (F != NULL)
	{
		if (!GrapsColoringGreedy(T, G, ColorSize))
			fprintf(F, "Graph can't be colored into %i colors \n", ColorSize);
		else
			for (i = 0; i < G->Size; i++)
				fprintf(F, "%i ", G->Dots[i].Color);
		fclose(F);
	}
}