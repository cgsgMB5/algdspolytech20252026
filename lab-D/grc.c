#include <stdio.h>
#include <stdlib.h>

#include "grc.h"

void PrintGraph(t_dlist G)
{
	int i;

	for (i = 0; i < G.Size; i++)
		printf("%i - %i\n", G.Dots[i].Number, G.Dots[i].Color);
}

int GrapsColoringGreedy(t_matr T, t_dlist* G, int ColorSize)
{
	int i, j;
	int ValidColor = 1, flag;

	G->Dots[0].Color = 1;

	for (i = 1; i < T.Size; i++)
	{
		flag = 0;
		ValidColor = 1;
		for (j = 0; j < T.Size && flag < ColorSize; j++)
		{
			if (T.Table[i][j] == 1)
				if (ValidColor == G->Dots[j].Color)
				{
					ValidColor = ValidColor % ColorSize + 1;
					j = 0;
					flag++;
					if (ValidColor == 0)
						ValidColor = 1;
				}
		}
		if (flag < ColorSize)
			G->Dots[i].Color = ValidColor;
		else
			return 0;
	}
	PrintGraph(*G);

	return 1;
}