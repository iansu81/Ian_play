#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using LetterAndCount = std::pair<char, int>;  // (letter, count)

char FirstOneLetter(const std::string s) {
    std::vector<LetterAndCount> counts;
    std::unordered_map<char, int> idxInVec; // letter <-> index in #counts

    for (int i = 0; i < s.size(); ++i) {
        const auto c = s[i];
        if (idxInVec.find(c) == idxInVec.end()) {
            idxInVec.insert({c, counts.size()});
            counts.push_back({c, 0});
        }
        int idx = idxInVec.at(c);
        counts[idx].second++;
    }

    for (const auto& [letter, count] : counts) {
        if (count == 1) {
            return letter;
        }
    }

    return {};
}

int main() {
    {
        // TEST1
        std::string s = "abcde";
        std::cout << FirstOneLetter(s) << std::endl;
    }

    {
        // TEST2
        std::string s = "abbbbbca";
        std::cout << FirstOneLetter(s) << std::endl;
    }

    {
        // TEST2
        std::string s = "cccbcccacccd";
        std::cout << FirstOneLetter(s) << std::endl;
    }
}