

string dayOfProgrammer(int year) {
    string y = "";
    int temp = year;

    // changed year from int to string

    while(temp){
        y.push_back(('0'+(temp%10)));
        temp/=10;
    }
    reverse(y.begin(),y.end());
    string ans;

    // there are three cases 
    

    if(year<=1917){
        
        // Julian Calender

        if(year%4==0){
            ans = "12.09."+y;
        }else{
            ans = "13.09."+y;
        }
    }else if(year==1918){

        // Transition year

        ans = "26.09."+y;
    }
    else{

        // Gregorian Calendar

        if(((year%4 ==0) && (year%100!=0)) || (year%400==0) ){
            ans = "12.09."+y;
        }else{
            ans = "13.09."+y;
        }
    }
    
    return ans;

}
