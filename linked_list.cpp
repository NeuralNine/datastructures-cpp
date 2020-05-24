#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

class LinkedList {

    private:
        Node *head;

    public:
        LinkedList() {
            head = NULL;
        }

        void add_element(int value) {
            if(head == NULL) {
                head = new Node;
                head->value = value;
                head->next = NULL;
            } else {
                Node *tmp = head;
                while(tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = new Node;
                tmp = tmp->next;
                tmp->value = value;
                tmp->next = NULL;
            }
        }

        int get_element(int index) {
            Node *tmp = head;
            for(int i = 0; i < index; i++) {
                if(tmp->next == NULL) {
                    cout << "Index out of bounds!" << endl;
                    return -99999;
                }
                tmp = tmp->next;
            }
            return tmp->value;
        }

        int find_element(int value) {
            Node *tmp = head;
            int index = 0;
            while(tmp->next != NULL) {
                if(tmp->value == value) {
                    return index;
                }
                tmp = tmp->next;
                index++;
            }
            return -1;
        }

        void print_elements() {
            Node *tmp = head;
            if(tmp != NULL) {
                cout << tmp->value << endl;
                while(tmp->next != NULL) {
                    tmp = tmp->next;
                    cout << tmp->value << endl;
                }
            }
        }

};

int main() {

    LinkedList mylist = LinkedList();
    mylist.add_element(20);
    mylist.add_element(30);
    mylist.add_element(10);
    mylist.add_element(20);
    mylist.add_element(30);
    mylist.add_element(10);
    mylist.add_element(25);
    mylist.add_element(30);
    mylist.add_element(10);
    mylist.add_element(20);
    mylist.add_element(30);
    mylist.add_element(10);
    mylist.print_elements();

    cout << mylist.get_element(11) << endl;
    cout << mylist.find_element(25) << endl;

    return 0;
}