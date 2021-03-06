#include "csv.h"
#include "utilities.h"
#include "optional.h"

#include <iostream>
#include <string>


struct MyInt {
    int Value;
};


int main() {
    using namespace CSV;

    try {
        CSVReader csv("test.csv", CSVParams().Delim(',').SkipHeader(true));
        while (csv.hasNext()) {
            Optional<int> a;
            int b;
            std::string c;
            MyInt d;
            csv.to(a, b, ignore, c,
                [&d](const std::string& s) {
                    d.Value = std::stoi(s);
                }
            );
            if (a) {
                std::cout << a.value() << ", ";
            } else {
                std::cout << "NA, ";
            }
            std::cout << b << ", "
                      << c << ", "
                      << d.Value << std::endl;
        }
    } catch (std::runtime_error& ex) {
        std::cerr << "error: " << ex.what() << std::endl;
    }
}

