class Solution {
    public int maximumPopulation(int[][] logs) {
        // constraint given
        int start = 1950, end = 2050;

        // array to count each year population
        int[] year_c = new int[101];
        int max = 0;
        
        for(int year = start; year <= end; year++){
            for(int i=0;i<logs.length;i++)
                // for each year it will find no. of people
                if(logs[i][0] <= year && logs[i][1] > year)
                    year_c[year-start]++;
            if(year_c[year-start] > max)
                max = year_c[year-start];
        }

        int idx = 0;
        for(int i=0;i<year_c.length;i++)
        // find maximum population in which year
            if(year_c[i] == max){
                idx = 1950 + i;
                break;
            }
        return idx;
    }
}