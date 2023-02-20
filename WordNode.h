#ifndef WORDNODE_H
#define WORDNODE_H
#include<iostream>
#include <vector>
#include <string>
using namespace std;
class WordNode {
    public:
        string m_key;
        int m_wordCount;
        vector<int> m_lineNumbers;
        WordNode *m_left;
        WordNode *m_right;
        WordNode *m_parent;

        WordNode(string key, int lineNum);
};

#endif // WORDNODE_H
