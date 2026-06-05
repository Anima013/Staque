#pragma once
#include <iostream>
class Staque {
    private:
        class Node {
            public:
                int data;
                Node *next;
                Node *prev;
                Node(int val) : data(val) {
                    next = nullptr;
                    prev = nullptr;
                }
        };
        Node *head;
        Node *tail;
    public: 
        // Default constructor
        Staque() : head(nullptr), tail(nullptr) { }
        // Copy constructor
        Staque(const Staque &);
        // Destructor
        ~Staque();
        // Check if the staque is empty
        bool isEmpty() const;
        // Check if a value is unique
        bool isUnique(int) const;
        // = operator overloading
        Staque &operator=(const Staque &);
        // << operator overloading
        friend std::ostream &operator<<(std::ostream &, const Staque &);
        // Insert elements
        void push(int);
        // Unlink a node (helper function for deletion)
        void unlink(Node *);
        // Delete elements
        void deleteElements(int, int, int);
        // Search for a value
        bool searchValue(int) const;
        // Print only even elements
        void printEvens() const;
        // Print only odd elements
        void printOdds() const;
        // Print the last inserted even element
        void printLastEven() const;
        // Print the last inserted odd element
        void printLastOdd() const;
};