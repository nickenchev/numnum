#include <bitset>
#include <iostream>
#include <iomanip>

using namespace std;

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

int main(const int argc, const char *argv[])
{
	if (argc > 1)
	{
		int number = 0;
		try
		{
			number = stoi(string(argv[1]));
		}
		catch (std::invalid_argument &ex)
		{
			cerr << "Not a valid integer" << endl;
		}

		int bitCount = binSize(number);
		if (bitCount)
		{
			cout << bitset<32>(number) << endl;
			cout << "0x" << hex << setw(8) << setfill('0') << number << endl;
		}
	}
	else
	{
		cerr << "Specify a base 10 integer" << endl;
	}
	return 0;
}
