class Trie {
    struct TrieNode {
        TrieNode *next[26];
        int cnt_words;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            cnt_words = 0;
        }
    };
    TrieNode *trie;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *use = trie;
        for (char x : word) {
            if (use -> next[x - 'a'] == NULL) {
                use -> next[x - 'a'] = new TrieNode;
            }           
            use = use -> next[x - 'a'];
        }
        (use -> cnt_words)++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *use = trie;
        for (char x : word) {
            if (use -> next[x - 'a'] == NULL) {
                return false;
            }
            use = use -> next[x - 'a'];
        }
        if (use -> cnt_words) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *use = trie;
        for (char x : prefix) {
            if (use -> next[x - 'a'] == NULL) {
                return false;
            }
            use = use -> next[x - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
