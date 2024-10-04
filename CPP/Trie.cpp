#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char ch)
  {
    data = ch;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }

    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    insertUtil(root, word);
  }

  bool searchUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      return root->isTerminal;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }

    else
    {
      return false;
    }

    return searchUtil(child, word.substr(1));
  }

  bool searchWord(string word)
  {
    return searchUtil(root, word);
  }

  // Phonebook Directory Problem

  void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
  {
    if (curr->isTerminal)
    {
      temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      TrieNode *next = curr->children[ch - 'a'];
      if (next != NULL)
      {
        prefix.push_back(ch);
        printSuggestions(next, temp, prefix);
        prefix.pop_back();
      }
    }
  }

  vector<vector<string>> getSuggestion(string str)
  {
    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < str.length(); i++)
    {
      char lastch = str[i];
      prefix.push_back(lastch);

      TrieNode *curr = prev->children[lastch - 'a'];

      if (curr == NULL)
      {
        break;
      }

      vector<string> temp;
      printSuggestions(curr, temp, prefix);
      output.push_back(temp);
      temp.clear();
      prev = curr;
    }
    return output;
  }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList,string &queryStr)
{
  Trie *t = new Trie();

  for (int i = 0; i < contactList.size(); i++)
  {
    string str = contactList[i];
    t->insertWord(str);
  }

  return t->getSuggestion(queryStr);
}
int main()
{
  Trie *t = new Trie();

  t->insertWord("ABCD");
  cout << " Present or Not " << t->searchWord("ABCD") << endl;

  return 0;
}

//  Different Version of Trie
/*
class TrieNode {
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;
  int childCount;

  TrieNode(char ch) {
    data = ch;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    childCount = 0;
    isTerminal = false;
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode('\0'); }

  void insertUtil(TrieNode *root, string word) {
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'a';
    TrieNode *child;

    if (root->children[index] != NULL) {
      child = root->children[index];
    }

    else {
      child = new TrieNode(word[0]);
      root->childCount++;
      root->children[index] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insertWord(string word) { insertUtil(root, word); }

  void lcp(string str, string &ans) {
    for (int i = 0; i < str.length(); i++) {
      char ch = str[i];

      if (root->childCount == 1) {
        ans.push_back(ch);
        int index = ch - 'a';
        root = root->children[index];
      } else {
        break;
      }

      if (root->isTerminal) {
        break;
      }
    }
  }
};

string longestCommonPrefix(vector<string> &arr, int n) {
  Trie *t = new Trie();

  for (int i = 0; i < n; i++) {
    t->insertWord(arr[i]);
  }

  string str = arr[0];
  string ans = "";
  t->lcp(str, ans);

  return ans;
}

*/