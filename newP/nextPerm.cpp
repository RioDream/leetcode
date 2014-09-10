#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int* A, int n){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
}


void nextPerm(int* A, int n){
    //1.找到最后一个升序
    int lastChangeable = -1;
    int i;
    for(i=0;i<n-1;i++){
        if(A[i]<A[i+1]) lastChangeable = i;
    }

    if(lastChangeable==-1){
        reverse(A, A+n-1);
        return;
    }

    //2.找到后面刚刚大于这个数的数， 注意后面的是降序排列的
    for(i=lastChangeable+1;i<n;i++){
        if(A[i]<A[lastChangeable]) break;
    }
    i--;

    //3. swap and reverse
    swap(A[lastChangeable], A[i]);
    reverse(A+lastChangeable+1, A+n-1);
}

int main(){

    int A[] = {4,3,2,1};
    printArr(A,4);

    nextPerm(A, 4);
    printArr(A,4);

    nextPerm(A, 4);
    printArr(A,4);

    nextPerm(A, 4);
    printArr(A,4);
}


