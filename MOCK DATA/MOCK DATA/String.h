#pragma once

#include <string>
#include <vector>
using namespace std;

namespace Utils {
	class String {
	public:
		static vector<string> split(string haystack, string needle);
		static vector<string> ReadFile( string filename);
	};
	
	
}