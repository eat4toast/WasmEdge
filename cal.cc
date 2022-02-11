#include<vector>
int main(){
	std::vector<int> number_first{1,2,3,4,5};
	std::vector<int> number_second{5,4,3,2,1};

	std::vector<int> res(5, 0);

	for (int i = 0; i < 5; i++)
		res[i] = number_first[i] * number_second[i];

}
