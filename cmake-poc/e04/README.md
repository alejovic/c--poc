

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

╰─λ cmake --build /mnt/data/workspace/DEV/c--poc/cmake-poc/e04/build --target operations
[2/2] Linking CXX static library liboperations.a

 ╰─λ cmake --build /mnt/data/workspace/DEV/c--poc/cmake-poc/e04/build --target logger
[2/2] Linking CXX static library liblogger.a

