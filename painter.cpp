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
	int N;
        string S;
	cin >> N >> S;
	
	map<char,set<char>> color = { {'U',{}}, {'R',{'R'}}, {'Y',{'Y'}}, {'B',{'B'}}, {'O',{'R','Y'}}, {'P',{'R','B'}},
	 {'G',{'B','Y'}}, {'A',{'R','B','Y'}} };
	int draw = 0;
	char cur = 'U';
	
	//vector<set<char>> paint (N, {});
	vector<char> basic = {'Y','R','B'};
	
	for(int i=0; i<3; ++i){
	   for(int j=0; j<N; ++j){
	      if((color[S[j]].find(basic[i]) != color[S[j]].end()) && (cur != basic[i])){
	         ++draw;
	         cur = basic[i];
	      }
	      else if (color[S[j]].find(basic[i]) == color[S[j]].end() ){
	         cur = 'U';
	      }
	   
	   }
	}
        
        cout << "Case #" << t << ": " << draw << "\n";
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
