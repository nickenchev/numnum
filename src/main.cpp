#include <bitset>
#include <iostream>
#include <iomanip>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

void displayNumber(long number);
int binSize(long number);
void printDec(long number);
void printHex(long number);
void printBin(long number);

int main(const int argc, const char *argv[])
{
    po::options_description desc("Usage: nn number\nAvailable options");
	desc.add_options()
		("help", "See this help screen")
		("d", po::value<long>(), "Provide a decimal number")
		("h", po::value<string>(), "Provide a hexidecimal number")
		("b", po::value<string>(), "Provide a binary number");

	po::variables_map varmap;
	po::store(po::parse_command_line(argc, argv, desc), varmap);
	po::notify(varmap);

	// help requested, or nn typed alone
	if (varmap.count("help") || argc == 1)
	{
		cout << "numnum Version 1.0" << endl;
		cout << desc << std::endl;
	}
	else
	{
		long number = 0;
		if (varmap.count("d"))
		{
			number = varmap["d"].as<long>();
			printHex(number);
			printBin(number);
		}
		else if (varmap.count("h"))
		{
			stringstream ss;
			ss << hex << varmap["h"].as<string>();
			ss >> number;
			printDec(number);
			printBin(number);
		}
		else
		{
			try
			{
				number = stoi(string(argv[1]));
			}
			catch (std::invalid_argument &ex)
			{
				cerr << "Not a valid integer" << endl;
			}
		}
	}
	return 0;
}

void printDec(long number)
{
	cout << number << endl;
}

void printHex(long number)
{
	cout << "0x" << hex << setw(8) << setfill('0') << number << endl;
}

void printBin(long number)
{
	int bitCount = binSize(number);
	if (bitCount)
	{
		cout << bitset<32>(number) << endl;
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
