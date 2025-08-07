# cpp-opengl：Basic Setting

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
        "-std=gnu++17", // : 언어 버전 옵션 - C++ 의 C++17 GNU 확장기능을 적용한다고 선언
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

### Makefile

- tasks.json 기본 설정

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Makefile Build",
      "type": "shell",
      "command": "mingw32-make",
      "args": [],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": []
    }
  ]
}
```

- makefile 기본 설정

```makefile
# Makefile
## Default Setting
### .PHONY 타겟 선언 (실제 파일과 구분)
.PHONY: default all run clean

### 기본 타겟 설정
default: run


## Variable
### 컴파일러 선택
CXX      := g++

### 컴파일러 옵션
CXXFLAGS := -Wall -Wextra -Werror -std=c++11 -g

### 소스 파일
SRC      := Main.cpp

### 오브젝트 파일(example0.cpp example1.cpp -> example0.o example1.o 를 의미하는 문법입니다.)
OBJ      := $(SRC:.cpp=.o)

### 실행 파일 이름
OUTPUT   := outputfile


## Target
### 기본 타겟: 실행 파일 생성
all: $(OUTPUT)

### 실행 파일 빌드
$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

#### 오브젝트 파일 생성(패턴규칙을 의미하는 문법입니다. .o 로 끝나는 타겟에 전부 적용됩니다.)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

### 실행 파일 실행
run: all
	./$(OUTPUT)

### 오브젝트 파일 및 실행 파일 삭제
clean:
	rm -f $(OBJ) $(OUTPUT)
```

## 환경 구축

&nbsp; OpenGL은 그래픽 렌더링에만 집중하는 API이기 때문에, 창 생성, 입력 처리, 오디오 등은 직접 제공하지 않습니다. 그래서 OpenGL로 개발을 할 때에는 보통 SDL, GLFW, SFML 같은 라이브러리와 함께 사용합니다.

&nbsp; 다음의 라이브러리들을 설치해야 합니다.

- OpenGL

  &nbsp; OpenGL(Open Graphics Library) 은 범용성을 보장하기 위해 발표된 2D, 3D 그래픽 API의 규격서이자 범용 크로스플랫폼 라이브러리 입니다.

- OpenAL

  &nbsp; 주로 3D 공간 음향, 위치 기반 오디오 등 게임의 고급 사운드 효과를 줄 수 있습니다.

- GLFW

  &nbsp; OpenGL 용 창 및 이벤트 처리 라이브러리

- SDL

  &nbsp; SDL(Simple DirectMedia Layer) 은 크로스플랫폼 멀티미디어 라이브러리로, 게임 및 멀티미디어 애플리케이션 개발을 쉽게 해주는 다양한 기능을 제공합니다. SDL은 창 생성, 입력(키보드/마우스/조이스틱), 오디오, 네트워크, 렌더링(2D 그래픽) 등을 지원하며, 특히 플랫폼별로 달라지는 저수준 API를 추상화해서 개발자가 한 번 작성한 코드로 여러 운영체제에서 동작하게 할 수 있습니다.

- SDL_net

&nbsp; 설치 명령어는 다음과 같습니다.

```bash
# 시스템 전체 업데이트
pacman -Syu

# OpenGL
## OpenGL 헤더 및 기본 개발 파일
pacman -S mingw-w64-ucrt-x86_64-opengl-api

## OpenGL용 창 및 이벤트 처리 라이브러리
pacman -S mingw-w64-ucrt-x86_64-glfw

## OpenGL 확장 래퍼 라이브러리
pacman -S mingw-w64-ucrt-x86_64-glew

## OpenAL 3D 사운드 등 고급 오디오 기능 라이브러리
pacman -S mingw-w64-ucrt-x86_64-openal

# SDL2
## SDL2 기본 라이브러리
pacman -S mingw-w64-ucrt-x86_64-SDL2

## SDL 확장 모듈 (이미지, 오디오, 텍스트 처리 등)
pacman -S mingw-w64-ucrt-x86_64-SDL2_image
pacman -S mingw-w64-ucrt-x86_64-SDL2_mixer
pacman -S mingw-w64-ucrt-x86_64-SDL2_ttf
```
