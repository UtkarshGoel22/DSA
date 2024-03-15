struct Node {
    unordered_map<char, Node*> map;
    bool flag = false;

    bool containsKey(char ch) {
        return map[ch] != NULL;
    }

    Node* get(char ch) {
        return map[ch];
    }

    void put(char ch, Node* node) {
        map[ch] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
    Node* root;

    bool searchUtil(string& word, int n, int i, Node* node) {
        if (!node) return false;
        if (i == n) return node->isEnd();
        if (word[i] != '.') return searchUtil(word, n, i+1, node->map[word[i]]);
        for (auto x : node->map) {
            if (searchUtil(word, n, i+1, x.second)) return true;
        }
        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        return searchUtil(word, word.length(), 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
