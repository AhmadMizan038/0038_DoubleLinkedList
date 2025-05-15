#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
    private:
        Node *START;

    public:
        DoubleLinkedList()
        {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            string nm;
            cout << "\nEnter the roll number of the student";
            cin >> nim;

            //step 1. ALLcate memory for new node
            Node *newNode = new Node();

            //step 2. Assign value to the data fields
            newNode->noMhs =  nim;

            //step 3. Insert at beginning if list is empty or nim is smallest
            if (START == NULL || nim <= START->noMhs)
            {
                if (START != NULL && nim == START->noMhs)
                {
                    cout << "\nDuplicate number not allowed" << endl;
                    return;
                }
                //step 4. newNode.next = START
                newNode->next = START;

                //step 5. start.prev = newNode (if start exsits)
                if (START != NULL)
                    START->prev = newNode;

                //step 6. newNode.prev = NULL
                newNode->prev = NULL;

                //step 7. START = newNode
                START = newNode;
                return;
            }

            // insert in between node
            // step 8. locate potition for insertion
            Node *current = START;
            while (current->next !=NULL && current->next->noMhs < nim)
            {
                current = current->next;
            }

            if (current->next !=NULL && nim == current->next->noMhs)
            {
                cout << "\nDuplicate roll number not allowed" << endl;
                return;
            }
            //step 9. insert between current and current->next
            newNode->next = current->next; //step9a
            newNode->prev = current; //step9b

            //insert  last node 
            if (current->next != NULL)
            current->next->prev = newNode; //step9c

            current->next = newNode; //step9d
        }

        void hapus()
        {
            if (START == NULL)
            {
                cout << "\nList empty" << endl;
                return;
            }

            cout <<"\nEnter the roll number of student whose is to be daleted";
            int rollNo;
            cin >> rollNo;

            Node *current = START;

            //step 1. traverse the list to find the node
            while (current != NULL && current->noMhs != rollNo)
                current = current->next;

            if (current == NULL)
            {
                cout << "record not found" << endl;
                return;
            }

            //step 2. if modeis last at the begining
            if (current == START)
            {
                START = current->next;//step 2a : START = START.next
                if (START !=NULL)
                    START->prev = NULL;//step 2b : START.prev = NULL
            }
            else 
            {
                //step 3. Link previuos note to next of current
                current->prev->next = current->next;

                //step 4. if current is not the last node
                if (current ->next != NULL)
                    current ->next->prev = current->prev;
            }

            //step 5.dalate the node
            delate current;
            coutb<< "record with roll number" << rollNo << "delate" << endl;
        }

        void traverse()
        {
            if (START == NULL)
            {
                cout << "\nList is empty" << endl;
                return;
            }

            //Mark firts node as currentNode
            Node *curentNode = START;

        }
}