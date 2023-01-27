#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
const int  SIZE = 15;
const int TOTAL_WORDS = 10;

string GetFileName();
void loadfileWords(string file_name,char letters[SIZE][SIZE],string wordstring[TOTAL_WORDS]);
void  DisplayPuzzle(char letters[SIZE][SIZE],string wordstring[TOTAL_WORDS]);
string  BuildWord(char letters[SIZE][SIZE],int x, int y, int x1, int y1);
bool CheckWord(string built, string real);

int main() {
  string file_name = GetFileName();
  char letters[SIZE][SIZE];
  string wordstring[TOTAL_WORDS];
  loadfileWords(file_name,letters,wordstring);
  DisplayPuzzle(letters,wordstring);
  string user;
  int game_end = 10;
  while (game_end != 0){
  int x1;
  int y1;
  int x2;
  int y2;
  
  cout << endl;
  cout << "What is the starting X Y (separated by a space)?"<<endl;
  cin>>x1>>y1;
  cout << "What is the ending X Y (separated by a space)?"<<endl;
  cin>>x2>>y2;
  cout<<BuildWord(letters,x1,y1,x2,y2)<<endl;
  }
  
}

string BuildWord(char letters[SIZE][SIZE],int x1, int y1,int x2, int y2){
  string ret = "";
  // GOING RIGHT
  if (x1 == x2 && y1<y2){
    int iterate = y2-y1;
    for(int i = 0; i<=iterate; i++){
        ret += letters[x1][y1];
        y1++;
    }
  }
  // GOING LEFT
  if (x1 == x2 && y1>y2){
    int iterate = y2-y1;
    for(int i = 0; i<=iterate; i++){
        ret += letters[x1][y1];
        y1++;
  }
  }
  return ret;
}

string GetFileName(){
  string file_name;
  cout << "Input File Name: " << endl;
  cin >> file_name;
  while (file_name.compare("puzzle.txt")!=0 && file_name.compare("puzzle2.txt" )!= 0){
    cout << "Input File Name: " << endl;
    cin >> file_name;
  }
  return file_name;
}

void loadfileWords(string file_name,char letters[SIZE][SIZE],string wordstring[TOTAL_WORDS]){
  ifstream MyReadFile(file_name);
  if (MyReadFile.is_open()){
    // int user;
    for(int x = 0; x<SIZE; x++){
      // cout << endl;
      for(int y = 0; y<SIZE; y++){
        // cout << "  ";
        MyReadFile >> letters[x][y];  
      }
    }
    for(int i = 0; i<TOTAL_WORDS; i++){
      // cout << endl;
      MyReadFile >> wordstring[i];
    }    
  }
  MyReadFile.close();
}
void DisplayPuzzle(char letters[SIZE][SIZE],string wordstring[TOTAL_WORDS]){
  cout << "    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14";
  for(int x = 0; x<SIZE; x++){
      cout << endl;
      cout << x;
      for(int y = 0; y<SIZE; y++){
        cout << "   ";
        cout << letters[x][y];  
      }
  }
  cout<< endl;
  cout << endl;
  cout << "*********REMAINING WORDS*********";
  for(int i = 0; i<TOTAL_WORDS; i++){
    cout << endl;
    cout << wordstring[i];
    }    
}
 



