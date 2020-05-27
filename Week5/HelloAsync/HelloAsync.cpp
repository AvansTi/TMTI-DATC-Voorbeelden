// Example from: http://thispointer.com/c11-multithreading-part-9-stdasync-tutorial-example/
#include <string>
#include <chrono>
#include <thread>
#include <future>
#include <iostream>

std::string fetchDataFromDB(const std::string& recvdData) {
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(std::chrono::seconds(5));

	//Do stuff like creating DB Connection and fetching Data
	return "DB_" + recvdData;
}

std::string fetchDataFromFile(const std::string& recvdData) {
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(std::chrono::seconds(5));

	//Do stuff like fetching Data File
	return "File_" + recvdData;
}

int main() {
	// Get Start Time
	auto start = std::chrono::system_clock::now();

	auto resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");

	//Fetch Data from File
	std::string fileData = fetchDataFromFile("Data");

	//Fetch Data from DB
	// Will block till data is available in future<std::string> object.
	std::string dbData = resultFromDB.get();

	// Get End Time
	auto end = std::chrono::system_clock::now();

	auto diff = std::chrono::duration_cast <std::chrono::seconds> (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;

	//Combine The Data
	std::string data = dbData + " :: " + fileData;

	//Printing the combined Data
	std::cout << "Data = " << data << std::endl;

	return 0;
}