
#include <string>

std::string get_value();

std::string get_value() {
	return "Hello from get_value!";
}

int main()
{
    const auto value = get_value();
}

