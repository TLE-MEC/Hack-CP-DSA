public class Solution {

	public static void main(String[] args) {
	
		int[] arr = {0,2,4,7,9,11,8,6,5,3,1};
		int ans = search(arr);
		System.out.print(ans);
	}
	
	static int search(int[] arr) {
		int start = 0;
		int end = arr.length-1;
		
		while(end>start) {
			int mid = start + (end-start)/2;
			if(arr[mid]>arr[mid+1]) {
				// You are in dec part of array
				// This may be the ans but look at left too
				end = mid;
			}else {
				//You are in asc part of array
				//mid+1 maybe the ans but look at right too
				start = mid+1;
			}
			
		}
			return start; //also end will be fine
		
	}

}
