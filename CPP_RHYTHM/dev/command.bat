:: # BAT：.cpp 파일들을 탐색합니다 ========================================
:: ## 상세 설명
:: dir     > 폴더 및 파일 리스트 출력
:: /a-d    > dir option. 폴더명은 검색에서 제외
:: /s      > dir option. 하위폴더 파일도 검색
:: /b      > dir option. 복잡한 테이블말고 최소포맷인 결과만 보기
:: %~dp0   > 탐색할 경로. 드라이브를 포함한 현재 bat 파일 경로
:: |       > 명령 간 데이터 전달 Pipe & Redirection
:: findstr > 텍스트의 패턴을 검색합니다.
:: /e      > findstr option. 줄의 끝에서 부터 검색합니다.
dir /a-d /s /b %~dp0 | findstr /e ".cpp"

:: # BAT：.cpp 파일들을 탐색한 후, 한 줄 씩 출력합니다 ======================
FOR /F "usebackq" %%a IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.cpp"`) DO (
  ECHO [CPP_PATH] = %%a
)

:: # BAT：.cpp 파일들을 탐색한 후, "변수"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 변수에 저장한 뒤 ECHO 로 출력합니다
(FOR /F "usebackq" %%i IN (`dir/a-d/s/b %~dp0 ^|findstr/e ".cpp"`) DO (SET cpps=!cpps! %%i)) & CALL ECHO "[CPP_PATH] = !cpps:~1!"

:: 다음 식은 bat 파일에선 정상적으로 돌아가지 않습니다.
::  이유 1. %~dp0은 batch 파일의 경로 값을 가진 인수입니다. cmd 명령줄 입력 시엔 %~dp0 을 쓸 수 없습니다.
::  이유 2. cmd 명령줄 입력 시엔 %<variable> 이 아니라 %%<variable> 를 사용합니다.
::  이유 3. bat 작업 중, 변수값이 명령 도중 변화할 경우엔 지연확장(DelayedExpansion)을 적용해야 합니다.
::  이유 4. cmd 명령줄 입력 시엔 cpps 변수가 선언된 적 없을 경우 "%cpps%" 라는 문자열로 인식하지만 bat 파일에선 비어있는 변수값 "" 으로 인식합니다.

:: 다음과 같은 차이를 감안하여 CMD에서 쓸 경우에는 다음과 같이 바꾸어주셔야 합니다.

:: # CMD：.cpp 파일들을 탐색한 후, "변수"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 변수에 저장한 뒤 ECHO 로 출력합니다
::(FOR /F "usebackq" %i IN (`dir/a-d/s/b <DIRECTORY_PATH> ^|findstr/e ".cpp"`) DO @(CALL SET cpps=%cpps% %i)) & CALL ECHO "[CPP_PATH] = %cpps:~7%"

:: # BAT：.cpp 파일들을 탐색한 후, "파일"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 파일에 저장한 뒤 ECHO 로 출력합니다
(FOR /F "usebackq" %%i IN (`dir/a-d/s/b %~dp0 ^|findstr/e ".cpp"`) DO (@<NUL SET/P= "%%i " >> cpps.txt)) & CALL SET/P cpps=<cpps.txt & @CALL ECHO "[CPP_PATH]: !cpps:~0,-1!" & DEL/Q cpps.txt

:: 위와 마찬가지로 CMD에서 쓸 경우에는 다음과 같이 바꾸어주셔야 합니다.

:: # CMD：.cpp 파일들을 탐색한 후, "변수"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 파일에 저장한 뒤 ECHO 로 출력합니다
::(FOR /F "usebackq" %i IN (`dir/a-d/s/b <DIRECTORY_PATH> ^|findstr/e ".cpp"`) DO @(@<NUL SET/P= "%i " >> cpps.txt)) & CALL SET/P cpps=<cpps.txt & CALL ECHO "[CPP_PATH]: %cpps:~0,-1%" & DEL/Q cpps.txt


:: # ====================================================================
g++ <INPUT_FILE> -o <OUTPUT_FILE>

gcc의 링커가 알고있는 정보들을 기반으로 위치를 추측하여 헤더들을 찾아서 링크시켜줍니다. -I를 이용해 경로를 추가시킬 수 있습니다.
g++ -I<INCLUDE_DIRECTORY_PATH> <INPUT_FILE> -o <OUTPUT_FILE>

g++ -L<LIBRARY_DIRECTORY_PATH> <INPUT_FILE> -o <OUTPUT_FILE>

-L<LIBRARY_DIRECTORY_PATH>

-L/data[...]/lib

(FOR /F "usebackq" %i IN (`dir/a-d/s/b <DIRECTORY_PATH> ^|findstr/e ".cpp"`) DO @(CALL SET cpps=%cpps% %i)) & CALL g++ %cpps:~7% -o ${fileDirname}\\${fileBasenameNoExtension}.exe -O2 -static -std=gnu++17