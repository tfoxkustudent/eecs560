#include <iostream>
#include <fstream>
#include <ostream>

void populateFile(int count,
                  std::string const& file)
{
    int random_integer;
    std::ofstream myfile(file);
    if (!myfile )
    {
       std::cerr << "error opening file\n";
       return;
    }

    for(int index=0; index<count; index++)
    {
        random_integer = (rand()%count)+1;
        myfile << random_integer << "\n";
    }
}

int main() {
	srand( time( NULL ) );
	std::string file1("10nums.txt");
	std::cout << "\nStarting first file\n";
	populateFile(10, file1);
	std::cout << "\nending first file\n";
	srand( time( NULL ) );
	std::cout << "\nStarting second file\n";
        std::string file2("50nums.txt");
        populateFile(50, file2);
	std::cout << "\nending second file\n";
	srand( time( NULL ) );
	std::cout << "\nStarting third file\n";
        std::string file3("100nums.txt");
        populateFile(100, file3);
	srand( time( NULL ) );
	std::cout << "\nStarting fourth file\n";
        std::string file4("500nums.txt");
        populateFile(500, file4);
	srand( time( NULL ) );
	std::cout << "\nStarting fifth file\n";
        std::string file5("1000nums.txt");
        populateFile(1000, file5);
	srand( time( NULL ) );
	std::cout << "\nStarting sixth file\n";
        std::string file6("5000nums.txt");
        populateFile(5000, file6);
	srand( time( NULL ) );
	std::cout << "\nStarting seventh file\n";
        std::string file7("10000nums.txt");
        populateFile(10000, file7);
}
