#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

int main()
{
    std::vector<std::string> lines;
    std::ifstream file("students.txt");
    std::random_device rd;
    std::mt19937 g(rd());
    if (file)
    {
        std::string line;
        while(std::getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    std::shuffle(lines.begin(), lines.end(), g);
    std::ofstream out("students2.txt", std::ios_base::out);
    if (out)
    {
        for (auto line: lines)
            out << line << '\n';
        out.close();
    }
}