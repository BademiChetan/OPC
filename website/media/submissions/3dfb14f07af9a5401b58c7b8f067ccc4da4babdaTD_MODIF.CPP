#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<graphics.h>
#include<dos.h>
/**************************************************************************
  CLASS NAME - stud
  DETAILS - It contains functions to implement changes in students record
**************************************************************************/

class stud
{
   char name[20];
   char address[40];
   unsigned long ph_no;

public:

/**************************************************************************
  FUNCTION NAME - get()
  DETAILS - It takes information of student by user and initialise them in respective data members
**************************************************************************/

void get()
{
   cout<<"\n\tEnter name : ";
   gets(name);
   cout<<"\n\tEnter address : ";
   gets(address);
   cout<<"\n\tEnter phone number : ";
   cin>>ph_no;
}

/**************************************************************************
  FUNCTION NAME - show()
  DETAILS - It displays information of student
**************************************************************************/

void show()
{
   cout<<"\n\tNAME         : "<<name;
   cout<<"\n\tADDRESS      : "<<address;
   cout<<"\n\tPhone number : "<<ph_no;
}

/**************************************************************************
  FUNCTION NAME - modify()
  DETAILS - It modifies information of student by users wish
**************************************************************************/

void modify()
{
   cout<<"\n\tCurrent name         :"<<name;
   cout<<"\n\tCurrent address      :"<<address;
   cout<<"\n\tCurrent phone number :"<<ph_no;
   cout<<"\n\tEnter new details ==>\n";
   char nam[20],add[40];
   unsigned long int ph;
   cout<<"\n\tNew name (enter '.' for old one) : ";
   gets(nam);
   cout<<"\n\tNew address (enter '1' for old one) : ";
   gets(add);
   cout<<"\n\tNew phone number (enter '-1' for old one) : ";
   cin>>ph;
   if(strcmpi(nam,".") != 0)
      strcpy(name,nam);
   if(strcmpi(add,"1") != 0)
      strcpy(address,add);
   if(ph != -1)
      ph_no=ph;
}

/**************************************************************************
  FUNCTION NAME - *get_name(),*get_address(),*get_name()
  DETAILS - It returns name of the student using pointer
**************************************************************************/

char *get_name()
{
  return(name);
}
char *get_address()
{
  return(address);
}
unsigned long get_ph_no()
{
  return(ph_no);
}
};

/**************************************************************************
  FUNCTION NAME - main()
  DETAILS - It calls all the functions
**************************************************************************/

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   int x,y;
   int midx,midy;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)          /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
      closegraph();
   }
   y:
    setcolor(BLACK);
    textbackground(0) ;
    for(int i=1;i<=250;i++)
    {
	 setcolor(i);
	 cleardevice();
	 settextstyle(1, HORIZ_DIR, 5);
	 outtextxy(80,i,"WELCOME");
	 outtextxy(280,i,"TO");
	 outtextxy(350,i,"PROJECT");
	 delay(20);
    }
    setcolor(BLACK);
    textbackground(BLUE);
    for(int j=1;j<=250;j++)
    {
	 setcolor(j);
	 cleardevice();
	 settextstyle(1, HORIZ_DIR, 5);
	 outtextxy(j-150,200,"TELEPHONE");
	 outtextxy(j+150,200,"DIRECTORY");
	 delay(20);
    }
   outtextxy(70,250,"\n\nTELEPHONE DIRECTORY");
   settextstyle(7,0,1);
     for(i=1;i<=250;i++)
    {
	 setcolor(9+i);
	 cleardevice();
	 outtextxy(i,200,"Designed by :-");
	 outtextxy(450-i,270,"SHUBHAM KEDIA");
	 sound(500+i);
    }
	 nosound();
	 int a=320;
	 int b=250;
	 for(i=0;i<=3000;i++)
    {
	 putpixel(rand()%(a+=1),rand()%(b+=1),i);
	 delay(2);
    }
	 delay(1000);
   clearviewport();
   int ch;
   stud s;
   z:

   clearviewport();
   cout<<"\n\n\n\n\n\n\n\n\n";
   rectangle(60,10,600,400);
   rectangle(62,12,602,402);
   settextstyle(2,0,6);
   setbkcolor(BLUE);
   outtextxy(200,30," HELP -> PRESS ANY KEY 1 TO 6 " );
   outtextxy(220,50,"\n\n\n1. TO ADD CONTACTS" );
   outtextxy(220,100,"\n\n2. TO SHOW CONTACTS" );
   outtextxy(220,150,"\n\n3. TO SEARCH CONTACTS" );
   outtextxy(220,200,"4.\n\n TO MODIFY CONTACTS" );
   outtextxy(220,250,"\n\n\n5. TO DELETE CONTACTS" );
   outtextxy(220,300,"\n\n\n6. TO EXIT " );
   outtextxy(220,350," Enter the choice ->");
   gotoxy(55,23);
   cin>>ch;
   switch(ch)
   {
      case  1:  //responsible for addition of record
      {
	 clearviewport();
	 fstream f;
	 f.open("rec.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
	 char ans;
	 gotoxy(1,1);
	 s.get();
	 f.write((char *)&s,sizeof(s));
	 clearviewport();
	 outtextxy(250,360, "Do you want to continue(press enter) ==> ");
	 ans=getche();
	 clearviewport();
	 if (ans=='y' || ans=='Y'||ans=='n' || ans=='N')
	    goto z;
	 else
	    goto z;
	// f.close();
      }
      case 2:  // will show all the contents of the file
      {
	 clearviewport();
	 gotoxy(1,1);
	 cout<<"\n\n";
	 fstream f;
	 f.open("rec.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
	 f.seekg(0);
	 int ctr=0;
	 while(f.read((char *)&s,sizeof(s)))
	 {
	    ctr=ctr+1;
	    if(ctr==20)
	    {
	       getchar();
	       clearviewport();
	       ctr=0;
	    }
	    s.show();
	    cout<<endl;
	    if(f.eof()==1)
	       break;
	 }
	 f.close();
	 outtextxy(240,350, "   Do you want to continue ==>");
	 char ans;
	 ans=getche();
	 if (ans=='y' || ans=='Y'||ans=='n' || ans=='N')
	 {
	    goto z;
	 }
	 else
	    goto z;
      }
      case 3: // search a particular contact
      {
	 gotoxy(1,1);
	 clearviewport();
	 char ans;
	 ifstream f;
	 stud s;
	 char nam[30];
	 f.open("rec.txt",ios::in|ios::binary);
	 cout<<"\n Enter the field by which you want to search:-";
	 cout<<"\n 1. BY NAME ";
	 cout<<"\n 2. BY ADDERESS ";
	 cout<<"\n 3. BY PHONE NO. ";
	 int se;
	 cin>>se;
	 switch(se)
	 {
	 case 1:{
		 cout<<"\n\n\nEnter  name  whose record to be search  :";
		 gets(nam);
		 char *n=s.get_name();
		 do
		 {
		  f.read((char *)&s,sizeof(s));
		  if(f.eof()==1)
		  break;
		  if(strcmpi(n,nam)==0)
		  break;
		 }while(f);
		 if(f.eof()!=0)
		 cout<<"\n\tRecord not found!!!!!";
		 else
		 {
		  s.show();
		  getchar();
		 }
		  f.close();
		  settextstyle(2,0,6);
		  break;
	       }
	 case 2:{char add[40];
		 cout<<"\n Enter the adderess whose record to be search:";
		 gets(add);
		 char *n= s.get_address();
		  do
		 {
		  f.read((char *)&s,sizeof(s));
		  if(f.eof()==1)
		  break;
		  if(strcmpi(n,nam)==0)
		  break;
		 }while(f);
		 if(f.eof()!=0)
		 cout<<"\n\tRecord not found!!!!!";
		 else
		 {
		  s.show();
		  getchar();
		 }
		  f.close();
		  settextstyle(2,0,6);
		  break;
	       }
	 case 3:{  unsigned long phon_nos;
		    cout<<"\n\n\nEnter ph no whose record to be search  :";
		 cin>>phon_nos;
		 unsigned long n= s.get_ph_no();
		 do
		 {
		  f.read((char *)&s,sizeof(s));
		  if(f.eof()==1)
		  break;
		  if(phon_nos==n)
		  break;
		 }while(f);
		 if(f.eof()!=0)
		 cout<<"\n\tRecord not found!!!!!";
		 else
		 {
		  s.show();
		  getchar();
		 }
		  f.close();
		  settextstyle(2,0,6);
		  break;
	       }
		 }  // End of switch 1
      outtextxy(250,350,"Do You Want To Continue ==>");
	 ans=getche();
	 if (ans=='y' || ans=='Y'||ans=='n' || ans=='N')
	    goto z;
      else
	    goto z;
      }
      case 4:  //for the modification
      {
	 clearviewport();
	 gotoxy(1,1);
	 char ans,nam[30];
	 fstream f; stud s;
	 f.open("rec.txt",ios::in|ios::binary);
	 cout<<"\n\n\n\tEnter person name whose record to be changed  :";
	 gets(nam);
	 char *n=s.get_name();
	 do
	 {
	    f.read((char *)&s,sizeof(s));
	    if(f.eof()==1)
	      break;
	    if(strcmpi(n,nam)==0)
	       break;
	 }while(f);
	 if(f.eof()!=0)
	    cout<<"\n\tRecord not found!!!!!";
	 else
	 {
	       s.modify();
	       int l=f.tellg();
	       f.close();
	       f.open("rec.txt",ios::out|ios::binary|ios::ate);
	       f.seekg(l-sizeof(s));
	       f.write((char *)&s,sizeof(s));
	 }
	 f.close();
	 outtextxy(290,360, "   Do you want to continue :-");
	 ans=getche();
	 if (ans=='y' || ans=='Y'||ans=='n' || ans=='N')
	 goto z;
	 else
	    goto z;
      }
      case 5:  //responsible for the deletion of the record
      {
	 clearviewport();
	 gotoxy(1,1);
	 char nam[30];
	 int flag=0;
	 stud s;
	 ifstream fin;
	 fstream fout;
	 fin.open("rec.txt",ios::in|ios::binary);
	 fout.open("temp.txt",ios::app|ios::binary);
	 int i;
	 fflush(stdin);
	 cout<<"\n\n\tEnter the name whose record is to be deleted : ";
	 gets(nam);
	 char *n=s.get_name();
	 while(fin)
	 {
	    fin.read((char *)&s,sizeof (s));
	    if(strcmp(n,nam)==0)
	    {
	       fout.read((char *)&s,sizeof(s));
	       flag=1;
	    }
	    else
	    {
	       if(fin.eof()==1)
		  break;
	       fout.write((char *)&s,sizeof(s));
	    }
	 }
	 if(flag==0)
	 {
	    cout<<"\n\n\t\tRecord not found!!!!!!";
	    getch();
	    goto data;
	 }
	 fin.close();
	 fout.close();
	 remove("rec.txt");
	 rename("temp.txt","rec.txt");
	 cout<<"\n\t\t\tDELETING ....";
	 delay(1000);
	 cout<<"\n\t\tRecord get Deleted";
	 getchar();
	 char ans;

	 data :
	 outtextxy(240,340, "   Do you want to continue:- ");
	 ans=getche();
	 if (ans=='y' || ans=='Y'||ans=='n' || ans=='N')
	    goto z;
	 else goto z;
      }
      case 6:
      {
	 clearviewport();
	 outtextxy(150,360,"****** THE END OF THE PROJECT ******");
	 outtextxy(200,390,"\n \n\n\n\n  PLEASE PRESS ENTER");
	 getchar();
	 clearviewport();
	 setbkcolor(0);
	 for (int i=0 ; i<2000; ++i )	    //Put Stars
	 {
	    putpixel(random(720), random(560), random( 16-1 )+1);
	    delay(1);
	 }
	 delay(1000);
	 setcolor(3);
	 settextstyle(3,0,7);
	 outtextxy(150,100,"THANK YOU");
	 outtextxy(150,250,"VISIT AGAIN");
	 getchar();
	 closegraph();
	 exit(1);
      }
      default:
	      goto z;
   }
}



