#include <iostream>

using namespace std;

class node{

protected:
    int element;
    node* link;

public:
    //constructor that accepts only element
    node(int element) {
        this->element = element;
        this->link = NULL;
    }

    //constructor that accepts both link and element
    node(int element, node* link){
        this->element = element;
        this->link = link;
    }

    //method to update the element
    void updateData(int element){
        this->element = element;
    }

    //method to update or setup link
    void updateLink(node* link){
        this->link = link;
    }

    //method to get the element from the node
    int getElement(){
        return this->element;
    }

    //method to get the next node
    node* getNextNode(){
        return this->link;
    }
};

class Linkedlist{
protected:
    node* head;
public:

    //constructor for the Linked List class
    Linkedlist(){
        head = NULL;
    }

    //method returns true if the list is empty
    bool isEmpty(){
        return head == NULL;
    }

    //returns head node
    node* getHead(){
        return this->head;
    }

    //method to add a node at starting
    void addToStart(int element){
        node* tempNode = new node(element);
        if(head == NULL){
            head = tempNode;
        }
        else{
            tempNode->updateLink(head);
            head = tempNode;
        }
    }

    // method to add a node at the end
    void addToEnd(int element){
        node* tempNode = new node(element);
        node* p = head;
        if(head == NULL){
            head = tempNode;
            return;
        }
        else{
            while(p->getNextNode()!= NULL){
                p = p->getNextNode();
            }
            p->updateLink(tempNode);
            return;
        }
    }

    //method to display all the elements of the Linked List
    void display(){
        cout<<"\n";
        node* tempNode = head;
        while(tempNode != NULL){
            if(tempNode->getNextNode() != NULL)
                cout<<tempNode->getElement()<<" --> ";
            else
                cout<<tempNode->getElement();

            tempNode = tempNode->getNextNode();
        }
        return;
    }

    //method that returns the length of the Linked List
    int length(){
        int count = 0;
        if(this->isEmpty()){
            return -1;
        }
        node* tempNode = head;
        while(tempNode != NULL){
            count += 1;
            tempNode = tempNode->getNextNode();
        }
        return count;
    }

    //method to insert element at a given position in the Linked List
    void insert(int element, int position){
        node* tempNode = head;
        node* prevNode = head;
        if(position == 1){
            this->addToStart(element);
        }
        else{
            int pos = 1;
            while(pos != position){
                prevNode = tempNode;
                tempNode = tempNode->getNextNode();
                pos += 1;
            }
            node* p1 = new node(element,prevNode->getNextNode());
            prevNode->updateLink(p1);
        }
        return;
    }

    //method to delete a element at a given position
    void deletePosition(int position){
        node* tempNode = head;
        node* prevNode = head;
        if(position == 1){
            head = tempNode->getNextNode();
            return;
        }
        else{
            int pos = 1;
            while(pos != position){
                prevNode = tempNode;
                tempNode = tempNode->getNextNode();
                pos += 1;
            }
            prevNode->updateLink(tempNode->getNextNode());
        }
    }

    //method to delete a data element
    void deleteData(int element){
        if(isEmpty()){
            cout<<"The List is Empty";
            return;
        }
        else{
            node* tempNode = head;
            node* prevNode = head;
            while(tempNode->getElement() != element){
                prevNode = tempNode;
                tempNode = tempNode->getNextNode();
            }
            prevNode->updateLink(tempNode->getNextNode());
            return;
        }
    }

    //method that returns reversed linked list
    Linkedlist reverse(){
        Linkedlist temp;
        node* tempNode = head;
        while(tempNode != NULL){
            temp.addToStart(tempNode->getElement());
            tempNode = tempNode->getNextNode();
        }
        return temp;

    }

    //method that recursively reverses the Linked List
    void recursiveReverse(node* tempNode , node* prevNode){
        if(tempNode->getNextNode() != NULL) {
            prevNode = tempNode;
            tempNode = tempNode->getNextNode();
            recursiveReverse(tempNode, prevNode);
        }
        else{
            head = tempNode;
        }
        tempNode->updateLink(prevNode);
        prevNode->updateLink(NULL);
        return;
    }

    //method that returns index of a particular element
    int indexOf(int element){
        if(this->isEmpty()){
            return -1;
        }

        node* tempNode = head;
        int position = 1;
        bool found = false;
        while(tempNode != NULL){
            if(tempNode->getElement() == element){
                found = true;
                return position;
            }
            else {
                tempNode = tempNode->getNextNode();
                position += 1;
            }
        }
        if(not found){
            return -1;
        }
    }

    //method that returns element at a particular position
    int atIndex(int position){
        if(isEmpty()){
            return -1;
        }
        else if(position > this->length()){
            cout<<"Postion is greater than the size of Linked List.";
            return -99999;
        }
        else{
            int tempPosition = 1;
            node* tempNode = head;
            while(tempPosition != position){
                tempNode = tempNode->getNextNode();
                tempPosition += 1;
            }
            return tempNode->getElement();
        }
    }

    //method that returns the max element
    int findMax(){
        int largest = -999999; //considering this element never occurs in the list
        node* tempNode = head;
        while(tempNode != NULL){
            if(tempNode->getElement() > largest){
                largest = tempNode->getElement();
            }
            tempNode = tempNode->getNextNode();
        }
        return largest;
    }

    //method that returns the min element
    int findMin(){
        int smallest = 999999; //considering this element never occurs in the list
        node* tempNode = head;
        while(tempNode != NULL){
            if(tempNode->getElement() < smallest){
                smallest = tempNode->getElement();
            }
            tempNode = tempNode->getNextNode();
        }
        return smallest;
    }

    //method that returns the occurences of an element
    int countOccurences(int element){
        if(isEmpty()){
            return 0;
        }
        else{
            int count = 0;
            node* tempNode = head;
            while(tempNode != NULL){
                if(tempNode->getElement() == element){
                    count += 1;
                }
                tempNode = tempNode->getNextNode();
            }
            return count;
        }
    }

    //pop method removes last element of the Linked List
    int pop(){
        int position = this->length();
        this->deletePosition(position);
    }

    //method that clears the Linked List
    void clear(){
        this->head = NULL;
        cout<<"The Linked List has been cleared.";
    }

    //method that returns a string of all elements of the String
    string toString(char seperator){
        if(isEmpty()){
            cout<<"Empty List";
            return "";
        }
        else{
            string finalString = "";
            node* tempNode = head;
            while(tempNode != NULL){

                finalString  = finalString + to_string(tempNode->getElement());
                if(tempNode->getNextNode()!=NULL){
                    finalString += seperator;
                }
                tempNode = tempNode->getNextNode();
            }
            return finalString;
        }

    }

    //method that returns the copy of the list
    Linkedlist copy(){
        Linkedlist temp;
        node* tempNode = head;
        while(tempNode != NULL){
            temp.addToEnd(tempNode->getElement());
            tempNode = tempNode->getNextNode();
        }
        return temp;
    }

};

int main() {
    Linkedlist l1;
    l1.addToStart(25);
    l1.addToStart(25);
    l1.addToStart(25);
    l1.addToStart(26);
    l1.addToStart(27);
    l1.addToStart(28);
    l1.display();

    l1.addToEnd(24);
    l1.addToEnd(23);
    cout<<"\n";
    l1.display();

    cout<<"\n\nLength of the Linked List is : "<<l1.length();
    cout<<"\nLargest element of the Linked List is : "<<l1.findMax();
    cout<<"\nSmallest element of the Linked List is : "<<l1.findMin();

    cout<<"\n\nThe Element at index 3 is : "<<l1.atIndex(3);

    cout<<"\nThe index of element 27 is : "<<l1.indexOf(27);
    cout<<"\nThe index of element 31 is : "<<l1.indexOf(31);

    cout<<"\nNumber of occurences of 25 in the Linked List are : "<<l1.countOccurences(25);
    cout<<"\nNumber of occurences of 37 in the Linked List are : "<<l1.countOccurences(37);

    Linkedlist l2 = l1.copy();
    cout<<"\nThe copied List is : ";
    l2.display();

    l2.insert(99,4);
    cout<<"\n";
    l2.display();

    l2.deletePosition(4);
    l2.display();

    l2.deleteData(23);
    l2.display();

    cout<<"\n"<<l2.toString('-');
    Linkedlist l3 = l2.reverse();
    l3.display();

    l3.recursiveReverse(l3.getHead(),NULL);
    l3.display();
    return 0;
}