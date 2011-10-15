#include <cstdio>
#include <cstdlib>
#include <string>
#include<iostream>
using namespace std;

void func(string ik,string k){
int z=ik.find(k),o=0;
while (z!=-1) {z=ik.find(k,z+k.size());o++;}
cout<<o<<endl;
}

int nextInt(){
char x= getchar();
int result=0;
while(x >='0' and x <='9'){
result*=10;
result+=x-'0';
x=getchar();
}
return result;
}

int main(){

int cnt;
cnt=nextInt();
for(int i=0;i<cnt;i++){
int len; len=nextInt();
string str;
cin>>str;
//cout<<str<<endl;
nextInt();
int qu; qu=nextInt();
int i1,j1;
for(int j =0;j<qu;j++){
i1=nextInt();
j1=nextInt();
string substr = str.substr(i1,j1);
func(str,substr);
}
}
return 0;
}

