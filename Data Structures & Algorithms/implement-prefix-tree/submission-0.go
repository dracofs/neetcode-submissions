type TrieNode struct {
    Value rune
    Next []*TrieNode
}

type PrefixTree struct {
    Root *TrieNode
    Seen map[string]bool
}

func Constructor() PrefixTree {
    return PrefixTree{
        Root: &TrieNode{
            Value: '.',
            Next: make([]*TrieNode, 26),
        },
        Seen: make(map[string]bool),
    }
}

func (this *PrefixTree) Insert(word string) {
    curr := this.Root
    for _, char := range word {
        check := curr.Next[char - 'a']

        if check == nil {
            curr.Next[char - 'a'] = &TrieNode{
                Value: char,
                Next: make([]*TrieNode, 26),
            }
        }

        curr = curr.Next[char - 'a']
    }

    this.Seen[word] = true
}

func (this *PrefixTree) Search(word string) bool {
    _, exists := this.Seen[word]
    return exists
}

func (this *PrefixTree) StartsWith(prefix string) bool {
    curr := this.Root

    for _, char := range prefix {
        if curr.Next[char - 'a'] == nil {
            return false
        }
        curr = curr.Next[char - 'a']
    }
    
    return true
}
