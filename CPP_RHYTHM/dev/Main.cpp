#include <iostream>

// # 환경 구성 ==================================================
// ## 헤더 파일과 라이브러리 =====================================
#include "include/fmod.hpp"
#include "include/fmod.h"
#include "include/fmod_errors.h"
#pragma comment (lib, "fmod_vc.lib")

using namespace std;

int main() {
  cout << "[VERSION]:v0.03" << endl;

  // ## 필수 인터페이스 3가지 ======================================
  
  // * System 는 사운드 시스템을 의미합니다. 다이렉트 디바이스와 유사합니다.
  FMOD::System* m_pSystem = nullptr;

  // * Sound 는 사운드 포인터입니다. 실제 사운드 메모리 입니다.
  FMOD::Sound* m_pSound = nullptr;

  // * Channel 은 오디오 채널입니다. 중복적으로 실행이 되기 위해서 필요하며, 최대 32채널까지 가능합니다.
  FMOD::Channel* m_pChannel = nullptr;


  return 0; 
}