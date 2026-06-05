#include "Staque.h"
#include <iostream>

// Copy constructor
Staque::Staque(const Staque &original) : head(nullptr), tail(nullptr)
{
    if (!original.isEmpty())
    {
        Node *current = original.head;
        while (current)
        {
            Node *newNode = new Node(current->data);
            if (!head)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            current = current->next;
        }
    }
}

// Destructor
Staque::~Staque() 
{
    while(head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

// Check if the staque is empty
bool Staque::isEmpty() const
{
    return (head == nullptr && tail == nullptr);
}

// Check if a value is unique
bool Staque::isUnique(int x) const {
    Node *temp = head;
    while(temp) {
        if(temp->data == x)
            return false;
        temp = temp->next;
    }
    return true;
}

// = operator overloading
Staque& Staque::operator=(const Staque &s) {
    // Delete old structure
    while(head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;

    // Assign new structure
    if(!s.isEmpty()) {
        Node *current = s.head;
        while(current) {
            Node *newNode = new Node(current->data);
            if(!head) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            current = current->next;
        }
    }
    return *this;
}

// << operator overloading
std::ostream& operator<<(std::ostream &out, const Staque &s) {
    Staque::Node *temp = s.head;
    while(temp) {
        out << temp->data << ' ';
        temp = temp->next;
    }
    return out;
}

// Add elements
void Staque::push(int val) {
    Node *newNode = new Node(val);
    // Insert odd number to the front of the list
    if(val % 2 != 0) {
        if(!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    // Insert even number to the end of the list
    else {
        if(!tail) {
            tail = head = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// Unlink a node (helper function for deletion)
void Staque::unlink(Node *del) {
    Node *left = del->prev;
    Node *right = del->next;
    if(left)
        left->next = right;
    else
        head = right;
    if(right)
        right->prev = left;
    else
        tail = left;
    delete del;
}

// Delete elements
void Staque::deleteElements(int evenCount = 0, int oddCount = 0, int lifoCount = 0) {
    // Delete even elements starting from the right
    if(evenCount > 0) {
        int evens = 0;
        Node *temp = tail;
        while(temp) {
            if(temp->data % 2 == 0)
                evens++;
            temp = temp->prev;
        }
        if(evens < evenCount) {
            std::cout << "Not enough evens to delete.\n\n";
            return;
        }
        temp = tail;
        int removedEvens = 0;
        while(temp && removedEvens < evenCount) {
            if(temp->data % 2 == 0) {
                Node *del = temp;
                temp = temp->prev;
                unlink(del);
                removedEvens++;
            }
            else {
                temp = temp->prev;
            }
        }
        return;
    }

    // Delete odd elements starting from the right
    if(oddCount > 0) {
        int odds = 0;
        Node *temp = tail;
        while(temp) {
            if(temp->data % 2 != 0)
                odds++;
            temp = temp->prev;
        }
        if(odds < oddCount) {
            std::cout << "Not enough odds to delete.\n\n";
            return;
        }
        temp = tail;
        int removedOdds = 0;
        while (temp && removedOdds < oddCount) {
            if (temp->data % 2 != 0)
            {
                Node *del = temp;
                temp = temp->prev;
                unlink(del);
                removedOdds++;
            }
            else
            {
                temp = temp->prev;
            }
        }
        return;
    }

    // Delete elements with LIFO starting from the right
    if(lifoCount > 0) {
        int size = 0;
        Node *temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }
        if(size < lifoCount) {
            std::cout << "Not enough nodes to delete. All elements will be deleted.\n\n";
            while(head) {
                Node *del = head;
                head = head->next;
                delete del;
            }
            tail = nullptr;
            return;
        }
        for (int i = 0; i < lifoCount; ++i) {
            Node *del = tail;
            unlink(del);
        }
    }
}

// Search for a value
bool Staque::searchValue(int x) const {
    // Search for an even value among even elements
    if(x % 2 == 0) {
        Node *temp = tail;
        while(temp) {
            if(temp->data == x)
                return true;
            if(temp->data % 2 != 0)
                return false;
            temp = temp->prev;
        }
        return false;
    }
    else {
        Node *temp = head;
        while(temp) {
            if(temp->data == x)
                return true;
            if(temp->data % 2 == 0)
                return false;
            temp = temp->next;
        }
        return false;
    }
}

// Print only even elements
void Staque::printEvens() const {
    Node *temp = tail;
    bool noEvens = true;
    while(temp) {
        if(temp->data % 2 == 0) {
            std::cout << temp->data << ' ';
            noEvens = false;
        }
        temp = temp->prev;
    }
    if(noEvens) {
        std::cout << "No evens in the list.\n\n";
    }
}

// Print only odd elements
void Staque::printOdds() const {
    Node *temp = head;
    bool noOdds = true;
    while(temp) {
        if(temp->data % 2 != 0) {
            std::cout << temp->data << ' ';
            noOdds = false;
        }
        temp = temp->next;
    }
    if(noOdds) {
        std::cout << "No odds in the list.\n\n";
    }
}

// Print the last inserted even element
void Staque::printLastEven() const {
    if(isEmpty()) {
        std::cout << "List is empty.\n\n";
        return;
    }
    if(tail->data % 2 == 0)
        std::cout << "Last even: " << tail->data << "\n\n";
    else
        std::cout << "No even element.\n\n";
}

// Print the last inserted odd element
void Staque::printLastOdd() const {
    if(isEmpty()) {
        std::cout << "List is empty.\n\n";
        return;
    }
    if(head->data % 2 != 0)
        std::cout << "Last odd: " << head->data << "\n\n";
    else
        std::cout << "No odd element.\n\n";
}