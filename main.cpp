#include "hotel.h"
#include<iostream>
#include<conio.h>
#include<thread>
#include<chrono>
using namespace std;
int main(){
    hotel h;
    bool auth = 0;
    int i = 0;
    bool logout = false;
    //authentication of the admin
    do{
        auth = h.authenticate();
    }while(!auth && ++i < 4);
    char x;
    if(auth == true){
        while(!logout){
            cout << endl;
            cout << "1  :get details of all rooms" << endl;
            cout << "2  :get total booked rooms" << endl;
            cout << "3  :book a room" << endl;
            cout << "4  :room checkout" << endl;
            cout << "5  :detail of a particular room" << endl;
            cout << "6  : logout" << endl;
            cin >> x;
            string name;
            switch(x - '0'){
                case 1:
                    h.printDetails();
                    break;
                case 2:
                    cout << "total booked rooms are -> " << h.totalBooked();
                    break;
                case 3:
                    cout << "enter the room number";
                    int z;
                    cin >> z;
                    cout << "enter the customer name";
                    // string name;
                    // cin >> name;
                    getline(cin >> ws,name);
                    h.bookRoom(z,name);
                    break;
                case 4:
                    cout << "enter the room number";
                    cin >> z;
                    h.leaveRoom(z);
                    break;
                case 5:
                    cout << "enter the room number to check";
                    cin >> z;
                    h.detail(z);
                    break;
                case 6:
                    cout << "logout success" << endl;
                    cout << "press any key to exit";
                    getch();
                    logout = 1;
                    break;
                    // auth = 0;
                default:
                    cout << endl;
                    cout << "wrong choice entered";
            }
            
        }
    }
    // return 0;
}