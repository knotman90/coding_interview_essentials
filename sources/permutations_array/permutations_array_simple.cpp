std::vector<std::vector<int> > array_permutations_simple_cpp(std::vector<int> arr)
{
    std::vector<std::vector<int> > out;
    do {
        out.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));
    return out;
}