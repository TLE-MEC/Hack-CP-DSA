#include <iostream>
using namespace std;

//Editable code--------------------------------------------------------------------------------------

// A template function to implement reversed_binary_value.
template<bool... digits> 
int reversed_binary_value(){
    int sum = 0;
    int product = 1;
    bool binary[] = { digits... }; //array of type bool with 0 or more elements
    for (bool digit : binary) {   // convert bit array into integer number(reversed)
        sum += (digit ? product : 0); // if digit has value true/1 add product to sum or add 0 to it
        product *= 2;
    }
    return sum; // return sum
};

//----------------------------------------------------------------------------------------------------

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
