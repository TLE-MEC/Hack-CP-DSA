#Function to return unique characters from passed substrings
def uniq_str(s):
    r_str = ""
    for char in range(len(s)):
        if r_str.count(s[char:char+1]) != 1:
            r_str += s[char:char+1]
    return r_str

#Main function that'll be executed
def merge_the_tools(string, k):
    st = ""
    for i in range(int(len(string)/k)):
        s = string[i*k:i*k+k]    #Breaking off the main string into multiple substrings of length k
        st += uniq_str(s) + "\n" #Cumulative addition of output for each substring
    i = len(st)
    print(st[0:i-1])
    return 0

