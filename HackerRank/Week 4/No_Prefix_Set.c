#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

int insertAndCheck(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';

        if (current->is_end_of_word) {
            return 1;
        }

        if (!current->children[index]) {
            current->children[index] = createNode();
        }

        current = current->children[index];

        if (i == strlen(word) - 1 && current->is_end_of_word) {
            return 1;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (current->children[i]) {
            return 1;
        }
    }

    current->is_end_of_word = 1;
    return 0;
}

void noPrefix(int words_count, char** words) {
    TrieNode* root = createNode();

    for (int i = 0; i < words_count; i++) {
        if (insertAndCheck(root, words[i])) {
            printf("BAD SET\n%s\n", words[i]);
            return;
        }
    }

    printf("GOOD SET\n");

}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    char** words = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* words_item = readline();

        *(words + i) = words_item;
    }

    noPrefix(n, words);

    return 0;
}