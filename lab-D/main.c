#include <stdio.h>
#include <stdlib.h>

#include "grc.h"

int main(void)
{
	t_matr Table;
	t_dlist Graph;
	int ColorSize = 0;

	ReadFile("input.txt", &Table, &Graph, &ColorSize);
	WriteFile("output.txt", Table, &Graph, ColorSize);
}