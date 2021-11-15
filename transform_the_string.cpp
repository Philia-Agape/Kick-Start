#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <bitset>
#include <forward_list>
#include <list>
#include <stack>


using namespace std;



void solve(int t){
	string S, F;
	cin >> S >> F;
	
	vector<bool> flag (26, false);
	int op = 0, temp = 26;
	
	for(int i=0; i<F.size(); ++i){ 
	   flag[F[i]-'a'] = true;
        }
        
        for(int i=0; i<S.size(); ++i){
           temp = 26;
           if(!flag[S[i]-'a']){
              for(int j=0; j<26; ++j){
                 if(flag[j]){
                    temp = min(abs(S[i]-'a'-j), temp);
                    temp = min(26 - abs(S[i]-'a'-j), temp);
                 }
              }
              op += temp;
           }
        }
        
        cout << "Case #" << t << ": " << op << "\n";
        return;
}

int main() {
	int T;
	cin >> T;
        for (int i=1; i<=T; ++i){
           solve(i);
        }
	return 0;
}
