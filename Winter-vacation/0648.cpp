struct TrieNode {
    int cntWords;
    vector <TrieNode *> next;
    TrieNode() {
        cntWords = 0;
        next.resize(26, NULL);
    }
};

void addToTrie(TrieNode *root, string str) {
    int i = 0;
    while (i < str.length() && root -> cntWords == 0) {
        if (root -> next[str[i] - 'a'] == NULL) {
            root -> next[str[i] - 'a'] = new TrieNode();
        }
        root = root -> next[str[i] - 'a'];
        i++;
    }
    root -> cntWords = 1; 
}

string findInTrie(TrieNode *root, string str) {
    int i = 0;
    string ret;
    while (i < str.length() && root -> cntWords == 0) {
        if (root -> next[str[i] - 'a'] == NULL) {
            return str;
        }
        ret += str[i];
        root = root -> next[str[i] - 'a'];
        i++;
    }
    return ret;
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode *root = new TrieNode();
        for (auto &s : dict) {
            addToTrie(root, s);
        }
        string ret;
        bool first = true;
        int i = 0;
        while (i < sentence.length()) {
            string cur;
            while (i < sentence.length() && sentence[i] == ' ') {
                i++;
            } 
            while (i < sentence.length() && sentence[i] != ' ') {
                cur += sentence[i];
                i++;
            }
            if (cur.length()) {
                if (! first) {
                    ret += " ";
                }
                first = false;
                ret += findInTrie(root, cur);
            }
        }
        return ret;
    }
};
