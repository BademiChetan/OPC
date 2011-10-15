#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <exception>
#include <stdexcept>

using namespace std;

int** board = NULL;
int size;
int no_test_cases;

struct cases{
    int x;
    int y;
};

cases* test_case = NULL;

void createBoard(int max){
     size = max;
     board = new int *[max];
     for(int i=0; i<max; i++)
         board[i] = new int[max];
}

void read(ifstream &input_file){
    int num_lines=0;
    int max = 1;
    string input;
    if(input_file.is_open()){
        while(getline(input_file, input)){
            if(num_lines == 0){
               no_test_cases = atoi((input.substr(0).c_str()));
               test_case = new cases[no_test_cases];
            } //if  
            else {
                try {
                    test_case[num_lines-1].x = atoi((input.substr(0).c_str()));
                    test_case[num_lines-1].y = atoi((input.substr(3,1).c_str()));
                    if(test_case[num_lines-1].x > max) max = test_case[num_lines-1].x;
                    if(test_case[num_lines-1].y > max) max = test_case[num_lines-1].y;
                }catch(out_of_range &e){}
            }//else
            num_lines++;
        }//while
    }//if
    createBoard(max);
}// read function


int check(int color, int x, int y){
    int flag = 0;
    for(int j=0; j<y; j++)
        if(board[x][j] == color){
            flag = 1;
            return 0;
        }
            
    for(int i=0; i<x; i++)
        if(board[i][y] == color){
            flag = 1;
            return 0;
         }
   
   return 1;
         
}

void colorize(){
    int flag;
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++){
            int color = 0;
            if( i==0 && j==0)
                board[i][j] = 0;
            else {
                flag = 1;
                color = 0;
                while(flag == 1){
                    if(check(color, i, j) == 1){
                        board[i][j] = color;
                        flag = 0;
                    }//if
                  //  if(flag == 0);
                  //      break;
                    color++;
                }//while
             } //else
        }//loop
}

int find(int x, int y){
    return board[x][y];    
}



int main(){
    ifstream input_file("input");
    read(input_file);
    colorize();
    for(int i=0; i<no_test_cases; i++){
        cout << find(test_case[i].x, test_case[i].y) << endl; 
    }
    return 0;
}
