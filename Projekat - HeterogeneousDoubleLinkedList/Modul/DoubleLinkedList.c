#include "DoubleLinkedList.h"

#pragma CHECK_MISRA("none")
#include <assert.h>
#include <stdlib.h>
#pragma CHECK_MISRA("all")

#define THRESHOLD 1000
static int list_elements = 0;

void Create_list(Heterogeneous_list* list)
{
    list -> head = NULL;
    list -> tail = NULL;
}

void Destroy_list(Heterogeneous_list* list)
{
    Element* current = list -> tail;

    while (current != list -> head)
    {
        current = current -> prev;
    }
    list -> head = NULL;
    list -> tail = NULL;
    list_elements = 0;
}

void List_insert_element(Heterogeneous_list* list, Element* location, types arg_type, void* arg_data)
{
    if (list_elements < THRESHOLD)
    {
        Element* e = (Element*)malloc(sizeof(Element));
        assert(e);
        e -> data = arg_data;
        e -> type = arg_type;

        if (location == NULL)
        {
            e -> next = list -> head;
            e -> prev = NULL;
            list -> head = e;
        }
        else
        {
            e -> next = location -> next;
		    e -> prev = location;
		    location -> next = e;
        }

        if (e -> next != NULL)
	    {
		    e -> next -> prev = e;
	    }
	    else
	    {
		    list -> tail = e;
	    }

        list_elements++;
    }
}

void List_delete_element(Heterogeneous_list* list, Element* location)
{
    assert(location);

	if (location == list -> head)
	{
		list -> head = location -> next;
	}
	else
	{
		location -> prev -> next = location -> next;
	}

    if(location == list -> tail)
	{
		list -> tail = location -> prev;
	}
	else
	{
		location -> next -> prev = location -> prev;
	}

    list_elements--;
	free(location);
}

int List_type(const Heterogeneous_list* list, types type)
{
    int i = 0;

    Element* current = list -> head;
    while (current != NULL)
    {
        if (type == current -> type)
        {
            i++;
        }
        current = current -> next;
    }

    return i;
}
