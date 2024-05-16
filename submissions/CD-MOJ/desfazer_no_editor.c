/*
	iagorrr ;)
	Double linked list implementation.
	- Constructor
	- Empty
    - set first
    - set last
    - move next
    - move previous
    - remove current.
	- push back
	- pop back
	- push front
	- pop front
 */
#include <stdio.h>
#include <stdlib.h>
#define Item char* 

typedef struct linked_list_node_t 
{
	Item item;
	struct linked_list_node_t *next;
	struct linked_list_node_t *previous;
} linked_list_node_t;

typedef struct linked_list_root_t
{
	linked_list_node_t *first;
	linked_list_node_t *last;
    linked_list_node_t *current;
	int size;
} linked_list_root_t;

int linked_list_constructor(linked_list_root_t *x)
{
	x->first = NULL;
	x->last = NULL;
    x->current = NULL;
	x->size = 0;
	return 1;
}

int linked_list_empty(linked_list_root_t *x)
{
	return x->first == NULL;
}

void linked_list_set_first(linked_list_root_t *x)
{
    x->current = x->first;
}

void linked_list_set_last(linked_list_root_t *x)
{
    x->current = x->last;
}
void linked_list_move_next(linked_list_root_t *x)
{
    x->current = x->current->next;
}

void linked_list_move_previous(linked_list_root_t *x)
{
    x->current = x->current->previous;
}

/*
    Remove the current element we are looking at and points the current to next.
*/
void linked_list_remove_current(linked_list_root_t *x)
{
    linked_list_node_t *t = x->current;

    if(x->current->previous == NULL && x->current->next == NULL) // single element.
    {
        x->first = NULL;
        x->last = NULL;
    }
    else if(x->current->previous == NULL) // is the first element.
    {
        x->first = x->current->next;
        x->first->previous = NULL;
    }
    else if(x->current->next == NULL) // is the last element
    {
        x->last = x->current->previous;
        x->last->next = NULL;
    }
    else // what ever element in the middle.
    {
        x->current->next->previous = x->current->previous;
        x->current->previous->next = x->current->next;
    }

    x->size--;

    x->current = x->current->next; 
    
    free(t); 
}
Item linked_list_front(linked_list_root_t *x)
{
	return x->first->item;
}
int linked_list_push_front(linked_list_root_t *x, Item i)
{
	linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));
	if(new_node == NULL) return 0;
	new_node->previous = NULL; // as it gonna be the first one.
	new_node->item = i;

	if(x->size == 0)
	{
		new_node->next = NULL;
		x->first = new_node;
		x->last = new_node;
	}
	else
	{
		x->first->previous = new_node;
		new_node->next = x->first;
		x->first = new_node;
	}

	x->size++;
	return 1;
}

int linked_list_pop_front(linked_list_root_t *x)
{

	// store a pointer to ther first so we can free it later.
	linked_list_node_t *t = x->first;

	// now the first is the one after the first '-'
	x->first = x->first->next;

	// :P
	x->size--;

	free(t);
	return 1;
}

Item linked_list_back(linked_list_root_t *x)
{
	return x->last->item;
}
int linked_list_push_back(linked_list_root_t *x, Item i)
{

	linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));
	if(new_node == NULL) return 0;
	new_node->next = NULL;
	new_node->item = i;

	if(x->size == 0)
	{
		x->first = new_node;
		x->last = new_node;
		new_node->previous = NULL;
	}
	else
	{
		x->last->next = new_node;
		new_node->previous = x->last;
		x->last = new_node;
	}

	x->size++;
	return 1;
}

int linked_list_pop_back(linked_list_root_t *x)
{
	// store the last element memory address to we can free it later.
	linked_list_node_t *t = x->last;

	// our last element now is the previous to the old last.
    x->last = x->last->previous;


	// as he is the last one now there is no next after '''him'''.
    if(x->last != NULL)
	    x->last->next = NULL;
    else {
        x->first = NULL;
    }
	// :)
	x->size--;
    free(t->item);
	free(t);
    return 1;
}

void show_linked_list(linked_list_root_t *l)
{
    linked_list_node_t *l2 = l->first;
    
    int i = 0;
    while(l2 != NULL)
    {
        printf("%i %s\n", i++, l2->item);
        l2 = l2->next;
    }
}
int main()
{
    char option[20];
    linked_list_root_t stack; linked_list_constructor(&stack); 
    while(scanf("%s", option) != EOF)
    {
        if(option[0] == 'i')
        {
            char buff; scanf("%c", &buff);
            Item  str = malloc(sizeof(char)*106);
            
            scanf("%[^\n]", str);
            linked_list_push_back(&stack, str); 
        }
        else
        {
            // printf("desfazer man !\n");
            if(linked_list_empty(&stack))
                printf("NULL\n");
            else {
                printf("%s\n", linked_list_back(&stack));
                linked_list_pop_back(&stack);
            }
        }
    }
    // show_linked_list(&stack);
}

// AC..

