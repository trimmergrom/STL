#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<map>
#include<list>
#include<string>
#include <stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>

#define tab "\t"
using std::cout;
using std::cin;
using std::endl;

const std::map<int, std::string> ACTIONS =
{
std::pair<int, std::string>(1, "transit at red"),
std::pair<int, std::string>(2, "higth speed"),
std::pair<int, std::string>(3, "vstrechaya polosa"),
std::pair<int, std::string>(4, "drirt na perekrestke"),
std::pair<int, std::string>(5, "parking zapret"),
std::pair<int, std::string>(6, "oskorblenie polic"),
std::pair<int, std::string>(7, "alcogol"),
std::pair<int, std::string>(8, "drive without orders"),
std::pair<int, std::string>(9, ""),
};

class Actions
{
	int id;
	std::string plase;
public:
	time_t act_time;
	//time(&act_time);
	//std::string t_time = ctime(&act_time);
	

	/*time_t get_act_time()
	{				
		return time(&act_time);
	}*/

	const int get_id()const
	{
		return id;
	}
	const std::string get_plase()const
	{
		return plase;
	}
	Actions(std::string* ctime(time_t), int id, std::string& plase):act_time(act_time), id(id),  plase(plase) {}
	~Actions(){}	
};
std::ostream& operator<<(std::ostream& os, const Actions& obj)
{	
	return os << obj.act_time << ACTIONS.at(obj.get_id()) << " " << obj.get_plase();
}
std::ofstream& operator<<(std::ofstream& ofs, const Actions& obj)
{
	ofs << obj.get_id() << obj.get_plase();
	return ofs;
}

void print(const std::map<std::string, std::list<Actions>>& base);
void save(const std::map<std::string, std::list<Actions>>& base, const std::string& filename);
void load(std::map<std::string, std::list<Actions>>& base, const std::string filename);
int check_Actions();
std::string input_plase();
std::string input_plate();
void menu(std::map<std::string, std::list<Actions>>& base, const std::string& filename);
void search_plate(const std::map<std::string, std::list<Actions>>& base);
void search_Actions(const std::map<std::string, std::list<Actions>>& base);
void search_place(const std::map<std::string, std::list<Actions>>& base);
std::string set_time(time_t act_time);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::list<Actions>> base;
	std::map<std::string, std::list<Actions>>::iterator it;

	menu(base, "base.txt");	
}
void print(const std::map<std::string, std::list<Actions>>& base)
{
	system("CLS");
	for (std::map<std::string, std::list<Actions>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << "\n";
		for (std::list<Actions>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << "\n";
		}
		cout << "\n------------------------------------------------------------\n";
	}
	system("PAUSE");
}
void search_plate(const std::map<std::string, std::list<Actions>>& base)
{
	std::string srch_plate = input_plate();	
	for (std::map<std::string, std::list<Actions>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{	
		if (it == base.find(srch_plate))
		{
			cout << "Data of license_plate: " << srch_plate << endl;
			for (std::list<Actions>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				cout << *jt << "\n";
			}
		}
		else if(it != base.find(srch_plate) && it == --base.end())cout << "Not in base" << endl;
	}	
	system("PAUSE");
}
void search_Actions(const std::map<std::string, std::list<Actions>>& base)
{
	cout << "Sampling by violation";
	int srch_id = check_Actions();
	for (std::map<std::string, std::list<Actions>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		for (std::list<Actions>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			if(jt->get_id() == srch_id)	cout << it->first << tab << *jt << "\n";
		}
	}

	system("PAUSE");
}
void search_place(const std::map<std::string, std::list<Actions>>& base)
{
	cout << "Sampling by plase";
	std::string srch_plase = input_plase();
	for (std::map<std::string, std::list<Actions>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		for (std::list<Actions>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			if (jt->get_plase() == srch_plase)	cout << it->first << tab << *jt << "\n";
		}
	}
	system("PAUSE");
}

void save(const std::map<std::string, std::list<Actions>>& base, const std::string& filename)
{
	std::ofstream fout(filename);	
	for (std::map<std::string, std::list<Actions>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		fout << it->first << ":";
		for (std::list<Actions>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			fout << *jt << ",";
		}
		fout.seekp(-1, std::ios::cur);// delete ended ','
		fout << ";\n";
	}
	fout.close();
	std::string command = "notepad ";
	command += filename;
	system(command.c_str());	
}
void load(std::map<std::string, std::list<Actions>>& base, const std::string filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string license_plate;
			std::string all_actions;
			std::getline(fin, license_plate, ':');
			std::getline(fin, all_actions);
			if (license_plate.empty() || all_actions.empty())continue;
			all_actions.erase(all_actions.find_last_of(';'));
			for (int start = -1, end = 0; end != std::string::npos; start = end)
			{
				start++;
				end = all_actions.find(',', start);
				std::string plase = all_actions.substr(start, end - start);
				int id = std::stoi(plase, 0, 10);
				plase.erase(-1, 1);
				//plase.erase(plase.find_last_of(';'));
				base[license_plate].push_back(Actions(id, plase));
			}
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
}
int check_Actions()
{
	system("CLS");
	for (std::pair<int, std::string> i : ACTIONS)
	{
		cout << i.first << tab << i.second << "\n";
	}
	int id;
	cout << "Выбрать нарушение: "; cin >> id;
	return id;
}
std::string input_plase()
{
	std::string plase;
	cout << "Ввести место события: ";
	std::cin.ignore(); std::getline(std::cin, plase);
	return plase;
}
std::string input_plate()
{
	//std::string plase;
	std::string license_plate;
	cout << "Enter license_plate: "; cin >> license_plate;
	return license_plate;
}
std::string set_time(time_t act_time)
{
	time(&act_time);
	return ctime(&act_time);
}
void menu(std::map<std::string, std::list<Actions>>& base, const std::string& filename)
{
	char key;
	do
	{
		system("CLS");
		cout << "1. Output general base;" << endl;
		cout << "2. License plate selection ;" << endl;
		cout << "3. Sampling by violation;" << endl;
		cout << "4. Sampling by plase;" << endl;
		cout << "5. Viborka ;" << endl;
		cout << "6. Viborka;" << endl;
		cout << "7. Save base;" << endl;
		cout << "8. Load base;" << endl;
		cout << "9. Addition new nout;" << endl;
		cout << "Esc - End program;" << endl;
	
		key = _getch();
		switch (key)
		{
		case '1': print(base); break;
		case '2': search_plate(base); break;
		case '3': search_Actions(base); break;
		case '4': search_place(base); break;
		case '5': //cout << "No option "; break;
		case '6': cout << "No option "; system("PAUSE");  break;
		case '7': save(base, filename); break;
		case '8': load(base, filename); break;
		case '9': base[input_plate()].push_back(Actions (set_time(), check_Actions(), input_plase())); break;
		
		}

	} while (key != 27);
}