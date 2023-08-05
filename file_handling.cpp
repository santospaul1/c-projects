#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

int main() {
    std::ifstream file("cat.txt");
    std::string text;
    if (file.is_open()) {
        // Read the contents of the file
        text.assign((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
        
        // Check if '@' is present in the text
        bool match = (text.find('@') != std::string::npos);
        std::cout << std::boolalpha << match << std::endl;
        
        // Search for the pattern '@' in the text
        std::regex pattern("@");
        std::smatch match_result;
        bool found = std::regex_search(text, match_result, pattern);
        std::cout << std::boolalpha << found << std::endl;
        
        // Find all occurrences of the pattern '@' in the text
        std::vector<std::string> match_result2;
        std::regex_iterator<std::string::iterator> rit(text.begin(), text.end(), pattern);
        std::regex_iterator<std::string::iterator> rend;
        while (rit != rend) {
            match_result2.push_back(rit->str());
            ++rit;
        }
        
        std::cout << "Matched strings: ";
        for (const auto& match : match_result2) {
            std::cout << match << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Number of matches: " << match_result2.size() << std::endl;
        
        // Print each matched string individually
        for (const auto& match : match_result2) {
            std::cout << match << std::endl;
        }
    }
    
    // Search for a phone number in the text
    std::string text2 = "My phone number is 923-575-8888";
    std::regex number_pattern(" \\d{3}-\\d{3}-\\d{4} ");
    std::smatch number_match;
    bool number_found = std::regex_search(text2, number_match, number_pattern);
    if (number_found) {
        std::cout << "Phone number found: " << number_match.str() << std::endl;
    }
    
    // Find all occurrences of the pattern '...at' in a given text
    std::string text3 = "The cat in the hat went splat";
    std::regex pattern2("...at");
    std::vector<std::string> match_result3;
    std::regex_iterator<std::string::iterator> rit2(text3.begin(), text3.end(), pattern2);
    std::regex_iterator<std::string::iterator> rend2;
    while (rit2 != rend2) {
        match_result3.push_back(rit2->str());
        ++rit2;
    }
    
    std::cout << "Matched strings: ";
    for (const auto& match : match_result3) {
        std::cout << match << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
