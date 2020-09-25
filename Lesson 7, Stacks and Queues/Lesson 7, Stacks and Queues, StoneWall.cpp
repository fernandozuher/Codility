int solution(vector<int> &H)
{
    int blocks {0};
    std::vector<int> stack(1, H[0]);
    for (int i {1}, N {static_cast<int>(H.size())}; i < N; i++) {
        if (H.at(i) < stack.back()) {
            stack.push_back(H.at(i));
            int j {};
            while (j < static_cast<int>(stack.size())-1)
                if (stack.at(j) > stack.back()) {
                    blocks++;
                    stack.erase(stack.begin() + j);
                }
                else if (stack.at(j) == stack.back())
                    stack.erase(stack.begin() + j);
                else
                    j++;
        }
        else if (H.at(i) > stack.back())
            stack.push_back(H.at(i));
    }
    return blocks + stack.size();
}