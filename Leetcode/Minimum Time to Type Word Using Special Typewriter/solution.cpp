// solution class
class Solution {
//public access-modifier
public:
    //function with a string parameter to check the time to type that parameter
    int minTimeToType(string word) {
        //initialize time as length of the parameter
        int time=word.length();
        //mid-way testing for output
        cout<<"time="<<time<<"\n";
        //converting character to position in alphabets using ascii value
        int c=(int)word[0]-97;
        //initialize a variable
        int x;
        //if the position of alphabet is closer to A, then directly add the position to the time value.
        if(26-c>c){
            time+=c;
            x=c;
        }
        //else add 26-position to time for getting minimum time
        else{
            time+=(26-c);
            x=26-c;
        }
        //completion of first character in the parameter
        //checking time again to verify the result
        cout<<"time="<<time<<"\n";
        //iterating over the other characters of the string to add minimum distance of next character from the current character.
        for(int i=1;i<word.length();i++){
            int f=(int)word[i]-97;
            int g=(int)word[i-1]-97;
            // cout<<f<<" "<<g<<" "<<abs(f-g)<<" "<<<<"\n";
            if(26-abs(-g+f)>abs(f-g)){
                // cout<<f-x;
                time+=abs(f-g);                
                // cout<<time<<endl;
            }
            else{
                time+=26-abs(-g+f);
            }
            cout<<"time="<<time<<"\n";

        }
        //returning the value of time as calculated above
        return time;
    }
};
