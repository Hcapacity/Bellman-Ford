#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#define _INF 99999999

#include<string>
#include<vector>

using namespace std;

int ctoin(char C);
char intoc(int num);
void FPrevious_Index(int Pre_Array[], int& Current_Index, int& Previous_Index);
void BF(int G[30][30], int Num_Ver, char Start_Ver, int Val_Array[], int Pre_Array[]);
string BF_Path(int G[30][30], int Num_Ver, char Start_Ver, char Goal_Ver);


#endif // BELLMAN_FORD_H