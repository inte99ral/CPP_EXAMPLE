# Makefile

## Default Setting ===============================================================
### .PHONY 타겟 선언 (실제 파일과 구분)
.PHONY: default all run clean

### 기본 타겟 설정
default: all

## Variable ======================================================================

### directory

SRC_DIR := src
INC_DIR := include
LIB_DIR := lib
BUILD_DIR := build

### files

OUTPUT := main.exe
SRCS := $(wildcard ./src/*.cpp ./src/*/*.cpp ./main.cpp)
OBJS := $(SRCS:./main.cpp=$(BUILD_DIR)/main.o)
OBJS := $(OBJS:./src/%.cpp=$(BUILD_DIR)/src/%.o)

### g++

#### g++ > 컴파일러 선택
CXX       := g++

#### g++ > 컴파일러 옵션 플래그
CXXFLAGS  := -O2 -Wall -g -std=gnu++17

#### g++ > 전처리단계 헤더 경로 추가
CXXINCS   := -I$(INC_DIR) 


#### 링킹단계 라이브러리 경로 추가
CXXLIBS := -L$(LIB_DIR)

#### 링킹단계 라이브러리 링크
CXXLINKS   := -lm

## Target ========================================================================

### 기본 타겟: 실행 파일 생성
# all: $(OUTPUT)
all:
	@echo $(SRCS)
	@echo $(OBJS)

### 링크단계 실행 파일 빌드
$(OUTPUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CXXLIBS) $(CXXLINKS) $^ -o $@

#### 전처리단계 오브젝트 파일 생성

# build/main.o <- main.cpp
$(BUILD_DIR)/%.o: %.cpp
	@mkdir $(dir $@) 2>nul || true
	$(CXX) $(CXXFLAGS) $(CXXINCS) -c $< -o $@

# build/src/foo.o <- src/foo.cpp
$(BUILD_DIR)/src/%.o: src/%.cpp
	@mkdir $(dir $@) 2>nul || true
	$(CXX) $(CXXFLAGS) $(CXXINCS) -c $< -o $@

# build/src/foo/bar.o <- src/foo/bar.cpp
$(BUILD_DIR)/src/%/%.o: src/%/%.cpp
	@mkdir $(dir $@) 2>nul || true
	$(CXX) $(CXXFLAGS) $(CXXINCS) -c $< -o $@


### 실행 파일 실행
run: all
	./$(OUTPUT)

### 오브젝트 파일 및 실행 파일 삭제
clean:
	if exist $(OUTPUT) del /Q $(OUTPUT)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)