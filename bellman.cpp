#include "bellman.h"

using namespace std;

int ctoin(char C){
    return int(C - 'A');
}

char intoc(int num){
    return char(num + 'A');
}

void FPrevious_Index(int Pre_Array[], int& Current_Index, int& Previous_Index){
    Previous_Index = Pre_Array[Current_Index];
    Current_Index = Previous_Index;
}

void BF(int G[30][30], int Num_Ver, char Start_Ver, int Val_Array[], int Pre_Array[]){

// Check first step
    bool Check_First = true;
    for(int i = 0; i < Num_Ver; i++){
        if(Val_Array[i]  == -1);
        else {
            Check_First = false;
            break;
            }
    }


//Start BF at step 0
    if(Check_First){
        for(int i = 0; i < Num_Ver; i++){
            if(G[ctoin(Start_Ver)][i] != 0){
                Val_Array[i] = G[ctoin(Start_Ver)][i];
                Pre_Array[i] = ctoin(Start_Ver);
            }
        }
        Val_Array[ctoin(Start_Ver)] = 0;
    }

    int Pre_Val_Array[Num_Ver];
    for(int i = 0; i < Num_Ver; i++){
        if(Val_Array[i] == -1){
            Val_Array[i] = _INF;
        }
        Pre_Val_Array[i] = Val_Array[i];
    }

// 1 Step BF
    if(!Check_First){
        for(int i = 0; i < Num_Ver; i++){
            for(int j = 0; j < Num_Ver; j++){               
                if(G[i][j] != 0){
                    if(Pre_Val_Array[i] + G[i][j] < Val_Array[j] && Pre_Val_Array[i] != _INF){
                        Val_Array[j] =  Pre_Val_Array[i] + G[i][j];
                        Pre_Array[j] = i;
                    }                    
                }
            }
        }
    }

    for(int i = 0; i < Num_Ver; i++){
        if(Val_Array[i] == _INF){
            Val_Array[i] = -1;
        }
    }
    
}


string BF_Path(int G[30][30], int Num_Ver, char Start_Ver, char Goal_Ver){

    string bf_Path = "";
    if(Start_Ver == Goal_Ver){
        bf_Path += Start_Ver;
        return bf_Path;
    }

    int Val_Array[30];
    int Pre_Array[30];

    for(int i = 0; i < Num_Ver; i++){
        Val_Array[i] = -1;
        Pre_Array[i] = -1;
    }

//Run BF.
    for(int i = 0; i < Num_Ver; i++){
            if(G[ctoin(Start_Ver)][i] != 0){
                Val_Array[i] = G[ctoin(Start_Ver)][i];
                Pre_Array[i] = ctoin(Start_Ver);
            }
        }
    Val_Array[ctoin(Start_Ver)] = 0;

    for(int i = 0; i < Num_Ver; i++){
        if(Val_Array[i] == -1){
            Val_Array[i] = _INF;
        }
    }
    
    int Pre_Val_Array[Num_Ver];
    for (int k = 0; k < Num_Ver - 1; k++){
        for(int i = 0; i < Num_Ver; i++){
            Pre_Val_Array[i] = Val_Array[i];
        }
        for(int i = 0; i < Num_Ver; i++){
            for(int j = 0; j < Num_Ver; j++){               
                if(G[i][j] != 0){
                    if(Pre_Val_Array[i] + G[i][j] < Val_Array[j] && Pre_Val_Array[i] != _INF){
                        Val_Array[j] =  Pre_Val_Array[i] + G[i][j];
                        Pre_Array[j] = i;
                    }                    
                }
            }
        }
    }

// Find Previous Path depending on Pre_Arr
    int Cur_Index = ctoin(Goal_Ver);
    int Pre_Index = -1;


    while(Pre_Index != ctoin(Start_Ver)){
        bf_Path += (char)(Cur_Index + 'A');
        bf_Path += " ";
        FPrevious_Index(Pre_Array, Cur_Index, Pre_Index);
    }
    bf_Path += Start_Ver;

    string Complete_bf_Path = "";
    for(int i = 0; i < bf_Path.size(); i++){
        Complete_bf_Path += bf_Path[bf_Path.size() - 1 - i];
    }

    return Complete_bf_Path;
}

