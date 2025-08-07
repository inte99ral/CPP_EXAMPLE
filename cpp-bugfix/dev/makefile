# Makefile

## Default Setting ===============================================================
### .PHONY 타겟 선언 (실제 파일과 구분)
.PHONY: default all run clean

### 기본 타겟 설정
default: all

OUTPUT := output.exe
SRCS := $(wildcard src/*.cpp src/*/*.cpp main.cpp)
OBJS := $(SRCS:%.cpp=build/%.o)

## Target ========================================================================
### 기본 타겟: 실행 파일 생성

# all:
# 	@echo $(SRCS)
# 	@echo $(OBJS)
all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	g++ $^ -o $@

build/%.o: %.cpp
	@IF NOT EXIST "$(subst /,\,$(dir $@))" MKDIR "$(subst /,\,$(dir $@))"
	g++ $< -o $@ -c

run: all
	@./$(OUTPUT)

clean:
	@IF EXIST $(OUTPUT) DEL /Q $(OUTPUT)
	@IF EXIST "build" RMDIR /S /Q "build"