/*
 * Author: Ahmed Yasser
 * Group: 7
 *
 * Description: This Project contains the implementation of a school database system
 * using a Doubly Linked List data structure.
 */

#include "school.h"
#include <stdlib.h>

// Function to initialize the list
ErrorState_t List_init(List_t* pl) {
    if (pl == NULL) {
        return FAILURE;
    }

    pl->pHead = NULL;
    pl->pTail = NULL;
    pl->ListSize = 0;

    return SUCCESS;
}

// Helper function to compare student names for alphabetical sorting
int CompareStudentNames(const char* name1, const char* name2) {
    return strcmp(name1, name2);
}

// Function to insert a student into the list
ErrorState_t List_insertStudent(List_t* pl, const ListEntry_t* pe) {
    if (pl == NULL || pe == NULL) {
        return FAILURE;
    }

    ListNode_t* newNode = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (newNode == NULL) {
        return FAILURE;
    }

    newNode->entry = *pe;
    newNode->pNext = NULL;
    newNode->pPrev = NULL;

    if (pl->pHead == NULL) {
        // Insert into an empty list
        pl->pHead = newNode;
        pl->pTail = newNode;
    } else {
        // Insert in alphabetical order
        ListNode_t* current = pl->pHead;
        ListNode_t* prev = NULL;

        while (current != NULL && CompareStudentNames(current->entry.Name, pe->Name) < 0) {
            prev = current;
            current = current->pNext;
        }

        if (prev == NULL) {
            // Insert at the head
            newNode->pNext = pl->pHead;
            pl->pHead->pPrev = newNode;
            pl->pHead = newNode;
        } else if (current == NULL) {
            // Insert at the tail
            newNode->pPrev = pl->pTail;
            pl->pTail->pNext = newNode;
            pl->pTail = newNode;
        } else {
            // Insert in the middle
            newNode->pNext = current;
            newNode->pPrev = prev;
            prev->pNext = newNode;
            current->pPrev = newNode;
        }
    }

    pl->ListSize++;

    return SUCCESS;
}

// Function to search for a student by ID
ErrorState_t List_searchStudent(const List_t* pl, u8 copy_u8ID, ListNode_t** pFoundStudent) {
    if (pl == NULL || pFoundStudent == NULL) {
        return FAILURE;
    }

    *pFoundStudent = NULL;

    ListNode_t* current = pl->pHead;
    while (current != NULL) {
        if (current->entry.ID == copy_u8ID) {
            *pFoundStudent = current;
            return SUCCESS;
        }
        current = current->pNext;
    }

    return NOT_FOUND;
}

// Function to delete a student by ID
ErrorState_t List_deleteStudent(List_t* pl, u8 copy_u8ID) {
    if (pl == NULL) {
        return FAILURE;
    }

    ListNode_t* studentToDelete;
    ErrorState_t searchResult = List_searchStudent(pl, copy_u8ID, &studentToDelete);

    if (searchResult == SUCCESS) {
        if (studentToDelete == pl->pHead) {
            pl->pHead = studentToDelete->pNext;
            if (pl->pHead != NULL) {
                pl->pHead->pPrev = NULL;
            }
        } else if (studentToDelete == pl->pTail) {
            pl->pTail = studentToDelete->pPrev;
            if (pl->pTail != NULL) {
                pl->pTail->pNext = NULL;
            }
        } else {
            studentToDelete->pPrev->pNext = studentToDelete->pNext;
            studentToDelete->pNext->pPrev = studentToDelete->pPrev;
        }

        free(studentToDelete);
        pl->ListSize--;

        return SUCCESS;
    }

    return NOT_FOUND;
}

// Function to edit a student's information
ErrorState_t List_editStudent(List_t* pl, u8 copy_u8ID, u8 newAge, Subject_t newDegrees) {
    if (pl == NULL) {
        return FAILURE;
    }

    ListNode_t* studentToEdit;
    ErrorState_t searchResult = List_searchStudent(pl, copy_u8ID, &studentToEdit);

    if (searchResult == SUCCESS) {
        // Edit the student's information (except name and ID)
        studentToEdit->entry.age = newAge;
        studentToEdit->entry.degrees = newDegrees;
        return SUCCESS;
    }

    return NOT_FOUND;
}

// Function to update a student's scores
ErrorState_t List_updateScore(List_t* pl, u8 copy_u8ID, Subject_t newDegrees) {
    if (pl == NULL) {
        return FAILURE;
    }

    ListNode_t* studentToUpdate;
    ErrorState_t searchResult = List_searchStudent(pl, copy_u8ID, &studentToUpdate);

    if (searchResult == SUCCESS) {
        // Update the student's scores
        studentToUpdate->entry.degrees = newDegrees;
        return SUCCESS;
    }

    return NOT_FOUND;
}

// Function to print the list
ErrorState_t List_printList(const List_t* pl) {
    if (pl == NULL) {
        return FAILURE;
    }

    ListNode_t* current = pl->pHead;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", current->entry.ID, current->entry.Name, current->entry.age);
        current = current->pNext;
    }

    return SUCCESS;
}

// Function to get the list size
ErrorState_t List_listSize(const List_t* pl, u32* pSize) {
    if (pl == NULL || pSize == NULL) {
        return FAILURE;
    }

    *pSize = pl->ListSize;

    return SUCCESS;
}

// Function to free the list and its nodes
ErrorState_t List_freeList(List_t* pl) {
    if (pl == NULL) {
        return FAILURE;
    }

    ListNode_t* current = pl->pHead;
    while (current != NULL) {
        ListNode_t* next = current->pNext;
        free(current);
        current = next;
    }

    pl->pHead = NULL;
    pl->pTail = NULL;
    pl->ListSize = 0;

    return SUCCESS;
}
