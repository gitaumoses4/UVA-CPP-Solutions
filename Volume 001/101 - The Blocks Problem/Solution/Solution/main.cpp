#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int **blocks;
int *location_i;
int *location_j;
int numberOfBlocks;

void printBlocks(){
    for(int i=0;i<numberOfBlocks;i++){
        blocks[i]=(int*)malloc(numberOfBlocks * sizeof(int));
        for(int j=0;j<numberOfBlocks;j++){
            blocks[i][j]=-1;
        }
    }
    for(int i=0;i<numberOfBlocks;i++){
        blocks[location_i[i]][location_j[i]]=i;
    }
    for(int j=0;j<numberOfBlocks;j++){
        printf("%d:",j);
        for(int i=0;i<numberOfBlocks;i++){
            if(blocks[j][i]!=-1){
                printf(" %d",blocks[j][i]);
            }
        }
        printf("\n");
    }
}

void moveAontoB(int a,int b){
    int start=location_j[b];
    for(int i=0;i<numberOfBlocks;i++){
        if(location_i[i]==location_i[b] && location_j[i]>start){
            start = location_j[i];
        }
        if((location_i[i]==location_i[a] && location_j[i]>location_j[a]) &&
                (location_i[i]==location_i[b] && location_j[i]>location_j[b])){
            location_i[i]=i;
            location_j[i]=0;
        }
    }
    location_i[a]=location_i[b];
    location_j[a]=start+1;
}

void moveAoverB(int a, int b){
    int start=location_j[b];
    for(int i=0;i<numberOfBlocks;i++){
        if(location_i[i]==location_i[b] && location_j[i]>start){
            start = location_j[i];
        }
        if((location_i[i]==location_i[a] && location_j[i]>location_j[a])){
            location_i[i]=i;
            location_j[i]=0;
        }
    }
    location_i[a]=location_i[b];
    location_j[a]=start+1;
}

void pileAoverB(int a,int b){
    int start=location_j[b];
    for(int i=0;i<numberOfBlocks;i++){
        if(location_i[i]==location_i[b] && location_j[i]>=start){
            start = location_j[i];
        }
    }
    for(int i=0;i<numberOfBlocks;i++){
        if(location_i[i]==location_i[a] && location_j[i]>=location_j[a]){
            location_j[i]=start+location_j[i]-location_j[a]+1;
            location_i[i]=location_i[b];
        }
    }
}

void pileAontoB(int a,int b){
    int start=location_j[b];
    for(int i=0;i<numberOfBlocks;i++){
        if(location_i[i]==location_i[b] && location_j[i]>start){
            start = location_j[i];
        }
        if((location_i[i]==location_i[b] && location_j[i]>location_j[b])){
            location_i[i]=i;
            location_j[i]=0;
        }
    }
    for(int i=0;i<numberOfBlocks;i++){
        if(location_i[i]==location_i[a] && location_j[i]>=location_j[a]){
            location_j[i]=start+location_j[i]-location_j[a]+1;
            location_i[i]=location_i[b];
        }
    }
}

int main()
{
    scanf("%d",&numberOfBlocks);

    blocks = (int**)malloc(numberOfBlocks * sizeof(int*));
    location_i = (int*) malloc(numberOfBlocks * sizeof(int));
    location_j = (int*) malloc(numberOfBlocks * sizeof(int));
    for(int i=0;i<numberOfBlocks;i++){
        location_i[i]=i;
        location_j[i]=0;
    }
    int canLoop = 1;
    while(canLoop){
        char command1[5], command2[5];
        int a, b;
        std::cin>>command1;
        if(strcmp(command1,"quit")==0){
            canLoop = 0;
            break;
        }else{
            std::cin>>a>>command2>>b;
            if(location_i[a] == location_i[b]){
                continue;
            }
            if(strcmp(command1,"move")==0){
                if(strcmp(command2,"onto")==0){
                    moveAontoB(a,b);
                }else{
                    moveAoverB(a,b);
                }
            }else{
                if(strcmp(command2,"onto")==0){
                    pileAontoB(a,b);
                }else{
                    pileAoverB(a,b);
                }
            }
        }
    }
    printBlocks();
}
