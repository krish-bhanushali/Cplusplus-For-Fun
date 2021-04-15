#include <iostream>
#include <cstdio>
using namespace std;



int max_of_two(int a,int b){
    return a>=b?a:b;
}

int max_of_three(int a,int b,int c){
    if(a>=max_of_two(b,c)){
        return a;
    }
    else if(b>=max_of_two(a,c)){
        return b;
        
    }
    else{
        return c;
    }
}



int max_of_four(int a,int b,int c,int d){
  if(a>=max_of_three(b,c,d)){
      return a;
  }else if(b>=max_of_three(a,c,d)){
      return b;
  }else if(c>=max_of_three(a,b,d)){
      return c;
  }else{
      return d;
  }
}
//above function can be done using one line but for readability it is broken down into pieces

int max_of_four_loop(int a,int b,int c,int d){
    int arr[4] = {a,b,c,d} ;
    int max = 0;
    for(int i=0;i<4;i++){
        if(arr[i]>=max){
            max = arr[i];
        }
    }
    return max;
}

//another method

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    //uncomment one of the bellow lines to get answer
    // int ans = max_of_four_loop(a, b, c, d);
    // int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
