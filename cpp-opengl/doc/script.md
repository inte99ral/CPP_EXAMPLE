# cpp-opengl

## g++ vscode setting

### tasks.json

- `@(CALL SET "srcs= ")`
- `&&`
- `` (FOR /F "usebackq" %i IN (`DIR/A-D/S/B ${fileDirname}\\src 2^>nul ^|findstr/e ".cpp"`) DO @(CALL SET "srcs=%srcs% %i")) ``
- `&&`
- `CALL`

  - `g++`

    - <b><u>g++ > 타겟팅</b></u>
      - `%srcs:~2% ${file}`
    - <b><u>g++ > 출력 결과물</b></u>
      - `-o`
        - `${fileDirname}\\${fileBasenameNoExtension}.exe`
    - <b><u>g++ > 옵션</b></u>
      - `-O2`
      - `-Wall`
      - `-static`
      - `-std=gnu++17`
    - <b><u>g++ > 전처리단계 헤더 경로 추가</b></u>
      - `-ID:\\Program Files\\boost\\include\\boost-1_87`
    - <b><u>g++ > 링킹단계 라이브러리 경로 추가</b></u>
      - `-LD:\\Program Files\\boost\\lib`
    - <b><u>g++ > 링킹단계 라이브러리 이름 지정</b></u>
      - `-lboost_system-mgw14-mt-d-x64-1_87`
      - `-lboost_thread-mgw14-mt-d-x64-1_87`
      - `-lwsock32`
      - `-lws2_32`

이를 tasks.json 에 맞춰서 폼을 변경하면 다음과 같습니다.

```json
{
  "command": "@(CALL",
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
},
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
