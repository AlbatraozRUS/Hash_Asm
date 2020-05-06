#include "List.h"
#include "Hash_Table.h"
#include "profiler.h"

struct MyList* InitHashTable()
{
    struct MyList *Table = (MyList*) calloc(SizeOfTable, sizeof(MyList));
    for (int NumTable = 0; NumTable < SizeOfTable; NumTable++){
        CreateList(&Table[NumTable]);
        InitList(&Table[NumTable]);
    }

    return Table;
}

bool SearchByValue(MyList *Table, char *Value)
{
    for (int NumTable = 0; NumTable < SizeOfTable; NumTable++){
        for (int NumOfList = 0; NumOfList <= Table[NumTable].size; NumOfList++){
         if (Table[NumTable].Element[NumOfList].data == nullptr)
             continue;

         if (strcmp(Table[NumTable].Element[NumOfList].data, Value) == 0){
             return true ;
         }
        }
    }
    return false;
}

bool FillHashTable(MyList *Table)
{
   size_t amount = 0;

   struct Line *Strings = Reading(&amount);
   FILE *Results = fopen("/Users/albatraozrus/Desktop/Proga/Hash/result.csv", "w");
   DecorateFile(Results);
        {LOG_DURATION("NotReallyHash")
   FILLHASHTABLE(Table, Strings, amount, NotReallyHash(),Results, "hello")}
        {LOG_DURATION("FirstLetter")
   FILLHASHTABLE(Table, Strings, amount, FirstLetter(Strings[Line].ptrbuffer),Results, "hello")}
        {LOG_DURATION("Length")
   FILLHASHTABLE(Table, Strings, amount, Length(Strings, Line),Results, "hello")}
        {LOG_DURATION("SumOfLetters")
   FILLHASHTABLE(Table, Strings, amount, SumOfLetters(Strings, Line),Results, "hello")}
        {LOG_DURATION("Roll")
   FILLHASHTABLE(Table, Strings, amount, Roll(Strings[Line].ptrbuffer),Results, "hello")}
        {LOG_DURATION("GNUHash")
   FILLHASHTABLE(Table, Strings, amount, GNUHash(Strings[Line].ptrbuffer,
           Strings[Line].ptrbuffer[Strings[Line].length - 1]),Results, "hello")}
        {LOG_DURATION("MurmurHash")
   FILLHASHTABLE(Table, Strings, amount, MurmurHash(Strings[Line].ptrbuffer, Strings[Line].length),Results, "hello")
   fclose(Results);
    }


   return true;
}

bool DecorateFile(FILE *Results)
{
  for (int index = 0; index < SizeOfTable; index++)
      fprintf(Results, "%d;", index);
  fprintf(Results, "\n");

    return true;
}

void HashDUMP(MyList *Table)
{
    printf("-----------------------------[DUMP]-----------------------------\n");
    printf("This is Dump, congratulations, you are fucked up somewhere...\n");
    printf("----------------------(Begin)\n");
    for (int NumTable = 0; NumTable < SizeOfTable; NumTable++){
    printf("LIST NUMBER - %d\n", NumTable);
    for (int i = 0; i < Table[NumTable].MaxSize; i++){
    printf("Element [%d] is %10s     ", i, Table[NumTable].Element[i].data);
    printf("Next [%d] is %d     ", i , Table[NumTable].Element[i].next);
    printf("Prev [%d] is %d\n", i ,Table[NumTable].Element[i].prev);}
    printf("Free`s index - %d\n", Table[NumTable].free);
    printf("Head - %d\n", Table[NumTable].head);
    printf("Tale - %d\n", Table[NumTable].tale);
    printf("The maximum size of List - %zu\n",Table[NumTable].MaxSize);
    printf("Size - %zu\n",Table[NumTable].size);
    printf("\n\n");
    }
    printf("\n\n");
    printf("(End)----------------------\n");
    printf("End of Dump. Good luck in searching of error\n");
    printf("And may the source be with you!\n");
    printf("----------------------------------------------------------------\n");
    printf("\n\n\n");
    //getchar();
}
