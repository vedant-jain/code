// https://codeforces.com/problemset/problem/1321/C

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main() {
	ll n;
	cin>>n;
 
	string s;
	cin>>s;
 
	if(s.length() == 1) {
		cout<<0<<"\n";
		exit(0);
	}
 
	map <char,vector<ll>> m;
	map <char,vector<ll>>::reverse_iterator it;
 
	for(int i = 0; i < n; i++) {
		m[s[i]].push_back(i);
	}
 
	ll ctr = 0,ind,k;
 
	for(it = m.rbegin(); it != m.rend(); it++) {
		if(it->first == 'a')
			continue;
		for(int j = 0; j < it->second.size(); j++) {
			ind = it->second[j];
			if(ind != n-1) {
				k = ind + 1;
				while(k < n && (s[k] == '#' || s[k] == s[ind])) 
					k++;
				if(k != n) {
					if(s[ind] - s[k] == 1) {
						s[ind] = '#';
						ctr++;
					}
				} 
			}				
			if(s[ind] != '#') {
				if(ind != 0) {
					k = ind - 1;
					while(k >= 0 && (s[k] == '#' || s[k] == s[ind]))
						k--;
					if(k != -1) {
						if(s[ind] - s[k] == 1) {
							s[ind] = '#';
							ctr++;
						}
					}	
				}									
			}
		}
	}
	cout<<ctr<<"\n";
}