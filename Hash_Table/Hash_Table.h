
#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

#include <cstdlib>
#include <cstdio>
#include "List.h"

const unsigned int SizeOfTable = 1000;
const char Input_File[] = "/Users/albatraozrus/Desktop/Proga/Hash/text.txt";;

struct Line {
    char *ptrbuffer;
    unsigned long length;
};

#define FILLHASHTABLE(Table, Strings, amount, FunctionName,File, Value){\
    for (int Line = 0; Line < amount; Line++)\
        PushBegin(&Table[FunctionName % SizeOfTable], Strings[Line].ptrbuffer);\
    {LOG_DURATION("Searching")\
    if (Value != nullptr)\{
        if (SearchByValue(Table, Value))\
            printf("Element %s was found!\n", Value);\
        else\
            printf("There is no such Element in Table!\n");\
        ;}}\
    Writting(Table,File);\
    for (int Line = 0; Line < SizeOfTable; Line++)\
        ClearList(&Table[Line]);\
    free(Table);\
    Table = InitHashTable();\
    }

struct MyList* InitHashTable();
void HashDUMP(MyList *Table);
bool FillHashTable(MyList *Table);
bool Writting(MyList *Table, FILE *Results);
struct Line * Reading(size_t *amount);
bool DecorateFile(FILE *Results);
//bool SearchByValue(MyList *Table, char *Value);

extern "C" bool SearchByValue(MyList *Table, char *Value);


unsigned int NotReallyHash();
unsigned int FirstLetter(const char *String);
unsigned int Length(const Line *String, int NumLine);
unsigned int SumOfLetters (const Line *String, int NumLine);
int Roll(const char* String);
int GNUHash(const char* string, char stopper);
unsigned int MurmurHash (char * key, unsigned int len);


#endif //HASH_TABLE_HASH_TABLE_H
