#include <iostream>
#include <string>
using namespace std;

int main(){
    string items[8] = {"B123", "C234", "A345","C15", "B177", "G3003", "C235", "B179"}; 
    for (int i = 0; i < 8 ; i++){
        if (items[i][0] == 'B'){
            cout << items[i] << endl;
        }
    }
return 0;
}