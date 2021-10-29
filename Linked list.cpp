#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data; //Dati
    Node* next; //Adrese uz nakamo
};
//CREATE NODE
Node* CreateNode()
{
    Node* newNode; //apraktaa raditaju uz jauno mezglu
    newNode = new Node; //izdala atminju jaunajam mezglam
    newNode->next = NULL;//adrese next=NULL,jo mezgli nav savienoti
    cout << "\n\t\t\t\t\t\tType the number: ";
    cin >> newNode->data;//ievada datus mezgla
    return newNode;
}
//PRINT LIST
void PrintList(Node* head)
{
    Node* cur;
    cout << "\n\t\t\t\t\t\tList elements: ";
    cur = head; //pariet uz sarakta sakumu
    while (cur != NULL)//kamer tekoshai mezgls nav pedejais izdrukaa datus un pariet uz nakoho mezglu
    {
        cout << cur->data << " "; //izvadda datus
        cur = cur->next; //aiziet uz nakosho mezglu, iedot adresi nakoshajam mezglam
    }
}
//ADD FIRST
Node* AddFirst(Node* head, Node* newNode)
{
    newNode->next = head; // ievada sakmuma adresi
    return newNode; //atgriezh jauna mezgla adresi
}
//ADD LAST
void AddLast(Node* head, Node* newNode)
{
    Node* cur;
    cur = head; //pariet uz sarakta sakumu
    while (cur->next != NULL) //kamer mezglam adrese nav NULL vinsh pariet uz nakosho mezglu
    {
        cur = cur->next;
    }
    cur->next = newNode; // pariet uz jaunizveioto mezglu
}
// FIND
Node* Find(Node* head, int y)
{
    Node* cur;
    cur = head; //pariet uz sarakta sakumu
    while (cur != NULL && cur->data != y)//kamer tekoshai mezgls nav y pariet uz nakoho mezglu
    {
        cur = cur->next; //aiziet uz nakosho mezglu, iedot adresi nakoshajam mezglam
    }
    return cur;
}
// ADD AFTER
void AddAfter(Node* temp, Node* newNode)
{
    newNode->next = temp->next; //jaunaa mezgla adrese ir vienada ar nakamaa mezgla adresi
    temp->next = newNode; //mezgla temp adrese norada uz newNode
}
// FIND BEFORE
Node* FindBefore(Node* head, int y)
{
    Node* cur, * prevCur;
    cur = head; //pariet uz sarakta sakumu
    prevCur = head;
    while (cur != NULL && cur->data != y)//kamer tekoshai mezgls nav y pariet uz nakoho mezglu
    {
        prevCur = cur; //previous current
        cur = cur->next; //aiziet uz nakosho mezglu, iedot adresi nakoshajam mezglam
    }
    return prevCur;
}
// DELETE FIRST
Node* DeleteFirst(Node* head)
{
    Node* cur;
    cur = head->next;
    delete head;
    return cur;
}
// DELETE LAST
void DeleteLast(Node* head)
{
    Node* cur, * prevCur;
    cur = head;
    prevCur = head;
    while (cur->next != NULL)
    {
        prevCur = cur;
        cur = cur->next;
    }
    prevCur -> next = NULL;
    delete cur;
}
// DELETE AFTER
void DeleteAfter(Node* cur)
{
    Node* temp;
    temp = cur->next;
    cur->next = temp->next;
    delete temp; // temp - mezglskuru dzesham
}
// FIND BEFORE2
Node* FindBefore2(Node* head, int y)
{
    Node* cur, * prevCur, * prevCur2 = NULL;
    cur = head; //pariet uz sarakta sakumu
    prevCur = head;
    while (cur != NULL && cur->data != y)//kamer tekoshai mezgls nav y pariet uz nakoho mezglu
    {
        prevCur2 = prevCur;
        prevCur = cur; //previous current
        cur = cur->next; //aiziet uz nakosho mezglu, iedot adresi nakoshajam mezglam
    }
    return prevCur2;
}
// LIST LENGHT
int ListLenght(Node* head, int n)
{
    Node* cur;
    cur = head;
    while (cur)
    {
        n++;
        cur = cur->next;
    }
    return n;
}
// DELETE ALL
Node* DeleteAll(Node* head)
{
    if (head)
    {
        Node* cur;
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        delete cur;
        cur = NULL;
        cout << "\n\t\t\t\t\t\tThe list has been deleted!";
    }
    else cout << "\n\t\t\t\t\t\tThe list is empty!";
    return NULL;
}

int main() {
    Node* head, * newNode, * temp, * temp2, * temp3;
    int x, y, n = 0, lenght;
    cout << "\t\t\t\t\t\tLinked list\n";
    head = CreateNode();
    do {
        system("cls");
        cout << "\n\t\t\t\t\t\tMenu\n";
        cout << "\t\t\t\t\t\t1. PrintList\n";
        cout << "\t\t\t\t\t\t2. AddFirst\n";
        cout << "\t\t\t\t\t\t3. AddLast\n";
        cout << "\t\t\t\t\t\t4. AddAfter\n";
        cout << "\t\t\t\t\t\t5. AddBefore\n";
        cout << "\t\t\t\t\t\t6. DeleteFirst\n";
        cout << "\t\t\t\t\t\t7. DeleteLast\n";
        cout << "\t\t\t\t\t\t8. DeleteAfter\n";
        cout << "\t\t\t\t\t\t9. DeleteBefore\n";
        cout << "\t\t\t\t\t\t10. ListLenght\n";
        cout << "\t\t\t\t\t\t11. DeleteAll\n";
        cout << "\t\t\t\t\t\t12. Info\n";
        cout << "\t\t\t\t\t\t0. Exit\n";
        cout << "\t\t\t\t\t\tAction: ";
        cin >> x;
        switch (x) {
            // PRINT LIST
        case 1:
            if (head)
                PrintList(head);
            else cout << "\t\t\t\t\t\tThe list is empty";
            system("pause>nul");
            break;
            // ADD FIRST
        case 2:
            newNode = CreateNode(); // izveido mezglu
            head = AddFirst(head, newNode); //jauns saraksta saakums
            system("pause>nul");
            break;
            // ADD LAST
        case 3:
            if (head)
            {
                newNode = CreateNode();
                AddLast(head, newNode);
            }
            else cout << "\n\t\t\t\t\t\tYour list is empty, add first element!";
            system("pause>nul");
            break;
            // ADD AFTER
        case 4:
            if (head)
            {
                cout << "\n\t\t\t\t\t\tInsert after what? ";
                cin >> y;
                temp = Find(head, y);
                if (temp)
                {
                    newNode = CreateNode();
                    AddAfter(temp, newNode);
                }
                else cout << "\n\t\t\t\t\t\tWrong node data!";
            }
            else cout << "\n\t\t\t\t\t\tYour list is empty, add first element!";
            system("pause>nul");
            break;
            //ADD BEFORE
        case 5:
            if (head)
            {
                cout << "\n\t\t\t\t\t\tInsert before what? ";
                cin >> y;
                temp = Find(head, y);
                if (temp)
                {
                    newNode = CreateNode();
                    if (temp == head)
                    {
                        head = AddFirst(head, newNode);
                    }
                    else
                    {
                        temp2 = FindBefore(head, y);
                        AddAfter(temp2, newNode);
                    }
                }
            }
            else cout << "\n\t\t\t\t\t\tYour list is empty, add first element!";
            system("pause>nul");
            break;
            // DELETE FIRST
        case 6:
            if (head)
            {
                head = DeleteFirst(head);
                cout << "\n\t\t\t\t\t\tYou have deleted the first element!";
            }
            else cout << "\n\t\t\t\t\t\tThe list is empty!";
            system("pause>nul");
            break;
            // DELETE LAST
        case 7:
            if (!head) cout << "\n\t\t\t\t\t\tThe list is empty!";
            else if (head->next != NULL)
            {
                DeleteLast(head);
                cout << "\n\t\t\t\t\t\tYou have deleted the last element!";
            }
            else if (head->next == NULL)
            {
                head = DeleteFirst(head);
                cout << "\n\t\t\t\t\t\tYou have deleted the last element!";
            }
            system("pause>nul");
            break;
            // DELETE AFTER
        case 8:
            if (head)
            {
                cout << "\n\t\t\t\t\t\tDelete after what? ";
                cin >> y;
                temp = Find(head, y);
                if (temp != NULL && temp->next == NULL)
                {
                    cout << "\n\t\t\t\t\t\tThe is no node to delete!";
                }
                else if (temp != NULL && temp->next != NULL)
                {
                    DeleteAfter(temp);
                    cout << "\n\t\t\t\t\t\tNode has been deleted!";
                }
                else cout << "\n\t\t\t\t\t\tNode doesn't exist!";
            }
            else cout << "\n\t\t\t\t\t\tYour list is empty, add first element!";
            system("pause>nul");
            break;
            // DELETE BEFORE
        case 9:
            if (head)
            {
                cout << "\n\t\t\t\t\t\tDelete before what? ";
                cin >> y;
                temp = Find(head, y);
                temp2 = FindBefore(head, y);
                temp3 = FindBefore2(head, y);
                if (head != NULL && head->next != NULL)
                {
                    head = DeleteFirst(head);
                    cout << "\n\t\t\t\t\t\tNode has been deleted!";
                }
                else if (temp)
                {
                    temp3->next = temp;
                    delete temp2;
                    cout << "\n\t\t\t\t\t\tNode has been deleted!";
                }
                else cout << "\n\t\t\t\t\t\tNode doen't exist";
            }
            else cout << "\n\t\t\t\t\t\tYour list is empty, add first element!";
            system("pause>nul");
            break;
            // LIST LENGHT
        case 10:           
                lenght = ListLenght(head, n);
                if(lenght > 1)
                cout << "\n\t\t\t\t\t\tThis list have " << lenght << " elements!";
                else if(lenght == 1)
                cout << "\n\t\t\t\t\t\tThis list have " << lenght << " element!";
                else cout << "\n\t\t\t\t\t\tThis list is empty!";
            system("pause>nul");
            break;
            // DELETE ALL
        case 11:
            head = DeleteAll(head);
            system("pause>nul");
            break;
        case 12:
            cout << "\n\t\t\t\t\t\tAuthor: Raitis Izhiks\n\t\t\t\t\t\tVer: 1.0";
            system("pause>nul");
            break;
        case 0: cout << "\n\t\t\t\t\t\tExit!";
            break;

        default: cout << "\n\t\t\t\t\t\tThe action is wrong!";
            break;
        }
    } while (x != 0);
    return 0;
    system("pause>nul");
}