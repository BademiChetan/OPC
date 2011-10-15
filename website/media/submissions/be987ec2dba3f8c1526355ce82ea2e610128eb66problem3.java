public class problem3 {
public static void main(String args[]){
 InputStreamReader istream = new InputStreamReader(System.in) ;
 BufferedReader bufRead = new BufferedReader(istream) ;
String T=bufRead.readLine();
int T=Integer.parseInt(T); 
for(i=0;i<T;i++){
String A=bufRead.readLine();
String B1=A.substring(1,1);
String B2=A.substring(4,4);
int a1=Interger.parseInt(B1);
int a2=Interger.parseInt(B2);
for(j=0;j<a2;j++){ a1=a1*2}
System.out.println(a1);
}
}