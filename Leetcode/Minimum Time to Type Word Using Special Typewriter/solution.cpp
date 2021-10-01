class Solution {
public:
    int minTimeToType(string word) {
        int time=word.length();
        cout<<"time="<<time<<"\n";
        int c=(int)word[0]-97;
        int x;
        if(26-c>c){
            time+=c;
            x=c;
        }
        else{
            time+=(26-c);
            x=26-c;
        }
        cout<<"time="<<time<<"\n";

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
        return time;
    }
};
