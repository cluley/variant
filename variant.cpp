#include <iostream>
#include <variant>
#include <vector>
#include <any>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "Hello World!";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto tmp = get_variant();

	if (std::holds_alternative<int>(tmp)) {
		std::cout << (std::get<int>(tmp) * 2) << std::endl;
	}
	else if (std::holds_alternative<std::string>(tmp)) {
		std::cout << std::get<std::string>(tmp) << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(tmp)) {
		for (const int& n : std::get<std::vector<int>>(tmp)) {
			std::cout << n << ' ';
		}
	}

	return 0;
}