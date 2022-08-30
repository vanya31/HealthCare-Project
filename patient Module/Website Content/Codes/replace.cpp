#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int dept;
    string Name;
    string Dept;
    int Rating;
    Node* next;
};
 
Node* head = new Node();

bool check(int x)
{
    if (head == NULL)
        return false;
 
    Node* t = new Node;
    t = head;
 
    while (t != NULL) {
        if (t->dept == x)
            return true;
        t = t->next;
    }
 
    return false;
}
 
void Insert_Record(int dept, string Name,
                   string Dept, int Rating)
{
    if (check(dept)) {
        cout << "Doctor with this "
             << "record Already Exists\n";
        return;
    }
 
    Node* t = new Node();
    t->dept = dept;
    t->Name = Name;
    t->Dept = Dept;
    t->Rating = Rating;
    t->next = NULL;
 
    if (head == NULL
        || (head->dept >= t->dept)) {
        t->next = head;
        head = t;
    }
 
    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->dept < t->dept) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
 
    cout << "Record Inserted "
         << "Successfully\n";
}
 
void Search_Record(int dept)
{
    if (!head) {
        cout << "No such Record "
             << "Available\n";
        return;
    }
 
    else {
        Node* p = head;
        while (p) {
            if (p->dept == dept) {
                cout << "Department Number\t"
                     << p->dept << endl;
                cout << "Name\t\t"
                     << p->Name << endl;
                cout << "Department\t"
                     << p->Dept << endl;
                cout << "Rating\t\t"
                     << p->Rating << endl;
                return;
            }
            p = p->next;
        }
 
        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}
 
int Delete_Record(int dept)
{
    Node* t = head;
    Node* p = NULL;
 
    
    if (t != NULL
        && t->dept == dept) {
        head = t->next;
        delete t;
 
        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }
 
    while (t != NULL && t->dept != dept) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;
 
        delete t;
        cout << "Record Deleted "
             << "Successfully\n";
 
        return 0;
    }
}
 
void Show_Record()
{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available\n";
    }
    else {
        cout << "Index\tName\tDepartment"
             << "\tRating\n";
 
        while (p != NULL) {
            cout << p->dept << "    \t"
                 << p->Name << "\t"
                 << p->Dept << "\t"
                 << p->Rating << endl;
            p = p->next;
        }
    }
}
 
int main()
{
    head = NULL;
    string Name, Department;
    int Dept,Rating;
 
    while (true) {
        cout << "\n\t\tWelcome to Doctor Portal "
                "\n\t\t Department and its following numbers"
                "\n\t1 Limbs "
                "Department\n\t\t\t\t2 Back "
                "Department\n\t3 Neck "
                "Department\n\t4 Stomach "
                "Department\n\t\tPress\n\t1 to "
                "create a new Doctor Record\n\t2 to delete a "
                "Doctor record\n\t3 to Search for a Doctor "
                "Record\n\t4 to view all Doctors "
                "\n\t5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;
 
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Doctor\n";
            cin >> Name;
            cout << "Enter Department Number of Doctor\n";
            cin >> Dept;
            cout << "Enter Department of Doctor \n";
            cin >> Department;
            cout << "Enter Rating of Doctotr\n";
            cin >> Rating;
            Insert_Record(Dept, Name, Department, Rating);
        }
        else if (Choice == 2) {
            cout << "Enter Department Number of Doctor whose record "
                    "you want to delete\n";
            cin >> Dept;
            Delete_Record(Dept);
        }
        else if (Choice == 3) {
            cout << "Enter Department Number of Doctor whom "
                    "you want to Search\n";
            cin >> Dept;
            Search_Record(Dept);
        }
        else if (Choice == 4) {
            Show_Record();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}