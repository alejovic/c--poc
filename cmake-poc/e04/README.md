

Targets

λ cmake --system-information info.txt

λ cmake -G "Ninja" -D CMAKE_CXX_COMPILER=/usr/bin/c++ ..
-- The C compiler identification is GNU 12.2.1
-- The CXX compiler identification is GNU 12.2.1

λ cmake -G "Ninja" -D CMAKE_CXX_COMPILER=/usr/bin/g++ ..
-- The C compiler identification is GNU 12.2.1
-- The CXX compiler identification is GNU 12.2.1

λ cmake -G "Ninja" -D CMAKE_CXX_COMPILER=/usr/bin/clang ..
-- The C compiler identification is GNU 12.2.1
-- The CXX compiler identification is Clang 15.0.7

