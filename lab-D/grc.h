
#ifndef _grc_h_

typedef struct
{
	int Number;
	int Color;
	int Power;
} t_dot;

typedef struct
{
	int Size;
	t_dot* Dots;
} t_dlist;


typedef struct
{
	int Size;
	int **Table;
} t_matr;

void PrintMatr(t_matr M);
void ReadFile(const char* FN, t_matr* A, t_dlist* G, int* CS);

int GrapsColoringGreedy(t_matr T, t_dlist* G, int ColorSize);
void WriteFile(const char* FN, t_matr T, t_dlist* G, int ColorSize);

#endif _grc_h_