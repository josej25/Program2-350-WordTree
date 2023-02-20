#include "WordTree.h"
#include "WordNode.h"
#include <iostream>

WordTree::WordTree()
{
    m_root = NULL;
}

void WordTree::insert(string key, int line)
{
    m_root = insert(m_root, key, line);
}

WordNode * WordTree::insert(WordNode* node, string key, int line)
{
    if (node == NULL) {
        node = new WordNode(key, line);
        node->m_key = key;
        node->m_wordCount = 1;
        node->m_lineNumbers.push_back(line);
        node->m_left = NULL;
        node->m_right = NULL;
        node->m_parent = NULL;
    }
    else if (node->m_key == key) {
        node->m_wordCount++;
        node->m_lineNumbers.push_back(line);
    }
    else if (node->m_key < key) {
        node->m_right = insert(node->m_right, key, line);
        node->m_right->m_parent = node;
    }
    else {
        node->m_left = insert(node->m_left, key, line);
        node->m_left->m_parent = node;
    }
    return node;
}

void WordTree::printTreeInOrder()
{
    printTreeInOrder(m_root);
}

void WordTree::printTreeInOrder(WordNode* node)
{
    if (node == NULL) {
        return;
    }
    printTreeInOrder(node->m_left);
    cout << node->m_key << "  " << node->m_wordCount << " times on lines: ";
    for (auto it : node->m_lineNumbers) {
        cout << " " << it;

    }
    cout << endl;
    printTreeInOrder(node->m_right);
}


bool WordTree::search(string key)
{
    WordNode* result = search(m_root, key);
    return result != NULL;
}

WordNode* WordTree::search(WordNode* node, string key)
{
    if (node == NULL) {
        return NULL;
    }
    else if (node->m_key == key) {
        return node;
    }
    else if (node->m_key < key) {
        return search(node->m_right, key);
    }
    else {
        return search(node->m_left, key);
    }
}
int WordTree::CountWords() {
    int count = 0;
    CountWords(m_root, count);
    return count;
}

void WordTree::CountWords(WordNode* node, int& count) {
    if (node == NULL) {
        return;
    }
    count += node->m_wordCount;
    CountWords(node->m_left, count);
    CountWords(node->m_right, count);
}

int WordTree::CountUniqueWords() {
    int count = 0;
    CountUniqueWords(m_root, count);
    return count;
}

void WordTree::CountUniqueWords(WordNode* node, int& count) {
    if (node == NULL) {
        return;
    }
    count++;
    CountUniqueWords(node->m_left, count);
    CountUniqueWords(node->m_right, count);
}

string WordTree::FindMin() {
    if (m_root == NULL) {
        return "";
    }
    return FindMin(m_root)->m_key;
}

WordNode* WordTree::FindMin(WordNode* node) {
    if (node->m_left == NULL) {
        return node;
    }
    return FindMin(node->m_left);
}

string WordTree::FindMax() {
    if (m_root == NULL) {
        return "";
    }
    return FindMax(m_root)->m_key;
}

WordNode* WordTree::FindMax(WordNode* node) {
    if (node->m_right == NULL) {
        return node;
    }
    return FindMax(node->m_right);
}
vector<int> WordTree::wordLines(string key) {
    WordNode* node = search(m_root, key);
    if (node == NULL) {
        return vector<int>();
    }
    return node->m_lineNumbers;
}
