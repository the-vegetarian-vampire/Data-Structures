#include <iostream>
#include <sstream>

#include <locale>

using namespace std;

long long factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    cout << factorial(4) << endl;
    cout << factorial(7) << endl;

    long long result = factorial(14); // Store the result of factorial(14)
    cout << result << "\n";           // Print the unformatted result

    stringstream ss;
    ss.imbue(locale("")); // Set to user's default locale
    ss << result;         // Insert the result into the stringstream

    cout << ss.str() << "\n"; // Print the formatted result with commas
}
