class Solution {
    // we have to find max area of a Island
    // we will find an island by searching in arr with value 1
    // call the dfs on that index to find the size of that island and mark it as 0,
    // so that we know that we have visited that index
    // check the final area and compare it with ans or max area

    public int maxAreaOfIsland(int[][] arr) {
        int ans = 0; // it will store max area

        // will iterate on arr and find the index having vale 1.
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if (arr[i][j] == 1) {
                    int recAns = dfs(arr, i, j); // call the dfs on the index and get the total area of this island
                    ans = Math.max(ans, recAns); // compare the area of island with max area.
                }
            }
        }

        return ans;
    }

    // function to find area using dfs
    public int dfs(int[][] arr, int i, int j) {
        // if index go out of bound we must return 0
        if (i < 0 || i >= arr.length || j < 0 || j >= arr[0].length || arr[i][j] == 0)
            return 0;

        int ans = 0;
        arr[i][j] = 0; // mark the current index as 0, so that we know that we have visited the index

        // call the function in all 4 direction to cal area
        ans += dfs(arr, i + 1, j);
        ans += dfs(arr, i - 1, j);
        ans += dfs(arr, i, j + 1);
        ans += dfs(arr, i, j - 1);

        return ans + 1; //return total +1 as we must include current index area as well
    }

}