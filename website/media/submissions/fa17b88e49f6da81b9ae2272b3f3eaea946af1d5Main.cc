#include <iostream>
using namespace std;

struct Point {
 	int x;
	int y;
};

   int getColor(Point p) {
        if(p.x == p.y)
            return 0;

        if(p.x < p.y){
            int tmp = p.x;
            p.x = p.y;
            p.y= tmp;
        }
        
        if(p.x % 2 == 0){
            return p.x + p.y;
        } else {
            return p.x - p.y;
        }        
    }

int main() {
        int no = 0;
	    cin >> no;
            Point *pts = new Point[no];

            for (int i = 0; i < no; i++) {
		int x,y;
		cin >> x;
		cin >> y;
		pts[i].x = x;
		pts[i].y = y;
            }

            for (int i = 0; i < no; i++) {
                cout << getColor(pts[i]) << endl;
            }

	delete pts;
}

