class Solution
{ 
    static double medianOfArrays(int n, int m, int a[], int b[]) 
    {
        //Creating ArrayList
        ArrayList<Integer> merged= new ArrayList<>();
        

	//Adding numbers to ArrayList
        for(int i=0; i<n; i++) {
            merged.add(a[i]);
        }
        for(int i=0; i<m; i++) {
            merged.add(b[i]);
        }
        

	//sorting
        Collections.sort(merged);

	//finding answer
        
        if(merged.size()%2==0) {
            int mid1= merged.get(merged.size()/2);
            int mid2= merged.get(merged.size()/2 - 1);
            
            return (((double)mid1+mid2)/2);
        }
        
        return (double)merged.get(merged.size()/2);
    }
}
