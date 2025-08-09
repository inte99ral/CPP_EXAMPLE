# Performance Check：성능검사

```cpp
// # Doc\Language_Reference\C++\Performance Check

// ## Documentation ==========================================================
/**
 * @name Performance Check
 *
 * @description
 *
 * 코드의 메모리 사용량과 시간, 코드 길이를 측정합니다.
 * 가끔 라이브러리 링크가 되어있지 않아 gcc 명령어에 -lpsapi 라이브러리 옵션을 추가해줘야 할 수도 있습니다.
 *
 * @example
 *
 * 1. 검사하고자 하는 함수가 있는 파일이 별도로 있다면 경로를 명시하여 #include ""...cpp" 로 전처리 단계에서 병합되도록 해주세요.
 * 2. 검사하고자 하는 파일 경로와 함수를 testVec 에 넣어주세요.
 *
 * @author inte99ral
 * @version 0.0.0 2025-04-19
 */

 // ## Import Declaration =====================================================

// ### API & Library:

#include <chrono>
// ├ chrono::high_resolution_clock
// ├ chrono::_V2::system_clock::time_point
// ├ chrono::duration_cast<T>
// └ chrono::microseconds
#include <windows.h>
// └ GetCurrentProcess()
#include <psapi.h>
// ├ PROCESS_MEMORY_COUNTERS_EX
// └ GetProcessMemoryInfo()
#include <filesystem>
// └ filesystem::exists
#include <fstream>
// └ ifstream
#include <iostream>
// └ cout
#include <functional>
// └ function
#include <iomanip>
// └ setw()

#include "./src/Main.cpp" // <---------------------------------[ TEST TARGET ]

// ### Definition:

#define MEMORY_STAMP size_t
#define TIME_STAMP chrono::_V2::system_clock::time_point

// ### Namespace:

using namespace std;

// ## Implements Definition ==================================================

MEMORY_STAMP getMemoryStamp() {
  PROCESS_MEMORY_COUNTERS_EX pmc;
  GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
  return pmc.PrivateUsage;
}

TIME_STAMP getTimeStamp() {
  return chrono::high_resolution_clock::now();
}

// ### Main

int main(int argc, char* argv[]) {
  // * {『코드길이 측정할 파일경로, 없을 시 ""』,『성능 측정할 함수명』}
  vector<pair<string, function<int(int, char**)>>> testVec;
  testVec.push_back({"./src/Main.cpp", main_00}); // <-----------------------[ TEST TARGET ]
  testVec.push_back({"", main_00});

  for(auto test : testVec) {
    int exitCode = 0;
    string testFile = test.first;
    auto testCode = test.second;

    MEMORY_STAMP memoryBefore = getMemoryStamp();
    TIME_STAMP timeStart = getTimeStamp();

    try {
      exitCode =  testCode(argc, argv);
    } catch(const exception& e) {
      exitCode = 1;
    }

    MEMORY_STAMP memoryAfter = getMemoryStamp();
    TIME_STAMP timeEnd = getTimeStamp();

    cout << "\n\n╔════════════════╦═════════════╗\n";

    if (testFile != "" && filesystem::exists(testFile)) {
      ifstream file(testFile);
      size_t charCount = 0;
      size_t lineCount = 0;
      for (string line; getline(file, line);) {
        charCount += line.size() + 1; // +1 은 줄바꿈 문자(\n) 포함
        lineCount++;
      }
      file.close();
      cout << "║" << setw(16) << left << " File Line" << "║ " << setw(5) << left << lineCount << " Lines ║\n";
      cout << "╠════════════════╬═════════════╣\n";
      cout << "║" << setw(16) << left << " File Byte" << "║ " << setw(9) << left << charCount << " B ║\n";
    }
    else {
      cout << "║ File Unopened  ║     ---     ║\n";
    }

    cout << "╠════════════════╬═════════════╣\n";

    if (exitCode == 0) {
      cout << "║" << setw(16) << left << " Time Duration" << "║ " << setw(8) << left << static_cast<float>(chrono::duration_cast<chrono::microseconds>(timeEnd - timeStart).count()) / 1000  << " ms ║\n";
      cout << "╠════════════════╬═════════════╣\n";
      cout << "║" << setw(16) << left << " Memory Usage" << "║ " << setw(8) << left << (memoryAfter - memoryBefore) / 1024  << " KB ║\n";
    }
    else {
      cout << "║ Code Error     ║     ---     ║\n";
    }

    cout << "╚════════════════╩═════════════╝\n";
  }
  return 0;
}
```
