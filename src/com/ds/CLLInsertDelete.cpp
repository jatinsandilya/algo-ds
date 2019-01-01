#include <bits/stdc++.h>

using namespace std;

class CLLNode {
    public:
        int data;
        CLLNode *next;

        CLLNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class CircularLinkedList {
    public:
        CLLNode *head;
        int _size;

        CircularLinkedList() {
            this->head = nullptr;
            _size = 0;
        }

        int size(){
            return this->_size;
        }

};

void print_singly_linked_list(CLLNode* node, string sep, ostream& fout,int size) {
    CLLNode * head = node;

    int pos = 0;

    while(pos < size){
        fout << node->data;
        fout << sep;

        node = node->next;

        pos++;
    }

}

void free_singly_linked_list(CLLNode* node) {
    while (node) {
        CLLNode* temp = node;
        node = node->next;

        free(temp);
    }
}

CLLNode* deleteNode(CLLNode* head, int position) {
    if(position==0){
        CLLNode * temp = head;
        CLLNode * curr = head;

        do{
            curr = curr->next;
        }while(curr->next!=head);
        curr->next = head->next;
        head = head->next;

        free(temp);
        return head;
    }
    else{
        CLLNode * curr = head, * prev = nullptr;
        while(position > 0){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;

        free(curr);
    }
    return head;
}

CLLNode* insertNodeAtPosition(CLLNode* head, int data, int pos,int SIZE) {
    CLLNode * node = new CLLNode(data);
    if(pos == 0 || pos == SIZE){
        node->next = head;
        CLLNode * curr = head;

        if(head!=nullptr){
            do{
                curr = curr->next;
            }while(curr->next!=head);

            curr->next = node;
        }else{
            node->next = node;
        }
    }

    if(pos==0){
        head = node;
        return head;
    }
    if(pos==SIZE){
       return head;
    }

    CLLNode * curr = head, * prev = nullptr;
    while(pos > 0 ){
        prev = curr;
        curr = curr->next;
        pos--;
    }
    node->next = curr;
    prev->next = node;

    return head;

}

int main(){

    CircularLinkedList* llist = new CircularLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        CLLNode * llist_head = insertNodeAtPosition(llist->head,llist_item,i,llist->size());
        llist->head = llist_head;
        (llist->_size)++;
    }
    print_singly_linked_list(llist->head, " ", cout,llist->size());

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    CLLNode* llist1 = deleteNode(llist->head, position);
    llist->head = llist1;

    (llist->_size)--;

    print_singly_linked_list(llist->head, " ", cout,llist->size());

    cout << "\n";

    return 0;
}
