//Shortest Unique Prefix

struct Trie {
    int cnt_pref;
    Trie *next[26];
    Trie() {
        cnt_pref = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

void add_word(Trie *root, string &s) {
    for (char x : s) {
        if (root -> next[x - 'a'] == NULL) {
            root -> next[x - 'a'] = new Trie;
        }
        root = root -> next[x - 'a'];
        (root -> cnt_pref)++;
    }    
}

string find_prefix(Trie *root, string &s) {
    string ret = "";
    for (char x : s) {
        root = root -> next[x - 'a'];
        ret += x;
        if (root -> cnt_pref == 1) {
            break;
        }
    }
    return ret;
}

vector<string> Solution::prefix(vector<string> &A) {
    Trie *root = new Trie;
    for (string x : A) {
        add_word(root, x);
    }
    vector <string> ans;
    for (string x : A) {
        ans.push_back(find_prefix(root, x));
    }
    return ans;
}
