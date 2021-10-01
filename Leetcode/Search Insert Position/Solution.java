Class Solution{

public int searchInsert(int[]nums,int target){

        int min=0;
        int max=nums.length-1;
        int mid=(max+min)/2;

        while(min<=max){


        if(nums[mid]==target)return mid;

        //if(nums[min] < target && nums[max] > target) return mid;

        else if(min==max){

        if(nums[mid]>target)return mid;
        else return mid+1;

        }
        else if(min==mid){
        if(nums[mid]>target)return mid;
        }

        if(nums[mid]<target)min=mid+1;
        else if(nums[mid]>target)max=mid-1;

        mid=(max+min)/2;

        }

        return 0;
        }

}