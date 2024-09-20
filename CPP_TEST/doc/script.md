# SCRIPT

    {
      "label": "파워쉘 컴파일 코드",
      "type": "shell",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "command": "g++",
      "args": [
        "$((Get-ChildItem",
        "-Path",
        "${fileDirname}",
        "-Recurse",
        "-Force",
        "-Filter",
        "*.?pp).FullName)",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "-O2",
        "-Wall",
        "-static",
        "-std=gnu++17"
      ]
    },

## cpp 모두 찾는 cmd 코드

```txt
(FOR
/F
"usebackq"
%i
IN
(`dir
${fileDirname}
/a-d
/s
/b
^|
findstr
/e
"\.cpp"`)
DO
@<NUL
SET
/P=
"%i "
>> 
${fileDirname}\\cpps.txt)
&
SET
/P
var=<${fileDirname}\\cpps.txt
& 
@CALL 
ECHO 
%var% 
& 
DEL /Q ${fileDirname}\\cpps.txt
```

## cpp 모두 찾아 g++ 빌드하는 코드

(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @<NUL SET /P="%i ">>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt) & SET /P var=<E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt & CALL g++ %var%-o E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.exe & DEL /Q E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt
