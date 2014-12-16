#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


class cls{
public:
    cls(){
        cout<<"jj"<<endl;
    }
};

int my_add(int x, int y){
    int carry = y;
    while(carry){
        int tmp = carry;
        carry = (x&carry)<<1;
        x = x^tmp;
    }
    return x;
}

int main(){
    cout<<((-7%3))<<endl;
    //cout<<(mod(-7,3))<<endl;
}