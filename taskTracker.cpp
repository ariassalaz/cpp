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

void addTask(string taskName);
void updateTask(string taskName, string newName);
void deleteTask(string taskName);
void markTaskAsInProgress(string taskName);
void markTaskAsDone(string taskName);
void markTaskAsNotDone(string taskName);
void listAllTasks();
void listTasksInProgress();
void listTasksDone();
void listTasksNotDone();
void removeTaskFromFile(string fileName, string taskName);


int main(){
    int userChoice;
    string name;
    string newName;
    cout << "****TASK TRACKER APPLICATION****\n";

    //menu to read user choice
    do{//repeat the menu until user choose to leave
    cout << "1. ADD TASKS\n";
    cout << "2. UPDATE TASK\n";
    cout << "3. DELETE TASK\n";
    cout << "4. MARK TEST AS IN PROGRESS\n";
    cout << "5. MARK TEST AS DONE\n";
    cout << "6. MARK TEST AS NOT DONE\n";
    cout << "7. LIST ALL TASKS\n";
    cout << "8. LIST ALL TASKS THAT ARE IN PROGRESS\n";
    cout << "9. LIST ALL TASKS THAT ARE DONE\n";
    cout << "10. LIST ALL TASKS THAT ARE NOT DONE\n";
    cout << "11. EXIT\n";
    cout << "CHOOSE AN OPTION: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1: //ADD TASK
        cout << "Enter a task to add: ";
        getline(cin  >> ws, name); //cleans whitespaces from buffer and reads the full line

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

    case 4://MARK TASK AS IN PROGRESS
        cout << "Enter the task to mark as in progress: ";
        getline(cin  >> ws, name);//user inputs tas to mark as "in progress"

        markTaskAsInProgress(name);

        break;

    case 5://MARK TASK AS DONE
        cout << "Enter the task to mark as done: ";
        getline(cin  >> ws, name); //user inputs tas to mark as "done"

        markTaskAsDone(name);

        break;

    case 6://MARK TASK AS NOT DONE
        cout << "Enter the task to mark as not done: ";
        getline(cin  >> ws, name);//user inputs tas to mark as "not done"

        markTaskAsNotDone(name);

        break;    

    case 7://LIST ALL TASKS
        listAllTasks();

        break;

    case 8://LIST TASKS IN PROGRESS
        listTasksInProgress();
        
        break;  
        
    case 9://LIST TASKS DONE
        listTasksDone();
        
        break;

    case 10://LIST TASKS NOT DONE
        listTasksNotDone();
        
        break;
    default:
        break;
    }
    
    
    }while(userChoice != 11); //if user chooses 11, the program ends

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
            lines.push_back(line); 
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

void markTaskAsInProgress(string taskName){
    ifstream in("list.txt"); //open file in read mode

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
            found = true;     //marks the task as found
            }
    }

    if(!found){
            cout << "Task not found" << endl;
            return;
    }else{
        cout << taskName << " marked as in progress"; 
        removeTaskFromFile("done.txt", taskName); //remove task from done and not done files
                                                  //in case the task is in one of those
                                                  //as the task is now in progress
        removeTaskFromFile("notDone.txt", taskName);
    }

    ofstream file("inProgress.txt", ios::app);//opens inProgress.txt file in write mode

    if (!file)
    {
        cerr << "Error: Couldn't open inProgress.txt file" << endl;
        return;
    }
    
    file << taskName << endl; //inserts the task name on the file inProgress
    
    file.close();
}

void markTaskAsDone(string taskName){
    ifstream in("list.txt"); //open file in read mode

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
            found = true;     //marks the task as found
        }
    }

    if(!found){
            cout << "Task not found" << endl;
            return;
    }else{
        cout << taskName << " marked as done";
        removeTaskFromFile("inProgress.txt", taskName); //remove the task from inProgress and notDone files
                                                        //in case the task is in one of those
                                                        //as it is now done
        removeTaskFromFile("notDone.txt", taskName);
    }

    ofstream file("done.txt", ios::app);//opens done.txt file in write mode

    if (!file)
    {
        cerr << "Error: Couldn't open done.txt file" << endl;
        return;
    }
    
    file << taskName << endl; //inserts the task in the done.txt file
    
    file.close();
}

void markTaskAsNotDone(string taskName){
    ifstream in("list.txt"); //open file in read mode

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
            found = true;     //marks the task as found
        }
    }

    if(!found){
            cout << "Task not found" << endl;
            return;
    }else{
        cout << taskName << " marked as not done";
        removeTaskFromFile("inProgress.txt", taskName);//removes the task from inProgress and done files
                                                       //in case the task is in one of those
                                                       //as the task is now marked as not done
        removeTaskFromFile("done.txt", taskName);
    }

    ofstream file("notDone.txt", ios::app); //opens notDone.txt file in write mode

    if (!file)
    {
        cerr << "Error: Couldn't open notDone.txt file" << endl;
        return;
    }
    
    file << taskName << endl;//inserts the task in the notDone file
    
    file.close();
}

void listAllTasks(){
    ifstream file("list.txt");//opens the list file in read mode

    if(!file)
    {
        cerr << "Error: Couldn't open list.txt file" << endl;
        return;
    }

    string line;

    while(getline(file, line)){ //reads every line in the file
        cout << line << endl;   //and prints the list
    }
}

void listTasksInProgress(){
    ifstream file("inProgress.txt");//opens the inProgress file in read mode

    if(!file)
    {
        cerr << "Error: Couldn't open inProgress.txt file" << endl;
        return;
    }

    string line;
    
    while(getline(file, line)){ //reads every line in the file
        cout << line << endl;   //and prints the list of tasks in progress
    }
}

void listTasksDone(){
    ifstream file("done.txt");//opens the done file in read mode

    if(!file)
    {
        cerr << "Error: Couldn't open done.txt file" << endl;
        return;
    }

    string line;
    
    while(getline(file, line)){ //reads every line in the file
        cout << line << endl;   //and prints the list of done tasks
    }
}

void listTasksNotDone(){
    ifstream file("notDone.txt");//opens the done file in read mode

    if(!file)
    {
        cerr << "Error: Couldn't open notDone.txt file" << endl;
        return;
    }

    string line;
    
    while(getline(file, line)){ //reads every line in the file
        cout << line << endl;   //and prints the list of not done tasks
    }
}


//we use this method because for example if we mark a task as in progress, 
//it can't also be in the done file and vice versa
void removeTaskFromFile(string fileName, string taskName){ //receives as parameters a fileName where we'll remove the task
                                                           //from the taskName we also receive as a parameter  
    ifstream in(fileName); //opens filename in readmode

    if(!in){
        cout << "Couldn't open " << fileName << " file";
        return;
    }

    vector<string> lines; //Saves momentarily the file information
    string line;

    while(getline(in, line)){ //reads every line in the file
        if(line != taskName){ 
            lines.push_back(line); //saves every task except the one we'll remove from the file
        }
    }

    in.close();

    ofstream out(fileName, ios::trunc);//opens filename in writemode

    for(const string&l : lines){
        out << l << endl;//rewrites the file eliminating the task we sent as a parameter
    }

    out.close();
}