#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int countPermutations = 0;
int expected = 0;

int val(char c){
    if(c >= '0' && c<= '9'){
        return (int)c - '0';
    }else{
        return (int)c - 'A' + 10;
    }
}

void solve(int *array, int length){
    int total =0;
    for(int i=1;i<=length;i++){
        int index = array[i-1];
        total += abs(index-i);
    }
    if(total == expected){
        countPermutations++;
    }
}
void swap(int * j , int * i)
{
    int temp=*i;
    *i=*j;
    *j=temp;
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
    int number;
    while(cin>>number){
        expected = floor(pow(number,2)/3.0);
        int * array = (int*)malloc(number * sizeof(int));
        for(int i=1;i<=number;i++){
            array[i-1]=i;
        }
        permute(array,0,number);

        cout<<countPermutations%1000000007<<endl;
        countPermutations=0;
    }
    return 0;
}
