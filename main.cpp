#include <iostream>
#include <bits/stdc++.h>
#include "include\todolist.h"
using namespace std;

// Example usage
int main()
{
    ToDoList todo;

   int choice;
    string task;

    do
    {
        cout << "\n                      ************************************************************   ";
        cout << "\n                      * Enter a number between 0 and 8 to manage your To Do List * ";
        cout << "\n                      ************************************************************   \n"


             "1. Add a task\n"
             "2. Remove a task\n"
             "3. Display to-do list\n"
             "4. Check if a task is done\n"
             "5. Mark a task as done\n"
             "6. Show number of tasks which has been done\n"
             "7. Are There Any Tasks To Do\n"
             "8. Count the number of Tasks"
             "0. Exit\n"
             "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter task to add: ";
            cin.ignore();
            getline(cin, task);
            if(todo.IsExist(task))
            {
                cout<<"\n=======================================================\n";
                cout<<"This task has been added before";
                cout<<"\n=======================================================\n";

            }
            else
            {
                todo.addTask(task);
                cout<<"\n=======================================================\n";
                cout<<"The Task has been added";
                cout<<"\n=======================================================\n";
            }

            break;

        case 2:
            cout << "Enter task to remove: ";
            cin.ignore();

            getline(cin, task);
            todo.removeTask(task);
            break;


        case 3:
            cin.ignore();
            todo.display();
            break;

        case 4:
            cout << "Enter task to check: ";
            cin.ignore();
            getline(cin, task);
            todo.checkTaskDone(task);
            break;
        case 5:
            cout << "Enter task to mark as done: ";
            cin.ignore();
            getline(cin, task);
            todo.markTaskAsDone(task);

            break;
        case 6:
            todo.countDone();
            break;

        case 7:
            todo.Are_There_Any_Tasks_To_Do();
            break;

        case 8:
            todo.Count_tasks();
            break;

        case 0:
            cout<<"\n=======================================================\n";
            cout << "Exiting program..." ;
            cout<<"\n=======================================================\n";

            break;

        default:
            cout<<"\n=======================================================\n";
            cout << "Invalid choice. Please enter a number between 0 and 8" ;
            cout<<"\n=======================================================\n";

        }
    }
    while(choice);

}
