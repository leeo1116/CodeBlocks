#include "Leetcode.h"

void WordDictionary::AddWord(string word){
    TrieNode *r = root;
    for(char c : word){
        if(!(r->children[c-'a']))
            r->children[c-'a'] = new TrieNode();
        r = r->children[c-'a'];
    }
    r->isKey = true;
}


bool WordDictionary::Search(string word){
    return Query(word.c_str(), root);

}


bool WordDictionary::Query(const char *word, TrieNode *root){
    TrieNode *r = root;
    for(int i = 0; word[i]; i++){
        if(!r)
            return false;
        if(word[i] != '.'){
            r = r->children[word[i]-'a'];
        }
        if(word[i] == '.'){
            TrieNode *tmp = r;
            for(int j = 0; j < 26; j++){
                r = tmp->children[j];
                if(Query(word+i+1, r))
                    return true;
            }
        }
    }
    return r && r->isKey;
}
