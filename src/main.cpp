#include <bitset>
#include <iostream>
#include <iomanip>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

const static string appVersion = "1.0";

int binSize(long number);
void printDec(long number);
void printHex(long number);
void printBin(long number);

int main(const int argc, const char *argv[])
{
    po::options_description desc("Usage: nn number\nAvailable options");
	desc.add_options()
		("help", "See this help screen")
		("decimal,D", po::value<long>(), "Provide a decimal number")
		("hexadecimal,H", po::value<string>(), "Provide a hexidecimal number")
		("octal,C", po::value<string>(), "Provide an octal number")
		("binary,B", po::value<string>(), "Provide a binary number")
		("input,I", po::value<string>(), "Fetch input from stdin");

	po::variables_map varmap;
	po::store(po::parse_command_line(argc, argv, desc), varmap);
	po::notify(varmap);

	// help requested, or nn typed alone
	if (varmap.count("help") || argc == 1)
	{
		cout << "numnum Version " << appVersion << "\n" << endl;
		cout << desc << std::endl;
	}
	else
	{
		long number = 0;
		if (varmap.count("decimal"))
		{
			number = varmap["decimal"].as<long>();
		}
		else if (varmap.count("hexadecimal"))
		{
			stringstream ss;
			ss << hex << varmap["hexadecimal"].as<string>();
			ss >> number;
		}
		else
		{
		}

		// output all variants
		printDec(number);
		printHex(number);
		printBin(number);
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
		string binStr = bitset<32>(number).to_string();
		cout << binStr << endl;
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
