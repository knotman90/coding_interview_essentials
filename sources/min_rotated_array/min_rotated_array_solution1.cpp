template<typename T>
auto min_rotated_array_brute_force(const std::vector<T>&V)
{
	return *(std::min_element(begin(V), end(V)));
}