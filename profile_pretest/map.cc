#include<map>
#include<cmath>

int main(){
	std::map<int, double> Hash_map;
	constexpr size_t len{2048};

	for (size_t i{}; i != len; i++)
		Hash_map[i] = std::cos(std::sin(i));
}
