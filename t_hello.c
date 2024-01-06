#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла списка
struct Node {
    int data;
    struct Node *next;
};

// Функция для добавления нового узла в конец списка
void appendNode(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// Функция для вывода списка
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    // Создаем пустой связанный список
    struct Node *head = NULL;

    // Проходим по аргументам и добавляем их в список
    for (int i = 1; i < argc; i++) {
        int data = atoi(argv[i]); // Преобразуем аргумент в целое число
        appendNode(&head, data);
    }

    // Выводим список
    printf("Linked List: ");
    printList(head);

    // Освобождаем память
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
