#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<utility>
using namespace std;

int main()
{
	int t, l, q, m, n;
	int count;
	int p1, p2, start;
	string s;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &l);
		cin >> s;
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &m, &n);
			string subs (s, m, n);
			count = 0;
			for(start = 0; start < l - n + 1; start++)
			{
				p1 = start;
				p2 = 0;
				while(p1 < l && p2 < n && s[p1] == subs[p2])
				{
					p1++;
					p2++;
				}
				if(p2 == n)
				{
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}


