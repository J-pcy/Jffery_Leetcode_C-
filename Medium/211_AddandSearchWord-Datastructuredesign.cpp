/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto &a : child) a = NULL;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchNode(word, root, 0);
    }
    
    bool searchNode(string &word, TrieNode *p, int index) {
        if (index == word.size()) return p->isWord;
        if (word[index] == '.') {
            for (auto &a : p->child) {
                if (a && searchNode(word, a, index + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[index] - 'a'] && searchNode(word, p->child[word[index] - 'a'], index + 1);
        }
    }
private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */