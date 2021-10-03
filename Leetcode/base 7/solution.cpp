/*Approach:
1) First we will check for number, if(num == 0), then we return "0".
2) We are using flag variable for identifying the number as positive or negative.
3) we are converting the number into positive.
4) Then we are iterating and each time we push the remainder into the string and number is decremented to num/7 until the number is zero.
5) After looping we are reversing the string and checking for the negative number if flag==1 then it is negative so we are adding negative sign and beginning and then returning the string.*/

string convertToBase7(int num) {
        if(num==0) return "0";
        string ret;
        int flag=0;
        if(num<0)
            flag=1;
        num = abs(num);
        while(num != 0){
            ret.push_back((num%7)+'0');
            num/=7;
        }
        reverse(ret.begin(),ret.end());
        if(flag==1){
            ret.insert(ret.begin(),'-');
        }
        return ret;
    }