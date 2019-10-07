#!bin/bash
cd test
mkdir lib
cd lib
sudo git clone https://github.com/google/googletest.git
cd ..
cd ..
mkdir build
cd build


if [[ "${TRAVIS_OS_NAME}" == "linux" ]]; then
    mkdir -p external/cmake
    pushd external/cmake
    wget https://cmake.org/files/v3.1/cmake-3.1.0-Linux-x86_64.sh
    chmod +x cmake-*-Linux-x86_64.sh
    ./cmake-*-Linux-x86_64.sh --exclude-subdir --skip-license
    export PATH="${PWD}/bin:$PATH"
    popd
else
    if ! brew ls --version cmake &>/dev/null; then brew update; brew install cmake; fi
fi

