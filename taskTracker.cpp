/*Task tracker is a project used to track and manage your tasks. 
In this task, you will build a simple command line interface (CLI)
to track what you need to do, what you have done, and what you are currently working on. 
This project will help you practice your programming skills, 
including working with the filesystem, handling user inputs,
and building a simple CLI application.

Requirements
The application should run from the command line, 
accept user actions and inputs as arguments.
The user should be able to:

Add, Update, and Delete tasks
Mark a task as in progress or done
List all tasks
List all tasks that are done
List all tasks that are not done
List all tasks that are in progress*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Task {
    public:
        
        void setStatus(string stat){
            status = stat;
        }

        string getStatus(){
            return status;
        }
        string getTaskName(){
            return taskName;
        }

        void setTaskName(string name){
            taskName = name;
        }

    private:
        string status;
        string taskName; //Task name given by user
};

void addTask(string taskName);
void updateTask(string taskName, string newName);
void deleteTask(string taskName);

int main(){
    int userChoice;
    string name;
    string newName;
    Task task;
    cout << "****TASK TRACKER APPLICATION****\n";

    //menu to read user choice
    cout << "1. ADD TASKS\n";
    cout << "2. UPDATE TASK\n";
    cout << "3. DELETE TASK\n";
    cout << "4. MARK TEST AS IN PROGRESS\n";
    cout << "5. MARK TEST AS DONE\n";
    cout << "6. LIST ALL TASKS\n";
    cout << "7. LIST ALL TASKS THAT ARE DONE\n";
    cout << "8. LIST ALL TASKS THAT ARE NOT DONE\n";
    cout << "9. LIST ALL TASKS THAT ARE IN PROGRESS\n";
    cout << "10. EXIT\n";
    cout << "CHOOSE AN OPTION: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1: //ADD TASK
        cout << "Enter a task to add: ";
        getline(cin  >> ws, name); //cleans whitespaces from buffer and reads the full line
        //task.setTaskName(name);

        addTask(name); //adds task to the list

        break;
    
    case 2: //UPDATE TASK
        cout << "Enter a task to update: ";
        getline(cin  >> ws, name); //user inputs the name of the task to update

        cout << "Enter new name: ";
        getline(cin  >> ws, newName);//new name for the task

        updateTask(name, newName);//updates task in the list

        break;

    case 3://DELETE TASK
        cout << "Enter a task to delete: ";
        getline(cin  >> ws, name);//name of the task to delete

        deleteTask(name);//deletes task from the list

        break; 
    default:
        break;
    }
    return 0;

    
}

void addTask(string taskName){
    ofstream file("list.txt", ios::app); //if list.txt exists opens file in append mode
                                         //if not it creates the file and opens it in append mode

    if (!file)//file not found
    {
        cerr << "Error: Couldn't create list.txt file" << endl;
        return;
    }
    
    file << taskName << endl; //writes taskName in file
    file.close();

    cout << "Task added successfully" << endl;
}

void updateTask(string taskName, string newName){
    ifstream in("list.txt"); //opens file in read mode

    if(!in)
    {
        cerr << "Error: Couldn't open list.txt file" << endl;
        return;
    }

    vector<string> lines; //Saves momentarily the file information
    string line;
    bool found = false;

    while(getline(in, line)){ //reads every line in the file
        if(line == taskName){ //if there's a task with the name inputed by the user
            lines.push_back(newName);//changes the old name by the new name
            found = true;
        }else{
            lines.push_back(line); //overwrites all the other lines from the file
        }
    }
    
    in.close();
    
    ofstream file("list.txt", ios::trunc); //open list.txt in trunc mode (overwrites the whole file)

    if (!file)
    {
        cerr << "Error: Couldn't open list.txt file" << endl;
        return;
    }

    for(const string& l : lines){ //writes every line from the lines vector
        file << l << endl;
    }

    if(found){
        cout << "Task updated successfully" << endl;
    }
    else{
        cout << "Task not found" << endl;
    }
    
}

void deleteTask(string taskName){
    ifstream in("list.txt"); //open file in read mode

    if(!in)
    {
        cerr << "Error: Couldn't open list.txt file" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool found = false;

    while(getline(in, line)){
        if(line != taskName){  //writes every line that doesn't have the name of the task 
                               //the user wants to delete
            lines.push_back(taskName); 
        }
        else{
            found = true;
        }
    }

    in.close();
    
    ofstream file("list.txt", ios::trunc); //open list.txt in trunc mode

    if (!file)
    {
        cerr << "Error: Couldn't open list.txt file" << endl;
        return;
    }

    for(const string& l : lines){ //writes every line from the lines vector
        file << l << endl;
    }

    if(found){
        cout << "Task deleted successfully" << endl;
    }
    else{
        cout << "Task not found" << endl;
    }
}