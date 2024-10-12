#include "todolist.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ToDoList::ToDoList()
{
    head=NULL;
}

void ToDoList:: addTask(string task) // Function to add a task to the list
{
    Task* newTask = new Task;
    newTask->info=task;
    if (head==NULL)
    {
        head = newTask;
    }
    else
    {
        Task* current = head;
        while (current->next!=NULL)
        {
            current = current->next;
        }
        current->next = newTask;
    }
    newTask->next=NULL;
}

void ToDoList:: removeTask(string task) // Function to remove a task from the list
{
    if ( IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty !";
        cout<<"\n=======================================================\n";

    }

    else if (head->info == task)
    {
        Task* temp = head;
        head = head->next;
        delete temp;
        cout<<"\n=======================================================\n";
        cout<<"The Task has been removed";
        cout<<"\n=======================================================\n";
    }

    else
    {
        Task* current = head;
        Task* prev = NULL;
        while (current!=NULL && current->info != task)
        {
            prev = current;
            current = current->next;
        }

        if (current==NULL)
        {
            cout<<"\n=======================================================\n";
            cout << "Task is not found!";
            cout<<"\n=======================================================\n";

        }
        else
        {
            prev->next = current->next;
            delete current;
            cout<<"\n=======================================================\n";
            cout<<"The Task has been removed";
            cout<<"\n=======================================================\n";
        }
    }
}


void ToDoList::display()// Function to display the to-do list
{
    if ( IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty." ;
        cout<<"\n=======================================================\n";

    }
    else
    {
        Task* current = head;
        cout<<"\n=======================================================\n";
        cout << "To-Do List:\n" << endl;

        while (current!=NULL)
        {
            cout << current->info ;
            if(current->IsDone)
                cout<<" : (Is done)\n";
            else
                cout<<" : (Is not done!)\n";
            current = current->next;
        }
        cout<<"\n=======================================================\n";

    }
}

void ToDoList:: checkTaskDone(string task)  // Function to check if a task is done or not
{
    if ( IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty !";
        cout<<"\n=======================================================\n";

    }
    else
    {

        Task* current = head;
        while (current!=NULL)
        {
            if (current->info == task)
            {
                if(current->IsDone)
                {
                    cout<<"\n=======================================================\n";
                    cout<<"This task has been done";
                    cout<<"\n=======================================================\n";


                }
                else
                {
                    cout<<"\n=======================================================\n";
                    cout<<"This task has not been done!";
                    cout<<"\n=======================================================\n";


                }
                return;

            }
            current = current->next;
        }
        if(current==NULL)
        {
            cout<<"\n=======================================================\n";
            cout<<"the task is not found";
            cout<<"\n=======================================================\n";

        }
    }
}
void ToDoList:: markTaskAsDone(string task)  //Function to mark a task as done
{
    if (IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty !";
        cout<<"\n=======================================================\n";

    }
    else
    {
        Task* current = head;
        while (current!=NULL)
        {
            if (current->info == task)
            {

                if(current->IsDone)
                {
                    cout<<"\n=======================================================\n";
                    cout<<"You already have been done it before!";
                    cout<<"\n=======================================================\n";


                }
                else
                {
                    current->IsDone=true;
                    cout<<"\n=======================================================\n";
                    cout<<"Done!";
                    cout<<"\n=======================================================\n";

                }
                return;
            }
            current = current->next;

        }
        if(current==NULL)
        {
            cout<<"\n=======================================================\n";
            cout<<"the task is not found";
            cout<<"\n=======================================================\n";

        }
    }
}
void ToDoList::countDone() //Function to count tasks which have been done
{
    if (IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty !";
        cout<<"\n=======================================================\n";

    }
    else
    {
        int counter =0;
        Task* current = head;
        while (current!=NULL)
        {
            if(current->IsDone)counter++;
            current=current-> next;

        }
        cout<<"\n=======================================================\n";
        cout<<"The number of tasks which has been done is : "<< counter;
        cout<<"\n=======================================================\n";
    }
}

void ToDoList:: Are_There_Any_Tasks_To_Do() //Function to check if there are Any Tasks To Do
{
    if (IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty !";
        cout<<"\n=======================================================\n";

    }
    else
    {
        bool  f1=1,f=1;
        Task* current = head;
        while (current!=NULL)
        {
            if(f1&&!current->IsDone)
            {
                f1=0;
                f=0;
                cout<<"\n=======================================================\n";
                cout<<"Yes you have not done yet some tasks\n";
                cout<<current->info<<endl;

            }
            else if (!current->IsDone)
            {
                cout<<current->info<<endl;

            }
            current=current->next;
        }
        if(current==NULL&&f)
        {
            cout<<"\n=======================================================\n";
            cout<<"Well done ! ... You have finished All your tasks.";
            cout<<"\n=======================================================\n";
        }
        else if(current==NULL&&!f)

            cout<<"\n=======================================================\n";

    }
}
bool ToDoList:: IsExist(string task) //Function to check if the task were added or not
{
    Task* current=head;
while (current!=NULL)
{
   if(current->info==task)
    return true;
    current = current->next;
}
if(current==NULL)
return false;

}
bool ToDoList::IsToDoListEmpty()  // Function to check if the to do list is empty
{
    return(head==NULL);
}

void ToDoList::Count_tasks()             //Function to count tasks
{
     if ( IsToDoListEmpty())
    {
        cout<<"\n=======================================================\n";
        cout << "To-Do List is empty. There is 0 Tasks" ;
        cout<<"\n=======================================================\n";

    }
    else{
    Task* current = head;
    int counter=0;
    while(current!=NULL)
    {
        counter++;
        current=current->next;
    }
    cout<<"\n=======================================================\n";
    cout<<"There are "<<counter<<" task/s to do ";
    cout<<"\n=======================================================\n";

}
}
