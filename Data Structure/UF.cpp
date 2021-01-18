#include<bits/stdc++.h>
using namespace std;

class UF{
public:
	int n;
	vector<int> v;
	vector<int> s;

	UF(int num){
		n=num;
		v.resize(n);
		s.resize(n);
		for(int i=0;i<n;i++){
			v[i]=i;
			s[i]=1;
		}
	}

	void union1(int u,int v){
		int ru=root(u);
		int rv=root(v);
		if(s[ru]>s[rv]){
			this->v[rv]=ru;
			s[ru]+=s[rv];
		}
		else{
			this->v[ru]=rv;
			s[rv]+=s[ru];
		}
	}

	bool connected(int u,int v){
		if(root(u)==root(v))
			return true;
		return false;
	}

	int root(int i){
		while(i!=v[i]){
			v[i]=v[v[i]];
			i=v[i];
		}
		return i;
	}
};

int main(){
	int n;cin>>n;
	UF uf(n);
	while(true){
		char c;int u,v;
		cin>>c;
		if(c=='q')
			break;
		if(c=='u'){
			cin>>u>>v;
			uf.union1(u,v);
		}
		else if(c=='c'){
			cin>>u>>v;
			cout<<uf.connected(u,v)<<endl;
		}
	}
	return 0;
}