#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grc.h"

void test_SetMatr_MinSize_returnValidVal_no1() {
    t_matr M;
    SetMatr(1, &M);
    printf("Test_SetMatr_MinSize_returnValidVal_no1:\n");
    printf("Size: %d\n", M.Size);
    printf("Table[0][0]: %d\n", M.Table[0][0]);
    free(M.Table[0]);
    free(M.Table);
}

void test_SetList_ZeroSize_returnValidVal_no2() {
    t_dlist L;
    SetList(0, &L);
    printf("Test_SetList_ZeroSize_returnValidVal_no2:\n");
    printf("Size: %d\n", L.Size);
    printf("Dots pointer: %p\n", (void*)L.Dots);
}

void test_PrintMatr_2x2_returnValidVal_no3() {
    t_matr M;
    SetMatr(2, &M);
    M.Table[0][0] = 1;
    M.Table[0][1] = 0;
    M.Table[1][0] = 0;
    M.Table[1][1] = 1;
    printf("Test_PrintMatr_2x2_returnValidVal_no3:\n");
    PrintMatr(M);
    free(M.Table[0]);
    free(M.Table);
}

void test_ReadFile_CorrectFile_returnValidVal_no4() {
    const char* filename = "test_input.txt";
    FILE* f = fopen(filename, "w");
    if (f == NULL) return;
    fprintf(f, "3 2\n");
    fprintf(f, "1 2\n");
    fprintf(f, "2 3\n");
    fclose(f);
    t_matr A;
    t_dlist G;
    int CS;
    ReadFile(filename, &A, &G, &CS);
    printf("Test_ReadFile_CorrectFile_returnValidVal_no4:\n");
    printf("Matrix size: %d\n", A.Size);
    printf("Graph size: %d\n", G.Size);
    printf("Colors: %d\n", CS);
    free(A.Table[0]); free(A.Table);
    free(G.Dots);
    remove(filename);
}

void test_GrapsColoringGreedy_Solvable_returnValidVal_no5() {
    t_matr T;
    SetMatr(3, &T);
    T.Table[0][0] = 0; T.Table[0][1] = 1; T.Table[0][2] = 0;
    T.Table[1][0] = 1; T.Table[1][1] = 0; T.Table[1][2] = 1;
    T.Table[2][0] = 0; T.Table[2][1] = 1; T.Table[2][2] = 0;
    t_dlist G;
    SetList(3, &G);
    int result = GrapsColoringGreedy(T, &G, 2);
    printf("Test_GrapsColoringGreedy_Solvable_returnValidVal_no5:\n");
    printf("Result: %d\n", result);
    for (int i = 0; i < G.Size; i++) {
        printf("Dot %d color: %d\n", G.Dots[i].Number, G.Dots[i].Color);
    }
    free(T.Table[0]); free(T.Table);
    free(G.Dots);
}
void test_GrapsColoringGreedy_Unsolvable_returnFalse_no6() {
    t_matr T;
    SetMatr(2, &T);
    T.Table[0][0] = 0; T.Table[0][1] = 1;
    T.Table[1][0] = 1; T.Table[1][1] = 0;
    t_dlist G;
    SetList(2, &G);
    int result = GrapsColoringGreedy(T, &G, 1);
    printf("Test_GrapsColoringGreedy_Unsolvable_returnFalse_no6:\n");
    printf("Result: %d\n", result);
    free(T.Table[0]); free(T.Table);
    free(G.Dots);
}

void test_WriteFile_possibility_returnValidVal_no7() {
    t_matr T;
    SetMatr(4, &T);
    T.Table[0][1] = 1; T.Table[1][0] = 1;
    T.Table[1][2] = 1; T.Table[2][1] = 1;
    T.Table[2][3] = 1; T.Table[3][2] = 1;
    t_dlist G;
    SetList(4, &G);
    WriteFile("test_output.txt", T, &G, 3);
    printf("Test_WriteFile_possibility_returnValidVal_no7:\n");
    FILE* f = fopen("test_output.txt", "r");
    if (f != NULL) {
        char buf[100];
        printf("File content: ");
        while (fgets(buf, sizeof(buf), f) != NULL) printf("%s", buf);
        fclose(f);
    }
    free(T.Table[0]);
    free(T.Table);
    free(G.Dots);
    remove("test_output.txt");
}

void test_PrintGraph_returnValidVal_no8() {
    t_dlist G;
    SetList(3, &G);
    G.Dots[0].Number = 1; G.Dots[0].Color = 1;
    G.Dots[1].Number = 2; G.Dots[1].Color = 2;
    G.Dots[2].Number = 3; G.Dots[2].Color = 3;
    printf("Test_PrintGraph_returnValidVal_no8:\n");
    PrintGraph(G);
    free(G.Dots);
}

void test_ReadFile_InvalidFormat_returnNull_no9() {
    const char* filename = "empty.txt";
    FILE* f = fopen(filename, "w");
    fclose(f);
    t_matr A;
    t_dlist G;
    int CS;
    ReadFile(filename, &A, &G, &CS);
    printf("Test_ReadFile_InvalidFormat_returnNull_no9:\n");
    remove(filename);
}

void test_GrapsColoringGreedy_IsolatedNode_no10() {
    t_matr T;
    SetMatr(3, &T);
    T.Table[0][0] = 0; T.Table[0][1] = 1; T.Table[0][2] = 0;
    T.Table[1][0] = 1; T.Table[1][1] = 0; T.Table[1][2] = 1;
    T.Table[2][0] = 0; T.Table[2][1] = 1; T.Table[2][2] = 0;
    t_dlist G;
    SetList(3, &G);
    int res = GrapsColoringGreedy(T, &G, 2);
    printf("Test_GrapsColoringGreedy_IsolatedNode_no10:\n");
    printf("Result: %d\n", res);
    for (int i = 0; i < G.Size; i++) {
        printf("Dot %d color: %d\n", G.Dots[i].Number, G.Dots[i].Color);
    }
    free(T.Table[0]);
    free(T.Table);
    free(G.Dots);
}

void AllUnits(void)
{
    test_SetMatr_MinSize_returnValidVal_no1();
    test_SetList_ZeroSize_returnValidVal_no2();
    test_PrintMatr_2x2_returnValidVal_no3();
    test_ReadFile_CorrectFile_returnValidVal_no4();
    test_GrapsColoringGreedy_Solvable_returnValidVal_no5();
    test_GrapsColoringGreedy_Unsolvable_returnFalse_no6();
    test_WriteFile_possibility_returnValidVal_no7();
    test_PrintGraph_returnValidVal_no8();
    test_ReadFile_InvalidFormat_returnNull_no9();
    test_GrapsColoringGreedy_IsolatedNode_no10();
}
