class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int last = A[0];
		int sameCount = 0;
		int new_len = n;
		for (int i = 0; i < new_len; i++){
			int temp = A[i];
			if (temp == last && i!=new_len-1){
				sameCount += 1;
			}
			else if (temp == last && i == new_len - 1){
				sameCount += 1;
				int dis = sameCount - 1;
				new_len -= dis;
				return new_len;
			}
			else if (sameCount != 1){
				int dis = sameCount - 1;
			
				
				int dest = i - dis;
				moveForward(A, n, i, dest);
				new_len -= dis;
				i -= dis;
				sameCount = 1;
			}
			last = temp;
		}

		return new_len;

	}

private:
	void moveForward(int A[], const int n, const int start, int dest){
		for (int i = start; i < n; i++){
			A[dest] = A[i];
			dest++;
		}
	}
};