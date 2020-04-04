#include <iostream>
#include <functional>
#include "RandomContainer.h"
#include "Account.h"
#include "PermutatedSequence.h"
#include "Classroom.h"

int countIf(std::vector<int>::iterator beg, std::vector<int>::iterator end, std::function<bool(int i)> func) {
    int num{};
    if (func == nullptr)
        throw std::runtime_error("Incorrect function adress\n");
    while (beg != end) {
        if (func(*beg))
            num++;
        beg++;
    }
    return num;
}

int main (int argc, char** argv) {

    try {
        //Zad 1
        std::cout << "1\n\n";

        RandomContainer rc(30, -100, 100);
        std::cout << rc;
        rc.sort();        
        std::cout << rc;
        rc.sortDesc();
        std::cout << rc;

        //Zad 2
        std::cout << "\n\n2\n\n";

        std::vector<int> nums;
        for (int i = 1; i <= 5; ++i)
            nums.push_back(i);
        PermutatedSequence ps(nums);
        ps.generateAllPermutations();

        //Zad 3
        std::cout << "\n\n3\n\n";

        std::vector<BankAccount> accounts = {BankAccount(12345.43), BankAccount(), 
            BankAccount(100.23), BankAccount(64672.5) };
        std::for_each(accounts.begin(), accounts.end(), [](BankAccount& acc) {std::cout << acc; });
        std::for_each(accounts.begin(), accounts.end(), [](BankAccount& acc) {acc.interest(); });
        std::cout << "\n\nAFTER\n\n";
        std::for_each(accounts.begin(), accounts.end(), [](BankAccount& acc) {std::cout << acc; });

        //Zad 4
        std::cout << "\n\n4\n\n";

        Classroom classroom("students.txt");

        if (classroom.anySurname("Pinochet"))
            std::cout << "There's Pinochet in a classroom!\n";
        else
            std::cout << "There isn't any Pinochet in a classroom!\n";
        if (classroom.noneSurname("Allende"))
            std::cout << "There's no Allende in a classroom!\n";
        else
            std::cout << "There's Allende in a classroom!\n";
        if (classroom.allGender("m"))
            std::cout << "Classroom is full of men!\n";
        else
            std::cout << "There's at least one women in a classroom!\n";

        //Zad. 5
        std::cout << "\n\n5\n\n";

        std::vector<int> anotherNumbers;
        for (int i = 1; i <= 30; ++i)
            anotherNumbers.push_back(i);
        std::cout << "std::count_if: " << std::count_if(anotherNumbers.begin(), anotherNumbers.end(),
            [](int i) {return i % 3 == 0; }) << '\n' <<"My countIf: " <<
            countIf(anotherNumbers.begin(), anotherNumbers.end(), [](int i) {return i % 3 == 0; }) << '\n';

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}