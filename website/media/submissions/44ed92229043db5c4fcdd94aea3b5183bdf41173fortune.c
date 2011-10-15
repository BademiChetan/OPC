#include <stdio.h>
#include <string.h>

class word_freq
{
public:
char* word;
int count;
word_freq* next;
word_freq(char* w) {word=w; count=0; next=NULL;
}
};

class freq_count{
private:
word_freq* freq_list;
public:
freq_count() {freq_list=NULL;}
void add(char* word);
void print_out();
};

void freq_count::add(char* word)
{
word_freq* ptr=freq_list;
bool found=false;

while (ptr!=NULL && !found){
found=(strcmp(word, ptr->word)==0);
if (!found) ptr=ptr->next;
}

if (found) (ptr->count)++;
else{
ptr=freq_list;
int word_size=strlen(word) +1;
char* dest=new char[word_size];
strcpy(dest, word);
word_freq* new_wf=new word_freq(dest);
new_wf->next=freq_list;
freq_list=new_wf;
(new_wf->count)++;
}
}

void freq_count::print_out(){
word_freq* ptr = freq_list;

printf("Word	Count\n");
while (ptr!=NULL){
printf("%-12s %3d\n", ptr->word, ptr->count);
ptr=ptr->next;
}
}

main(){
freq_count c;
char word[80];
while (scanf("%s", word)==1){
c.add(word);
}
c.print_out();
}
