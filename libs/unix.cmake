if(NOT WIN32)
  include_directories("${CMAKE_CURRENT_LIST_DIR}/WinSDKHeader/")
  include_directories("${CMAKE_CURRENT_LIST_DIR}/DXC/inc")
  include_directories("${CMAKE_CURRENT_LIST_DIR}/DirectXMath/Inc/")
  include_directories("${CMAKE_CURRENT_LIST_DIR}/dxgiformat/")
endif()
