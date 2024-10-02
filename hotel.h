#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <conio.h>
#include <fstream>
// #define MAX 100;
using namespace std;

class hotel
{
public:
    int charges = 1000;

protected:
    // vector<int> rooms;
    vector<int> available;
    vector<string> details;
    vector<string> logs;
    int booked = 0;
    string username = "admin";
    string pass = "abcd1234!";

public:
    // constructor
    hotel()
    {
        for (int i = 0; i < 100; i++)
        {
            // rooms.push_back(i);
            available.push_back(true);
            details.push_back("");
        }
    }
    bool authenticate()
    {
        cout << endl;
        cout << "enter username";
        string x;
        cin >> x;
        cout << "enter password";
        string y = "";
        cin >> y;
        if (x == username && y == pass)
        {
            return 1;
        }
        else
            return 0;
    }

    // function to print all details
    void printDetails()
    {
        cout << endl;
        cout << "room" << "  " << "availability" << "  " << "name";
        cout << endl;
        for (int i = 0; i < 100; i++)
        {
            cout << i << "  " << available[i] << "  " << details[i];
            cout << endl;
        }
        logs.push_back("detailsPrinted");
    }

    // function to book the room
    void bookRoom(int roomNo, string name)
    {
        cout << endl;
        if (roomNo >= 100)
        {
            cout << "room do not exist";
            return;
        }
        if (available[roomNo] == false)
        {
            cout << "room already booked" << endl;
            cout << "check details";
            return;
        }
        if (this->booked == 100)
        {
            cout << "all rooms are full";
            return;
        }
        available[roomNo] = false;
        details[roomNo] = name;
        this->booked += 1;
        logs.push_back(to_string(roomNo) + "roomBooked");
        cout << "booking successful";
    }

    // function to leave the room
    void leaveRoom(int roomNo)
    {
        cout << endl;
        if (available[roomNo] == true)
        {
            cout << "room already empty" << endl;
            return;
        }
        available[roomNo] = true;
        details[roomNo] = "";
        logs.push_back(to_string(roomNo) + "roomReleased");
        this->booked -= 1;
    }
    // returns the total rooms booked
    int totalBooked()
    {
        return this->booked;
    }
    // gives the details of particular room
    void detail(int roomNo)
    {
        cout << endl;
        cout << roomNo << endl;
        cout << "available -> " << available[roomNo];
        cout << endl;
        cout << "person name -> " << details[roomNo];
    }
    // storing the data for permanant period
   
};