#include <iostream>

class Node {
    public:
        int getElement() {
            return this->element;
        }
        void setElement(int e) {
            this->element = e;
        }
        Node(){}
        Node* goNext() {
            return this->next;
        }
        void printNode() {
            for(int i = 0; this->next != nullptr; th)
        }
    private:
        int element;
        Node *next;
};

int main() {
    Node n = Node();
    return 0;
}