

#include <stdio.h>
#include <string.h>
char temp[50005];
char buf[50005];
int count;

typedef unsigned char CTYPE;   // type of alphabet letters

#define ALPHA      (256)       // alphabet size
#define MAX_PATLEN (100)       // maximum pattern length

int betap[ MAX_PATLEN+1 ];
int Delta[ ALPHA ];



void makebetap( const CTYPE* p, int m ) {
    int i = 0, j = betap[0] = -1;

    while( i < m ) {
        while( (j > -1) && (p[i] != p[j]) )
            j = betap[j];
        if( p[++i] == p[++j] )
            betap[i] = betap[j];
        else
            betap[i] = j;
    }
}

void makeDelta( const CTYPE* p, int m ) {
    int i;

    for( i = 0; i < ALPHA; ++i )
        Delta[i] = m + 1;
    for( i = 0; i < m; ++i )
        Delta[ p[i] ] = m - i;
}

void FJS( const CTYPE* p, int m, const CTYPE* x, int n ) {
    if( m < 1 ) return;
    makebetap( p, m );
    makeDelta( p, m );

    int i = 0, j = 0, mp = m-1, ip = mp;
    while( ip < n ) {
        if( j <= 0 ) {
            while( p[ mp ] != x[ ip ] ) {
                ip += Delta[ x[ ip+1 ] ];
                if( ip >= n ) return;
            }
            j = 0;
            i = ip - mp;
            while( (j < mp) && (x[i] == p[j]) )
                { ++i; ++j; }
            if( j == mp ) {
               count++;
                ++i; ++j;
            }
            if( j <= 0 )
                ++i;
            else
                j = betap[j];
        } else {
            while( (j < m) && (x[i] == p[j]) )
                { ++i; ++j; }
            if( j == m )
                count++;
            j = betap[j];
        }
        ip = i + mp - j;
    }
}

int main( int argc, char** argv ) {

  
     int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",buf);
        int i;
        scanf("%d",&i);
        while(i--)
        {
            int m,l;
            scanf("%d%d",&m,&l);
            strncpy(temp,buf+m,l);
            temp[l]='\0';
           // printf("%s\n",temp);
            count=0;
            
            FJS( (CTYPE*) temp, strlen(temp),(CTYPE*) buf, strlen( buf ) );
            printf("%d\n",count);               
        }
    }
        return 0;
}
