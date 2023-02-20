#ifndef WORDTREE_H
#define WORDTREE_H

#include "WordNode.h"
#include <iostream>
#include <string>

class WordTree
{
public:
WordTree();
void insert(std::string word, int lineNum);
void printTreeInOrder();
bool search(std::string word);
    int CountWords();
    int CountUniqueWords();
    string FindMin();
    string FindMax();
void remove(std::string word);
vector<int> wordLines(string word);


protected:

void printTreeInOrder(WordNode* node);
WordNode* insert(WordNode* node, std::string word, int lineNum);
WordNode* search(WordNode* node, std::string word);
    void CountWords(WordNode* node, int& count);
    void CountUniqueWords(WordNode* node, int& count);
    WordNode* FindMin(WordNode* node);
    WordNode* FindMax(WordNode* node);
void remove(WordNode* node, std::string word);
int successor(std::string word);
private:
    WordNode * m_root;
};

#endif // WORDTREE_H





