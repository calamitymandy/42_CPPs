#include <iostream>
#include <fstream>
#include <string>

// Replace all occurrences of s1 with s2 in content
std::string replaceAll(const std::string &content, const std::string &s1, const std::string &s2) {
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return ""; // because it should return a string
    }

    std::string result;
    std::string::size_type pos = 0;
    std::string::size_type foundit;

    while ((foundit = content.find(s1, pos)) != std::string::npos) { //std::string::npos is a static constant that represents “no position” (so invalid index)
            result.append(content.substr(pos, foundit - pos)); // takes the substring from the current position pos up to the start of the found s1.
            result.append(s2); // instead of what was in s1 we append s2
            pos = foundit + s1.length(); // Move the current position past the matched s1
    }
    result.append(content.substr(pos)); // append whatever is left after the last match
    return result;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Open input file
    std::ifstream infile(filename.c_str()); // c_str(): function that returns a C-style string (const char)* version of a C++ std::string (necessary for if/ofstream classes)
    if (!infile) {
        std::cerr << "Error: could not open input file" << std::endl;
        return 1;
    }

    // Read file content & load into a single string
    std::string content;
    std::string line;
    while (std::getline(infile, line)) {
        content += line; // load each line
        if (!infile.eof())
            content += "\n"; // add \n to preserve original formatting
    }
    infile.close();

    if (content.empty())
        std::cerr << "Error: infile is empty" << std::endl;

    // Replace occurences
    std::string replaced = replaceAll(content, s1, s2);

    // Write output file
    std::ofstream outfile((filename + ".replace").c_str()); // Open output file stream
    if (!outfile) {
        std::cerr << "Error: could not open output file" << std::endl;
        return 1; 
    }
    outfile << replaced; // Write in the Open output file stream
    outfile.close();

    return 0;
}