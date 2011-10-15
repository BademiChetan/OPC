#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <cstdio>
using namespace std; 

struct node{
  int value ;
  int cost;
  float rank;
  int available;
} myobject;

bool mycomparator (struct node i,struct node j) { return (i.rank > j.rank); }

int solution(vector<node> input, int index,int budget){
  
  if (budget <= 0 )
    return 0;
  if (index >= input.size())
    return 0;
  int value = 0;
  if (( input[index].available * input[index].cost) <= budget){
    // all money available ,take all quantity available and move to next
    return ( input[index].available * input[index].value) + solution(input,index + 1, budget - (( input[index].available * input[index].cost) ));
  } else {
    // money deficit 
    // take as much and move to next if budget is +ve
    int buypower = (budget)/input[index].cost;
    if(buypower > 0 )
      {
	// buy something and pass
	return (buypower * input[index].value ) + solution(input,index  + 1,budget - (buypower * input[index].cost));
      }
    else {
      // cannot buy here 
      // pass on 
      return solution(input,index + 1, budget);

    }

  }
  
  
}

int main()
{
  int t;
  cin>>t;

  while(t--){
    int n,w ;
    scanf("%d%d",&n,&w);
    int sum =0;
    vector<node> input;
    for(int i=0;i<n;i++)
    {
      int cost,value,av;
      scanf("%d%d%d",&cost,&value,&av);
      struct node temp;
      temp.cost = cost;
      temp.value = value;
      temp.available = av;
      temp.rank = (float)value/cost;
      //cout << temp.rank<<endl;
      input.push_back(temp);
    }
    sort(input.begin(),input.end(),mycomparator);
    
    cout << solution(input,0,w)<<endl;
  }
}
