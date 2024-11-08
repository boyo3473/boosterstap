#include <windows.h>
#include <urlmon.h>
#include <shlwapi.h>
#include <iostream>
#include <string>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "Shlwapi.lib")

using namespace std;

void typeWriter(const string& text, int delay = 50) {
    for (char c : text) {
        cout << c;
        Sleep(delay);
    }
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 5);

    std::cout << "  _____ _____            _____ _  __  ____                  _            _____ _               \n";
    std::cout << " |_   _|  __ \\     /\\   / ____| |/ / |  _ \\                | |          / ____| |              \n";
    std::cout << "   | | | |__) |   /  \\ | |    | ' /  | |_) | ___   ___  ___| |_ ___ _ _| (___ | |_ __ _ _ __  \n";
    std::cout << "   | | |  _  /   / /\\ \\| |    |  <   |  _ < / _ \\ / _ \\/ __| __/ _ \\ '__\\___ \\| __/ _` | '_ \\ \n";
    std::cout << "  _| |_| | \\ \\  / ____ \\ |____| . \\  | |_) | (_) | (_) \\__ \\ ||  __/ |  ____) | || (_| | |_) |\n";
    std::cout << " |_____|_|  \\_\\/_/    \\_\\_____|_|\\_\\ |____/ \\___/ \\___/|___/\\__\\___|_| |_____/ \\__\\__,_| .__/ \n";
    std::cout << "                                                                                       | |    \n";
    std::cout << "                                                                                       |_|    \n";

    Sleep(3000);

    typeWriter("Getting Latest Version of IRACK..\n", 50);
    Sleep(1000);
    typeWriter("Installing..\n", 50);

    const char* url = "https://github.com/boyo3473/irack/releases/download/idk/IRACK.Loader.exe";
    char exePath[MAX_PATH];
    if (GetModuleFileName(NULL, exePath, MAX_PATH) == 0) return 1;
    PathRemoveFileSpec(exePath);
    std::string filePath = std::string(exePath) + "\\IRACK Loader.exe";

    if (PathFileExists(filePath.c_str())) {
        if (!DeleteFile(filePath.c_str())) return 1;
    }

    HRESULT hr = URLDownloadToFile(NULL, url, filePath.c_str(), 0, NULL);

    if (SUCCEEDED(hr)) {
        
        typeWriter("Done!\n", 50);
        Sleep(1000);

        string input;
        typeWriter("Would you like to open IRACK (Y/N): ", 40);
        cin >> input;

        if (input == "y")
        {
            ShellExecute(NULL, "open", filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
        }
      


        typeWriter("Exiting in 10 Seconds.\n", 50);
        Sleep(10000);
    }
    else {
        typeWriter("Download failed.\n", 50);
    }

    return 0;
}
