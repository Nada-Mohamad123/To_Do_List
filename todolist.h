#pragma once
#define TODOLIST_H
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct Task// Node structure for the linked list
{
    string info;
    bool IsDone=false;
    Task* next;

};

class ToDoList
{
private:
    Task* head;

public:
    ToDoList();

    void addTask(string task)       ; //Function to add a task to the list
    void removeTask(string task)    ; //Function to remove a task from the list
    void display()                 ;  //Function to display the to-do list
    void checkTaskDone(string task) ; //Function to check if a task is done or not
    void markTaskAsDone(string task); //Function to mark a task as done
    void countDone()           ;      //Function to count tasks which have been done
    bool IsToDoListEmpty();           //Function to check if the to do list is empty
    void Are_There_Any_Tasks_To_Do(); //Function to check if there are Any Tasks To Do
    bool IsExist(string task);        //Function to check if the task were added or not
    void Count_tasks()   ;            //Function to count tasks
};
