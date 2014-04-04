//--------解法一-------
class Solution {
public:
	int removeDuplicates(int A[], int n) {
	    int last = A[0];
	    if(n==0){
	        return 0;
	    }
	    int new_len=1;
	    for(int i=0;i<n;i++){
	        int temp = A[i];
	        if(temp!=last){
	            A[new_len] = temp;
	            new_len++;
	        }
	        last = temp;
	    }
	    return new_len;
	}

};

//-----------------------


class Solution {
public:
	int removeDuplicates(int A[], int n) {
	    int last = A[0]-1;

	    int new_len=0;
	    for(int i=0;i<n;i++){
	        int temp = A[i];
	        if(temp!=last){
	            A[new_len] = temp;
	            new_len++;
	        }
	        last = temp;
	    }
	    return new_len;
	}

};