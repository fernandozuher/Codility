#include <algorithm> // sort
int solution(vector<int> &A)
{
    if (!A.size())
        return -1;
    
    std::vector<int> backup {A};
    std::sort(A.begin(), A.end());
    int mode {A.at(0)}, count_mode {1}, current_count {0}, previous {A.at(0)};

    for (auto it = A.begin(); it != A.end(); it++)
        if (previous == *it)
            current_count++;
        else {
            if (current_count > count_mode) {
                count_mode = current_count;
                mode = *(it - 1);
            }
            current_count = 1;
            previous = *it;
        }

    if (current_count > count_mode) {
        count_mode = current_count;
        mode = A.back();
    }
    auto index {std::find(backup.begin(), backup.end(), mode) - backup.begin()};
    return count_mode > (static_cast<int>(backup.size()) / 2) ? index : -1;
}