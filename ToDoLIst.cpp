#include<iostream>
#include<fstream>
using namespace std;

class temp{
    int id, search_id;
    string task;
    fstream file, file2;
    char choice1;

public:
    void addtask();
    void showtask();
    void searchtask();
    void deletetask();
    void updatetask();
}obj;

int main(){
    char choice;

    cout<<"\n\t 1.Add Task";
    cout<<"\n\t 2.Show Task";
    cout<<"\n\t 3.Search Task";
    cout<<"\n\t 4.Delete Task";
    cout<<"\n\t 5.Update Task";
    cout<<"\n\t Enter your choice:: ";
    cin>>choice;

    switch(choice){
        case '1': obj.addtask(); break;
        case '2': obj.showtask(); break;
        case '3': obj.searchtask(); break;
        case '4': obj.deletetask(); break;
        case '5': obj.updatetask(); break;
        default: cout<<"Invalid input";
    }
}

void temp::addtask(){
    choice1='y';
    while(choice1=='y'){
        cout<<"\nEnter task id:: ";
        cin>>id;

        cout<<"Enter task description:: ";
        cin.ignore();
        getline(cin,task);

        file.open("list.txt",ios::app);
        file<<id<<" "<<task<<endl;
        file.close();

        cout<<"Do you want to add another task (y/n)? ";
        cin>>choice1;
    }
}

void temp::showtask(){
    cout<<"\n\tID\tTask\n";
    file.open("list.txt",ios::in);

    while(file>>id){
        file.ignore();
        getline(file,task);
        cout<<id<<"\t"<<task<<endl;
    }

    file.close();
}

void temp::searchtask(){
    cout<<"\nEnter task id to search:: ";
    cin>>search_id;

    file.open("list.txt",ios::in);
    bool found = false;

    while(file>>id){
        file.ignore();
        getline(file,task);

        if(id==search_id){
            cout<<"\nTask Found!";
            cout<<"\nID: "<<id;
            cout<<"\nTask: "<<task<<endl;
            found = true;
        }
    }

    if(!found)
        cout<<"\nTask not found!";

    file.close();
}

void temp::deletetask(){
    cout<<"\nEnter task id to delete:: ";
    cin>>search_id;

    file.open("list.txt",ios::in);
    file2.open("temp.txt",ios::out);

    bool found = false;

    while(file>>id){
        file.ignore();
        getline(file,task);

        if(id!=search_id){
            file2<<id<<" "<<task<<endl;
        }
        else{
            found = true;
        }
    }

    file.close();
    file2.close();

    remove("list.txt");
    rename("temp.txt","list.txt");

    if(found)
        cout<<"\nTask deleted successfully!";
    else
        cout<<"\nTask not found!";
}

void temp::updatetask(){
    cout<<"\nEnter task id to update:: ";
    cin>>search_id;

    file.open("list.txt",ios::in);
    file2.open("temp.txt",ios::out);

    bool found = false;
    string newtask;

    while(file>>id){
        file.ignore();
        getline(file,task);

        if(id==search_id){
            cout<<"\nEnter new task description:: ";
            cin.ignore();
            getline(cin,newtask);

            file2<<id<<" "<<newtask<<endl;
            found = true;
        }
        else{
            file2<<id<<" "<<task<<endl;
        }
    }

    file.close();
    file2.close();

    remove("list.txt");
    rename("temp.txt","list.txt");

    if(found)
        cout<<"\nTask updated successfully!";
    else
        cout<<"\nTask not found!";
}
