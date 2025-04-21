
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int value=0;
    vector<int> mylist; 
    do {   
        if (_kbhit()){
            cin>>value; 
            if(cin.good()){ 
                mylist.push_back(value); 
            }else{
                cin.clear();
                cin.ignore(10000,'\n');
            }
            system("cls");
            cout<<"new list: { " ;
            for(int i=0;i< mylist.size();i++){
                cout<<mylist[i]<<' ';
            }
            cout<<" }"<<std::endl;
        }

        //check if Esc Pressed
    } while(GetAsyncKeyState(VK_ESCAPE)==0);

    return 0;
}