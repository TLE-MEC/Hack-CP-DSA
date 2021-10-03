//XOR - returns 1 if two bits are different
//'^' - Bitwise XOR

//2^i = i << 1
//let i = 2, 2 left shift by 1 = 4, 2^2 = 4
//With every loop, value of 'ans' is updated

class Solution {
public:
    int xorOperation(int n, int start) {

		int ans =0;
		for(int i=0;i<n;i++){
			ans ^= start + 2^i;
		}
		return ans;

    }
};
