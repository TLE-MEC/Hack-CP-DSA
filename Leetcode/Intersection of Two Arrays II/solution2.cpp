vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;   //Result vector
        map<int, int> freq;   // A map to keep track of elements and their count in the first array
        for(int i: nums1)      //Traversing through the 1st vector
            freq[i]++;           //Inserts i into the map and adds the count by 1 or adds the count by 1 if the element already exists in the map
        for(int i: nums2){       //Traversing through the 2nd vector
            if(freq[i] > 0){      //If the element exists with count>0
                freq[i]--;            //Count is decreased and the element is added to the result vector
                res.push_back(i);
            }
        }
        return res;
    }
