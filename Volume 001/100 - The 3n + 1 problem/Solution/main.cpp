#include <iostream>
#include <math.h>
#include <map>

std::map<int,int> myMap;

int solve(int original,int n, int count){
    if( n<=1 ){
        myMap.insert(std::make_pair(original,count+1));
        return count+1;
    }else{
        if(myMap.find(n)!=myMap.end()){
            int value = myMap.at(n);
            myMap.insert(std::make_pair(original,count+value));
            return count+value;
        }else{
            return solve(original, n%2==0?n/2:3*n+1, count+1 );
        }
    }
}

int main()
{
    int a,b;
    while(std::cin>>a>>b){
        int min = a<b?a:b;
        int max = a<b?b:a;

        int greatest = 0;
        for(int i=min; i<=max;i++){
            int result;
            if(myMap.find(i)!=myMap.end()){
                result = myMap.at(i);
            }else{
                result = solve(i,i,0);
            }
            greatest = greatest<result?result:greatest;
        }
        std::cout<<a<<" "<<b<<" "<<greatest<<std::endl;
    }
}
