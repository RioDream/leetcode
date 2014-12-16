#include <iostream>
#include <math.h>

using namespace std;

int numberOfOne(int n){
    int highNum=-1;
    int lowNum=0;
    int currNum=0;
    int count = 0;
    int digit=0;
    while(highNum!=0){
        
        currNum = n%10;
        highNum = n/10;

        switch(currNum){
            case 0:
                count += highNum*pow(10,digit);
                break;
            case 1:
                count += highNum*pow(10,digit) + lowNum + 1;
                break;
            default:
                count += (highNum+1)*pow(10,digit);
        }

        lowNum = currNum*pow(10,digit)+lowNum;
        digit++;
        n /= 10;
    }
    return count;
}

int main(){
    cout<<numberOfOne(123)<<endl;
}