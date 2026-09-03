#ifndef LIST_QUESTIONS_H
#define LIST_QUESTIONS_H

//#define DEBUG

#include "LinkedList.h"
#include <stdbool.h>
/*
 * Problem: Determine if a linked list has a cycle
 *
 * Description:
 * Given the head of a linked list, determine if the list contains a cycle. A cycle occurs if a node can be
 * reached again by continuously following the `next` pointer. Internally, 'pos' is used to denote the index
 * of the node that the tail's next pointer is connected to, indicating a cycle. Note that 'pos' is not
 * accessible or passed as a parameter; it's only used for problem understanding and explanation.
 *
 * Task:
 * Implement a function to check if the given linked list has a cycle. The function should return 'true' if a
 * cycle is present and 'false' otherwise.
 *
 * Prototype:
 * bool hasCycle(struct Node *head);
 */

static bool hasCycle(struct Node *head)
{
	if (head == NULL){
		return false;
	}

	Node* pos = head;
	Node* cur_node = head->next;
	while (cur_node != NULL){
		if (cur_node == pos){
			return true;
		}
		cur_node = cur_node->next;
	}
	return false;
}

/*
 * Problem: Merge Two Sorted Lists
 *
 * Description:
 * You are given the heads of two sorted linked lists, list1 and list2. Your task is to merge these two
 * lists into one single sorted list. The merged list should be constructed by splicing together the nodes
 * of the first two lists without creating new nodes, but by rearranging the nodes from the given lists.
 *
 * Task:
 * Implement a function that merges two sorted linked lists and returns the head of the newly merged sorted
 * linked list.
 *
 * Prototype:
 * struct Node* mergeTwoLists(struct Node* list1, struct Node* list2);
 *
 * Note:
 * Both list1 and list2 are sorted in non-decreasing order.
 */

static struct Node* mergeLists(struct Node* list1, struct Node* list2)
{

	if (list1 == NULL && list2 == NULL){
		return NULL;
	}else if (list1 == NULL){
		return list2;
	}else if (list2 == NULL){
		return list1;
	}

	Node* new_node = NULL;
	Node* cur_pos;
	Node* cur_pos_l1 = list1;
	Node* cur_pos_l2 = list2;
	
	//Placeholder return statement
	#ifdef DEBUG
	printf("list1: ");
	printList(list1);
	printf("list2: ");
	printList(list2);
	#endif

	while (cur_pos_l1 != NULL && cur_pos_l2 != NULL){
		if (cur_pos_l1->data < cur_pos_l2->data){
			if (new_node == NULL){
				new_node = createNode(list1->data);
				cur_pos = new_node;
			}else{

				cur_pos->next = cur_pos_l1;
				cur_pos = cur_pos->next;
			}
			cur_pos_l1 = cur_pos_l1->next;
		}else
		{
			if (new_node == NULL){
				new_node = createNode(list2->data);
				cur_pos = new_node;
			}else{
				cur_pos->next = cur_pos_l2;
				cur_pos = cur_pos->next;
			}
			cur_pos_l2 = cur_pos_l2->next;

		}
		#ifdef DEBUG
		printf("current merge status: ");
		printList(new_node);
		printf("curlist1: ");
		printList(cur_pos_l1);
		printf("curlist2: ");
		printList(cur_pos_l2);
		#endif
	}

	if (cur_pos_l1 == NULL){
		//l2 pushed onto new_node
		while (cur_pos_l2 != NULL){
			cur_pos->next = cur_pos_l2;
			cur_pos = cur_pos->next;
			cur_pos_l2 = cur_pos_l2->next;
		}
	}else{
		while (cur_pos_l1 != NULL){
			cur_pos->next = cur_pos_l1;
			cur_pos = cur_pos->next;
			cur_pos_l1 = cur_pos_l1->next;
		}
	}
	return new_node;
}

#endif
