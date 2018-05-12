// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

//struct for a node
typedef struct node
{
    char word[LENGTH + 1];//length already defined in dictinary.h
    struct node *next;
}
node;
//array of node(each letter will be stored in one bucket or elememt)
node *hashtable[26];

int totalNoOfWords = 0;

//hash function to calculate the index of first letter in the string(dictionary word)
int hashKeyIndex(const char *word)
{
    char firstChar = tolower(word[0]);//convert all cases to lower while calculating the index.
    return firstChar - 'a';
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //compare text words against the dictinary words
    int bucketNumber =  hashKeyIndex(word);//finding the bucket from the hash function in which the word is located and getting the head of the node pointer.
    if (hashtable[head] == NULL)
    {
        return false;
    }
    node * cursor = hashtable[head];//head points to the first word in the linked list
   // if word exists look for it in the data structure.
    while (cursor != NULL)
    {
        char * dicWord = cursor->word;//pointer to dicWord variable to access the first word from the  Linked List.

        if (strcasecmp(word, dicWord) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //open dictinary to check if file exists
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }
    //store the word that is checked in the while loop
    char word[LENGTH + 1];
    //populate hash table with nodes containing words in the dictionary
    //look for a word from the dictionary called file here, look for a string and put that string in
    //a variable called word and execute the loop until EOF is reached.

    while fscanf(file, "%s", word) ! =  EOF)
    {
        //for every word that is scanned malloc a node for it.Check to make sure that the pointer to that
        //node does not return NULL.
        node * new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();//if pointer is null, unload the dictionary and exit.
            totalNoOfWords;
            return false;
        }
        else//copy the word into node
        {
            strcpy(new_node -> word, );
        }
        totalNoOfWords ++;//get the total number of words

        //call hash function and insert the word in linked list at the head
        int bucketNumber =  hashKeyIndex(word);//int bucketNumber is the head
        new_node->next = hashtable[bucketNumber];//points to the value of head
        hashtable[bucketNumber] = new_node;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return totalNoOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
