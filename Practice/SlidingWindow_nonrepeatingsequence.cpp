#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    int n = s.length();
    int ans = 1;
    int i = 0, j = 0;
    std::unordered_set<char> charSet;
    while(j < n)
    {
        if (charSet.find(s[j]) == charSet.end()) {
            charSet.insert(s[j]);
            ans = std::max(ans, j-i+1);
            j++;
        }
        else
        {
            charSet.erase(s[i]);
            i++;
        }
    }

    std::cout << "Length of the longest non-repeating character substring: " << ans << std::endl;
    return 0;
}