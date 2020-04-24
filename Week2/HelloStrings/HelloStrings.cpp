
#pragma warning(disable : 5050) 
import std.core;

using namespace std::string_literals; // literals

constexpr std::size_t stringLength(const std::string_view& s) {
	return s.size();
}


int main() {
	
	// C String
	constexpr char cstr[500] = "Hello World";
	std::cout << "String cstr, contains: " << cstr << ". of length: " << std::strlen(cstr) << std::endl;

	// C++ String
	std::string cppstring = "Hello World"s;
	std::string cppstring2 {"Hallo Klas"s};
	std::cout << "String cppstring, contains: " << cppstring << ". of length: " << cppstring.size() << std::endl;

	// Concatinate String
	std::string combinedString = cppstring + " " + cppstring2;
	std::cout << "Combined String: " << combinedString << std::endl;


	// String_view
	// Godbolt example:  https://godbolt.org/z/z6gfLc (find non string_view) vs string_view https://godbolt.org/z/u2w35N
	std::cout << "String length: " << stringLength("hello avans, This is a quit long string"s) << '\n';

	constexpr auto v = std::string_view{ "Hello world!" };
	constexpr auto found_at = v.find("world");

	return found_at;
}