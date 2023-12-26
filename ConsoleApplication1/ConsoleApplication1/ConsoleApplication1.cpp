Любимый староста Мы ничего не читали., [26.12.2023 22:19]
#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>

using namespace std;
int ID;

struct todo {
    int id;
    string task;
};


void addtodo() {
    system("cls");
    cout << "\t*******************************************************************" << endl;
    cout << "\t*                      To Do List Application                     *" << endl;
    cout << "\t*******************************************************************" << endl << endl << endl << endl;
    todo todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task);
    ID++;

    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task;
    write.close();


    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout << "\n\tDo you want to add more task? y/n: ";
    cin >> ch;


    if (ch == 'y') {
        addtodo();
    }
    else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}

int main()
{
    system("cls");
    cout << "\t*******************************************************************" << endl;
    cout << "\t*                      To Do List Application                     *" << endl;
    cout << "\t*******************************************************************" << endl << endl << endl << endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout << endl;
        cout << "\n\t1.Add Task";
        cout << "\n\t2.Display Task";
        cout << "\n\t3.Search Task";
        cout << "\n\t4.Delete Task";
        cout << "\n\t5.Update Task";

        int choice;
        cout << "\n\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

}