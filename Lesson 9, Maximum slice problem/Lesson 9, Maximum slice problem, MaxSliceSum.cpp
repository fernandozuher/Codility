int solution(vector<int> &A)
{
    int result {-2147483648}, sum {0};
    for (auto it = A.begin(); it != A.end(); it++, sum = 0)
        for (auto it2 = it; it2 != A.end(); sum += *it2++, result = std::max(result, sum));
    return result;
}