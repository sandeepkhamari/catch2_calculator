# remove the build directory.
rm -rf build

# create a build directory.
mkdir -p build

# change directory.
cd build

# Build generation and configuration.
cmake -S.. -B.

# Build project.
cmake --build .

# Run tests using ctest.
ctest --verbose

# Run tagged tests: runs only test tagged with "generator".
cd test
./test_calculator [generator]
./test_calculator [test1]
./test_calculator [generator],[test1]

# Find catch2 version.
sudo apt show catch2
