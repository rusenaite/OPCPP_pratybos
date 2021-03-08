#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#define MAX_NAME_NUMBER 30

void selectionSort(std::vector <std::string> &vect){
    for (std::vector<std::string>::iterator iter = vect.begin(); iter != vect.end() - 1; ++iter){
        std::vector<std::string>::iterator minimum = iter;
        for (std::vector<std::string>::iterator iit = iter + 1; iit != vect.end(); ++iit){
            if(iit -> compare(*minimum) < 0){
                minimum = iit;
            }
        }
        if(minimum != iter){
            std::iter_swap(minimum, iter);
        }
    }
}

void printVector(std::vector <std::string> &vect){
    for(size_t i = 0; i < vect.size(); i++){
        std::cout << vect[i] << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    /* vector is engraved into the code */
    std::vector <std::string> names1 {
        "John", "Adele", "Bethany", "Chase",
        "Rod", "Daniel", "Marie", "Dan",
        "Jim", "Lauren", "Gavin", "Ann",
        "Zoe", "Hardin", "Calvin"
    };
    std::cout << "Vector of names before sorting: \n\n";
    printVector(names1);
    selectionSort(names1);
    std::cout << "Vector of names after sorting: \n\n";
    printVector(names1);

    /* custom vector */
    std::vector <std::string> names2;
    std::string name;
    int count = 0;

    std::cout << "\nNow, enter names of your vector (enter '-' to finish): \n";

    while (std::getline(std::cin, name) && name != "-"){
        names2.push_back(name);
        count++;
        if(count == MAX_NAME_NUMBER - 1){
            std::cout << "\n* You have reached the limit for the names you can enter. * Press '-' to finish the input:";
        }
    }

    std::cout << "\nYour vector stores " << int(names2.size()) << " names.\n";
    selectionSort(names2);
    std::cout << "\nSorted entered vector is: \n";
    printVector(names2);

    //saving results into a file
    std::ofstream ofs("out.txt");
    if(ofs){
        std::cout << "\nFile was created successfully.";
        ofs << "Sorted entered vector:\n" << std::endl;
        for(size_t i = 0; i < names2.size(); i++){
            ofs << names2[i] << std::endl;
        }
        ofs.close();
    } else{
        std::cout << "\nError. File was not created.";
        ofs.close();
    }

    std::cout << "\n\nProgram have saved sorted entered names into a file.\n";

    return 0;
}
