#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<algorithm>


#define tab "\t"
#define delimiter "\n--------------------\n"
//#define STL_SET
#define STL_MAP
//#define STL_LIST

int main()
{
#ifdef STL_SET
	/*std::set<int> set = { 55, 25, 75, 32, 64, 80 };
for (std::set<int>::iterator it = set.begin();
	it != set.end(); ++it)
{
	std::cout << *it << tab;
}
std::cout << std::endl;*/

	int n;
	std::cout << "Enter size of containers: "; std::cin >> n;
	std::multiset<int> set;
	for (int i = 0; i < n; i++)
	{
		set.insert(rand() % 100);
	}
	for (std::set<int>::iterator it = set.begin();
		it != set.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	std::cout << "Size: " << set.size() << std::endl;
	int value;
	std::cout << "Enter deleted value: "; std::cin >> value;
	set.erase(value);
	for (std::set<int>::iterator it = set.begin();
		it != set.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	int start_value;
	int stop_value;
	std::cout << "Enter start_value deleted elements";
	std::cin >> start_value;
	std::cout << "Enter stop_value deleted elements";
	std::cin >> stop_value;
	set.erase(set.find(start_value), set.find(stop_value));
	for (int i : set) std::cout << i << tab;
#endif // STL-SET

#ifdef STL_MAP
	std::map<std::string, std::string> week;
	std::map<std::string, std::string>::iterator it;

		week =
	{
		std::pair<std::string, std::string>("O1210", "Sunday"),

		std::pair<std::string, std::string>("A1", "Monday"),
		std::pair<std::string, std::string>("C2", "Tuesday"),
		std::pair<std::string, std::string>("D3", "Wednesday"),
		std::pair<std::string, std::string>("H3", "Wednesday"),
		{"Y4", "Thursday"},
		{"R5", "Friday" },
		{"E6", "Saturday"},
		{"T76", "Saturday"},
		{"W46", "Saturday"},

	};
	for (std::map<std::string, std::string>::iterator it = week.begin();
		it != week.end(); ++it)
	{
		std::cout << it->first << tab << it->second << std::endl;

	}
	std::cout << delimiter << std::endl;
	for (std::pair<std::string, std::string> i : week)
	{
		std::cout << i.first << tab << i.second << std::endl;
	}
	//if(it == week.find("C2"));
	
#endif

#ifdef STL_LIST
	std::list<int> list = { 33, 12, 1, 4, 8, 21 };
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::wcout << delimiter << std::endl;
	int value;
	int n;
	int _shift;
	std::wcout << "Enter inserted number: "; std::wcin >> value;
	std::wcout << "Enter number inserted lelments: "; std::wcin >> n;
	std::wcout << "Enter shift iterator: "; std::wcin >> _shift;
	it = list.begin();
	//for (int i = 0; i < _shift; i++)++it;
	std::advance(it, _shift);
	
	//list.insert(it, n, value);
	for (it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::wcout << delimiter << std::endl;

#endif // DEBUG

}
