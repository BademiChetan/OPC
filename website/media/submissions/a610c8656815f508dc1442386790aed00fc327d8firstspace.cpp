
#include<iostream>

#include<cstring>

 

using namespace std;

 

void char_permutation(char str[],char append[])

{

int length = strlen(str);

if (length)

{

for(int i=0;i<length;++i)

{

char* str1 = new char[length+1];

int cnt;

int cnt2;

for(cnt=0,cnt2=0; cnt<length; ++cnt,++cnt2)

{

if (cnt == i)

{

str1[cnt] = str[++cnt2];

continue;

}

else

str1[cnt] = str[cnt2];

}

str1[cnt] = '\0';

 

int alength = strlen(append);

char* append1 = new char [alength+2];

strncpy(append1,append,alength);

append1[alength] = str[i];

append1[alength+1] = '\0';

 

char_permutation(str1,append1);

 

delete []str1;

delete []append1;

}

}

else

{

cout << append << endl;

}

}

 

 

int main()

{

char str[] = "raghu"; // shows a little humor

char append[] = "\0";

 

cout << "Original = " << str << endl;

char_permutation(str,append);

cout << "Done ........" << endl;

 

cin.get(); // wait

return 0;

}
