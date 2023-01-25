#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

typedef enum {type_char, type_int8_t, type_int16_t, type_int32_t, type_int64_t, type_uint8_t, type_uint16_t, type_uint32_t, type_uint64_t, type_float, type_double} types;

typedef struct Element{
    void* data;
    types type;
    struct Element* prev;
    struct Element* next;
}Element;

typedef struct heterogeneous_list{
    Element* head;
    Element* tail;
}Heterogeneous_list;

void Create_list(Heterogeneous_list* list);

void Destroy_list(Heterogeneous_list* list);

void List_insert_element(Heterogeneous_list* list, Element* location, types arg_type, void* arg_data);

void List_delete_element(Heterogeneous_list* list, Element* location);

int List_type(const Heterogeneous_list* list, types type);

#endif
