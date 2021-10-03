class Solution {
    public List<List<String>> Anagrams(String[] string_list) {
        HashMap<String,List<String>> map=new HashMap<>();
        List<List<String>> ans=new ArrayList<>();

        for(int i=0;i<string_list.length;i++){
            char [] temp=string_list[i].toCharArray();
            Arrays.sort(temp);
            String sorted=String.valueOf(temp); //sort current word
            
            if(map.containsKey(sorted)){ //if anagram exists, then add to the list
                List<String> list=map.get(sorted);
                list.add(string_list[i]);
                map.put(sorted,list);
            } else{
                List<String> list=new ArrayList<>();
                list.add(string_list[i]);
                map.put(sorted,list); //if anagram group not there, insert new key and list
            }
        }
        for(Map.Entry<String,List<String>> entry:map.entrySet()){
            ans.add(entry.getValue()); //add groups to arraylist
        }
        return ans;
    }
}