class Solution {
    public int trap(int[] height) {
        //create 2 temprory array
        int a[] = new int[height.length];
        int b[] = new int[height.length];
        int min = Integer.MIN_VALUE;
        //first we are finfig min hight while traversing height array form left to right
        for(int i=0;i<height.length;i++){
            if(min<height[i]){
             min=height[i];
            }
            a[i]=min;
        }
        //fnow we are finfig min hight while traversing height array form right to left
        min = Integer.MIN_VALUE;
        for(int i=height.length-1;i>=0;i--){
            if(min<height[i]){
             min=height[i];
            }
            b[i]=min;
        }
        int total_water=0;
        //at last we will add min number from temrory array and minus hight which is not coming in use while storing water
        for(int i=0;i<height.length;i++){
            total_water+= Math.min(a[i],b[i])-height[i];
        }
        return total_water;   
    }
}

