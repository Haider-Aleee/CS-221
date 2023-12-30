#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>  // Add this include for std::array
using namespace std;

const int ROW = 7;
const int COLUMN = 12;

char Myarray[7][12] = {
    {'d', 'o', 'g', 'x', 'b', 'x', 'x', 'x', 'n', 'o', 'o', 'n'},
    {'r', 'h', 'e', 'l', 'l', 'o', 't', 'h', 'e', 'r', 'e', 'x'},
    {'o', 'k', 'c', 'i', 'u', 'q', 'b', 'r', 'o', 'w', 'n', 'm'},
    {'w', 'x', 'w', 'g', 'e', 'x', 'l', 'x', 'h', 'j', 'i', 'j'},
    {'o', 'o', 'z', 'o', 'k', 'v', 'u', 'x', 'd', 'r', 'o', 'w'},
    {'r', 'l', 'x', 'd', 'r', 'x', 'e', 'x', 't', 'x', 'j', 'a'},
    {'d', 'r', 'o', 'w', 'b', 'l', 'o', 'n', 'k', 'g', 'o', 'd'}};

vector<vector<int>> directions = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

class TrieNode {
public:
    bool isEnd;
    TrieNode* next[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
        }
        node->isEnd = true;
    }

    bool isValidIndex(int index_r, int index_c) {
        return (index_r >= 0 && index_c >= 0 && index_r < ROW && index_c < COLUMN);
    }

    void search(int index_r, int index_c, const vector<int>& direction) {
        TrieNode* node = root;
        int start_r = index_r;
        int start_c = index_c;
        string word = "";

        while (isValidIndex(index_r, index_c)) {
            char ch = Myarray[index_r][index_c];
            int index = ch - 'a';

            if (node->next[index] == nullptr) {
                return;
            }

            word += ch;
            node = node->next[index];

            if (node->isEnd) {
                cout << "Found word: " << word << " at (" << start_r << ":" << start_c << ") to (" << index_r << ":" << index_c << ")\n";
            }

            index_r += direction[0];
            index_c += direction[1];
        }
    }

    void solve() {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                for (const vector<int>& dir : directions) {
                    search(i, j, dir);
                }
            }
        }
    }
};

int main() {
    string wordlistPath = "wordlist.txt";
    Trie* trie = new Trie();

    ifstream wordlistFile(wordlistPath);
    if (!wordlistFile.is_open()) {
        cerr << "Error opening wordlist file.\n";
        return 1;
    }

    string word;
    while (getline(wordlistFile, word)) {
        trie->insert(word);
    }
    wordlistFile.close();

    trie->solve();

    return 0;
}
