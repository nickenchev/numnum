#include <bitset>
#include <iostream>
#include <iomanip>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

void displayNumber(long number);
int binSize(long number);

int main(const int argc, const char *argv[])
{
    po::options_description desc("Available options");
	desc.add_options()
		("help", "See this help screen")
		("d", "Provide a decimal number")
		("h", "Provide a hexidecimal number")
		("b", "Provide a binary number");


	po::variables_map varmap;
	po::store(po::parse_command_line(argc, argv, desc), varmap);
	po::notify(varmap);

	if (varmap.count("help") || argc == 1)
	{
		cout << "numnum Version 1.0" << endl;
		cout << desc << std::endl;
	}
	else
	{
		long number = 0;
		try
		{
			number = stoi(string(argv[1]));
		}
		catch (std::invalid_argument &ex)
		{
			cerr << "Not a valid integer" << endl;
		}
		displayNumber(number);
	}
	return 0;
}

void displayNumber(long number)
{
	int bitCount = binSize(number);
	if (bitCount)
	{
		cout << bitset<32>(number) << endl;
		cout << "0x" << hex << setw(8) << setfill('0') << number << endl;
	}
}

int binSize(long number)
{
	int bitCount = 0;
	while (number > 0)
	{
		number >>= 1;
		++bitCount;
	}
	return bitCount;
}
