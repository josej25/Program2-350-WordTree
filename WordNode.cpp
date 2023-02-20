#include "WordNode.h"

WordNode::WordNode(string key, int lineNum)
{
    m_key = key;
    m_wordCount = 0;
    m_lineNumbers.push_back(lineNum);
    m_left = NULL;
    m_right = NULL;
    m_parent = NULL;
}
