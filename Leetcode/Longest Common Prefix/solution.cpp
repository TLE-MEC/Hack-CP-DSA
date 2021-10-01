char * longestCommonPrefix(char ** strs, int strsSize)
{
    // if string size is 0 then return "".
    if(strsSize==0) return "";
    // simple run a for loop while fixing first element and then compare it with others.
    for(int i=0;i<strlen(strs[0]);i++)
    {
          for(int j=1;j<strsSize;j++)
          {
              if(strs[0][i]!=strs[j][i])
              {
                   // as soon as our loop char not match it means we the longest sting so return it.
                   strs[0][i]='\0';
                   return strs[0];
             }
         }
    }
 return strs[0];
}
