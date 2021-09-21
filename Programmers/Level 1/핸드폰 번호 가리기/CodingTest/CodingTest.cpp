#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	const size_t starLength = phone_number.size() - 4;
	const string star(starLength, '*');
	phone_number.replace(0, starLength, star);

	return phone_number;
}

int main() {

	return 0;
}