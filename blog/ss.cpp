 #include <iostream>
#include <vector>

using namespace std;


    string getPermutation(int n, int k) {
        vector<int> perm(n,0);
        for(int i=0;i<n;i++) perm[i]=i+1;
        
        int Aii = 1;
        int i=1;
        while(Aii<k){
            Aii *= i;
            i++;
        }

        i--;

        int j = n-i-1; //需要变化的
        cout<<i<<endl;
        cout<<Aii<<endl;
        
        //i是已经全排序的后i位数
        
        while(i>0){
            int tmp = (k-1)/Aii; // * 相对于第一个增加了几？
            int j = n-i-1;
            if(j>=0){
                sort(perm.begin()+j, perm.end());
                swap(perm[j], perm[j+tmp]);
            }
            k -= tmp*Aii;
            Aii /= i;
            i--;
        }
        
        string permStr(n,' ');
        for(int i=0;i<n;i++) permStr[i]=perm[i]+'0';
        return permStr;
    }


int main(){
    cout<<getPermutation(4,10);
}