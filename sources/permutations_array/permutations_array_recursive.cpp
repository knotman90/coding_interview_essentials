void permutations(std::vector<int> arr, const int pos, std::vector<std::vector<int> >& res)
{
    if (pos == arr.size()) {
        res.push_back(arr);
        return;
    }
    else {
        for (int i = pos; i < arr.size(); ++i) {
            std::swap(arr[pos], arr[i]);
            permutations(arr, pos + 1, res);
            std::swap(arr[pos], arr[i]);
        }
    }
}
std::vector<std::vector<int> > array_permutations(std::vector<int> arr)
{
    std::vector<std::vector<int> > out;
    permutations(arr, 0, out);
    return out;
}