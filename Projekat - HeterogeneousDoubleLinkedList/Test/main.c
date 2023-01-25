/****************************************************************************************************************************************************
 *  Autor: Ognjen Stojisavljevic                                                                                                                    *
 *  Broj indeksa: RA-155/2019                                                                                                                       *
 *  Smer: RT-RK(racunarstvo i automatika)                                                                                                           *
 *  Predmet: Programska podrska u realnom vremenu                                                                                                   *
 *                                                                                                                                                  *
 *  Opis projekta: Problem koji je potrebno resiti je napraviti dvostruko spregnutu listu koja moze da skladisti bilo koji tip podatka,             *
 *                 odnosno da se tipovi podataka unutar nje mogu razlikovati. Lista ce biti zaseban modul realizovan kao staticka biblioteka.       *
 *                 Dodatnu funkcionalnost koju ce posedovati lista jeste funkcija koja proverava koliko podataka ima zadatog tipa.                  *
 *                                                                                                                                                  *
 *  Bitne inforimacije: Data lista radi sa tipovima : char, float, double, unsigned i singed int8_t, int16_t, int32_t, int64_t.                     *
 *                      Ogranicena je na 1000 elemenata. Korisnik je potrebno da brine o tipu koji unosi.                                           *
 *                                                                                                                                                  *
 *  Napomene: Koriscena je malloc funkcionalnost iako nije po standardu, jer je potrebna za alociranje memorije za elemente liste                   *
 *            Main nije po standardu i koriscen je iskljucivo za testiranje, u njemu se nalazi i funkcija za pritanje zadate liste                  *
 *            "DoubleLinkedList.h", line 4: warning: (MISRA-C:2004 1.1/R) Ensure strict ANSI C mode (-ps) is enabled - ne znam sta je greska        *
 *            Izbacuje warninge gde god sam dodeljivao pokazivacu NULL pointer                                                                      *
 *            Takodje kad sam prevezivao pokazivace liste jedne na druge, misra je javljala warnimg - nisam siguran kako bih to resio po misri      *
 *                                                                                                                                                  *
 ***************************************************************************************************************************************************/

#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void List_print(Heterogeneous_list* list)
{
    Element* current = list -> head;

    if (list -> head == NULL)
    {
        printf("List is empty!\n");
    }

	while (current != NULL)
	{
		switch (current -> type)
        {
            case type_char:
                char data_char;
                data_char = *(char*)current -> data;
                printf("%c\n", data_char);
                break;

            case type_int8_t:
                int8_t data_int8;
                data_int8 = *(int8_t*)current -> data;
                printf("%"PRId8"\n", data_int8);
                break;

            case type_int16_t:
                int16_t data_int16;
                data_int16 = *(int16_t*)current -> data;
                printf("%"PRId16"\n", data_int16);
                break;

            case type_int32_t:
                int32_t data_int32;
                data_int32 = *(int32_t*)current -> data;
                printf("%"PRId32"\n", data_int32);
                break;

            case type_int64_t:
                int64_t data_int64;
                data_int64 = *(int64_t*)current -> data;
                printf("%"PRId64"\n", data_int64);
                break;

            case type_uint8_t:
                uint8_t data_uint8;
                data_uint8 = *(uint8_t*)current -> data;
                printf("%"PRIi8"\n", data_uint8);
                break;

            case type_uint16_t:
                uint16_t data_uint16;
                data_uint16 = *(uint16_t*)current -> data;
                printf("%"PRIi16"\n", data_uint16);
                break;

            case type_uint32_t:
                uint32_t data_uint32;
                data_uint32 = *(uint32_t*)current -> data;
                printf("%"PRIi32"\n", data_uint32);
                break;

            case type_uint64_t:
                uint64_t data_uint64;
                data_uint64 = *(uint64_t*)current -> data;
                printf("%"PRIi64"\n", data_uint64);
                break;

            case type_float:
                float data_float;
                data_float = *(float*)current -> data;
                printf("%f\n", data_float);
                break;

            case type_double:
                double data_double;
                data_double = *(double*)current -> data;
                printf("%lf\n", data_double);
                break;

            default:
                printf("Type not supported\n");
        }

        current = current -> next;
	};
}


int main()
{
    Heterogeneous_list list;

    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    int8_t e = 10;
    int16_t f = -1221;
    int32_t g = -14214;
    int64_t h = 101111;
    uint8_t i = 5;
    uint16_t j = 11;
    uint16_t j1 = 11;
    uint16_t j2 = 51;
    uint16_t j3 = 43;
    uint16_t j4 = 58;
    uint16_t j5 = 32;
    uint16_t j6 = 10;
    uint32_t k = 31;
    uint64_t l = 241;
    double m = 24.54;
    float n = 21.12;

    Create_list(&list);

    printf("Adding elements to the list:\n");
    List_insert_element(&list, list.head, type_char, (void*)&a);
    List_insert_element(&list, list.head, type_char, (void*)&b);
    List_insert_element(&list, list.tail, type_char, (void*)&c);
    List_insert_element(&list, list.head->next, type_char, (void*)&d);
    List_insert_element(&list, list.head->next, type_int8_t, (void*)&e);
    List_insert_element(&list, list.head->next, type_int16_t, (void*)&f);
    List_insert_element(&list, list.head->next, type_int32_t, (void*)&g);
    List_insert_element(&list, list.head->next, type_int64_t, (void*)&h);
    List_insert_element(&list, list.tail, type_uint8_t, (void*)&i);
    List_insert_element(&list, list.tail, type_uint16_t, (void*)&j);
    List_insert_element(&list, list.tail, type_uint32_t, (void*)&k);
    List_insert_element(&list, list.tail, type_uint64_t, (void*)&l);
    List_insert_element(&list, list.tail, type_double, (void*)&m);
    List_insert_element(&list, list.tail, type_float, (void*)&n);
    List_print(&list);
    int o = List_type(&list, type_char);
    printf("\nNumber of requested type is:%d", o);
    printf("\n\n");

    Destroy_list(&list);
    printf("\nDestroying list:\n");
    List_print(&list);
    printf("\n\n");

    printf("Again adding elements to the list:\n");
    List_insert_element(&list, list.head, type_char, (void*)&a);
    List_insert_element(&list, list.head, type_char, (void*)&b);
    List_insert_element(&list, list.tail, type_char, (void*)&c);
    List_insert_element(&list, list.head->next, type_char, (void*)&d);
    List_insert_element(&list, list.tail, type_uint16_t, (void*)&j1);
    List_insert_element(&list, list.tail, type_uint16_t, (void*)&j2);
    List_insert_element(&list, list.tail, type_uint16_t, (void*)&j3);
    List_insert_element(&list, list.tail->prev->prev->prev->prev, type_uint16_t, (void*)&j4);
    List_insert_element(&list, list.tail, type_uint16_t, (void*)&j5);
    List_insert_element(&list, list.tail, type_uint16_t, (void*)&j6);
    o = List_type(&list, type_uint16_t);
    printf("\nNumber of requested type is:%d", o);
    o = List_type(&list, type_uint32_t);
    printf("\nNumber of requested type is:%d\n", o);

    List_print(&list);
    printf("\n\n");

    printf("Deleting elements from the list:\n");
    List_delete_element(&list, list.head->next);
    List_delete_element(&list, list.tail);
    List_print(&list);
    printf("\n");

}