#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


std::vector<std::string> Split(const std::string& str, char sep) {
    std::vector<std::string> tokens;
    size_t begin = 0;
    size_t end = 0;
    while ((end = str.find(sep, begin)) != std::string::npos) {
        if (end - begin) {
            const std::string& token = str.substr(begin, end - begin);
            tokens.push_back(token);
        }
        begin = end + 1;
    }
    return tokens;
}


int main() {
    std::string line;
    std::unordered_map<std::string, int> wordCounts;
    while (std::getline(std::cin, line)) {
        const std::vector<std::string>& words = Split(line, ' ');
        for (const auto& word : words) {
            wordCounts[word] += 1;
        }
    }
    for (const auto& kv: wordCounts) {
        if (kv.second > 100) {
            std::cout << kv.first << " " << kv.second << std::endl;
        }
    }
}

