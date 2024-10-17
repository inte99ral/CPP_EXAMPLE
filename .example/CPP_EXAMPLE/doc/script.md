# 프로젝트 구조 및 형상 관리 컨벤션

cpp 프로젝트 구조
https://stackoverflow.com/questions/2360734/whats-a-good-directory-structure-for-larger-c-projects-using-makefile

## Visual Studio C++ MFC 프로젝트 구조

- MFC (Microsoft Foundation Class Library, 마이크로소프트 파운데이션 클래스 라이브러리)는 윈도우 응용 프로그램의 통합 개발 환경인 마이크로소프트 비주얼 C++ 에 부속되는 클래스 라이브러리입니다.
- 단순하게 표현하면 C++로 GUI 윈도우 프로그램을 만드는 라이브러리입니다.
- 해당 구조는 솔루션(.sln) 단위로 구성되며, 솔루션은 다수의 프로젝트를 포함합니다.
- 각 프로젝트들은 exe, dll 파일을 생성합니다.
- 프로젝트 구성 파일과 개발한 코드, 빌드 산출물들이 모두 섞여있는 단순한 구조입니다.
- 체계적인 관리를 위해선 별도의 구조로 정리할 필요가 있습니다.

```text
PROJECT_FOLDER/ (솔루션 최상위 폴더)
├─ PROJECT_FOLDER/ (각 프로젝트 공통 구성파일, 설정, .cpp, .hpp)
│  ├─ debug/ (프로젝트의 디버그 빌드로 생성된 obj 파일)
│  └─ release/ (프로젝트의 릴리즈 빌드로 생성된 obj 파일)
├─ debug/ (솔루션의 디버그 빌드 결과물이 저장되는 경로)
└─ release/ (솔루션의 릴리즈 빌드 결과물이 저장되는 경로)
```

## 보편적인 구조

- 체계적인 관리를 감안하여 짜여지는 보편적인 구조입니다.
- 전체 프로젝트의 형상 관리를 위해서 확장자와 역할 별로 묶습니다.

  ```text
  PROJECT_NAME/ (root)
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

## 개인적으로 자주쓰는 구조

- 개인적으로 자주쓰는 구조는 다음과 같습니다.

  ```text
  PROJECT_NAME/ (root folder 최상위 루트 폴더)
  ├─ build/ (컴파일된 빌드 결과물, .exe, .dll)
  │  ├─ debug/ (디버그 빌드. 또는 test/ 시범용 빌드)
  │  └─ release/ (릴리즈 빌드. 또는 dist/ 배포용 빌드)
  ├─ dev/ (개발 중인 소스코드 및 에셋)
  │  ├─ asset/ (BGM과 이미지 등의 에셋)
  │  ├─ include/ (all special included .h)
  │  ├─ lib/ (all third-party library files (.a/.so files) here)
  │  └─ src/ ((.c , .h .cpp) files here)
  ├─ doc/ (개발 관련 문서, 원페이저, SRS, SDS, 매뉴얼, 참고문서)
  ├── .gitignore
  ├── LICENSE
  ├── Makefile
  └── README.md
  ```

## visual studio c++ 프로젝트 구조 변경

- [참고 링크](https://www.bearpooh.com/63)
