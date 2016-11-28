OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := /deploy.brianwbush.info/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/lib/x64/libLeap.so -Wl,-rpath,../lib/x64
  else
    LEAP_LIBRARY := /deploy.brianwbush.info/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/lib/x86/libLeap.so -Wl,-rpath,../lib/x86
  endif
else
  # OS X
  LEAP_LIBRARY := /deploy.brianwbush.info/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/lib/libLeap.dylib
endif

Sample: Sample.cpp
	$(CXX) -Wall -g -I/deploy.brianwbush.info/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/include Sample.cpp -o Sample $(LEAP_LIBRARY)
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib ../lib/libLeap.dylib Sample
endif

clean:
	rm -rf Sample Sample.dSYM
