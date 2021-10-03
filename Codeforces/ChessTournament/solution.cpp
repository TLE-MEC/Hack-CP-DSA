/*
Each chess game ends in either a win for one player 
and a loss for another player, or a draw for both players.
Expectations of the player can be of 2 types: 
1. a player wants not to lose any game (i. e. finish the tournament with zero losses);
2. a player wants to win at least one game.

Output : Print "YES" and the sequence if it is possible to meet the expectations of the players.
         else print  "NO"

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,j,n) for(int i= j;i<n;i++)
#define COUNT(vect, n) count(vect.begin(), vect.end(), n)
#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);
 
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        vector<vector<char>> v(n, vector<char> (n));
        //if all players *dont want to lose the game* => Draw all matches.
        if (COUNT(s,'1')==n) {
            rep(i,n){
                rep(j,n){
                    (i==j)? v[i][j]='X':v[i][j]='=';
                }
            }
        }
        // if Count of players who wants to win atleast 1 game is <= 2
        // print "NO" => Impossible Case 
        if (COUNT(s,'2')==2 || COUNT(s,'2')==1) cout << "NO\n";
        else{
            rep(i,n){
                char c = s[i];
                // else if string[i] == '1' => draw all of it's corresponding games.
                if (c=='1'){
                    rep(j,n){
                        v[i][j] = '=';
                        v[j][i] = '=';
                    }
                }
                else{
                    // else alternately, let player1 win one match
                    //and player2 lose next match using brute force
                    bool set=false;
                    repp(j,i+1,n){
                        if(s[j]=='2'){
                            if (!set){
                                v[i][j] = '+';
                                v[j][i] = '-';
                                set = true;
                            }
                            else {
                                v[i][j] = '-';
                                v[j][i] = '+';
                            }
                        }
                    }
                }
            }
            // for all i==j set Verdict = 'X'
            rep(i,n) v[i][i] = 'X';
            cout << "YES\n";
            // print sequence
            for(auto i:v){
                for(auto j:i) cout << j;
                cout << endl;
            }
        }
    }
    return 0;
}
