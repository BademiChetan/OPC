#include<iostream>

using namespace std;

main(){
  
  int t,n,a[200];
  
  cin>>t;
  
  while(t--){
    cin>>n;
    if(n==1){
      if(n%2==0)
	cout<<"LOSE"<<endl;
      else
	cout<<"WIN"<<endl;
      continue;
    }
    for(int i=0;i<n;i++)
      cin>>a[i];
    if(n==2){
      if(a[0]%2==1 && a[1]%2==0 ||a[0]%2==0 && a[1]%2==1)
	cout<<"LOSE"<<endl;
      else
	cout<<"WIN"<<endl;
      continue;
    }
    int res=0;
    for(int i=0;i<n;i++){
      if(a[i]%2==0)
	res = res^1;
      else
	res = res^0;
    }
    if(res == 0 && n%2==0 || res==1 && n%2==1)
      cout<<"WIN"<<endl;
    else
      cout<<"LOSE"<<endl;
  }
}
