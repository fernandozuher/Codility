int solution(vector<int> &A, vector<int> &B)
{
    int i {}, alive, N; alive = N = static_cast<int>(A.size());
    for (std::vector<int> stack; i < N; i++)
        if (B.at(i))
            stack.push_back(i);
        else if (!stack.empty()) {
            alive--;
            if (A.at(stack.back()) < A.at(i))
                stack.pop_back(), i--;
        }
    return alive;
}
// O(N)