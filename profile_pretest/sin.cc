#include<array>
#include<cmath>
int main() {
    constexpr size_t arr_length = 4096;
   std::array<double, arr_length> arr{};

// compute bound
   for (size_t i{}; i < arr_length; i++) 
    arr[i] = std::sin(i);

   for (auto& i: arr) i = std::cos(i);

   for (auto& i: arr) i = std::cos(std::sin(i));

   for (auto& i: arr) i = std::sin(std::cos(i));
}
