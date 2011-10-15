#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
//#include "gconio.h"

class bigint{
     public:
      
               int len;
               int *num;

  // public:
               bigint(){
                       len=1;
                       num=new int[1];
                       num[0]=0;
               }
               bigint(int x){
           num=new int[x];
          
           len=x;
       }
               bigint(char *str){
                       int i;
                       len=strlen(str);
                       num=new int[len];
                      
                       for(i=0;i<len;i++)
                               num[i]=((int)str[i])-48;
               }
               bigint( bigint & copy){
                       int i;
                       len=copy.len;
                       num=new int[len];
                      
                       for(i=0;i<len;i++)
                               num[i]=copy.num[i];
               }
               void operator =(bigint & another){
                       int i;
                       len=another.len;
                       //free(num);
                       num=new int[len];
                     
                       for(i=0;i<len;i++)
                               num[i]=another.num[i];

               }
               void operator = ( char *s){
            int i;
                   len=strlen(s);
           num=new int[len];
      
            for(i=0;i<len;i++)
                num[i]=(int)(s[i])-48;
        }
       void operator = (int x){
           int i,temp=x,digits=0;
           if(temp==0) {len=1; num[0]=0; return; }
           while(temp){
                    temp/=10;
                    digits++;
           }
           len=digits;

           i=digits-1;

           while(x>0){
              num[i]=(char)((x%10)+48);
              x=x/10;
              i--;
           }
           //(*this).print(); cout<<endl;

       }

       void get(){
            char str[100000];
          
            int i;
            scanf("%s",str);
            
            len=strlen(str);
            num=new int[len];
           
            for(i=0;i<len;i++)
            {

                num[i]=(int)str[i]-48;
            }
       }
               void print(){
                       int i;
                       for(i=0;i<len;i++)
                               printf("%d",num[i]);

               }

               int operator > (bigint & another){
                       int i;
                       (*this).clear(); another.clear();
                       if(len>another.len)
                               return 1;
                       if(len<another.len)
                               return 0;
                       for(i=0;i<len;i++)
                               if(num[i]==another.num[i])
                                       continue;
                               else if(num[i]>another.num[i])
                                       return 1;
                               else return 0;
                       return 0;

               }

               int operator < (bigint & another){
                       int i;
                       if(len>another.len)
                               return 0;
                       if(len<another.len)
                               return 1;
                       for(i=0;i<len;i++)
                               if(num[i]==another.num[i])
                                       continue;
                               else if(num[i]>another.num[i])
                                       return 0;
                               else
                                       return 1;
                       return 0;

               }
               int operator ==(bigint & another)
               {
                       int i;
                       if(len>another.len||len<another.len)
                               return 0;
                       for(i=0;i<len;i++)
                               if(num[i]!=another.num[i])
                                       return 0;
                       return 1;
               }
               int operator !=(bigint &another)
               {
                       int i;
                       if(len!=another.len)
                               return 1;
                       for(i=0;i<len;i++)
                               if(num[i]!=another.num[i])
                                       return 1;
                       return 0;
               }
               int operator <= (bigint &another){
             if((*this)< another || (*this) == another)
                         return 1;
            else return 0;

       }
       int operator >= (bigint &another){
           if((*this)> another || (*this) == another)
                         return 1;
            else return 0;

       }

               void clear(){
            int i,j;
            for(i=0;i<len && num[i]==0 ;i++);

            len-=i;
            for(j=0;j<len;j++)
               num[j]=num[j+i];
           if(len==0)
           {
                 len=1;
                 num[0]=0;
           }


       }


               char* operator + (bigint other){

              int swapped=0,carry=0,i,j,k,resultlength=
len>other.len? len+1 : other.len+1;
              bigint result(resultlength),temp(resultlength);
              k=result.len-1;

              //making the number having more length as the first number
              if(len<other.len) {

                            swapped=1;
                            temp=(*this);
                            (*this)=other;
                            other=temp;
              }



              //adding until equal length

              for(i=len-1,j=other.len-1;j>=0;j--,i--,k--)
              {
                   result.num[k]=num[i]+other.num[j]+carry;
                   if(result.num[k]>9){
                       result.num[k]-=10;
                        carry=1;
                   }
                   else carry=0;

              }
              //remaining numbers in the first number...
              for(;i>=0;i--,k--){
                  result.num[k]=carry+num[i];
                  if(result.num[k]>9){
                           result.num[k]-=10;
                           carry=1;
                  }
                  else carry=0;
              }

              if(carry==0){
                 for(i=0;i<result.len-1;i++)
                        result.num[i]=result.num[i+1];
                 result.len--;

              }
              else
                    result.num[0]=1;
              result.clear();
             // result.print(); cout<<endl;
              char * resultstring=new char[result.len+1];
              
              for(i=0;i<result.len;i++)
                        resultstring[i]=(char)(result.num[i]+48);
              resultstring[i]='\0';

              if(swapped==1){
                 bigint temp= (*this);
                 *this= other;
                 other= temp;
                 swapped=0;
               }

              return resultstring;
       }

       char* operator * (bigint other){
                   bigint result(other.len+len);
                   int carry,l,i,j,k,tempnum;
                   char * resultstring;
                   bigint tempresults[other.len]; //declaring an array of temp bigintegers
                   for(i=0;i<result.len;i++)
                     result.num[i]=0;

                   for(i=0;i<other.len;i++)  //finding all the tempresults
                   {       carry=0;
                           tempnum=other.num[other.len-i-1];
//current multiplier
                           //cout<<"tempnum=" <<tempnum<<endl;
                           tempresults[i].len=len+i+1;
//allocating memory for tempbigints
                           tempresults[i].num=new int[tempresults[i].len];
                          
                           for(k=tempresults[i].len-1,l=len-1; l>=0;k--){
                                     if(k>len)
                                     {
                                         tempresults[i].num[k]=0;
                                         continue;
                                     }
                                     else{

tempresults[i].num[k]=(tempnum*num[l--])+carry;
                                          if(tempresults[i].num[k]>9){
                                              carry=tempresults[i].num[k]/10;
                                            //  cout<<"carry="<<carry<<endl;
                                              tempresults[i].num[k]%=10;
                                          }
                                          else
                                             carry=0;

                                     }
                           }

                           if(carry==0){
                                        tempresults[i].len--;
                                         for(j=0;j<tempresults[i].len;j++)

tempresults[i].num[j]=tempresults[i].num[j+1];


                           }
                           else
                                        tempresults[i].num[0]=carry;

                         //  tempresults[i].print();


                   }

                   for(i=0;i<other.len;i++)
                         result=result+tempresults[i];


              resultstring=new char[result.len+1];
             
              for(j=0;j<result.len;j++)
                        resultstring[j]=(char)(result.num[j]+48);
              resultstring[j]='\0';

              return resultstring;

       }
       char * operator - (bigint other){ //returns only the difference b/w two no.s
           char *result;
           int i,j,k,l,x,swapped=0;
           bigint first(this->len);
           bigint temp;

           for(i=0;i<len;i++)
                    first.num[i]=this->num[i];


           //(*this).print(); cout<<endl;
           //other.print(); cout<<endl;

           if(first<other)        //keeping the greater no. as the first
           {
                  swapped=1;
                    temp=first;
                    first=other;
                    other=temp;

           }
           result=new char[first.len+1];  //allocating memory for result
          
           for(i=first.len-1,j=other.len-1,k=0; j>=0; i--,j--,k++){
                  if(first.num[i]>=other.num[j])
                  {
                          result[k]=(char)(first.num[i]-other.num[j]+48);
                          continue;
                  }
                  first.num[i]+=10;
                  result[k]=(char)(first.num[i]-other.num[j]+48);
                  l=i-1;
                  while(first.num[l]==0&&l>=0){
                       first.num[l]=9;
                       l--;

                  }
                  first.num[l]--;
           }

           while(i>=0){
                 result[k]=(char)(first.num[i]+48);
                 k++;
                 i--;
           }
            result[k]='\0';
           //cout<<result<<"  reversed to  ";



           //Now the result is in reverse order of length k.. so reverse the result..

           for(i=0,j=k-1;i<j ; i++,j--){
                    l=result[i];
                    result[i]=result[j];
                    result[j]=l;
           }
           //cout<<result<<endl;
           //now omitting the leading zeroes
           for(i=0;i<k && result[i]==0  ;i++) ;
           //the no. of leading zeroes is i  0001234
           for(j=0;j<k-i+1;j++)
               result[j]=result[j+i];
           if(strlen(result)==0) return "0";



              if(swapped==1){
                 bigint temp= (*this);
                 *this= other;
                 other= temp;
                 swapped=0;
               }
           return result;
       }

       char * operator ^ (bigint other){
           bigint result("1"),one("1"), zero("0");
           int i;
           bigint l(1);
           bigint thisone(len);
           char *resultstring;


           for(i=0;i<len;i++)
                            thisone.num[i]=num[i];
           if(other==zero)
                 return "1";
           for(l=zero; l<other; l=l+one)
                result=result* thisone;
           resultstring=new char[result.len+1];
          
           for(i=0;i<result.len;i++)
                        resultstring[i]=(char)(result.num[i]+48);
           resultstring[i]='\0';

           return resultstring;


       }

       char * operator /( bigint dividend){
            bigint x,zero("0"),one("1"),nine("9"),ten("0"), divisor,current,s,remainder;
            char *quotient=new char[len],*curr;

            divisor=(*this);

            int length=dividend.len,position=0,i,start=0,q=0,oldstart;
            if(dividend==zero){cout<<"\nDivide error.."; exit(0);}
            while(position<divisor.len){
                    start=position;
                    oldstart=start;
                    position+=length;
                   // free(curr);
                    curr=new char[remainder.len+length+1];
                    for(i=0;i<remainder.len;i++)
                    {
                             curr[i]=(char)(remainder.num[i]+48);
                    }
                    for(;start<position;i++,start++){
                          curr[i]=(char)(divisor.num[start]+48);

                    }
                    curr[i]='\0';
                  //  cout<<curr<<endl;
                    current=curr;
                    current.clear();
                 //   if(current<divisor){
                  //       if(position<divi           
                    
                   // }
                        
                      

                    again:
                    if(current<dividend)
                    {
                        start=start-length;
                        position++; 
                        if(position>divisor.len)
                                          {quotient[q++]='0';quotient[q]='\0';return quotient;}
                        //free(curr);
                        curr=new char[remainder.len+length+2];
                        for(i=0;i<remainder.len;i++)
                        {
                             curr[i]=(char)(remainder.num[i]+48);
                        }
                        for(start=oldstart;start<position;i++,start++){
                          curr[i]=(char)(divisor.num[start]+48);

                        }
                         quotient[q++]='0';
                         curr[i]='\0';
                    current=curr;
                    current.clear();
                    if(current<dividend) goto again;
                    }
        
        
        
                    //cout<<"current=" ;current.print();cout<<endl;
                    bigint product;
                    for(x=one;x<=nine;++x)
                    {
                          product=x*dividend; product.clear();
                          if(product>current)
                                  break;
                    }
                    //cout<<"x=";x.print();cout<<endl;
                    x=x-one;
                    x.clear();
                    //cout<<"x=";x.print();cout<<endl;
                    
                    s=x*dividend;
                    //cout<<"s= "; s.print(); cout<<endl;
                    quotient[q++]=(char)(x.num[0]+48);


                    remainder=current-s;
                    remainder.clear();
                    //cout<<"R= ";remainder.print(); cout<<endl;
                    length=1;



            }

            quotient[q]='\0';
            
            return quotient;

       }

       void sqrt(bigint x){
             char *result=new char [x.len];
             int q=0,take=2,i,pos=0,j;
             bigint rem("0"),temp,k,ss,zero("0"),
divisor=zero,mod,sq,nine("9"),ten("10");
             if(x.len%2==1)
                    take=1;

             while(pos<x.len){

                         temp.len=take+rem.len;

                         temp.num=new int[temp.len];

                         for(i=0;i<rem.len;i++)
                             temp.num[i]=rem.num[i];

                         for(;i<temp.len;i++)
                                 temp.num[i]=x.num[pos++];

                         temp.clear();
                         //cout<<"temp=";temp.print(); cout<<endl;
                         rem.len=temp.len;
                         mod=divisor%ten;
                         divisor=divisor+mod;
                         divisor=divisor*ten;
                         //cout<<"rem="; rem.print(); cout<<endl;
                         for(k=zero; k<=nine; ++k){
                                 ss=divisor+k;
                                 sq=ss*k;
                                 if(sq>temp)
                                             break;
                         }
                         --k;

                         divisor=divisor+k;
                         //cout<<"div=";divisor.print(); cout<<endl;
                         mod=k%ten;
                         sq=k*k;
                         rem=temp-sq

                         ;
                         rem.clear();
                         //cout<<"rem="; rem.print(); cout<<endl;
                         mod.clear();
                         //cout<<"mod=";mod.print();cout<<endl;

                         result[q]=(char)(mod.num[0]+48);
                         q++;
                         //cout<<result[q-1]<<endl;

                         take=2;

             }

             result[q]='\0';
             (*this)=result;

       }


       char * operator %( bigint other){
               bigint zero("0"),div(len),mod,x,result;
               int i;
               char *resultstring;

               for(i=0;i<len;i++)
                        div.num[i]=num[i];
               if(other>div) {result=div; goto calculated;}
               mod=div/other;
               mod.clear();
               x=mod*other;
               x.clear();
               if(div==x) result=zero;
               else
                  result=div-x;
               result.clear();
               calculated:
               //mod.print(); cout<<" "; x.print(); cout<<" ";
//result.print(); cout<<endl;
               resultstring=new char[result.len+1];
    
              for(i=0;i<result.len;i++)
                        resultstring[i]=(char)(result.num[i]+48);
              resultstring[i]='\0';

              return resultstring;

       }


       void operator ++(){
            bigint one("1");
           (*this)=(*this)+one;
       }
       void operator --(){
            bigint one("1");
            (*this)=(*this)-one;
       }

       void flush(){
            free(num);
            len=1;
            num=new int[1];
            num[0]=0;
       }

       void operator +=( bigint x){
            (*this)=(*this)+x;
       }
       void operator -=(bigint x){
            (*this)=(*this)-x;
       }

       void operator *=(bigint x){
            (*this)=(*this)*x;
       }
       void operator /=(bigint x){
            (*this)=(*this)/x;
       }
       void operator %=(bigint x){
            (*this)=(*this)%x;
       }
       void operator ^=(bigint x){
            (*this)=(*this)^x;
       }

       char* operator !(){
             char *fact; int i;
             bigint num((*this));
             bigint factorial("1");
             bigint value("1");
             for(;value<num||value==num;factorial=factorial*value,++value);
             fact=new char[factorial.len+1];
             for(i=0;i<factorial.len;i++)
                         fact[i]=char(factorial.num[i]+48);
             fact[i]='\0';
             return fact;

       }
       ~bigint(){
             free(num);
       }    
};



int main(){
    
    int t,n;
    bigint arr,two("2"), num;
    scanf("%d",&t);
    
    while(t--){
    scanf("%d",&n);
    num.get();
    arr.len=1;
    arr.num[0]=2;
    
    
    int i;
    for(i=0;i<n;i++){
      arr=arr^two;
      arr=arr%num;
    }
    arr.print();
    printf("\n");
   }    
    
    return 0;
}     
               

