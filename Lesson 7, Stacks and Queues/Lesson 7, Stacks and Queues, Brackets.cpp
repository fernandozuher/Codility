#include <vector> // vector<T>
#include <algorithm> // find()
int solution(string &S)
{
    std::vector<char> stack, temp {'(', '{', '['};
    for (auto ch : S)
        if (std::find(temp.begin(), temp.end(), ch) != temp.end())
            stack.push_back(ch);
        else if (!stack.empty() && (ch == stack.back()+1 || ch == stack.back()+2))
            stack.pop_back();
        else
            return 0;
    return stack.empty();
}
// 14 lines, O(n)