#include <iostream>
#include <math.h>
#include <string.h>

#define NUMBER_OF_BINS          3
#define NUMBER_OF_GLASS_TYPES   3

#define BIN_ONE                 0
#define BIN_TWO                 1
#define BIN_THREE               2

#define BROWN_GLASS             0
#define GREEN_GLASS             1
#define CLEAR_GLASS             2

#define BROWN_GLASS_SYMBOL      'B'
#define GREEN_GLASS_SYMBOL      'G'
#define CLEAR_GLASS_SYMBOL      'C'

using namespace std;

int **bins;
char glasses[3]={'B','G','C'};
int minValue=99999999999;
string minConfiguration;

void swap(int * j , int * i)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void solve(int * array,int length){
    int count = 0;
    string configuration = "";
    for(int i=0;i<length;i++){
        int index = array[i];
        int first = (index + 3 - 1) % 3;
        int second = (index + 1) % 3;

        count+=bins[i][first]+bins[i][second];
        configuration+=glasses[index];
    }
    if(minValue==count){
        if(minConfiguration.empty()){
            minConfiguration=configuration;
        }else{
            minConfiguration = strcmp(minConfiguration.c_str(),configuration.c_str())<0?minConfiguration:configuration;
        }
        minValue = min(minValue,count);
    }else{
        minValue = min(minValue,count);
        if(minValue == count){
            minConfiguration=configuration;
        }
    }
}

void permute(int *array,int i,int length) {
    if (length == i){
        solve(array,length);
        return;
    }
    int j = i;
    for (j = i; j < length; j++) {
        swap(array+i,array+j);
        permute(array,i+1,length);
        swap(array+i,array+j);
    }
    return;
}

int main()
{
   while(true){
        bins = (int**)malloc(NUMBER_OF_BINS * sizeof(int*));
        for(int i=0;i<NUMBER_OF_BINS;i++){
            bins[i] = (int*)malloc(NUMBER_OF_GLASS_TYPES * sizeof(int));
            for(int j=0;j<NUMBER_OF_GLASS_TYPES;j++){
                if(!(cin>>bins[i][j])){
                    exit(0);
                }
            }
        }
        int indices[3]={0,1,2};
        permute(indices,0,3);
        cout<<minConfiguration<<" "<<minValue<<endl;
        minConfiguration="";
        minValue=99999999999;
    }
    return 0;
}
