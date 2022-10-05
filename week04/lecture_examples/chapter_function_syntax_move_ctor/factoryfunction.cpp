#include <fstream>
#include <iostream>
#include <string>
#include <utility>







std::ofstream fileFactory(std::string const filename) {
	std::ofstream theFile{filename};
	return theFile;
}






void writeToFile(std::ofstream file){
	file << "hello, world\n";
}





int main(){
	std::ofstream out=fileFactory("hello.txt");
	out << "hello\n";
	writeToFile(std::move(out));
	// cannot use out here anymore
	if (out << "more?"){
		std::cout << "oops out should be empty now\n";
	}
}


