#include <iostream>
#include <vector>

using namespace std;
int main(){
	//Take input
	int T;	//num of test cases
	cin>>T;
	vector< vector<int> > nums;
	for(int i=0; i<T; i++){
		int N;	//number of integers
		cin>>N;
		vector<int> numsIn;
		
		for(int j=0; j<N; j++){
			int temp;
			cin>>temp;
			numsIn.push_back(temp);
		}
		nums.push_back(numsIn);
	}
	for(int i=0; i<T; i++){
		for(int j=0; j<nums[i].size(); j++){
			if(nums[i].size()==1)
				break;
			int a=nums[i].back();
			nums[i].pop_back();
			int b=nums[i].back();
			nums[i].pop_back();
			nums[i].push_back(a+b-(j+1));
		}
		if(nums[i][0]&1)
			cout<<"WIN"<<endl;
		else cout<<"LOSE"<<endl;
	}
	return 0;
}
	
		
