#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;

        DoublyLinkedList() {
            this->head = nullptr;
        }

};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ostream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}


void free_doubly_linked_list(DoublyLinkedListNode * head){
    while( head != nullptr){
        DoublyLinkedListNode * temp = head;
        head=head->next;
        free(temp);
    }
}

DoublyLinkedListNode* insertNodeAtTail(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
    if(head==nullptr){
        head = node;
        head->next = nullptr;
        head->prev = nullptr;
        return head;
    }
    DoublyLinkedListNode *curr = head, *prev=nullptr;
    while(curr!=nullptr){
        prev = curr;
        curr = curr->next;
    }
    node->next = curr;
    node->prev = prev;
    if(prev!=nullptr){
        prev->next = node;
     }

    return head;
}


DoublyLinkedListNode* insertNodeAtHead(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
    if(head==nullptr){
        head = node;
        head->next = nullptr;
        head->prev = nullptr;
        return head;
    }
    node->next = head;
    head->prev = node;
    head = node;

    return head;
}

DoublyLinkedListNode* insertNodeAtPosition(DoublyLinkedListNode* head, int data,int pos) {
    DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
    if(head==nullptr){
        head = node;
        head->next = nullptr;
        head->prev = nullptr;
        return head;
    }
    DoublyLinkedListNode *curr = head, *prev=nullptr;
    while(pos > 0 && curr!=nullptr){
        prev = curr;
        curr = curr->next;
        pos--;
    }
    node->next = curr;
    node->prev = prev;
    if(prev!=nullptr){
        prev->next = node;
     }
    if(curr!=nullptr){
        curr->prev = node;
    }

    return head;
}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));

    DoublyLinkedList* llist = new DoublyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    	DoublyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, llist_item,i);
      	llist->head = llist_head;
    }


    print_doubly_linked_list(llist->head, "\n", cout);
    cout << "\n";

    free_doubly_linked_list(llist->head);

    //fout.close();

    return 0;
}
