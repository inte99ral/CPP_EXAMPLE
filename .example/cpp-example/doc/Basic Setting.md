# Basic Setting

## 프로젝트 구조 및 형상 관리 컨벤션

cpp 프로젝트 구조
https://stackoverflow.com/questions/2360734/whats-a-good-directory-structure-for-larger-c-projects-using-makefile

### Visual Studio C++ MFC 프로젝트 구조

- MFC (Microsoft Foundation Class Library, 마이크로소프트 파운데이션 클래스 라이브러리)는 윈도우 응용 프로그램의 통합 개발 환경인 마이크로소프트 비주얼 C++ 에 부속되는 클래스 라이브러리입니다.
- 단순하게 표현하면 C++로 GUI 윈도우 프로그램을 만드는 라이브러리입니다.
- 해당 구조는 솔루션(.sln) 단위로 구성되며, 솔루션은 다수의 프로젝트를 포함합니다.
- 각 프로젝트들은 exe, dll 파일을 생성합니다.
- 프로젝트 구성 파일과 개발한 코드, 빌드 산출물들이 모두 섞여있는 단순한 구조입니다.
- 체계적인 관리를 위해선 별도의 구조로 정리할 필요가 있습니다.

```text
project-folder/ (솔루션 최상위 폴더)
├─ project-folder/ (각 프로젝트 공통 구성파일, 설정, .cpp, .hpp)
│  ├─ debug/ (프로젝트의 디버그 빌드로 생성된 obj 파일)
│  └─ release/ (프로젝트의 릴리즈 빌드로 생성된 obj 파일)
├─ debug/ (솔루션의 디버그 빌드 결과물이 저장되는 경로)
└─ release/ (솔루션의 릴리즈 빌드 결과물이 저장되는 경로)
```

### 보편적인 구조

- 체계적인 관리를 감안하여 짜여지는 보편적인 구조입니다.
- 전체 프로젝트의 형상 관리를 위해서 확장자와 역할 별로 묶습니다.

  ```text
  project-folder/ (root)
  ├─ bin/ (빌드 결과물, .exe, .dll, 재배포 패키지 등)
  ├─ build/ (빌드 결과물, .exe, .dll, 재배포 패키지 등)
  │  ├─ ExExe/ (ExExe 프로젝트 폴더)
  │  └─ ExDLL/ (ExDLL 프로젝트 폴더)
  ├─ doc/ (개발 관련 문서, 원페이저, SRS, SDS, 매뉴얼, 참고문서)
  ├─ include/ (각 프로젝트에서 직접 작성했거나 외부 라이브러리의 헤더파일)
  │  ├─ ExExe/ (ExExe 프로젝트 폴더)
  │  ├─ ExDLL/ (ExDLL 프로젝트 폴더)
  │  └─ ExLibrary/ (외부 라이브러리 폴더)
  ├─ lib/ (외부 라이브러리나 프로젝트 빌드로 생성된 .lib 파일)
  │  ├─ ExExe/ (ExExe 프로젝트 폴더)
  │  ├─ ExDLL/ (ExDLL 프로젝트 폴더)
  │  └─ ExLibrary/ (외부 라이브러리 폴더)
  ├─ obj/ (프로젝트 빌드로 생성된 obj 파일과 빌드 산출물)
  │  ├─ ExExe/ (ExExe 프로젝트 폴더)
  │  │  ├─ debug/ (ExExe 디버그 빌드)
  │  │  └─ release/ (ExExe 릴리즈 빌드)
  │  └─ ExDLL/ (ExDLL 프로젝트 폴더)
  │     ├─ debug/ (ExDLL 디버그 빌드)
  │     └─ release/ (ExDLL 릴리즈 빌드)
  └─ src/ (.cpp 소스 파일)
     ├─ ExExe/ (ExExe 프로젝트 폴더)
     ├─ ExDLL/ (ExDLL 프로젝트 폴더)
     └─ ExLibrary/ (외부 라이브러리 폴더)
  ```

### 개인적으로 자주쓰는 구조

- 개인적으로 자주쓰는 구조는 다음과 같습니다.

  ```text
  project-folder/ (root folder 최상위 루트 폴더)
  ├─ build/ (컴파일된 빌드 결과물, .exe, .dll)
  │  ├─ debug/ (디버그 빌드. 또는 test/ 시범용 빌드)
  │  └─ release/ (릴리즈 빌드. 또는 dist/ 배포용 빌드)
  ├─ dev/ (개발 중인 소스코드 및 에셋)
  │  ├─ asset/ (BGM과 이미지 등의 에셋)
  │  ├─ include/ (소스코드와 라이브러리의 인터페이스 all special included .h)
  │  ├─ lib/ (외부 참조 라이브러리 all third-party library files (.a/.so files) here)
  │  └─ src/ (개발 소스코드 (.c , .h .cpp) files here)
  ├─ doc/ (개발 관련 문서, 원페이저, SRS, SDS, 매뉴얼, 참고문서)
  ├── .gitignore
  ├── LICENSE
  ├── Makefile
  └── README.md
  ```

## g++ vscode setting

### tasks.json

```json
// # tasks.json
{
  "version": "2.0.0",
  "tasks": [
    // ## C++ 디버그 빌드 및 상세 설명
    {
      // ### Label: 작업의 이름(라벨명), 우리가 보고 찾는 용도이므로 한 눈에 어떤 작업인지 파악하기 쉽도록 이름을 짓는 것이 좋습니다.
      "label": "C++: g++ 디버그 빌드 (상세설명)",

      // ### Detail: 작업의 세부설명, 작업의 세부설명입니다.
      "detail": "-g 옵션으로 표준 디버깅 정보를 포함하여 빌드합니다.",

      // ### Type: 작업의 타입, 이 작업이 어떠한 유형의 작업인지 서술합니다. 대표적으로 shell(해당 명령어를 쉘에서 실행), process(해당 프로그램을 구동), cppbuild(파일 빌드 및 디버깅) 가 있습니다.
      "type": "cppbuild",

      // ### Group: 작업의 그룹, vscode가 해당 작업을 찾기 위한 작업의 태그입니다. 정해진 값 외에는 허용되지 않습니다. build(컴파일 및 빌드), test(vscode 터미널에서 테스트 구동), none(작업을 그룹에 할당 안 함) 가 있습니다.
      "group": {
        "kind": "build",
        // #### isDefault: 작업 우선순위 설정, true로 지정한 작업이 있을 경우, 다른 false는 무시되고 해당 작업을 합니다. true 지정한 작업이 복수일 경우, false는 무시되고 true 인 작업들만 목록에 올라옵니다.
        "isDefault": true
      },

      // ### Command: 작업시 실행할 명령어.
      "command": "@(CALL",

      // ### Arguments: 작업 실행할 명령어 인자값, 각 옵션과 입력값들을 적습니다.
      "args": [
        // * cpp 파일 목록 초기화
        "SET",
        "\"srcs= \")",
        "&&",
        // * FOR
        "(FOR",
        "/F",
        "\"usebackq\"",
        "%i",
        "IN",
        // ** FOR > dir cpp 파일 검색
        "(`DIR/A-D/S/B",
        "${fileDirname}\\src",
        // ** FOR > 에러 출력 리다이렉션
        "2^>nul",
        "^|findstr/e",
        "\".cpp\"`)",
        "DO",
        "@(CALL",
        "SET",
        "\"srcs=%srcs% %i\"",
        "))",
        "&&",
        // * g++
        "CALL",
        "g++",
        // ** g++ > 타겟팅
        "%srcs:~2%", // : FOR 루프에서 찾은 모든 .cpp 파일 경로들
        "${file}", // : 현재 vscode에서 열고있는 파일, 즉 Main.cpp
        // ** g++ > 출력 결과물
        "-o${fileDirname}\\${fileBasenameNoExtension}.exe", // : {Main.cpp 와 같은경로}/{Main.cpp 와 같은이름}.exe
        // ** g++ > 옵션
        "-O2", // : 최적화 레벨 옵션 - O2 옵션은 loop unrolling, function inlining, 메모리 및 속도희생을 제외한 모든 범위 최적화하는 옵션
        "-Wall", // : 경고 레벨 옵션 - Wall 은 모든 모호한 코딩에 대해서 경고를 보내는 옵션
        "-static", // : 정적 동적 선택 옵션 - static 은 정적 라이브러리와 공유 라이브러리 중 정적을 우선합니다. 속도는 빠르지만 파일 사이즈가 커짐
        "-g", // : 표준 디버깅 정보 포함 옵션
        "-std=gnu++17", // : 언어 버전 옵션 - C++ 의 C++17 Clang GNU 확장기능을 적용한다고 선언
        // ** g++ > 전처리단계 헤더 경로 추가
        "-ID:\\Program Files\\boost\\include\\boost-1_87",
        // ** g++ > 링킹단계 라이브러리 경로 추가
        "-LD:\\Program Files\\boost\\lib",
        // ** g++ > 링킹단계 라이브러리 이름 지정
        "-lboost_system-mgw14-mt-d-x64-1_87",
        "-lboost_thread-mgw14-mt-d-x64-1_87",
        "-lwsock32",
        "-lws2_32"
      ]

      // ### Options: 작업 실행 옵션, 작업 설정 등 추가적인 사항
      "options": {
        // 작업 디렉터리 주소 설정 옵션
        "cwd": "${fileDirname}",
        // 쉘 터미널 지정
        "shell": {
          }
        }
      },

      // ### Problem Matcher: 문제 상황 및 경고 문구 매칭 : 컴파일러 출력을 파싱하여 오류와 경고를 표시합니다. https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
      "problemMatcher": {
        // 문제를 발생시킨 대상
        "owner": "cpp",
        // 문제의 발생지
        "fileLocation": ["relative", "${workspaceRoot}"],
        // 문제 상황 및 경고 문구의 패턴
        "pattern": {
          // 정규 표현식 : 정규 표현식으로 컴파일러의 문구를 분석합니다. (에러 테스트 예시: helloWorld.c:5:3: warning: implicit declaration of function 'prinft')
          "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
          "file": 1,
          "line": 2,
          "column": 3,
          "severity": 4,
          "message": 5
        }
      }
    }
  ]
}
```
