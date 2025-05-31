# CPP_ASIO

## g++ 명령어

```bat
:: srcs 변수 초기화
@(CALL SET \"srcs= \")

&&

:: srcs 변수에 .cpp 로 끝나는 파일 경로 넣기
(FOR /F \"usebackq\" %i IN (`DIR/A-D/S/B ${fileDirname}\\src 2^>nul ^|findstr/e \".cpp\"`) DO @(CALL SET \"srcs=%srcs% %i\"))

&

:: srcs 변수와 함께 대상 Main.cpp(= ${file}) 까지 gcc 컴파일
CALL g++ %srcs:~2% ${file} -o ${fileDirname}\\${fileBasenameNoExtension}.exe -O2 -Wall -static -std=gnu++17 -ID:\\Program Files\\boost\\include\\boost-1_87 -LD:\\Program Files\\boost\\lib -lboost_system-mgw14-mt-d-x64-1_87 -lboost_thread-mgw14-mt-d-x64-1_87 -lwsock32 -lws2_32
```

위 명령어를 task.json 에 맞춰서 변경하면 다음과 같습니다.

```json
{
  // task.json 에 대한 공식문서 https://go.microsoft.com/fwlink/?LinkId=733558
  "version": "2.0.0",
  "tasks": [
    // ### [x] C++：CMD：ASIO 라이브러리 빌드 ======================================
    {
      "label": "C++：CMD：ASIO 라이브러리 빌드",
      "detail": "내부의 cpp 파일들을 반복검색한 후 빌드합니다.",
      "type": "cppbuild",
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": {
        "owner": "cpp",
        "fileLocation": ["relative", "${workspaceRoot}"],
        "pattern": {
          "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
          "file": 1,
          "line": 2,
          "column": 3,
          "severity": 4,
          "message": 5
        }
      },
      "command": "@(CALL",
      "args": [
        // * cpp 파일 목록 초기화
        "SET",
        "\"srcs= \")",
        "&&",
        // * FOR dir cpp 파일 검색
        "(FOR",
        "/F",
        "\"usebackq\"",
        "%i",
        "IN",
        "(`DIR/A-D/S/B",
        "${fileDirname}\\src",
        // ** 에러 출력 리다이렉션
        "2^>nul",
        "^|findstr/e",
        "\".cpp\"`)",
        "DO",
        "@(CALL",
        "SET",
        "\"srcs=%srcs% %i\"",
        "))",
        "&",
        // * g++
        "CALL",
        "g++",
        // ** g++ > 타겟팅
        "%srcs:~2%",
        "${file}",
        "-o${fileDirname}\\${fileBasenameNoExtension}.exe",
        // ** g++ > 옵션
        "-O2",
        "-Wall",
        "-static",
        "-std=gnu++17",
        // ** g++ > 참조 설정
        "-ID:\\Program Files\\boost\\include\\boost-1_87",
        "-LD:\\Program Files\\boost\\lib",
        "-lboost_system-mgw14-mt-d-x64-1_87",
        "-lboost_thread-mgw14-mt-d-x64-1_87",
        "-lwsock32",
        "-lws2_32"
      ]
    }
  ]
}
```
