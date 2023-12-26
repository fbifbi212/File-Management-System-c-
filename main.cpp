#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Function to add a file
void addFile() {
    std::string fileName, fileContent;

    std::cout << "Enter file name: ";
    std::cin >> fileName;

    std::ofstream file(fileName.c_str());
    std::cin.ignore();
    std::cout << "Enter file content (press Enter then Ctrl+D in a new line to finish):\n";
    while (std::getline(std::cin, fileContent)) {
        file << fileContent << std::endl;
    }
    file.close();

    std::cout << "File created successfully.\n";
}

// Function to delete a file
void deleteFile() {
    std::string fileName;

    std::cout << "Enter file name to delete: ";
    std::cin >> fileName;

    if (std::remove(fileName.c_str()) == 0) {
        std::cout << "File deleted successfully.\n";
    } else {
        std::cout << "Error deleting the file.\n";
    }
}

// Function to list all files in the directory
void listFiles() {
    std::vector<std::string> files;
    std::string fileName;
    std::ifstream fileList("filelist.txt");

    while (std::getline(fileList, fileName)) {
        files.push_back(fileName);
    }
    fileList.close();

    std::cout << "List of files:\n";
    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
}

int main() {
    int choice;

    while (true) {
        std::cout << "\nFile Management System\n";
        std::cout << "1. Add File\n";
        std::cout << "2. Delete File\n";
        std::cout << "3. List Files\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                listFiles();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}