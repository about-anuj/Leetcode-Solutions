class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string s) {
        return s+"tinyurl";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string  s) {
        s.erase(end(s)-7,end(s));
        return s;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));