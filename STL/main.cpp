#include<iostream>
#include<array>
#include<vector>
#include<deque>

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE


int main()
{
#ifdef STL_ARRAY
	const int N = 5;
	std::array<int, N> arr = { 3, 5, 7 };
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << std::endl;
#endif //

#ifdef STL_VECTOR
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << tab;
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Max_Size: " << vec.max_size() << std::endl;
	vec.push_back(888);
	vec.reserve(25);
	vec.shrink_to_fit();
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Max_Size: " << vec.max_size() << std::endl;

	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			std::cout << vec.at(i) << tab;
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	int index;
	int value;
	int count;
	std::cout << "Enter index of added number: "; std::cin >> index;
	std::cout << "Enter count of count number: "; std::cin >> count;
	std::cout << "Enter value of added number: "; std::cin >> value;
	vec.insert(vec.begin() + index, value);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	vec.insert(vec.begin() + index, count, value);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	vec.insert(vec.begin() + index, {444, 555, 777});
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	vec.erase(vec.begin()+  index);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;



#endif // 

#ifdef STL_DEQUE

#endif //
	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	deque.push_front(0);

	for (int i : deque)
	{
		std::cout << i << tab;
	}
	std::cout << std::endl;


}