#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int o, e, t, n, temp, turn;
	scanf("%d", &t);
	while(t--)
	{
		o = e = 0;
		turn = 1;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &temp);
			temp % 2 == 0 ? e++ : o++;
		}

		while(o + e != 1)
		{
			if(turn % 2 == 1) //odd turn
			{
				if(e >= 2) e -= 2, o++;
				else if(o > 1) o--;
				else o--; //does not support
			}
			else
			{
				if(o >= 2) o -= 2, e++; //support
				else if(e > 1) e--;  //support
				else e--; //does not support
			}
			turn++;
		}
		if(o == 1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}
