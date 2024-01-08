#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
    int rank;
};

// Function to assign ranks to nodes based on their values in descending order
void assignRanks(struct Node* head) {
    struct Node* current;
    struct Node* index;

    // Assign initial ranks
    for (current = head; current != NULL; current = current->next) {
        current->rank = 1; // Initialize all ranks to 1
    }

    // Compare each node with others and update ranks accordingly
    for (current = head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data < index->data) {
                // Increment rank of the node with a larger value
                index->rank++;
            } else if (current->data > index->data) {
                // Increment rank of the node with a larger value
                current->rank++;
            }
            // If values are equal, ranks remain the same
        }
    }
}

// Function to display the nodes along with their ranks
void displayNodes(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("Node data: %d, Rank: %d\n", current->data, current->rank);
        current = current->next;
    }
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->rank = 0; // Initialize rank to 0

    return newNode;
}

int main() {
    // Create a linked list
    struct Node* head = createNode(30);
    head->next = createNode(10);
    head->next->next = createNode(20);

    // Assign ranks to nodes based on descending order of values
    assignRanks(head);

    // Display nodes with ranks
    displayNodes(head);

    // Free allocated memory
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
