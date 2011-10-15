#include<iostream>
#include<string>
using namespace std;

int main() {
	int t,n,q,m,k,flag,count;
	string s;
	cin >> t;		// number of test cases.
	for(int i=0;i<t;i++) {
		cin >> n;		// length of the string.
		cin >> s;
		cin >> q;
		for(int j=0;j<q;j++) {
			count=0;
			cin >> m >> k;		// m is the starting point, k is the length of substring.
			for(int a=0;a<m;a++) {
				if(s[a]==s[m]) {
					flag=1;
					for(int b=m+1,c=a+1;b<m+k;b++,c++) {
						if(s[b]!=s[c]) { 
							flag=0; 
							break; 
						  }
					  }
					if(flag==1) count++;
				  }
			  }
			for(int a=m+1;a<=n-k;a++) {
				if(s[a]==s[m]) {
					flag=1;
					for(int b=m+1,c=a+1;b<m+k;b++,c++) {
						if(s[b]!=s[c]) { 
							flag=0; 
							break; 
						  }
					  }
					if(flag==1) count++;
				  }
			  }
			cout << count+1 << endl;
		  }
	  }
}
