/*
 * sorted-list.c
 */

#include <stdlib.h>


/*
 * SLCreate creates a new, empty sorted list.  The caller must provide
 * a comparator function that can be used to order objects that will be
 * kept in the list, and a destruct function that gets rid of the objects
 * once they are no longer in the list or referred to in an iterator.
 * 
 * If the function succeeds, it returns a (non-NULL) SortedListT object,
 * otherwise, it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){

	if(cf == NULL || df == NULL){
		return NULL;
	}

	SortedListPtr list = (SortedListPtr)malloc(sizeof(struct SortedList));
	
	list -> size = 0;
	list -> cf = cf;
	list -> df = df;
	list -> front = NULL;

	retrun list;

}

/*
 * SLDestroy destroys a list, freeing all dynamically allocated memory.
 *
 * You need to fill in this function as part of your implementation.
 */
void SLDestroy(SortedListPtr list){

	DestructFuncT clear=list->df; 

	while(list->head!=NULL){
	
		curr=list->head;	

		//Clears the data pointed to by the current node
		if (curr->data!=NULL) 
			clear(curr->data);

		//Iterates and destroys current node
		list->head=curr->next;
		free(curr);
	}
	
	free(list);
}


/*
 * SLInsert inserts a given object into a sorted list, maintaining sorted
 * order of all objects in the list.  If the new object is equal to an object
 * already in the list (according to the comparator function), then the operation should fail.
 *
 * If the function succeeds, it returns 1, otherwise it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

int SLInsert(SortedListPtr list, void *newObj){
	
	if(newObj == NULL){
		return 0;
	}

	if(list == NULL){
		return 0;
	}

	//Populate NewNode data with newObj
	NodePtr NewNode = (Nodeptr)malloc(sizeof(struct Node));
	NewNode -> data = newObj;
	NewNode -> next = NULL:
	NewNode -> RefCount = 1;

	//If there's nothing in the list, then add NewNode to the front
	if(list -> size = 0){
		list -> front = NewNode;
		list -> size = 1;
		
		return 1;
	}
	
	//if list already contains nodes, we need to figure out where to add it
	if(list -> size != 0){
	
		NodePtr curr = list -> front;
		NodePtr lag = NULL:
		
		//Compare data to see where to insert NewNode ----    -1 = 1st is smaller  0 = objects are equal  1 = 2nd object is smaller
		int val = cf(curr -> data, NewNode -> data);
		
		//First deal with val = 0, so curr-> data == NewNode-> data
		if(val == 0){
			free(NewNode);
			df(newObj);
			return 0;
		}
		//If val == -1 then we need to make NewNode the new front
		if(val == -1){
			NewNode -> next = list -> front;
			list -> front = NewNode;
			list -> size++;
			return 1;
		}
		//If val == 1, then we need to insert NewNode somewhere past front
		if(val == 1){
			while(true){
				lag = curr;
				curr = curr -> next;
				
				//We found a match somewhere in the list so free NewNode
				if(cf(curr -> data, NewNode -> data) == 0){
					free(NewNode);
					return 0;
				}
				//We found that curr is less than Newnode in the list so insert right before it
				if(cf(curr -> data, NewNode -> data) == -1){
					lag -> next = NewNode;
					NewNode -> next = curr;
					list -> size++;
					return 1;
				}
				//We reach the tail of the list and NewNode is still the smallest item, NewNode becomes the new tail
				if(curr  == NULL){
					lag -> next = NewNode;
					list -> size++;
					return 1;
				}
				
			}
		}

	return 0;	
}


/*
 * SLRemove removes a given object from a sorted list.  Sorted ordering
 * should be maintained.  SLRemove may not change the object whose
 * pointer is passed as the second argument.  This allows you to pass
 * a pointer to a temp object equal to the object in the sorted list you
 * want to remove.
 *
 * If the function succeeds, it returns 1, otherwise it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

int SLRemove(SortedListPtr list, void *newObj){

	NodePtr curr = list->head; 
	NodePtr prev = front; 
	CompareFuncT compFunc = list->cf; 

	//If head is only node
	if (curr->next==NULL) 
		if (compFunc((curr->data),newObj)!=0)
			return 0;
		else { 
			list->head=NULL; 
			curr->ref--; 
			list->length--; 
			if (curr->ref==0)
				DeleteNode(curr); 	

			return 1;
		} 
			

	int compareValue = 1; 

	//If list contains more than 1 node, find appropriate node
	do {
		compareValue = compFunc((curr->data),newObj);

		if (compareValue==0) 
			break;
		 
		prev=front; 
		curr=prev->next;

	} while (curr->next!=NULL)



	if(compareValue==0) {


		if (



	}
	

<<<<<<< HEAD
	//Delete node if nothing is pointing to it 
	if (tmp->RefCount==0){

		DeleteNode(tmp);

	}	

}

/* Deletes a node that has nothign pointing to id */ 
=======
>>>>>>> ec6b642c81d0b7205cb6a4e2c93de15eea9dd4c0

}


/*
 * SLCreateIterator creates an iterator object that will allow the caller
 * to "walk" through the list from beginning to the end using SLNextItem.
 *
 * If the function succeeds, it returns a non-NULL pointer to a
 * SortedListIterT object, otherwise it returns NULL.  The SortedListT
 * object should point to the first item in the sorted list, if the sorted
 * list is not empty.  If the sorted list object is empty, then the iterator
 * should have a null pointer.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListIteratorPtr SLCreateIterator(SortedListPtr list);


/*
 * SLDestroyIterator destroys an iterator object that was created using
 * SLCreateIterator().  Note that this function should destroy the
 * iterator but should NOT affect the original list used to create
 * the iterator in any way.
 *
 * You need to fill in this function as part of your implementation.
 */

void SLDestroyIterator(SortedListIteratorPtr iter);

<<<<<<< HEAD
	// if iterator points to something, decrease the refcount
	if (iter->current!=NULL) 
		iter->current->RefCount--; 

	// if the node that was pointed by the iterator has nothign pointing to it delete it 
	if ( iter->current->RefCount<1) 
		DeleteNode(iter->current, iter->destroyFunc); 

	free (iter);
}
=======
>>>>>>> ec6b642c81d0b7205cb6a4e2c93de15eea9dd4c0

/*
 * SLGetItem returns the pointer to the data associated with the
 * SortedListIteratorPtr.  It should return 0 if the iterator
 * advances past the end of the sorted list.
 * 
 * You need to fill in this function as part of your implementation.
*/

void * SLGetItem( SortedListIteratorPtr iter );

/*
 * SLNextItem returns the pointer to the data associated with the
 * next object in the list associated with the given iterator.
 * It should return a NULL when the end of the list has been reached.
 *
 * One complication you MUST consider/address is what happens if a
 * sorted list associated with an iterator is modified while that
 * iterator is active.  For example, what if an iterator is "pointing"
 * to some object in the list as the next one to be returned but that
 * object is removed from the list using SLRemove() before SLNextItem()
 * is called.
 *
 * You need to fill in this function as part of your implementation.
 */

void * SLNextItem(SortedListIteratorPtr iter){

	if (iter == NULL) 
		return; 

	// if iter is at the end of the list	
	if ( iter->current->next == NULL) 
		return NUll; 
	else { 

		Nodeptr tmp = iter->current; 
		iter->current = tmp->next; 
		iter->current->RefCount++;
		tmp->RefCount--;

		if (tmp->RefCount<1) 
			DeleteNode(tmp, iter->destroyFunc);

		return;
	}
	


}

