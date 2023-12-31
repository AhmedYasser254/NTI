/*
 * Author: Ahmed Yasser
 * Group: 7
 *
 * Description: This Project contains the implementation of a school database system
 * using a Doubly Linked List data structure.
 */


#ifndef SCHOOL_H_
#define SCHOOL_H_

#include "Config.h"
#include "ErrorState.h"
#include "stdio.h"
typedef struct {
    u8 math_deg;
    u8 english_deg;
    u8 arabic_deg;
} Subject_t;

typedef struct {
    u32 phone;
    u8 address[ADDRESSSIZE];
} Personal_t;

typedef struct myStudent {
    u8 ID;
    u8 Name[NAMESIZE];
    u8 age;
    Personal_t data;
    Subject_t degrees;
} Student_t;

typedef Student_t ListEntry_t;

typedef struct Node {
    struct Node* pNext;
    struct Node* pPrev;
    ListEntry_t entry;
} ListNode_t;

typedef struct myList {
    ListNode_t* pHead;
    ListNode_t* pTail;
    int ListSize;
} List_t;

ErrorState_t  List_init(List_t* pl); // init head = tail = NULL
ErrorState_t List_insertStudent(List_t* pl, const ListEntry_t* pe) ;
ErrorState_t List_searchStudent(const List_t* pl, u8 copy_u8ID, ListNode_t** pFoundStudent);
ErrorState_t  List_deleteStudent(List_t* pl , u8 copy_u8ID);
ErrorState_t List_editStudent(List_t* pl, u8 copy_u8ID, u8 newAge, Subject_t newDegrees) ;
ErrorState_t List_updateScore(List_t* pl, u8 copy_u8ID, Subject_t newDegrees) ;
ErrorState_t List_printList(const List_t* pl);
ErrorState_t List_listSize(const List_t* pl, u32* pSize) ;
ErrorState_t  List_freeList( List_t* pl);

#endif /* SCHOOL_H_ */
