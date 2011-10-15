#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int T,tc,N,WT,idx,maks;
int W[16], V[16], F[16];
vector<pair<int,int> > ar[2];

int main() {
	cin>>T;
	for(tc=1;tc<=T;tc++) {
		cin>>N>>WT;
		for(int i=0;i<N;i++) {
			cin>>W[i]>>V[i]>>F[i];
		}
		ar[0].clear(); ar[1].clear();
		ar[0].push_back(make_pair(0,0));
		maks=-1;
		idx=0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<F[i];j++) {
				ar[1-idx].clear();
				maks=-1;
				//cout<<"start"<<endl;
				for(int k=0;k<ar[idx].size();k++) {
					if(maks>=-ar[idx][k].second) continue;
					//cout<<"("<<ar[idx][k].first<<","<<-ar[idx][k].second<<") ";
					maks=-ar[idx][k].second;
					//if that chem is taken
					if(ar[idx][k].first+W[i]<=WT) ar[1-idx].push_back(make_pair(ar[idx][k].first+W[i],ar[idx][k].second-V[i]));
					//if that chem isnt taken
					ar[1-idx].push_back(make_pair(ar[idx][k].first,ar[idx][k].second));
				}
				//cout<<endl<<"end"<<endl;
				//getchar();
				sort(ar[1-idx].begin(),ar[1-idx].end());
				idx=1-idx;
			}
		}
		maks=-1;
		//cout<<"start"<<endl;
		for(int k=0;k<ar[idx].size();k++) {
			if(maks>=-ar[idx][k].second) continue;
			//cout<<"("<<ar[idx][k].first<<","<<-ar[idx][k].second<<") ";
			maks=-ar[idx][k].second;
		}
		//cout<<"end"<<endl;
		cout<<maks<<endl;
	}
}
