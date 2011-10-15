#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {

int no, i;
scanf ( "%d", &no );
for  (i =0;i<no;i++) {
    char *str;
    int len;
    scanf ( "%d", &len );
    str = malloc ( (len +1) * sizeof ( char ) );
    scanf ( "%s", str );
    
    int q;
    int j = 0,ki;
    scanf ( "%d", &q );
    int m[q],k[q];
    char *sub[q];
    int same[q];
    
    for ( j = 0; j<q; j++ ){
        scanf ("%d %d",&m[j],&k[j]);
        sub[j] = str + m[j];
        same[j] = 0;
    }
    for ( ki = 0; str[ki] != '\0'; ki++ ) {
        for ( j = 0;j<q;j++)
            if ( sub[j][0] == str [ki])
                if ( strncmp ( sub[j], &str[ki], k[j] * sizeof (char ) ) == 0)
                    same[j]++;
    }
    for ( j = 0; j<q; j++ )
    printf("%d\n", same[j]);

}
}    
