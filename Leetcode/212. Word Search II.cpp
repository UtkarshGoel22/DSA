struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    bool isEnd() {
        return flag;
    }

    void removeEnd() {
        flag = false;
    }

    void setEnd() {
        flag = true;
    }
};

class Solution {
    Node* root = new Node();

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    void search(vector<vector<char>>& board, int i, int j, int m, int n, Node* node, string word, vector<string>& result) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
            return;
        }
        if (!node->containsKey(board[i][j])) return;

        node = node->get(board[i][j]);
        char ch = board[i][j];
        word += board[i][j];

        if (node->isEnd()) {
            result.push_back(word);
            node->removeEnd();
        }

        board[i][j] = '#';

        search(board, i - 1, j, m, n, node, word, result);
        search(board, i + 1, j, m, n, node, word, result);
        search(board, i, j - 1, m, n, node, word, result);
        search(board, i, j + 1, m, n, node, word, result);
        
        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        for (string word : words) insert(word);

        Node* node = root;
        vector<string> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, node, "", result);
            }
        }

        return result;
    }
};
