class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    int listsize;

    MyLinkedList() {
        head = NULL;
        listsize = 0;
    }

    int get(int index) {
        if (index < 0 || index >= listsize) return -1;
        Node* curr = head;
        for (int i = 0; i < index; i++) {  // i should start from 0
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        listsize++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {  // Yeh loop temp ko last node tak le jayega
                temp = temp->next;
            }
            temp->next = newNode;
        }
        listsize++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > listsize) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        listsize++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= listsize) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        listsize--;
    }
};
